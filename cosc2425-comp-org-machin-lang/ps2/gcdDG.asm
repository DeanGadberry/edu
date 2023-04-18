; Copyright (C) Dean Gadberry - All Rights Reserved
; Unauthorized copying of this file, via any medium is strictly prohibited
; Proprietary and confidential
; Written by Dean Gadberry <code@deangadberry.com>, 2023

; gcdDG.asm
; Dean Gadberry
; COSC 2425 0400
; Problem Set 2, Problem 3
; References:
	; https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/
		; Euclidean algorithm by subtraction
	; https://stackoverflow.com/questions/50204908/masm-how-to-make-desired-function-call
	; https://learn.microsoft.com/en-us/cpp/assembler/masm/operator-gt?view=msvc-170
	; https://stackoverflow.com/questions/9246002/call-atoi-assembler-printf-assembler

.386
.model flat, stdcall, c
.stack 4096

.data
firstNumber dword 0
secondNumber dword 0
gcdFinal dword 0

firstNumberPrompt BYTE "Please enter your first integer: ", 0
secondNumberPrompt BYTE "Please enter your second integer: ", 0
gcdOutput BYTE "GCD: ", 0

.code
includelib libucrt.lib
includelib libcmt.lib
includelib libvcruntime.lib
includelib legacy_stdio_definitions.lib

extrn printf:near
extrn exit:near
extrn gets:near
extrn atoi:near

gcd proc uses esi ecx
	.if esi <= 0
		mov eax, ecx
		ret				; returns second value if first value is subtracted to/past 0
	.elseif ecx <= 0
		mov eax, esi
		ret				; returns first value if second value is subtracted to/past 0
	.elseif esi == ecx
		mov eax, esi
		ret				; returns value if both values are equivalent
	.elseif esi > ecx
		sub esi, ecx
		call gcd
		ret
	.elseif esi < ecx
		sub ecx, esi
		call gcd
		ret
	.endif
gcd endp

main proc

	push offset firstNumberPrompt
	call printf						; prompts user for first number
	push offset firstNumber
	call gets						; stores first number variable with user input
	push offset firstNumber
	call atoi
	mov firstNumber, eax
	push offset secondNumberPrompt
	call printf						; prompts user for second number
	push offset secondNumber
	call gets						; stores second number variable with user input
	push offset secondNumber
	call atoi
	mov secondNumber, eax

	mov esi, firstNumber
	mov ecx, secondNumber
	call gcd
	mov gcdFinal, eax

	push offset gcdOutput
	call printf
	push offset gcdFinal
	call printf                     ; still need to convert this number correctly

	push	0
	call	exit

main endp
end
