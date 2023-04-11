; Copyright (C) Dean Gadberry - All Rights Reserved
; Unauthorized copying of this file, via any medium is strictly prohibited
; Proprietary and confidential
; Written by Dean Gadberry <code@deangadberry.com>, 2023

; yourNameDG.asm
; Dean Gadberry
; COSC 2425 0400
; Problem Set 2, Problem 2
; References:

.386
.model flat, stdcall, c
.stack 4096

.data
yourname BYTE "Dean Gadberry", 0

.code
includelib libucrt.lib
includelib legacy_stdio_definition.lib
includelib libcmt.lib
includelib libvcruntime.lib

extrn printf:near
extrn exit:near

public main
main proc
	push	offset yourname
	call	printf
	push	0
	call	exit

main endp
end