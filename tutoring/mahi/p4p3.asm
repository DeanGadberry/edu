.model small
.stack 100h
.data
    prompt db "Enter a positive integer (include zero): $"
    newline db 0dh, 0ah, "$"   ; Newline character for formatting output
    result db "The factorial is: $"
    number dw ?
    factorial dw ?
.code
main PROC
    mov ax, @data
    mov ds, ax

    ; Prompt user to enter a positive integer
    mov ah, 09h
    lea dx, prompt
    int 21h

    ; Read the input number from the user
    mov ah, 01h     ; Function to read a character from standard input
    int 21h         ; BIOS interrupt call
    sub al, '0'     ; Convert ASCII character to binary digit
    mov number, ax  ; Store the number in the variable

    ; Calculate factorial
    mov cx, number  ; Initialize loop counter with the input number
    mov factorial, 1 ; Initialize factorial to 1
    mov ax, 1       ; Initialize accumulator to 1
calculate_factorial:
    mul cx          ; Multiply accumulator by loop counter
    loop calculate_factorial ; Decrement loop counter and repeat until it becomes zero

    ; Output the result
    mov ah, 09h
    lea dx, result
    int 21h

    mov ax, factorial
    call print_number

    ; Output newline character for formatting
    mov ah, 09h
    lea dx, newline
    int 21h

    ; Exit the program
    mov ah, 4ch
    int 21h

main ENDP

print_number PROC
    ; Print the number in AX register
    mov cx, 10          ; Initialize divisor (for decimal conversion)
    mov bx, 0           ; Initialize flag to indicate leading zeros
print_digit:
    xor dx, dx          ; Clear DX register
    div cx              ; Divide AX by 10
    add dl, '0'         ; Convert remainder to ASCII
    push dx             ; Push ASCII digit onto stack
    test ax, ax         ; Test if quotient is zero
    jnz print_digit     ; If not zero, continue loop
print_loop:
    pop dx              ; Pop digit from stack
    mov ah, 02h         ; DOS function to display character
    int 21h             ; Call DOS
    loop print_loop     ; Loop until stack is empty
    ret
print_number ENDP

END main




