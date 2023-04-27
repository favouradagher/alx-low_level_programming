section .data
    hello: db "Hello, Holberton", 10, 0

section .text
    global main

main:
    push rbp
    mov rbp, rsp

    lea rdi, [hello]
    mov al, 0
    call printf

    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret

