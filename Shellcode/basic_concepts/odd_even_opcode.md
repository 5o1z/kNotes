48 01 c0 - add rax, rax
48 01 d8 - add rax, rbx
48 01 c8 - add rax, rcx
48 01 d0 - add rax, rdx
48 01 f8 - add rax, rdi
48 01 f0 - add rax, rsi
48 01 e0 - add rax, rsp
48 01 e8 - add rax, rbp
4c 01 c0 - add rax, r8
4c 01 c8 - add rax, r9
4c 01 d0 - add rax, r10
4c 01 d8 - add rax, r11
4c 01 e0 - add rax, r12
4c 01 e8 - add rax, r13
4c 01 f0 - add rax, r14
4c 01 f8 - add rax, r15
48 01 c2 - add rdx, rax
48 01 da - add rdx, rbx
48 01 ca - add rdx, rcx
48 01 d2 - add rdx, rdx
48 01 fa - add rdx, rdi
48 01 f2 - add rdx, rsi
48 01 e2 - add rdx, rsp
48 01 ea - add rdx, rbp
4c 01 c2 - add rdx, r8
4c 01 ca - add rdx, r9
4c 01 d2 - add rdx, r10
4c 01 da - add rdx, r11
4c 01 e2 - add rdx, r12
4c 01 ea - add rdx, r13
4c 01 f2 - add rdx, r14
4c 01 fa - add rdx, r15
48 01 c6 - add rsi, rax
48 01 de - add rsi, rbx
48 01 ce - add rsi, rcx
48 01 d6 - add rsi, rdx
48 01 fe - add rsi, rdi
48 01 f6 - add rsi, rsi
48 01 e6 - add rsi, rsp
48 01 ee - add rsi, rbp
4c 01 c6 - add rsi, r8
4c 01 ce - add rsi, r9
4c 01 d6 - add rsi, r10
4c 01 de - add rsi, r11
4c 01 e6 - add rsi, r12
4c 01 ee - add rsi, r13
4c 01 f6 - add rsi, r14
4c 01 fe - add rsi, r15
48 01 c4 - add rsp, rax
48 01 dc - add rsp, rbx
48 01 cc - add rsp, rcx
48 01 d4 - add rsp, rdx
48 01 fc - add rsp, rdi
48 01 f4 - add rsp, rsi
48 01 e4 - add rsp, rsp
48 01 ec - add rsp, rbp
4c 01 c4 - add rsp, r8
4c 01 cc - add rsp, r9
4c 01 d4 - add rsp, r10
4c 01 dc - add rsp, r11
4c 01 e4 - add rsp, r12
4c 01 ec - add rsp, r13
4c 01 f4 - add rsp, r14
4c 01 fc - add rsp, r15
01 c0 - add eax, eax
01 d8 - add eax, ebx
01 c8 - add eax, ecx
01 d0 - add eax, edx
01 f8 - add eax, edi
01 f0 - add eax, esi
01 e0 - add eax, esp
01 e8 - add eax, ebp
01 c2 - add edx, eax
01 da - add edx, ebx
01 ca - add edx, ecx
01 d2 - add edx, edx
01 fa - add edx, edi
01 f2 - add edx, esi
01 e2 - add edx, esp
01 ea - add edx, ebp
01 c6 - add esi, eax
01 de - add esi, ebx
01 ce - add esi, ecx
01 d6 - add esi, edx
01 fe - add esi, edi
01 f6 - add esi, esi
01 e6 - add esi, esp
01 ee - add esi, ebp
01 c4 - add esp, eax
01 dc - add esp, ebx
01 cc - add esp, ecx
01 d4 - add esp, edx
01 fc - add esp, edi
01 f4 - add esp, esi
01 e4 - add esp, esp
01 ec - add esp, ebp
66 01 c0 - add ax, ax
66 01 d8 - add ax, bx
66 01 c8 - add ax, cx
66 01 d0 - add ax, dx
66 01 e0 - add ax, sp
66 01 e8 - add ax, bp
66 01 c2 - add dx, ax
66 01 da - add dx, bx
66 01 ca - add dx, cx
66 01 d2 - add dx, dx
66 01 e2 - add dx, sp
66 01 ea - add dx, bp
66 01 c4 - add sp, ax
66 01 dc - add sp, bx
66 01 cc - add sp, cx
66 01 d4 - add sp, dx
66 01 e4 - add sp, sp
66 01 ec - add sp, bp
00 c3 - add bl, al
00 db - add bl, bl
00 cb - add bl, cl
00 d3 - add bl, dl
00 e3 - add bl, ah
00 fb - add bl, bh
00 eb - add bl, ch
00 f3 - add bl, dh
00 c1 - add cl, al
00 d9 - add cl, bl
00 c9 - add cl, cl
00 d1 - add cl, dl
00 e1 - add cl, ah
00 f9 - add cl, bh
00 e9 - add cl, ch
00 f1 - add cl, dh
00 c7 - add bh, al
00 df - add bh, bl
00 cf - add bh, cl
00 d7 - add bh, dl
00 e7 - add bh, ah
00 ff - add bh, bh
00 ef - add bh, ch
00 f7 - add bh, dh
00 c5 - add ch, al
00 dd - add ch, bl
00 cd - add ch, cl
00 d5 - add ch, dl
00 e5 - add ch, ah
00 fd - add ch, bh
00 ed - add ch, ch
00 f5 - add ch, dh
80 c3 7e - add bl, 0x7e
80 c1 7e - add cl, 0x7e
80 c7 7e - add bh, 0x7e
80 c5 7e - add ch, 0x7e
48 83 c0 7f - add rax, 0x7f
48 83 c2 7f - add rdx, 0x7f
48 83 c6 7f - add rsi, 0x7f
48 83 c4 7f - add rsp, 0x7f
83 c0 7f - add eax, 0x7f
83 c2 7f - add edx, 0x7f
83 c6 7f - add esi, 0x7f
83 c4 7f - add esp, 0x7f
66 83 c0 7f - add ax, 0x7f
66 83 c2 7f - add dx, 0x7f
66 83 c4 7f - add sp, 0x7f
04 7f - add al, 0x7f
48 01 00 - add QWORD PTR [rax], rax
48 01 18 - add QWORD PTR [rax], rbx
48 01 08 - add QWORD PTR [rax], rcx
48 01 10 - add QWORD PTR [rax], rdx
48 01 38 - add QWORD PTR [rax], rdi
48 01 30 - add QWORD PTR [rax], rsi
48 01 20 - add QWORD PTR [rax], rsp
48 01 28 - add QWORD PTR [rax], rbp
4c 01 00 - add QWORD PTR [rax], r8
4c 01 08 - add QWORD PTR [rax], r9
4c 01 10 - add QWORD PTR [rax], r10
4c 01 18 - add QWORD PTR [rax], r11
4c 01 20 - add QWORD PTR [rax], r12
4c 01 28 - add QWORD PTR [rax], r13
4c 01 30 - add QWORD PTR [rax], r14
4c 01 38 - add QWORD PTR [rax], r15
01 00 - add DWORD PTR [rax], eax
01 18 - add DWORD PTR [rax], ebx
01 08 - add DWORD PTR [rax], ecx
01 10 - add DWORD PTR [rax], edx
01 38 - add DWORD PTR [rax], edi
01 30 - add DWORD PTR [rax], esi
01 20 - add DWORD PTR [rax], esp
01 28 - add DWORD PTR [rax], ebp
66 01 00 - add WORD PTR [rax], ax
66 01 18 - add WORD PTR [rax], bx
66 01 08 - add WORD PTR [rax], cx
66 01 10 - add WORD PTR [rax], dx
66 01 20 - add WORD PTR [rax], sp
66 01 28 - add WORD PTR [rax], bp
00 03 - add BYTE PTR [rbx], al
00 1b - add BYTE PTR [rbx], bl
00 0b - add BYTE PTR [rbx], cl
00 13 - add BYTE PTR [rbx], dl
00 23 - add BYTE PTR [rbx], ah
00 3b - add BYTE PTR [rbx], bh
00 2b - add BYTE PTR [rbx], ch
00 33 - add BYTE PTR [rbx], dh
00 01 - add BYTE PTR [rcx], al
00 19 - add BYTE PTR [rcx], bl
00 09 - add BYTE PTR [rcx], cl
00 11 - add BYTE PTR [rcx], dl
00 21 - add BYTE PTR [rcx], ah
00 39 - add BYTE PTR [rcx], bh
00 29 - add BYTE PTR [rcx], ch
00 31 - add BYTE PTR [rcx], dh
48 01 02 - add QWORD PTR [rdx], rax
48 01 1a - add QWORD PTR [rdx], rbx
48 01 0a - add QWORD PTR [rdx], rcx
48 01 12 - add QWORD PTR [rdx], rdx
48 01 3a - add QWORD PTR [rdx], rdi
48 01 32 - add QWORD PTR [rdx], rsi
48 01 22 - add QWORD PTR [rdx], rsp
48 01 2a - add QWORD PTR [rdx], rbp
4c 01 02 - add QWORD PTR [rdx], r8
4c 01 0a - add QWORD PTR [rdx], r9
4c 01 12 - add QWORD PTR [rdx], r10
4c 01 1a - add QWORD PTR [rdx], r11
4c 01 22 - add QWORD PTR [rdx], r12
4c 01 2a - add QWORD PTR [rdx], r13
4c 01 32 - add QWORD PTR [rdx], r14
4c 01 3a - add QWORD PTR [rdx], r15
01 02 - add DWORD PTR [rdx], eax
01 1a - add DWORD PTR [rdx], ebx
01 0a - add DWORD PTR [rdx], ecx
01 12 - add DWORD PTR [rdx], edx
01 3a - add DWORD PTR [rdx], edi
01 32 - add DWORD PTR [rdx], esi
01 22 - add DWORD PTR [rdx], esp
01 2a - add DWORD PTR [rdx], ebp
66 01 02 - add WORD PTR [rdx], ax
66 01 1a - add WORD PTR [rdx], bx
66 01 0a - add WORD PTR [rdx], cx
66 01 12 - add WORD PTR [rdx], dx
66 01 22 - add WORD PTR [rdx], sp
66 01 2a - add WORD PTR [rdx], bp
00 07 - add BYTE PTR [rdi], al
00 1f - add BYTE PTR [rdi], bl
00 0f - add BYTE PTR [rdi], cl
00 17 - add BYTE PTR [rdi], dl
00 27 - add BYTE PTR [rdi], ah
00 3f - add BYTE PTR [rdi], bh
00 2f - add BYTE PTR [rdi], ch
00 37 - add BYTE PTR [rdi], dh
48 01 06 - add QWORD PTR [rsi], rax
48 01 1e - add QWORD PTR [rsi], rbx
48 01 0e - add QWORD PTR [rsi], rcx
48 01 16 - add QWORD PTR [rsi], rdx
48 01 3e - add QWORD PTR [rsi], rdi
48 01 36 - add QWORD PTR [rsi], rsi
48 01 26 - add QWORD PTR [rsi], rsp
48 01 2e - add QWORD PTR [rsi], rbp
4c 01 06 - add QWORD PTR [rsi], r8
4c 01 0e - add QWORD PTR [rsi], r9
4c 01 16 - add QWORD PTR [rsi], r10
4c 01 1e - add QWORD PTR [rsi], r11
4c 01 26 - add QWORD PTR [rsi], r12
4c 01 2e - add QWORD PTR [rsi], r13
4c 01 36 - add QWORD PTR [rsi], r14
4c 01 3e - add QWORD PTR [rsi], r15
01 06 - add DWORD PTR [rsi], eax
01 1e - add DWORD PTR [rsi], ebx
01 0e - add DWORD PTR [rsi], ecx
01 16 - add DWORD PTR [rsi], edx
01 3e - add DWORD PTR [rsi], edi
01 36 - add DWORD PTR [rsi], esi
01 26 - add DWORD PTR [rsi], esp
01 2e - add DWORD PTR [rsi], ebp
66 01 06 - add WORD PTR [rsi], ax
66 01 1e - add WORD PTR [rsi], bx
66 01 0e - add WORD PTR [rsi], cx
66 01 16 - add WORD PTR [rsi], dx
66 01 26 - add WORD PTR [rsi], sp
66 01 2e - add WORD PTR [rsi], bp
00 45 00 - add BYTE PTR [rbp+0x0], al
00 5d 00 - add BYTE PTR [rbp+0x0], bl
00 4d 00 - add BYTE PTR [rbp+0x0], cl
00 55 00 - add BYTE PTR [rbp+0x0], dl
00 65 00 - add BYTE PTR [rbp+0x0], ah
00 7d 00 - add BYTE PTR [rbp+0x0], bh
00 6d 00 - add BYTE PTR [rbp+0x0], ch
00 75 00 - add BYTE PTR [rbp+0x0], dh
41 00 01 - add BYTE PTR [r9], al
41 00 19 - add BYTE PTR [r9], bl
41 00 09 - add BYTE PTR [r9], cl
41 00 11 - add BYTE PTR [r9], dl
41 00 39 - add BYTE PTR [r9], dil
41 00 31 - add BYTE PTR [r9], sil
41 00 03 - add BYTE PTR [r11], al
41 00 1b - add BYTE PTR [r11], bl
41 00 0b - add BYTE PTR [r11], cl
41 00 13 - add BYTE PTR [r11], dl
41 00 3b - add BYTE PTR [r11], dil
41 00 33 - add BYTE PTR [r11], sil
41 00 45 00 - add BYTE PTR [r13+0x0], al
41 00 5d 00 - add BYTE PTR [r13+0x0], bl
41 00 4d 00 - add BYTE PTR [r13+0x0], cl
41 00 55 00 - add BYTE PTR [r13+0x0], dl
41 00 7d 00 - add BYTE PTR [r13+0x0], dil
41 00 75 00 - add BYTE PTR [r13+0x0], sil
41 00 07 - add BYTE PTR [r15], al
41 00 1f - add BYTE PTR [r15], bl
41 00 0f - add BYTE PTR [r15], cl
41 00 17 - add BYTE PTR [r15], dl
41 00 3f - add BYTE PTR [r15], dil
41 00 37 - add BYTE PTR [r15], sil
48 03 00 - add rax, QWORD PTR [rax]
48 03 18 - add rbx, QWORD PTR [rax]
48 03 08 - add rcx, QWORD PTR [rax]
48 03 10 - add rdx, QWORD PTR [rax]
48 03 38 - add rdi, QWORD PTR [rax]
48 03 30 - add rsi, QWORD PTR [rax]
48 03 20 - add rsp, QWORD PTR [rax]
48 03 28 - add rbp, QWORD PTR [rax]
4c 03 00 - add r8, QWORD PTR [rax]
4c 03 08 - add r9, QWORD PTR [rax]
4c 03 10 - add r10, QWORD PTR [rax]
4c 03 18 - add r11, QWORD PTR [rax]
4c 03 20 - add r12, QWORD PTR [rax]
4c 03 28 - add r13, QWORD PTR [rax]
4c 03 30 - add r14, QWORD PTR [rax]
4c 03 38 - add r15, QWORD PTR [rax]
03 00 - add eax, DWORD PTR [rax]
03 18 - add ebx, DWORD PTR [rax]
03 08 - add ecx, DWORD PTR [rax]
03 10 - add edx, DWORD PTR [rax]
03 38 - add edi, DWORD PTR [rax]
03 30 - add esi, DWORD PTR [rax]
03 20 - add esp, DWORD PTR [rax]
03 28 - add ebp, DWORD PTR [rax]
66 03 00 - add ax, WORD PTR [rax]
66 03 18 - add bx, WORD PTR [rax]
66 03 08 - add cx, WORD PTR [rax]
66 03 10 - add dx, WORD PTR [rax]
66 03 20 - add sp, WORD PTR [rax]
66 03 28 - add bp, WORD PTR [rax]
02 03 - add al, BYTE PTR [rbx]
02 1b - add bl, BYTE PTR [rbx]
02 0b - add cl, BYTE PTR [rbx]
02 13 - add dl, BYTE PTR [rbx]
02 23 - add ah, BYTE PTR [rbx]
02 3b - add bh, BYTE PTR [rbx]
02 2b - add ch, BYTE PTR [rbx]
02 33 - add dh, BYTE PTR [rbx]
02 01 - add al, BYTE PTR [rcx]
02 19 - add bl, BYTE PTR [rcx]
02 09 - add cl, BYTE PTR [rcx]
02 11 - add dl, BYTE PTR [rcx]
02 21 - add ah, BYTE PTR [rcx]
02 39 - add bh, BYTE PTR [rcx]
02 29 - add ch, BYTE PTR [rcx]
02 31 - add dh, BYTE PTR [rcx]
48 03 02 - add rax, QWORD PTR [rdx]
48 03 1a - add rbx, QWORD PTR [rdx]
48 03 0a - add rcx, QWORD PTR [rdx]
48 03 12 - add rdx, QWORD PTR [rdx]
48 03 3a - add rdi, QWORD PTR [rdx]
48 03 32 - add rsi, QWORD PTR [rdx]
48 03 22 - add rsp, QWORD PTR [rdx]
48 03 2a - add rbp, QWORD PTR [rdx]
4c 03 02 - add r8, QWORD PTR [rdx]
4c 03 0a - add r9, QWORD PTR [rdx]
4c 03 12 - add r10, QWORD PTR [rdx]
4c 03 1a - add r11, QWORD PTR [rdx]
4c 03 22 - add r12, QWORD PTR [rdx]
4c 03 2a - add r13, QWORD PTR [rdx]
4c 03 32 - add r14, QWORD PTR [rdx]
4c 03 3a - add r15, QWORD PTR [rdx]
03 02 - add eax, DWORD PTR [rdx]
03 1a - add ebx, DWORD PTR [rdx]
03 0a - add ecx, DWORD PTR [rdx]
03 12 - add edx, DWORD PTR [rdx]
03 3a - add edi, DWORD PTR [rdx]
03 32 - add esi, DWORD PTR [rdx]
03 22 - add esp, DWORD PTR [rdx]
03 2a - add ebp, DWORD PTR [rdx]
66 03 02 - add ax, WORD PTR [rdx]
66 03 1a - add bx, WORD PTR [rdx]
66 03 0a - add cx, WORD PTR [rdx]
66 03 12 - add dx, WORD PTR [rdx]
66 03 22 - add sp, WORD PTR [rdx]
66 03 2a - add bp, WORD PTR [rdx]
02 07 - add al, BYTE PTR [rdi]
02 1f - add bl, BYTE PTR [rdi]
02 0f - add cl, BYTE PTR [rdi]
02 17 - add dl, BYTE PTR [rdi]
02 27 - add ah, BYTE PTR [rdi]
02 3f - add bh, BYTE PTR [rdi]
02 2f - add ch, BYTE PTR [rdi]
02 37 - add dh, BYTE PTR [rdi]
48 03 06 - add rax, QWORD PTR [rsi]
48 03 1e - add rbx, QWORD PTR [rsi]
48 03 0e - add rcx, QWORD PTR [rsi]
48 03 16 - add rdx, QWORD PTR [rsi]
48 03 3e - add rdi, QWORD PTR [rsi]
48 03 36 - add rsi, QWORD PTR [rsi]
48 03 26 - add rsp, QWORD PTR [rsi]
48 03 2e - add rbp, QWORD PTR [rsi]
4c 03 06 - add r8, QWORD PTR [rsi]
4c 03 0e - add r9, QWORD PTR [rsi]
4c 03 16 - add r10, QWORD PTR [rsi]
4c 03 1e - add r11, QWORD PTR [rsi]
4c 03 26 - add r12, QWORD PTR [rsi]
4c 03 2e - add r13, QWORD PTR [rsi]
4c 03 36 - add r14, QWORD PTR [rsi]
4c 03 3e - add r15, QWORD PTR [rsi]
03 06 - add eax, DWORD PTR [rsi]
03 1e - add ebx, DWORD PTR [rsi]
03 0e - add ecx, DWORD PTR [rsi]
03 16 - add edx, DWORD PTR [rsi]
03 3e - add edi, DWORD PTR [rsi]
03 36 - add esi, DWORD PTR [rsi]
03 26 - add esp, DWORD PTR [rsi]
03 2e - add ebp, DWORD PTR [rsi]
66 03 06 - add ax, WORD PTR [rsi]
66 03 1e - add bx, WORD PTR [rsi]
66 03 0e - add cx, WORD PTR [rsi]
66 03 16 - add dx, WORD PTR [rsi]
66 03 26 - add sp, WORD PTR [rsi]
66 03 2e - add bp, WORD PTR [rsi]
02 45 00 - add al, BYTE PTR [rbp+0x0]
02 5d 00 - add bl, BYTE PTR [rbp+0x0]
02 4d 00 - add cl, BYTE PTR [rbp+0x0]
02 55 00 - add dl, BYTE PTR [rbp+0x0]
02 65 00 - add ah, BYTE PTR [rbp+0x0]
02 7d 00 - add bh, BYTE PTR [rbp+0x0]
02 6d 00 - add ch, BYTE PTR [rbp+0x0]
02 75 00 - add dh, BYTE PTR [rbp+0x0]
41 02 01 - add al, BYTE PTR [r9]
41 02 19 - add bl, BYTE PTR [r9]
41 02 09 - add cl, BYTE PTR [r9]
41 02 11 - add dl, BYTE PTR [r9]
41 02 39 - add dil, BYTE PTR [r9]
41 02 31 - add sil, BYTE PTR [r9]
41 02 03 - add al, BYTE PTR [r11]
41 02 1b - add bl, BYTE PTR [r11]
41 02 0b - add cl, BYTE PTR [r11]
41 02 13 - add dl, BYTE PTR [r11]
41 02 3b - add dil, BYTE PTR [r11]
41 02 33 - add sil, BYTE PTR [r11]
41 02 45 00 - add al, BYTE PTR [r13+0x0]
41 02 5d 00 - add bl, BYTE PTR [r13+0x0]
41 02 4d 00 - add cl, BYTE PTR [r13+0x0]
41 02 55 00 - add dl, BYTE PTR [r13+0x0]
41 02 7d 00 - add dil, BYTE PTR [r13+0x0]
41 02 75 00 - add sil, BYTE PTR [r13+0x0]
41 02 07 - add al, BYTE PTR [r15]
41 02 1f - add bl, BYTE PTR [r15]
41 02 0f - add cl, BYTE PTR [r15]
41 02 17 - add dl, BYTE PTR [r15]
41 02 3f - add dil, BYTE PTR [r15]
41 02 37 - add sil, BYTE PTR [r15]




48 29 c0 - sub rax, rax
48 29 d8 - sub rax, rbx
48 29 c8 - sub rax, rcx
48 29 d0 - sub rax, rdx
48 29 f8 - sub rax, rdi
48 29 f0 - sub rax, rsi
48 29 e0 - sub rax, rsp
48 29 e8 - sub rax, rbp
4c 29 c0 - sub rax, r8
4c 29 c8 - sub rax, r9
4c 29 d0 - sub rax, r10
4c 29 d8 - sub rax, r11
4c 29 e0 - sub rax, r12
4c 29 e8 - sub rax, r13
4c 29 f0 - sub rax, r14
4c 29 f8 - sub rax, r15
48 29 c2 - sub rdx, rax
48 29 da - sub rdx, rbx
48 29 ca - sub rdx, rcx
48 29 d2 - sub rdx, rdx
48 29 fa - sub rdx, rdi
48 29 f2 - sub rdx, rsi
48 29 e2 - sub rdx, rsp
48 29 ea - sub rdx, rbp
4c 29 c2 - sub rdx, r8
4c 29 ca - sub rdx, r9
4c 29 d2 - sub rdx, r10
4c 29 da - sub rdx, r11
4c 29 e2 - sub rdx, r12
4c 29 ea - sub rdx, r13
4c 29 f2 - sub rdx, r14
4c 29 fa - sub rdx, r15
48 29 c6 - sub rsi, rax
48 29 de - sub rsi, rbx
48 29 ce - sub rsi, rcx
48 29 d6 - sub rsi, rdx
48 29 fe - sub rsi, rdi
48 29 f6 - sub rsi, rsi
48 29 e6 - sub rsi, rsp
48 29 ee - sub rsi, rbp
4c 29 c6 - sub rsi, r8
4c 29 ce - sub rsi, r9
4c 29 d6 - sub rsi, r10
4c 29 de - sub rsi, r11
4c 29 e6 - sub rsi, r12
4c 29 ee - sub rsi, r13
4c 29 f6 - sub rsi, r14
4c 29 fe - sub rsi, r15
48 29 c4 - sub rsp, rax
48 29 dc - sub rsp, rbx
48 29 cc - sub rsp, rcx
48 29 d4 - sub rsp, rdx
48 29 fc - sub rsp, rdi
48 29 f4 - sub rsp, rsi
48 29 e4 - sub rsp, rsp
48 29 ec - sub rsp, rbp
4c 29 c4 - sub rsp, r8
4c 29 cc - sub rsp, r9
4c 29 d4 - sub rsp, r10
4c 29 dc - sub rsp, r11
4c 29 e4 - sub rsp, r12
4c 29 ec - sub rsp, r13
4c 29 f4 - sub rsp, r14
4c 29 fc - sub rsp, r15
29 c0 - sub eax, eax
29 d8 - sub eax, ebx
29 c8 - sub eax, ecx
29 d0 - sub eax, edx
29 f8 - sub eax, edi
29 f0 - sub eax, esi
29 e0 - sub eax, esp
29 e8 - sub eax, ebp
29 c2 - sub edx, eax
29 da - sub edx, ebx
29 ca - sub edx, ecx
29 d2 - sub edx, edx
29 fa - sub edx, edi
29 f2 - sub edx, esi
29 e2 - sub edx, esp
29 ea - sub edx, ebp
29 c6 - sub esi, eax
29 de - sub esi, ebx
29 ce - sub esi, ecx
29 d6 - sub esi, edx
29 fe - sub esi, edi
29 f6 - sub esi, esi
29 e6 - sub esi, esp
29 ee - sub esi, ebp
29 c4 - sub esp, eax
29 dc - sub esp, ebx
29 cc - sub esp, ecx
29 d4 - sub esp, edx
29 fc - sub esp, edi
29 f4 - sub esp, esi
29 e4 - sub esp, esp
29 ec - sub esp, ebp
66 29 c0 - sub ax, ax
66 29 d8 - sub ax, bx
66 29 c8 - sub ax, cx
66 29 d0 - sub ax, dx
66 29 e0 - sub ax, sp
66 29 e8 - sub ax, bp
66 29 c2 - sub dx, ax
66 29 da - sub dx, bx
66 29 ca - sub dx, cx
66 29 d2 - sub dx, dx
66 29 e2 - sub dx, sp
66 29 ea - sub dx, bp
66 29 c4 - sub sp, ax
66 29 dc - sub sp, bx
66 29 cc - sub sp, cx
66 29 d4 - sub sp, dx
66 29 e4 - sub sp, sp
66 29 ec - sub sp, bp
28 c3 - sub bl, al
28 db - sub bl, bl
28 cb - sub bl, cl
28 d3 - sub bl, dl
28 e3 - sub bl, ah
28 fb - sub bl, bh
28 eb - sub bl, ch
28 f3 - sub bl, dh
28 c1 - sub cl, al
28 d9 - sub cl, bl
28 c9 - sub cl, cl
28 d1 - sub cl, dl
28 e1 - sub cl, ah
28 f9 - sub cl, bh
28 e9 - sub cl, ch
28 f1 - sub cl, dh
28 c7 - sub bh, al
28 df - sub bh, bl
28 cf - sub bh, cl
28 d7 - sub bh, dl
28 e7 - sub bh, ah
28 ff - sub bh, bh
28 ef - sub bh, ch
28 f7 - sub bh, dh
28 c5 - sub ch, al
28 dd - sub ch, bl
28 cd - sub ch, cl
28 d5 - sub ch, dl
28 e5 - sub ch, ah
28 fd - sub ch, bh
28 ed - sub ch, ch
28 f5 - sub ch, dh
80 eb 7e - sub bl, 0x7e
80 e9 7e - sub cl, 0x7e
80 ef 7e - sub bh, 0x7e
80 ed 7e - sub ch, 0x7e
48 83 e8 7f - sub rax, 0x7f
48 83 ea 7f - sub rdx, 0x7f
48 83 ee 7f - sub rsi, 0x7f
48 83 ec 7f - sub rsp, 0x7f
83 e8 7f - sub eax, 0x7f
83 ea 7f - sub edx, 0x7f
83 ee 7f - sub esi, 0x7f
83 ec 7f - sub esp, 0x7f
66 83 e8 7f - sub ax, 0x7f
66 83 ea 7f - sub dx, 0x7f
66 83 ec 7f - sub sp, 0x7f
2c 7f - sub al, 0x7f
48 29 00 - sub QWORD PTR [rax], rax
48 29 18 - sub QWORD PTR [rax], rbx
48 29 08 - sub QWORD PTR [rax], rcx
48 29 10 - sub QWORD PTR [rax], rdx
48 29 38 - sub QWORD PTR [rax], rdi
48 29 30 - sub QWORD PTR [rax], rsi
48 29 20 - sub QWORD PTR [rax], rsp
48 29 28 - sub QWORD PTR [rax], rbp
4c 29 00 - sub QWORD PTR [rax], r8
4c 29 08 - sub QWORD PTR [rax], r9
4c 29 10 - sub QWORD PTR [rax], r10
4c 29 18 - sub QWORD PTR [rax], r11
4c 29 20 - sub QWORD PTR [rax], r12
4c 29 28 - sub QWORD PTR [rax], r13
4c 29 30 - sub QWORD PTR [rax], r14
4c 29 38 - sub QWORD PTR [rax], r15
29 00 - sub DWORD PTR [rax], eax
29 18 - sub DWORD PTR [rax], ebx
29 08 - sub DWORD PTR [rax], ecx
29 10 - sub DWORD PTR [rax], edx
29 38 - sub DWORD PTR [rax], edi
29 30 - sub DWORD PTR [rax], esi
29 20 - sub DWORD PTR [rax], esp
29 28 - sub DWORD PTR [rax], ebp
66 29 00 - sub WORD PTR [rax], ax
66 29 18 - sub WORD PTR [rax], bx
66 29 08 - sub WORD PTR [rax], cx
66 29 10 - sub WORD PTR [rax], dx
66 29 20 - sub WORD PTR [rax], sp
66 29 28 - sub WORD PTR [rax], bp
28 03 - sub BYTE PTR [rbx], al
28 1b - sub BYTE PTR [rbx], bl
28 0b - sub BYTE PTR [rbx], cl
28 13 - sub BYTE PTR [rbx], dl
28 23 - sub BYTE PTR [rbx], ah
28 3b - sub BYTE PTR [rbx], bh
28 2b - sub BYTE PTR [rbx], ch
28 33 - sub BYTE PTR [rbx], dh
28 01 - sub BYTE PTR [rcx], al
28 19 - sub BYTE PTR [rcx], bl
28 09 - sub BYTE PTR [rcx], cl
28 11 - sub BYTE PTR [rcx], dl
28 21 - sub BYTE PTR [rcx], ah
28 39 - sub BYTE PTR [rcx], bh
28 29 - sub BYTE PTR [rcx], ch
28 31 - sub BYTE PTR [rcx], dh
48 29 02 - sub QWORD PTR [rdx], rax
48 29 1a - sub QWORD PTR [rdx], rbx
48 29 0a - sub QWORD PTR [rdx], rcx
48 29 12 - sub QWORD PTR [rdx], rdx
48 29 3a - sub QWORD PTR [rdx], rdi
48 29 32 - sub QWORD PTR [rdx], rsi
48 29 22 - sub QWORD PTR [rdx], rsp
48 29 2a - sub QWORD PTR [rdx], rbp
4c 29 02 - sub QWORD PTR [rdx], r8
4c 29 0a - sub QWORD PTR [rdx], r9
4c 29 12 - sub QWORD PTR [rdx], r10
4c 29 1a - sub QWORD PTR [rdx], r11
4c 29 22 - sub QWORD PTR [rdx], r12
4c 29 2a - sub QWORD PTR [rdx], r13
4c 29 32 - sub QWORD PTR [rdx], r14
4c 29 3a - sub QWORD PTR [rdx], r15
29 02 - sub DWORD PTR [rdx], eax
29 1a - sub DWORD PTR [rdx], ebx
29 0a - sub DWORD PTR [rdx], ecx
29 12 - sub DWORD PTR [rdx], edx
29 3a - sub DWORD PTR [rdx], edi
29 32 - sub DWORD PTR [rdx], esi
29 22 - sub DWORD PTR [rdx], esp
29 2a - sub DWORD PTR [rdx], ebp
66 29 02 - sub WORD PTR [rdx], ax
66 29 1a - sub WORD PTR [rdx], bx
66 29 0a - sub WORD PTR [rdx], cx
66 29 12 - sub WORD PTR [rdx], dx
66 29 22 - sub WORD PTR [rdx], sp
66 29 2a - sub WORD PTR [rdx], bp
28 07 - sub BYTE PTR [rdi], al
28 1f - sub BYTE PTR [rdi], bl
28 0f - sub BYTE PTR [rdi], cl
28 17 - sub BYTE PTR [rdi], dl
28 27 - sub BYTE PTR [rdi], ah
28 3f - sub BYTE PTR [rdi], bh
28 2f - sub BYTE PTR [rdi], ch
28 37 - sub BYTE PTR [rdi], dh
48 29 06 - sub QWORD PTR [rsi], rax
48 29 1e - sub QWORD PTR [rsi], rbx
48 29 0e - sub QWORD PTR [rsi], rcx
48 29 16 - sub QWORD PTR [rsi], rdx
48 29 3e - sub QWORD PTR [rsi], rdi
48 29 36 - sub QWORD PTR [rsi], rsi
48 29 26 - sub QWORD PTR [rsi], rsp
48 29 2e - sub QWORD PTR [rsi], rbp
4c 29 06 - sub QWORD PTR [rsi], r8
4c 29 0e - sub QWORD PTR [rsi], r9
4c 29 16 - sub QWORD PTR [rsi], r10
4c 29 1e - sub QWORD PTR [rsi], r11
4c 29 26 - sub QWORD PTR [rsi], r12
4c 29 2e - sub QWORD PTR [rsi], r13
4c 29 36 - sub QWORD PTR [rsi], r14
4c 29 3e - sub QWORD PTR [rsi], r15
29 06 - sub DWORD PTR [rsi], eax
29 1e - sub DWORD PTR [rsi], ebx
29 0e - sub DWORD PTR [rsi], ecx
29 16 - sub DWORD PTR [rsi], edx
29 3e - sub DWORD PTR [rsi], edi
29 36 - sub DWORD PTR [rsi], esi
29 26 - sub DWORD PTR [rsi], esp
29 2e - sub DWORD PTR [rsi], ebp
66 29 06 - sub WORD PTR [rsi], ax
66 29 1e - sub WORD PTR [rsi], bx
66 29 0e - sub WORD PTR [rsi], cx
66 29 16 - sub WORD PTR [rsi], dx
66 29 26 - sub WORD PTR [rsi], sp
66 29 2e - sub WORD PTR [rsi], bp
28 45 00 - sub BYTE PTR [rbp+0x0], al
28 5d 00 - sub BYTE PTR [rbp+0x0], bl
28 4d 00 - sub BYTE PTR [rbp+0x0], cl
28 55 00 - sub BYTE PTR [rbp+0x0], dl
28 65 00 - sub BYTE PTR [rbp+0x0], ah
28 7d 00 - sub BYTE PTR [rbp+0x0], bh
28 6d 00 - sub BYTE PTR [rbp+0x0], ch
28 75 00 - sub BYTE PTR [rbp+0x0], dh
41 28 01 - sub BYTE PTR [r9], al
41 28 19 - sub BYTE PTR [r9], bl
41 28 09 - sub BYTE PTR [r9], cl
41 28 11 - sub BYTE PTR [r9], dl
41 28 39 - sub BYTE PTR [r9], dil
41 28 31 - sub BYTE PTR [r9], sil
41 28 03 - sub BYTE PTR [r11], al
41 28 1b - sub BYTE PTR [r11], bl
41 28 0b - sub BYTE PTR [r11], cl
41 28 13 - sub BYTE PTR [r11], dl
41 28 3b - sub BYTE PTR [r11], dil
41 28 33 - sub BYTE PTR [r11], sil
41 28 45 00 - sub BYTE PTR [r13+0x0], al
41 28 5d 00 - sub BYTE PTR [r13+0x0], bl
41 28 4d 00 - sub BYTE PTR [r13+0x0], cl
41 28 55 00 - sub BYTE PTR [r13+0x0], dl
41 28 7d 00 - sub BYTE PTR [r13+0x0], dil
41 28 75 00 - sub BYTE PTR [r13+0x0], sil
41 28 07 - sub BYTE PTR [r15], al
41 28 1f - sub BYTE PTR [r15], bl
41 28 0f - sub BYTE PTR [r15], cl
41 28 17 - sub BYTE PTR [r15], dl
41 28 3f - sub BYTE PTR [r15], dil
41 28 37 - sub BYTE PTR [r15], sil
48 2b 00 - sub rax, QWORD PTR [rax]
48 2b 18 - sub rbx, QWORD PTR [rax]
48 2b 08 - sub rcx, QWORD PTR [rax]
48 2b 10 - sub rdx, QWORD PTR [rax]
48 2b 38 - sub rdi, QWORD PTR [rax]
48 2b 30 - sub rsi, QWORD PTR [rax]
48 2b 20 - sub rsp, QWORD PTR [rax]
48 2b 28 - sub rbp, QWORD PTR [rax]
4c 2b 00 - sub r8, QWORD PTR [rax]
4c 2b 08 - sub r9, QWORD PTR [rax]
4c 2b 10 - sub r10, QWORD PTR [rax]
4c 2b 18 - sub r11, QWORD PTR [rax]
4c 2b 20 - sub r12, QWORD PTR [rax]
4c 2b 28 - sub r13, QWORD PTR [rax]
4c 2b 30 - sub r14, QWORD PTR [rax]
4c 2b 38 - sub r15, QWORD PTR [rax]
2b 00 - sub eax, DWORD PTR [rax]
2b 18 - sub ebx, DWORD PTR [rax]
2b 08 - sub ecx, DWORD PTR [rax]
2b 10 - sub edx, DWORD PTR [rax]
2b 38 - sub edi, DWORD PTR [rax]
2b 30 - sub esi, DWORD PTR [rax]
2b 20 - sub esp, DWORD PTR [rax]
2b 28 - sub ebp, DWORD PTR [rax]
66 2b 00 - sub ax, WORD PTR [rax]
66 2b 18 - sub bx, WORD PTR [rax]
66 2b 08 - sub cx, WORD PTR [rax]
66 2b 10 - sub dx, WORD PTR [rax]
66 2b 20 - sub sp, WORD PTR [rax]
66 2b 28 - sub bp, WORD PTR [rax]
2a 03 - sub al, BYTE PTR [rbx]
2a 1b - sub bl, BYTE PTR [rbx]
2a 0b - sub cl, BYTE PTR [rbx]
2a 13 - sub dl, BYTE PTR [rbx]
2a 23 - sub ah, BYTE PTR [rbx]
2a 3b - sub bh, BYTE PTR [rbx]
2a 2b - sub ch, BYTE PTR [rbx]
2a 33 - sub dh, BYTE PTR [rbx]
2a 01 - sub al, BYTE PTR [rcx]
2a 19 - sub bl, BYTE PTR [rcx]
2a 09 - sub cl, BYTE PTR [rcx]
2a 11 - sub dl, BYTE PTR [rcx]
2a 21 - sub ah, BYTE PTR [rcx]
2a 39 - sub bh, BYTE PTR [rcx]
2a 29 - sub ch, BYTE PTR [rcx]
2a 31 - sub dh, BYTE PTR [rcx]
48 2b 02 - sub rax, QWORD PTR [rdx]
48 2b 1a - sub rbx, QWORD PTR [rdx]
48 2b 0a - sub rcx, QWORD PTR [rdx]
48 2b 12 - sub rdx, QWORD PTR [rdx]
48 2b 3a - sub rdi, QWORD PTR [rdx]
48 2b 32 - sub rsi, QWORD PTR [rdx]
48 2b 22 - sub rsp, QWORD PTR [rdx]
48 2b 2a - sub rbp, QWORD PTR [rdx]
4c 2b 02 - sub r8, QWORD PTR [rdx]
4c 2b 0a - sub r9, QWORD PTR [rdx]
4c 2b 12 - sub r10, QWORD PTR [rdx]
4c 2b 1a - sub r11, QWORD PTR [rdx]
4c 2b 22 - sub r12, QWORD PTR [rdx]
4c 2b 2a - sub r13, QWORD PTR [rdx]
4c 2b 32 - sub r14, QWORD PTR [rdx]
4c 2b 3a - sub r15, QWORD PTR [rdx]
2b 02 - sub eax, DWORD PTR [rdx]
2b 1a - sub ebx, DWORD PTR [rdx]
2b 0a - sub ecx, DWORD PTR [rdx]
2b 12 - sub edx, DWORD PTR [rdx]
2b 3a - sub edi, DWORD PTR [rdx]
2b 32 - sub esi, DWORD PTR [rdx]
2b 22 - sub esp, DWORD PTR [rdx]
2b 2a - sub ebp, DWORD PTR [rdx]
66 2b 02 - sub ax, WORD PTR [rdx]
66 2b 1a - sub bx, WORD PTR [rdx]
66 2b 0a - sub cx, WORD PTR [rdx]
66 2b 12 - sub dx, WORD PTR [rdx]
66 2b 22 - sub sp, WORD PTR [rdx]
66 2b 2a - sub bp, WORD PTR [rdx]
2a 07 - sub al, BYTE PTR [rdi]
2a 1f - sub bl, BYTE PTR [rdi]
2a 0f - sub cl, BYTE PTR [rdi]
2a 17 - sub dl, BYTE PTR [rdi]
2a 27 - sub ah, BYTE PTR [rdi]
2a 3f - sub bh, BYTE PTR [rdi]
2a 2f - sub ch, BYTE PTR [rdi]
2a 37 - sub dh, BYTE PTR [rdi]
48 2b 06 - sub rax, QWORD PTR [rsi]
48 2b 1e - sub rbx, QWORD PTR [rsi]
48 2b 0e - sub rcx, QWORD PTR [rsi]
48 2b 16 - sub rdx, QWORD PTR [rsi]
48 2b 3e - sub rdi, QWORD PTR [rsi]
48 2b 36 - sub rsi, QWORD PTR [rsi]
48 2b 26 - sub rsp, QWORD PTR [rsi]
48 2b 2e - sub rbp, QWORD PTR [rsi]
4c 2b 06 - sub r8, QWORD PTR [rsi]
4c 2b 0e - sub r9, QWORD PTR [rsi]
4c 2b 16 - sub r10, QWORD PTR [rsi]
4c 2b 1e - sub r11, QWORD PTR [rsi]
4c 2b 26 - sub r12, QWORD PTR [rsi]
4c 2b 2e - sub r13, QWORD PTR [rsi]
4c 2b 36 - sub r14, QWORD PTR [rsi]
4c 2b 3e - sub r15, QWORD PTR [rsi]
2b 06 - sub eax, DWORD PTR [rsi]
2b 1e - sub ebx, DWORD PTR [rsi]
2b 0e - sub ecx, DWORD PTR [rsi]
2b 16 - sub edx, DWORD PTR [rsi]
2b 3e - sub edi, DWORD PTR [rsi]
2b 36 - sub esi, DWORD PTR [rsi]
2b 26 - sub esp, DWORD PTR [rsi]
2b 2e - sub ebp, DWORD PTR [rsi]
66 2b 06 - sub ax, WORD PTR [rsi]
66 2b 1e - sub bx, WORD PTR [rsi]
66 2b 0e - sub cx, WORD PTR [rsi]
66 2b 16 - sub dx, WORD PTR [rsi]
66 2b 26 - sub sp, WORD PTR [rsi]
66 2b 2e - sub bp, WORD PTR [rsi]
2a 45 00 - sub al, BYTE PTR [rbp+0x0]
2a 5d 00 - sub bl, BYTE PTR [rbp+0x0]
2a 4d 00 - sub cl, BYTE PTR [rbp+0x0]
2a 55 00 - sub dl, BYTE PTR [rbp+0x0]
2a 65 00 - sub ah, BYTE PTR [rbp+0x0]
2a 7d 00 - sub bh, BYTE PTR [rbp+0x0]
2a 6d 00 - sub ch, BYTE PTR [rbp+0x0]
2a 75 00 - sub dh, BYTE PTR [rbp+0x0]
41 2a 01 - sub al, BYTE PTR [r9]
41 2a 19 - sub bl, BYTE PTR [r9]
41 2a 09 - sub cl, BYTE PTR [r9]
41 2a 11 - sub dl, BYTE PTR [r9]
41 2a 39 - sub dil, BYTE PTR [r9]
41 2a 31 - sub sil, BYTE PTR [r9]
41 2a 03 - sub al, BYTE PTR [r11]
41 2a 1b - sub bl, BYTE PTR [r11]
41 2a 0b - sub cl, BYTE PTR [r11]
41 2a 13 - sub dl, BYTE PTR [r11]
41 2a 3b - sub dil, BYTE PTR [r11]
41 2a 33 - sub sil, BYTE PTR [r11]
41 2a 45 00 - sub al, BYTE PTR [r13+0x0]
41 2a 5d 00 - sub bl, BYTE PTR [r13+0x0]
41 2a 4d 00 - sub cl, BYTE PTR [r13+0x0]
41 2a 55 00 - sub dl, BYTE PTR [r13+0x0]
41 2a 7d 00 - sub dil, BYTE PTR [r13+0x0]
41 2a 75 00 - sub sil, BYTE PTR [r13+0x0]
41 2a 07 - sub al, BYTE PTR [r15]
41 2a 1f - sub bl, BYTE PTR [r15]
41 2a 0f - sub cl, BYTE PTR [r15]
41 2a 17 - sub dl, BYTE PTR [r15]
41 2a 3f - sub dil, BYTE PTR [r15]
41 2a 37 - sub sil, BYTE PTR [r15]




48 89 c0 - mov rax, rax
48 89 d8 - mov rax, rbx
48 89 c8 - mov rax, rcx
48 89 d0 - mov rax, rdx
48 89 f8 - mov rax, rdi
48 89 f0 - mov rax, rsi
48 89 e0 - mov rax, rsp
48 89 e8 - mov rax, rbp
4c 89 c0 - mov rax, r8
4c 89 c8 - mov rax, r9
4c 89 d0 - mov rax, r10
4c 89 d8 - mov rax, r11
4c 89 e0 - mov rax, r12
4c 89 e8 - mov rax, r13
4c 89 f0 - mov rax, r14
4c 89 f8 - mov rax, r15
48 89 c2 - mov rdx, rax
48 89 da - mov rdx, rbx
48 89 ca - mov rdx, rcx
48 89 d2 - mov rdx, rdx
48 89 fa - mov rdx, rdi
48 89 f2 - mov rdx, rsi
48 89 e2 - mov rdx, rsp
48 89 ea - mov rdx, rbp
4c 89 c2 - mov rdx, r8
4c 89 ca - mov rdx, r9
4c 89 d2 - mov rdx, r10
4c 89 da - mov rdx, r11
4c 89 e2 - mov rdx, r12
4c 89 ea - mov rdx, r13
4c 89 f2 - mov rdx, r14
4c 89 fa - mov rdx, r15
48 89 c6 - mov rsi, rax
48 89 de - mov rsi, rbx
48 89 ce - mov rsi, rcx
48 89 d6 - mov rsi, rdx
48 89 fe - mov rsi, rdi
48 89 f6 - mov rsi, rsi
48 89 e6 - mov rsi, rsp
48 89 ee - mov rsi, rbp
4c 89 c6 - mov rsi, r8
4c 89 ce - mov rsi, r9
4c 89 d6 - mov rsi, r10
4c 89 de - mov rsi, r11
4c 89 e6 - mov rsi, r12
4c 89 ee - mov rsi, r13
4c 89 f6 - mov rsi, r14
4c 89 fe - mov rsi, r15
48 89 c4 - mov rsp, rax
48 89 dc - mov rsp, rbx
48 89 cc - mov rsp, rcx
48 89 d4 - mov rsp, rdx
48 89 fc - mov rsp, rdi
48 89 f4 - mov rsp, rsi
48 89 e4 - mov rsp, rsp
48 89 ec - mov rsp, rbp
4c 89 c4 - mov rsp, r8
4c 89 cc - mov rsp, r9
4c 89 d4 - mov rsp, r10
4c 89 dc - mov rsp, r11
4c 89 e4 - mov rsp, r12
4c 89 ec - mov rsp, r13
4c 89 f4 - mov rsp, r14
4c 89 fc - mov rsp, r15
89 c0 - mov eax, eax
89 d8 - mov eax, ebx
89 c8 - mov eax, ecx
89 d0 - mov eax, edx
89 f8 - mov eax, edi
89 f0 - mov eax, esi
89 e0 - mov eax, esp
89 e8 - mov eax, ebp
89 c2 - mov edx, eax
89 da - mov edx, ebx
89 ca - mov edx, ecx
89 d2 - mov edx, edx
89 fa - mov edx, edi
89 f2 - mov edx, esi
89 e2 - mov edx, esp
89 ea - mov edx, ebp
89 c6 - mov esi, eax
89 de - mov esi, ebx
89 ce - mov esi, ecx
89 d6 - mov esi, edx
89 fe - mov esi, edi
89 f6 - mov esi, esi
89 e6 - mov esi, esp
89 ee - mov esi, ebp
89 c4 - mov esp, eax
89 dc - mov esp, ebx
89 cc - mov esp, ecx
89 d4 - mov esp, edx
89 fc - mov esp, edi
89 f4 - mov esp, esi
89 e4 - mov esp, esp
89 ec - mov esp, ebp
66 89 c0 - mov ax, ax
66 89 d8 - mov ax, bx
66 89 c8 - mov ax, cx
66 89 d0 - mov ax, dx
66 89 e0 - mov ax, sp
66 89 e8 - mov ax, bp
66 89 c2 - mov dx, ax
66 89 da - mov dx, bx
66 89 ca - mov dx, cx
66 89 d2 - mov dx, dx
66 89 e2 - mov dx, sp
66 89 ea - mov dx, bp
66 89 c4 - mov sp, ax
66 89 dc - mov sp, bx
66 89 cc - mov sp, cx
66 89 d4 - mov sp, dx
66 89 e4 - mov sp, sp
66 89 ec - mov sp, bp
88 c3 - mov bl, al
88 db - mov bl, bl
88 cb - mov bl, cl
88 d3 - mov bl, dl
88 e3 - mov bl, ah
88 fb - mov bl, bh
88 eb - mov bl, ch
88 f3 - mov bl, dh
88 c1 - mov cl, al
88 d9 - mov cl, bl
88 c9 - mov cl, cl
88 d1 - mov cl, dl
88 e1 - mov cl, ah
88 f9 - mov cl, bh
88 e9 - mov cl, ch
88 f1 - mov cl, dh
88 c7 - mov bh, al
88 df - mov bh, bl
88 cf - mov bh, cl
88 d7 - mov bh, dl
88 e7 - mov bh, ah
88 ff - mov bh, bh
88 ef - mov bh, ch
88 f7 - mov bh, dh
88 c5 - mov ch, al
88 dd - mov ch, bl
88 cd - mov ch, cl
88 d5 - mov ch, dl
88 e5 - mov ch, ah
88 fd - mov ch, bh
88 ed - mov ch, ch
88 f5 - mov ch, dh
b3 7e - mov bl, 0x7e
b1 7e - mov cl, 0x7e
b7 7e - mov bh, 0x7e
b5 7e - mov ch, 0x7e
40 b7 7e - mov dil, 0x7e
b0 7f - mov al, 0x7f
b2 7f - mov dl, 0x7f
b4 7f - mov ah, 0x7f
b6 7f - mov dh, 0x7f
48 89 00 - mov QWORD PTR [rax], rax
48 89 18 - mov QWORD PTR [rax], rbx
48 89 08 - mov QWORD PTR [rax], rcx
48 89 10 - mov QWORD PTR [rax], rdx
48 89 38 - mov QWORD PTR [rax], rdi
48 89 30 - mov QWORD PTR [rax], rsi
48 89 20 - mov QWORD PTR [rax], rsp
48 89 28 - mov QWORD PTR [rax], rbp
4c 89 00 - mov QWORD PTR [rax], r8
4c 89 08 - mov QWORD PTR [rax], r9
4c 89 10 - mov QWORD PTR [rax], r10
4c 89 18 - mov QWORD PTR [rax], r11
4c 89 20 - mov QWORD PTR [rax], r12
4c 89 28 - mov QWORD PTR [rax], r13
4c 89 30 - mov QWORD PTR [rax], r14
4c 89 38 - mov QWORD PTR [rax], r15
89 00 - mov DWORD PTR [rax], eax
89 18 - mov DWORD PTR [rax], ebx
89 08 - mov DWORD PTR [rax], ecx
89 10 - mov DWORD PTR [rax], edx
89 38 - mov DWORD PTR [rax], edi
89 30 - mov DWORD PTR [rax], esi
89 20 - mov DWORD PTR [rax], esp
89 28 - mov DWORD PTR [rax], ebp
66 89 00 - mov WORD PTR [rax], ax
66 89 18 - mov WORD PTR [rax], bx
66 89 08 - mov WORD PTR [rax], cx
66 89 10 - mov WORD PTR [rax], dx
66 89 20 - mov WORD PTR [rax], sp
66 89 28 - mov WORD PTR [rax], bp
88 03 - mov BYTE PTR [rbx], al
88 1b - mov BYTE PTR [rbx], bl
88 0b - mov BYTE PTR [rbx], cl
88 13 - mov BYTE PTR [rbx], dl
88 23 - mov BYTE PTR [rbx], ah
88 3b - mov BYTE PTR [rbx], bh
88 2b - mov BYTE PTR [rbx], ch
88 33 - mov BYTE PTR [rbx], dh
88 01 - mov BYTE PTR [rcx], al
88 19 - mov BYTE PTR [rcx], bl
88 09 - mov BYTE PTR [rcx], cl
88 11 - mov BYTE PTR [rcx], dl
88 21 - mov BYTE PTR [rcx], ah
88 39 - mov BYTE PTR [rcx], bh
88 29 - mov BYTE PTR [rcx], ch
88 31 - mov BYTE PTR [rcx], dh
48 89 02 - mov QWORD PTR [rdx], rax
48 89 1a - mov QWORD PTR [rdx], rbx
48 89 0a - mov QWORD PTR [rdx], rcx
48 89 12 - mov QWORD PTR [rdx], rdx
48 89 3a - mov QWORD PTR [rdx], rdi
48 89 32 - mov QWORD PTR [rdx], rsi
48 89 22 - mov QWORD PTR [rdx], rsp
48 89 2a - mov QWORD PTR [rdx], rbp
4c 89 02 - mov QWORD PTR [rdx], r8
4c 89 0a - mov QWORD PTR [rdx], r9
4c 89 12 - mov QWORD PTR [rdx], r10
4c 89 1a - mov QWORD PTR [rdx], r11
4c 89 22 - mov QWORD PTR [rdx], r12
4c 89 2a - mov QWORD PTR [rdx], r13
4c 89 32 - mov QWORD PTR [rdx], r14
4c 89 3a - mov QWORD PTR [rdx], r15
89 02 - mov DWORD PTR [rdx], eax
89 1a - mov DWORD PTR [rdx], ebx
89 0a - mov DWORD PTR [rdx], ecx
89 12 - mov DWORD PTR [rdx], edx
89 3a - mov DWORD PTR [rdx], edi
89 32 - mov DWORD PTR [rdx], esi
89 22 - mov DWORD PTR [rdx], esp
89 2a - mov DWORD PTR [rdx], ebp
66 89 02 - mov WORD PTR [rdx], ax
66 89 1a - mov WORD PTR [rdx], bx
66 89 0a - mov WORD PTR [rdx], cx
66 89 12 - mov WORD PTR [rdx], dx
66 89 22 - mov WORD PTR [rdx], sp
66 89 2a - mov WORD PTR [rdx], bp
88 07 - mov BYTE PTR [rdi], al
88 1f - mov BYTE PTR [rdi], bl
88 0f - mov BYTE PTR [rdi], cl
88 17 - mov BYTE PTR [rdi], dl
88 27 - mov BYTE PTR [rdi], ah
88 3f - mov BYTE PTR [rdi], bh
88 2f - mov BYTE PTR [rdi], ch
88 37 - mov BYTE PTR [rdi], dh
48 89 06 - mov QWORD PTR [rsi], rax
48 89 1e - mov QWORD PTR [rsi], rbx
48 89 0e - mov QWORD PTR [rsi], rcx
48 89 16 - mov QWORD PTR [rsi], rdx
48 89 3e - mov QWORD PTR [rsi], rdi
48 89 36 - mov QWORD PTR [rsi], rsi
48 89 26 - mov QWORD PTR [rsi], rsp
48 89 2e - mov QWORD PTR [rsi], rbp
4c 89 06 - mov QWORD PTR [rsi], r8
4c 89 0e - mov QWORD PTR [rsi], r9
4c 89 16 - mov QWORD PTR [rsi], r10
4c 89 1e - mov QWORD PTR [rsi], r11
4c 89 26 - mov QWORD PTR [rsi], r12
4c 89 2e - mov QWORD PTR [rsi], r13
4c 89 36 - mov QWORD PTR [rsi], r14
4c 89 3e - mov QWORD PTR [rsi], r15
89 06 - mov DWORD PTR [rsi], eax
89 1e - mov DWORD PTR [rsi], ebx
89 0e - mov DWORD PTR [rsi], ecx
89 16 - mov DWORD PTR [rsi], edx
89 3e - mov DWORD PTR [rsi], edi
89 36 - mov DWORD PTR [rsi], esi
89 26 - mov DWORD PTR [rsi], esp
89 2e - mov DWORD PTR [rsi], ebp
66 89 06 - mov WORD PTR [rsi], ax
66 89 1e - mov WORD PTR [rsi], bx
66 89 0e - mov WORD PTR [rsi], cx
66 89 16 - mov WORD PTR [rsi], dx
66 89 26 - mov WORD PTR [rsi], sp
66 89 2e - mov WORD PTR [rsi], bp
88 45 00 - mov BYTE PTR [rbp+0x0], al
88 5d 00 - mov BYTE PTR [rbp+0x0], bl
88 4d 00 - mov BYTE PTR [rbp+0x0], cl
88 55 00 - mov BYTE PTR [rbp+0x0], dl
88 65 00 - mov BYTE PTR [rbp+0x0], ah
88 7d 00 - mov BYTE PTR [rbp+0x0], bh
88 6d 00 - mov BYTE PTR [rbp+0x0], ch
88 75 00 - mov BYTE PTR [rbp+0x0], dh
41 88 01 - mov BYTE PTR [r9], al
41 88 19 - mov BYTE PTR [r9], bl
41 88 09 - mov BYTE PTR [r9], cl
41 88 11 - mov BYTE PTR [r9], dl
41 88 39 - mov BYTE PTR [r9], dil
41 88 31 - mov BYTE PTR [r9], sil
41 88 03 - mov BYTE PTR [r11], al
41 88 1b - mov BYTE PTR [r11], bl
41 88 0b - mov BYTE PTR [r11], cl
41 88 13 - mov BYTE PTR [r11], dl
41 88 3b - mov BYTE PTR [r11], dil
41 88 33 - mov BYTE PTR [r11], sil
41 88 45 00 - mov BYTE PTR [r13+0x0], al
41 88 5d 00 - mov BYTE PTR [r13+0x0], bl
41 88 4d 00 - mov BYTE PTR [r13+0x0], cl
41 88 55 00 - mov BYTE PTR [r13+0x0], dl
41 88 7d 00 - mov BYTE PTR [r13+0x0], dil
41 88 75 00 - mov BYTE PTR [r13+0x0], sil
41 88 07 - mov BYTE PTR [r15], al
41 88 1f - mov BYTE PTR [r15], bl
41 88 0f - mov BYTE PTR [r15], cl
41 88 17 - mov BYTE PTR [r15], dl
41 88 3f - mov BYTE PTR [r15], dil
41 88 37 - mov BYTE PTR [r15], sil
48 8b 00 - mov rax, QWORD PTR [rax]
48 8b 18 - mov rbx, QWORD PTR [rax]
48 8b 08 - mov rcx, QWORD PTR [rax]
48 8b 10 - mov rdx, QWORD PTR [rax]
48 8b 38 - mov rdi, QWORD PTR [rax]
48 8b 30 - mov rsi, QWORD PTR [rax]
48 8b 20 - mov rsp, QWORD PTR [rax]
48 8b 28 - mov rbp, QWORD PTR [rax]
4c 8b 00 - mov r8, QWORD PTR [rax]
4c 8b 08 - mov r9, QWORD PTR [rax]
4c 8b 10 - mov r10, QWORD PTR [rax]
4c 8b 18 - mov r11, QWORD PTR [rax]
4c 8b 20 - mov r12, QWORD PTR [rax]
4c 8b 28 - mov r13, QWORD PTR [rax]
4c 8b 30 - mov r14, QWORD PTR [rax]
4c 8b 38 - mov r15, QWORD PTR [rax]
8b 00 - mov eax, DWORD PTR [rax]
8b 18 - mov ebx, DWORD PTR [rax]
8b 08 - mov ecx, DWORD PTR [rax]
8b 10 - mov edx, DWORD PTR [rax]
8b 38 - mov edi, DWORD PTR [rax]
8b 30 - mov esi, DWORD PTR [rax]
8b 20 - mov esp, DWORD PTR [rax]
8b 28 - mov ebp, DWORD PTR [rax]
66 8b 00 - mov ax, WORD PTR [rax]
66 8b 18 - mov bx, WORD PTR [rax]
66 8b 08 - mov cx, WORD PTR [rax]
66 8b 10 - mov dx, WORD PTR [rax]
66 8b 20 - mov sp, WORD PTR [rax]
66 8b 28 - mov bp, WORD PTR [rax]
8a 03 - mov al, BYTE PTR [rbx]
8a 1b - mov bl, BYTE PTR [rbx]
8a 0b - mov cl, BYTE PTR [rbx]
8a 13 - mov dl, BYTE PTR [rbx]
8a 23 - mov ah, BYTE PTR [rbx]
8a 3b - mov bh, BYTE PTR [rbx]
8a 2b - mov ch, BYTE PTR [rbx]
8a 33 - mov dh, BYTE PTR [rbx]
8a 01 - mov al, BYTE PTR [rcx]
8a 19 - mov bl, BYTE PTR [rcx]
8a 09 - mov cl, BYTE PTR [rcx]
8a 11 - mov dl, BYTE PTR [rcx]
8a 21 - mov ah, BYTE PTR [rcx]
8a 39 - mov bh, BYTE PTR [rcx]
8a 29 - mov ch, BYTE PTR [rcx]
8a 31 - mov dh, BYTE PTR [rcx]
48 8b 02 - mov rax, QWORD PTR [rdx]
48 8b 1a - mov rbx, QWORD PTR [rdx]
48 8b 0a - mov rcx, QWORD PTR [rdx]
48 8b 12 - mov rdx, QWORD PTR [rdx]
48 8b 3a - mov rdi, QWORD PTR [rdx]
48 8b 32 - mov rsi, QWORD PTR [rdx]
48 8b 22 - mov rsp, QWORD PTR [rdx]
48 8b 2a - mov rbp, QWORD PTR [rdx]
4c 8b 02 - mov r8, QWORD PTR [rdx]
4c 8b 0a - mov r9, QWORD PTR [rdx]
4c 8b 12 - mov r10, QWORD PTR [rdx]
4c 8b 1a - mov r11, QWORD PTR [rdx]
4c 8b 22 - mov r12, QWORD PTR [rdx]
4c 8b 2a - mov r13, QWORD PTR [rdx]
4c 8b 32 - mov r14, QWORD PTR [rdx]
4c 8b 3a - mov r15, QWORD PTR [rdx]
8b 02 - mov eax, DWORD PTR [rdx]
8b 1a - mov ebx, DWORD PTR [rdx]
8b 0a - mov ecx, DWORD PTR [rdx]
8b 12 - mov edx, DWORD PTR [rdx]
8b 3a - mov edi, DWORD PTR [rdx]
8b 32 - mov esi, DWORD PTR [rdx]
8b 22 - mov esp, DWORD PTR [rdx]
8b 2a - mov ebp, DWORD PTR [rdx]
66 8b 02 - mov ax, WORD PTR [rdx]
66 8b 1a - mov bx, WORD PTR [rdx]
66 8b 0a - mov cx, WORD PTR [rdx]
66 8b 12 - mov dx, WORD PTR [rdx]
66 8b 22 - mov sp, WORD PTR [rdx]
66 8b 2a - mov bp, WORD PTR [rdx]
8a 07 - mov al, BYTE PTR [rdi]
8a 1f - mov bl, BYTE PTR [rdi]
8a 0f - mov cl, BYTE PTR [rdi]
8a 17 - mov dl, BYTE PTR [rdi]
8a 27 - mov ah, BYTE PTR [rdi]
8a 3f - mov bh, BYTE PTR [rdi]
8a 2f - mov ch, BYTE PTR [rdi]
8a 37 - mov dh, BYTE PTR [rdi]
48 8b 06 - mov rax, QWORD PTR [rsi]
48 8b 1e - mov rbx, QWORD PTR [rsi]
48 8b 0e - mov rcx, QWORD PTR [rsi]
48 8b 16 - mov rdx, QWORD PTR [rsi]
48 8b 3e - mov rdi, QWORD PTR [rsi]
48 8b 36 - mov rsi, QWORD PTR [rsi]
48 8b 26 - mov rsp, QWORD PTR [rsi]
48 8b 2e - mov rbp, QWORD PTR [rsi]
4c 8b 06 - mov r8, QWORD PTR [rsi]
4c 8b 0e - mov r9, QWORD PTR [rsi]
4c 8b 16 - mov r10, QWORD PTR [rsi]
4c 8b 1e - mov r11, QWORD PTR [rsi]
4c 8b 26 - mov r12, QWORD PTR [rsi]
4c 8b 2e - mov r13, QWORD PTR [rsi]
4c 8b 36 - mov r14, QWORD PTR [rsi]
4c 8b 3e - mov r15, QWORD PTR [rsi]
8b 06 - mov eax, DWORD PTR [rsi]
8b 1e - mov ebx, DWORD PTR [rsi]
8b 0e - mov ecx, DWORD PTR [rsi]
8b 16 - mov edx, DWORD PTR [rsi]
8b 3e - mov edi, DWORD PTR [rsi]
8b 36 - mov esi, DWORD PTR [rsi]
8b 26 - mov esp, DWORD PTR [rsi]
8b 2e - mov ebp, DWORD PTR [rsi]
66 8b 06 - mov ax, WORD PTR [rsi]
66 8b 1e - mov bx, WORD PTR [rsi]
66 8b 0e - mov cx, WORD PTR [rsi]
66 8b 16 - mov dx, WORD PTR [rsi]
66 8b 26 - mov sp, WORD PTR [rsi]
66 8b 2e - mov bp, WORD PTR [rsi]
8a 45 00 - mov al, BYTE PTR [rbp+0x0]
8a 5d 00 - mov bl, BYTE PTR [rbp+0x0]
8a 4d 00 - mov cl, BYTE PTR [rbp+0x0]
8a 55 00 - mov dl, BYTE PTR [rbp+0x0]
8a 65 00 - mov ah, BYTE PTR [rbp+0x0]
8a 7d 00 - mov bh, BYTE PTR [rbp+0x0]
8a 6d 00 - mov ch, BYTE PTR [rbp+0x0]
8a 75 00 - mov dh, BYTE PTR [rbp+0x0]
41 8a 01 - mov al, BYTE PTR [r9]
41 8a 19 - mov bl, BYTE PTR [r9]
41 8a 09 - mov cl, BYTE PTR [r9]
41 8a 11 - mov dl, BYTE PTR [r9]
41 8a 39 - mov dil, BYTE PTR [r9]
41 8a 31 - mov sil, BYTE PTR [r9]
41 8a 03 - mov al, BYTE PTR [r11]
41 8a 1b - mov bl, BYTE PTR [r11]
41 8a 0b - mov cl, BYTE PTR [r11]
41 8a 13 - mov dl, BYTE PTR [r11]
41 8a 3b - mov dil, BYTE PTR [r11]
41 8a 33 - mov sil, BYTE PTR [r11]
41 8a 45 00 - mov al, BYTE PTR [r13+0x0]
41 8a 5d 00 - mov bl, BYTE PTR [r13+0x0]
41 8a 4d 00 - mov cl, BYTE PTR [r13+0x0]
41 8a 55 00 - mov dl, BYTE PTR [r13+0x0]
41 8a 7d 00 - mov dil, BYTE PTR [r13+0x0]
41 8a 75 00 - mov sil, BYTE PTR [r13+0x0]
41 8a 07 - mov al, BYTE PTR [r15]
41 8a 1f - mov bl, BYTE PTR [r15]
41 8a 0f - mov cl, BYTE PTR [r15]
41 8a 17 - mov dl, BYTE PTR [r15]
41 8a 3f - mov dil, BYTE PTR [r15]
41 8a 37 - mov sil, BYTE PTR [r15]




48 8d 00 - lea rax, [rax]
48 8d 02 - lea rax, [rdx]
48 8d 06 - lea rax, [rsi]
48 8d 18 - lea rbx, [rax]
48 8d 1a - lea rbx, [rdx]
48 8d 1e - lea rbx, [rsi]
48 8d 08 - lea rcx, [rax]
48 8d 0a - lea rcx, [rdx]
48 8d 0e - lea rcx, [rsi]
48 8d 10 - lea rdx, [rax]
48 8d 12 - lea rdx, [rdx]
48 8d 16 - lea rdx, [rsi]
48 8d 38 - lea rdi, [rax]
48 8d 3a - lea rdi, [rdx]
48 8d 3e - lea rdi, [rsi]
48 8d 30 - lea rsi, [rax]
48 8d 32 - lea rsi, [rdx]
48 8d 36 - lea rsi, [rsi]
48 8d 20 - lea rsp, [rax]
48 8d 22 - lea rsp, [rdx]
48 8d 26 - lea rsp, [rsi]
48 8d 28 - lea rbp, [rax]
48 8d 2a - lea rbp, [rdx]
48 8d 2e - lea rbp, [rsi]
4c 8d 00 - lea r8, [rax]
4c 8d 02 - lea r8, [rdx]
4c 8d 06 - lea r8, [rsi]
4c 8d 08 - lea r9, [rax]
4c 8d 0a - lea r9, [rdx]
4c 8d 0e - lea r9, [rsi]
4c 8d 10 - lea r10, [rax]
4c 8d 12 - lea r10, [rdx]
4c 8d 16 - lea r10, [rsi]
4c 8d 18 - lea r11, [rax]
4c 8d 1a - lea r11, [rdx]
4c 8d 1e - lea r11, [rsi]
4c 8d 20 - lea r12, [rax]
4c 8d 22 - lea r12, [rdx]
4c 8d 26 - lea r12, [rsi]
4c 8d 28 - lea r13, [rax]
4c 8d 2a - lea r13, [rdx]
4c 8d 2e - lea r13, [rsi]
4c 8d 30 - lea r14, [rax]
4c 8d 32 - lea r14, [rdx]
4c 8d 36 - lea r14, [rsi]
4c 8d 38 - lea r15, [rax]
4c 8d 3a - lea r15, [rdx]
4c 8d 3e - lea r15, [rsi]
48 8d 40 7f - lea rax, [rax+0x7f]
48 8d 42 7f - lea rax, [rdx+0x7f]
48 8d 46 7f - lea rax, [rsi+0x7f]
48 8d 58 7f - lea rbx, [rax+0x7f]
48 8d 5a 7f - lea rbx, [rdx+0x7f]
48 8d 5e 7f - lea rbx, [rsi+0x7f]
48 8d 48 7f - lea rcx, [rax+0x7f]
48 8d 4a 7f - lea rcx, [rdx+0x7f]
48 8d 4e 7f - lea rcx, [rsi+0x7f]
48 8d 50 7f - lea rdx, [rax+0x7f]
48 8d 52 7f - lea rdx, [rdx+0x7f]
48 8d 56 7f - lea rdx, [rsi+0x7f]
48 8d 78 7f - lea rdi, [rax+0x7f]
48 8d 7a 7f - lea rdi, [rdx+0x7f]
48 8d 7e 7f - lea rdi, [rsi+0x7f]
48 8d 70 7f - lea rsi, [rax+0x7f]
48 8d 72 7f - lea rsi, [rdx+0x7f]
48 8d 76 7f - lea rsi, [rsi+0x7f]
48 8d 60 7f - lea rsp, [rax+0x7f]
48 8d 62 7f - lea rsp, [rdx+0x7f]
48 8d 66 7f - lea rsp, [rsi+0x7f]
48 8d 68 7f - lea rbp, [rax+0x7f]
48 8d 6a 7f - lea rbp, [rdx+0x7f]
48 8d 6e 7f - lea rbp, [rsi+0x7f]
4c 8d 40 7f - lea r8, [rax+0x7f]
4c 8d 42 7f - lea r8, [rdx+0x7f]
4c 8d 46 7f - lea r8, [rsi+0x7f]
4c 8d 48 7f - lea r9, [rax+0x7f]
4c 8d 4a 7f - lea r9, [rdx+0x7f]
4c 8d 4e 7f - lea r9, [rsi+0x7f]
4c 8d 50 7f - lea r10, [rax+0x7f]
4c 8d 52 7f - lea r10, [rdx+0x7f]
4c 8d 56 7f - lea r10, [rsi+0x7f]
4c 8d 58 7f - lea r11, [rax+0x7f]
4c 8d 5a 7f - lea r11, [rdx+0x7f]
4c 8d 5e 7f - lea r11, [rsi+0x7f]
4c 8d 60 7f - lea r12, [rax+0x7f]
4c 8d 62 7f - lea r12, [rdx+0x7f]
4c 8d 66 7f - lea r12, [rsi+0x7f]
4c 8d 68 7f - lea r13, [rax+0x7f]
4c 8d 6a 7f - lea r13, [rdx+0x7f]
4c 8d 6e 7f - lea r13, [rsi+0x7f]
4c 8d 70 7f - lea r14, [rax+0x7f]
4c 8d 72 7f - lea r14, [rdx+0x7f]
4c 8d 76 7f - lea r14, [rsi+0x7f]
4c 8d 78 7f - lea r15, [rax+0x7f]
4c 8d 7a 7f - lea r15, [rdx+0x7f]
4c 8d 7e 7f - lea r15, [rsi+0x7f]




48 93 - xchg rbx, rax
48 91 - xchg rcx, rax
48 97 - xchg rdi, rax
48 95 - xchg rbp, rax
49 90 - xchg r8, rax
49 92 - xchg r10, rax
49 94 - xchg r12, rax
49 96 - xchg r14, rax
48 87 d2 - xchg rdx, rdx
48 87 fa - xchg rdx, rdi
48 87 f2 - xchg rdx, rsi
48 87 e2 - xchg rdx, rsp
48 87 ea - xchg rdx, rbp
4c 87 c2 - xchg rdx, r8
4c 87 ca - xchg rdx, r9
4c 87 d2 - xchg rdx, r10
4c 87 da - xchg rdx, r11
4c 87 e2 - xchg rdx, r12
4c 87 ea - xchg rdx, r13
4c 87 f2 - xchg rdx, r14
4c 87 fa - xchg rdx, r15
48 87 f6 - xchg rsi, rsi
48 87 e6 - xchg rsi, rsp
48 87 ee - xchg rsi, rbp
4c 87 c6 - xchg rsi, r8
4c 87 ce - xchg rsi, r9
4c 87 d6 - xchg rsi, r10
4c 87 de - xchg rsi, r11
4c 87 e6 - xchg rsi, r12
4c 87 ee - xchg rsi, r13
4c 87 f6 - xchg rsi, r14
4c 87 fe - xchg rsi, r15
48 87 e4 - xchg rsp, rsp
48 87 ec - xchg rsp, rbp
4c 87 c4 - xchg rsp, r8
4c 87 cc - xchg rsp, r9
4c 87 d4 - xchg rsp, r10
4c 87 dc - xchg rsp, r11
4c 87 e4 - xchg rsp, r12
4c 87 ec - xchg rsp, r13
4c 87 f4 - xchg rsp, r14
4c 87 fc - xchg rsp, r15
87 c0 - xchg eax, eax
87 d2 - xchg edx, edx
87 fa - xchg edx, edi
87 f2 - xchg edx, esi
87 e2 - xchg edx, esp
87 ea - xchg edx, ebp
87 f6 - xchg esi, esi
87 e6 - xchg esi, esp
87 ee - xchg esi, ebp
87 e4 - xchg esp, esp
87 ec - xchg esp, ebp
66 93 - xchg bx, ax
66 91 - xchg cx, ax
66 95 - xchg bp, ax
66 87 d2 - xchg dx, dx
66 87 e2 - xchg dx, sp
66 87 ea - xchg dx, bp
66 87 e4 - xchg sp, sp
66 87 ec - xchg sp, bp
86 db - xchg bl, bl
86 cb - xchg bl, cl
86 d3 - xchg bl, dl
86 e3 - xchg bl, ah
86 fb - xchg bl, bh
86 eb - xchg bl, ch
86 f3 - xchg bl, dh
86 c9 - xchg cl, cl
86 d1 - xchg cl, dl
86 e1 - xchg cl, ah
86 f9 - xchg cl, bh
86 e9 - xchg cl, ch
86 f1 - xchg cl, dh
86 ff - xchg bh, bh
86 ef - xchg bh, ch
86 f7 - xchg bh, dh
86 ed - xchg ch, ch
86 f5 - xchg ch, dh
48 87 00 - xchg QWORD PTR [rax], rax
48 87 18 - xchg QWORD PTR [rax], rbx
48 87 08 - xchg QWORD PTR [rax], rcx
48 87 10 - xchg QWORD PTR [rax], rdx
48 87 38 - xchg QWORD PTR [rax], rdi
48 87 30 - xchg QWORD PTR [rax], rsi
48 87 20 - xchg QWORD PTR [rax], rsp
48 87 28 - xchg QWORD PTR [rax], rbp
4c 87 00 - xchg QWORD PTR [rax], r8
4c 87 08 - xchg QWORD PTR [rax], r9
4c 87 10 - xchg QWORD PTR [rax], r10
4c 87 18 - xchg QWORD PTR [rax], r11
4c 87 20 - xchg QWORD PTR [rax], r12
4c 87 28 - xchg QWORD PTR [rax], r13
4c 87 30 - xchg QWORD PTR [rax], r14
4c 87 38 - xchg QWORD PTR [rax], r15
87 00 - xchg DWORD PTR [rax], eax
87 18 - xchg DWORD PTR [rax], ebx
87 08 - xchg DWORD PTR [rax], ecx
87 10 - xchg DWORD PTR [rax], edx
87 38 - xchg DWORD PTR [rax], edi
87 30 - xchg DWORD PTR [rax], esi
87 20 - xchg DWORD PTR [rax], esp
87 28 - xchg DWORD PTR [rax], ebp
66 87 00 - xchg WORD PTR [rax], ax
66 87 18 - xchg WORD PTR [rax], bx
66 87 08 - xchg WORD PTR [rax], cx
66 87 10 - xchg WORD PTR [rax], dx
66 87 20 - xchg WORD PTR [rax], sp
66 87 28 - xchg WORD PTR [rax], bp
86 03 - xchg BYTE PTR [rbx], al
86 1b - xchg BYTE PTR [rbx], bl
86 0b - xchg BYTE PTR [rbx], cl
86 13 - xchg BYTE PTR [rbx], dl
86 23 - xchg BYTE PTR [rbx], ah
86 3b - xchg BYTE PTR [rbx], bh
86 2b - xchg BYTE PTR [rbx], ch
86 33 - xchg BYTE PTR [rbx], dh
86 01 - xchg BYTE PTR [rcx], al
86 19 - xchg BYTE PTR [rcx], bl
86 09 - xchg BYTE PTR [rcx], cl
86 11 - xchg BYTE PTR [rcx], dl
86 21 - xchg BYTE PTR [rcx], ah
86 39 - xchg BYTE PTR [rcx], bh
86 29 - xchg BYTE PTR [rcx], ch
86 31 - xchg BYTE PTR [rcx], dh
48 87 02 - xchg QWORD PTR [rdx], rax
48 87 1a - xchg QWORD PTR [rdx], rbx
48 87 0a - xchg QWORD PTR [rdx], rcx
48 87 12 - xchg QWORD PTR [rdx], rdx
48 87 3a - xchg QWORD PTR [rdx], rdi
48 87 32 - xchg QWORD PTR [rdx], rsi
48 87 22 - xchg QWORD PTR [rdx], rsp
48 87 2a - xchg QWORD PTR [rdx], rbp
4c 87 02 - xchg QWORD PTR [rdx], r8
4c 87 0a - xchg QWORD PTR [rdx], r9
4c 87 12 - xchg QWORD PTR [rdx], r10
4c 87 1a - xchg QWORD PTR [rdx], r11
4c 87 22 - xchg QWORD PTR [rdx], r12
4c 87 2a - xchg QWORD PTR [rdx], r13
4c 87 32 - xchg QWORD PTR [rdx], r14
4c 87 3a - xchg QWORD PTR [rdx], r15
87 02 - xchg DWORD PTR [rdx], eax
87 1a - xchg DWORD PTR [rdx], ebx
87 0a - xchg DWORD PTR [rdx], ecx
87 12 - xchg DWORD PTR [rdx], edx
87 3a - xchg DWORD PTR [rdx], edi
87 32 - xchg DWORD PTR [rdx], esi
87 22 - xchg DWORD PTR [rdx], esp
87 2a - xchg DWORD PTR [rdx], ebp
66 87 02 - xchg WORD PTR [rdx], ax
66 87 1a - xchg WORD PTR [rdx], bx
66 87 0a - xchg WORD PTR [rdx], cx
66 87 12 - xchg WORD PTR [rdx], dx
66 87 22 - xchg WORD PTR [rdx], sp
66 87 2a - xchg WORD PTR [rdx], bp
86 07 - xchg BYTE PTR [rdi], al
86 1f - xchg BYTE PTR [rdi], bl
86 0f - xchg BYTE PTR [rdi], cl
86 17 - xchg BYTE PTR [rdi], dl
86 27 - xchg BYTE PTR [rdi], ah
86 3f - xchg BYTE PTR [rdi], bh
86 2f - xchg BYTE PTR [rdi], ch
86 37 - xchg BYTE PTR [rdi], dh
48 87 06 - xchg QWORD PTR [rsi], rax
48 87 1e - xchg QWORD PTR [rsi], rbx
48 87 0e - xchg QWORD PTR [rsi], rcx
48 87 16 - xchg QWORD PTR [rsi], rdx
48 87 3e - xchg QWORD PTR [rsi], rdi
48 87 36 - xchg QWORD PTR [rsi], rsi
48 87 26 - xchg QWORD PTR [rsi], rsp
48 87 2e - xchg QWORD PTR [rsi], rbp
4c 87 06 - xchg QWORD PTR [rsi], r8
4c 87 0e - xchg QWORD PTR [rsi], r9
4c 87 16 - xchg QWORD PTR [rsi], r10
4c 87 1e - xchg QWORD PTR [rsi], r11
4c 87 26 - xchg QWORD PTR [rsi], r12
4c 87 2e - xchg QWORD PTR [rsi], r13
4c 87 36 - xchg QWORD PTR [rsi], r14
4c 87 3e - xchg QWORD PTR [rsi], r15
87 06 - xchg DWORD PTR [rsi], eax
87 1e - xchg DWORD PTR [rsi], ebx
87 0e - xchg DWORD PTR [rsi], ecx
87 16 - xchg DWORD PTR [rsi], edx
87 3e - xchg DWORD PTR [rsi], edi
87 36 - xchg DWORD PTR [rsi], esi
87 26 - xchg DWORD PTR [rsi], esp
87 2e - xchg DWORD PTR [rsi], ebp
66 87 06 - xchg WORD PTR [rsi], ax
66 87 1e - xchg WORD PTR [rsi], bx
66 87 0e - xchg WORD PTR [rsi], cx
66 87 16 - xchg WORD PTR [rsi], dx
66 87 26 - xchg WORD PTR [rsi], sp
66 87 2e - xchg WORD PTR [rsi], bp
86 45 00 - xchg BYTE PTR [rbp+0x0], al
86 5d 00 - xchg BYTE PTR [rbp+0x0], bl
86 4d 00 - xchg BYTE PTR [rbp+0x0], cl
86 55 00 - xchg BYTE PTR [rbp+0x0], dl
86 65 00 - xchg BYTE PTR [rbp+0x0], ah
86 7d 00 - xchg BYTE PTR [rbp+0x0], bh
86 6d 00 - xchg BYTE PTR [rbp+0x0], ch
86 75 00 - xchg BYTE PTR [rbp+0x0], dh
41 86 01 - xchg BYTE PTR [r9], al
41 86 19 - xchg BYTE PTR [r9], bl
41 86 09 - xchg BYTE PTR [r9], cl
41 86 11 - xchg BYTE PTR [r9], dl
41 86 39 - xchg BYTE PTR [r9], dil
41 86 31 - xchg BYTE PTR [r9], sil
41 86 03 - xchg BYTE PTR [r11], al
41 86 1b - xchg BYTE PTR [r11], bl
41 86 0b - xchg BYTE PTR [r11], cl
41 86 13 - xchg BYTE PTR [r11], dl
41 86 3b - xchg BYTE PTR [r11], dil
41 86 33 - xchg BYTE PTR [r11], sil
41 86 45 00 - xchg BYTE PTR [r13+0x0], al
41 86 5d 00 - xchg BYTE PTR [r13+0x0], bl
41 86 4d 00 - xchg BYTE PTR [r13+0x0], cl
41 86 55 00 - xchg BYTE PTR [r13+0x0], dl
41 86 7d 00 - xchg BYTE PTR [r13+0x0], dil
41 86 75 00 - xchg BYTE PTR [r13+0x0], sil
41 86 07 - xchg BYTE PTR [r15], al
41 86 1f - xchg BYTE PTR [r15], bl
41 86 0f - xchg BYTE PTR [r15], cl
41 86 17 - xchg BYTE PTR [r15], dl
41 86 3f - xchg BYTE PTR [r15], dil
41 86 37 - xchg BYTE PTR [r15], sil




48 09 c0 - or rax, rax
48 09 d8 - or rax, rbx
48 09 c8 - or rax, rcx
48 09 d0 - or rax, rdx
48 09 f8 - or rax, rdi
48 09 f0 - or rax, rsi
48 09 e0 - or rax, rsp
48 09 e8 - or rax, rbp
4c 09 c0 - or rax, r8
4c 09 c8 - or rax, r9
4c 09 d0 - or rax, r10
4c 09 d8 - or rax, r11
4c 09 e0 - or rax, r12
4c 09 e8 - or rax, r13
4c 09 f0 - or rax, r14
4c 09 f8 - or rax, r15
48 09 c2 - or rdx, rax
48 09 da - or rdx, rbx
48 09 ca - or rdx, rcx
48 09 d2 - or rdx, rdx
48 09 fa - or rdx, rdi
48 09 f2 - or rdx, rsi
48 09 e2 - or rdx, rsp
48 09 ea - or rdx, rbp
4c 09 c2 - or rdx, r8
4c 09 ca - or rdx, r9
4c 09 d2 - or rdx, r10
4c 09 da - or rdx, r11
4c 09 e2 - or rdx, r12
4c 09 ea - or rdx, r13
4c 09 f2 - or rdx, r14
4c 09 fa - or rdx, r15
48 09 c6 - or rsi, rax
48 09 de - or rsi, rbx
48 09 ce - or rsi, rcx
48 09 d6 - or rsi, rdx
48 09 fe - or rsi, rdi
48 09 f6 - or rsi, rsi
48 09 e6 - or rsi, rsp
48 09 ee - or rsi, rbp
4c 09 c6 - or rsi, r8
4c 09 ce - or rsi, r9
4c 09 d6 - or rsi, r10
4c 09 de - or rsi, r11
4c 09 e6 - or rsi, r12
4c 09 ee - or rsi, r13
4c 09 f6 - or rsi, r14
4c 09 fe - or rsi, r15
48 09 c4 - or rsp, rax
48 09 dc - or rsp, rbx
48 09 cc - or rsp, rcx
48 09 d4 - or rsp, rdx
48 09 fc - or rsp, rdi
48 09 f4 - or rsp, rsi
48 09 e4 - or rsp, rsp
48 09 ec - or rsp, rbp
4c 09 c4 - or rsp, r8
4c 09 cc - or rsp, r9
4c 09 d4 - or rsp, r10
4c 09 dc - or rsp, r11
4c 09 e4 - or rsp, r12
4c 09 ec - or rsp, r13
4c 09 f4 - or rsp, r14
4c 09 fc - or rsp, r15
09 c0 - or eax, eax
09 d8 - or eax, ebx
09 c8 - or eax, ecx
09 d0 - or eax, edx
09 f8 - or eax, edi
09 f0 - or eax, esi
09 e0 - or eax, esp
09 e8 - or eax, ebp
09 c2 - or edx, eax
09 da - or edx, ebx
09 ca - or edx, ecx
09 d2 - or edx, edx
09 fa - or edx, edi
09 f2 - or edx, esi
09 e2 - or edx, esp
09 ea - or edx, ebp
09 c6 - or esi, eax
09 de - or esi, ebx
09 ce - or esi, ecx
09 d6 - or esi, edx
09 fe - or esi, edi
09 f6 - or esi, esi
09 e6 - or esi, esp
09 ee - or esi, ebp
09 c4 - or esp, eax
09 dc - or esp, ebx
09 cc - or esp, ecx
09 d4 - or esp, edx
09 fc - or esp, edi
09 f4 - or esp, esi
09 e4 - or esp, esp
09 ec - or esp, ebp
66 09 c0 - or ax, ax
66 09 d8 - or ax, bx
66 09 c8 - or ax, cx
66 09 d0 - or ax, dx
66 09 e0 - or ax, sp
66 09 e8 - or ax, bp
66 09 c2 - or dx, ax
66 09 da - or dx, bx
66 09 ca - or dx, cx
66 09 d2 - or dx, dx
66 09 e2 - or dx, sp
66 09 ea - or dx, bp
66 09 c4 - or sp, ax
66 09 dc - or sp, bx
66 09 cc - or sp, cx
66 09 d4 - or sp, dx
66 09 e4 - or sp, sp
66 09 ec - or sp, bp
08 c3 - or bl, al
08 db - or bl, bl
08 cb - or bl, cl
08 d3 - or bl, dl
08 e3 - or bl, ah
08 fb - or bl, bh
08 eb - or bl, ch
08 f3 - or bl, dh
08 c1 - or cl, al
08 d9 - or cl, bl
08 c9 - or cl, cl
08 d1 - or cl, dl
08 e1 - or cl, ah
08 f9 - or cl, bh
08 e9 - or cl, ch
08 f1 - or cl, dh
08 c7 - or bh, al
08 df - or bh, bl
08 cf - or bh, cl
08 d7 - or bh, dl
08 e7 - or bh, ah
08 ff - or bh, bh
08 ef - or bh, ch
08 f7 - or bh, dh
08 c5 - or ch, al
08 dd - or ch, bl
08 cd - or ch, cl
08 d5 - or ch, dl
08 e5 - or ch, ah
08 fd - or ch, bh
08 ed - or ch, ch
08 f5 - or ch, dh
80 cb 7e - or bl, 0x7e
80 c9 7e - or cl, 0x7e
80 cf 7e - or bh, 0x7e
80 cd 7e - or ch, 0x7e
48 83 c8 7f - or rax, 0x7f
48 83 ca 7f - or rdx, 0x7f
48 83 ce 7f - or rsi, 0x7f
48 83 cc 7f - or rsp, 0x7f
83 c8 7f - or eax, 0x7f
83 ca 7f - or edx, 0x7f
83 ce 7f - or esi, 0x7f
83 cc 7f - or esp, 0x7f
66 83 c8 7f - or ax, 0x7f
66 83 ca 7f - or dx, 0x7f
66 83 cc 7f - or sp, 0x7f
0c 7f - or al, 0x7f
48 09 00 - or QWORD PTR [rax], rax
48 09 18 - or QWORD PTR [rax], rbx
48 09 08 - or QWORD PTR [rax], rcx
48 09 10 - or QWORD PTR [rax], rdx
48 09 38 - or QWORD PTR [rax], rdi
48 09 30 - or QWORD PTR [rax], rsi
48 09 20 - or QWORD PTR [rax], rsp
48 09 28 - or QWORD PTR [rax], rbp
4c 09 00 - or QWORD PTR [rax], r8
4c 09 08 - or QWORD PTR [rax], r9
4c 09 10 - or QWORD PTR [rax], r10
4c 09 18 - or QWORD PTR [rax], r11
4c 09 20 - or QWORD PTR [rax], r12
4c 09 28 - or QWORD PTR [rax], r13
4c 09 30 - or QWORD PTR [rax], r14
4c 09 38 - or QWORD PTR [rax], r15
09 00 - or DWORD PTR [rax], eax
09 18 - or DWORD PTR [rax], ebx
09 08 - or DWORD PTR [rax], ecx
09 10 - or DWORD PTR [rax], edx
09 38 - or DWORD PTR [rax], edi
09 30 - or DWORD PTR [rax], esi
09 20 - or DWORD PTR [rax], esp
09 28 - or DWORD PTR [rax], ebp
66 09 00 - or WORD PTR [rax], ax
66 09 18 - or WORD PTR [rax], bx
66 09 08 - or WORD PTR [rax], cx
66 09 10 - or WORD PTR [rax], dx
66 09 20 - or WORD PTR [rax], sp
66 09 28 - or WORD PTR [rax], bp
08 03 - or BYTE PTR [rbx], al
08 1b - or BYTE PTR [rbx], bl
08 0b - or BYTE PTR [rbx], cl
08 13 - or BYTE PTR [rbx], dl
08 23 - or BYTE PTR [rbx], ah
08 3b - or BYTE PTR [rbx], bh
08 2b - or BYTE PTR [rbx], ch
08 33 - or BYTE PTR [rbx], dh
08 01 - or BYTE PTR [rcx], al
08 19 - or BYTE PTR [rcx], bl
08 09 - or BYTE PTR [rcx], cl
08 11 - or BYTE PTR [rcx], dl
08 21 - or BYTE PTR [rcx], ah
08 39 - or BYTE PTR [rcx], bh
08 29 - or BYTE PTR [rcx], ch
08 31 - or BYTE PTR [rcx], dh
48 09 02 - or QWORD PTR [rdx], rax
48 09 1a - or QWORD PTR [rdx], rbx
48 09 0a - or QWORD PTR [rdx], rcx
48 09 12 - or QWORD PTR [rdx], rdx
48 09 3a - or QWORD PTR [rdx], rdi
48 09 32 - or QWORD PTR [rdx], rsi
48 09 22 - or QWORD PTR [rdx], rsp
48 09 2a - or QWORD PTR [rdx], rbp
4c 09 02 - or QWORD PTR [rdx], r8
4c 09 0a - or QWORD PTR [rdx], r9
4c 09 12 - or QWORD PTR [rdx], r10
4c 09 1a - or QWORD PTR [rdx], r11
4c 09 22 - or QWORD PTR [rdx], r12
4c 09 2a - or QWORD PTR [rdx], r13
4c 09 32 - or QWORD PTR [rdx], r14
4c 09 3a - or QWORD PTR [rdx], r15
09 02 - or DWORD PTR [rdx], eax
09 1a - or DWORD PTR [rdx], ebx
09 0a - or DWORD PTR [rdx], ecx
09 12 - or DWORD PTR [rdx], edx
09 3a - or DWORD PTR [rdx], edi
09 32 - or DWORD PTR [rdx], esi
09 22 - or DWORD PTR [rdx], esp
09 2a - or DWORD PTR [rdx], ebp
66 09 02 - or WORD PTR [rdx], ax
66 09 1a - or WORD PTR [rdx], bx
66 09 0a - or WORD PTR [rdx], cx
66 09 12 - or WORD PTR [rdx], dx
66 09 22 - or WORD PTR [rdx], sp
66 09 2a - or WORD PTR [rdx], bp
08 07 - or BYTE PTR [rdi], al
08 1f - or BYTE PTR [rdi], bl
08 0f - or BYTE PTR [rdi], cl
08 17 - or BYTE PTR [rdi], dl
08 27 - or BYTE PTR [rdi], ah
08 3f - or BYTE PTR [rdi], bh
08 2f - or BYTE PTR [rdi], ch
08 37 - or BYTE PTR [rdi], dh
48 09 06 - or QWORD PTR [rsi], rax
48 09 1e - or QWORD PTR [rsi], rbx
48 09 0e - or QWORD PTR [rsi], rcx
48 09 16 - or QWORD PTR [rsi], rdx
48 09 3e - or QWORD PTR [rsi], rdi
48 09 36 - or QWORD PTR [rsi], rsi
48 09 26 - or QWORD PTR [rsi], rsp
48 09 2e - or QWORD PTR [rsi], rbp
4c 09 06 - or QWORD PTR [rsi], r8
4c 09 0e - or QWORD PTR [rsi], r9
4c 09 16 - or QWORD PTR [rsi], r10
4c 09 1e - or QWORD PTR [rsi], r11
4c 09 26 - or QWORD PTR [rsi], r12
4c 09 2e - or QWORD PTR [rsi], r13
4c 09 36 - or QWORD PTR [rsi], r14
4c 09 3e - or QWORD PTR [rsi], r15
09 06 - or DWORD PTR [rsi], eax
09 1e - or DWORD PTR [rsi], ebx
09 0e - or DWORD PTR [rsi], ecx
09 16 - or DWORD PTR [rsi], edx
09 3e - or DWORD PTR [rsi], edi
09 36 - or DWORD PTR [rsi], esi
09 26 - or DWORD PTR [rsi], esp
09 2e - or DWORD PTR [rsi], ebp
66 09 06 - or WORD PTR [rsi], ax
66 09 1e - or WORD PTR [rsi], bx
66 09 0e - or WORD PTR [rsi], cx
66 09 16 - or WORD PTR [rsi], dx
66 09 26 - or WORD PTR [rsi], sp
66 09 2e - or WORD PTR [rsi], bp
08 45 00 - or BYTE PTR [rbp+0x0], al
08 5d 00 - or BYTE PTR [rbp+0x0], bl
08 4d 00 - or BYTE PTR [rbp+0x0], cl
08 55 00 - or BYTE PTR [rbp+0x0], dl
08 65 00 - or BYTE PTR [rbp+0x0], ah
08 7d 00 - or BYTE PTR [rbp+0x0], bh
08 6d 00 - or BYTE PTR [rbp+0x0], ch
08 75 00 - or BYTE PTR [rbp+0x0], dh
41 08 01 - or BYTE PTR [r9], al
41 08 19 - or BYTE PTR [r9], bl
41 08 09 - or BYTE PTR [r9], cl
41 08 11 - or BYTE PTR [r9], dl
41 08 39 - or BYTE PTR [r9], dil
41 08 31 - or BYTE PTR [r9], sil
41 08 03 - or BYTE PTR [r11], al
41 08 1b - or BYTE PTR [r11], bl
41 08 0b - or BYTE PTR [r11], cl
41 08 13 - or BYTE PTR [r11], dl
41 08 3b - or BYTE PTR [r11], dil
41 08 33 - or BYTE PTR [r11], sil
41 08 45 00 - or BYTE PTR [r13+0x0], al
41 08 5d 00 - or BYTE PTR [r13+0x0], bl
41 08 4d 00 - or BYTE PTR [r13+0x0], cl
41 08 55 00 - or BYTE PTR [r13+0x0], dl
41 08 7d 00 - or BYTE PTR [r13+0x0], dil
41 08 75 00 - or BYTE PTR [r13+0x0], sil
41 08 07 - or BYTE PTR [r15], al
41 08 1f - or BYTE PTR [r15], bl
41 08 0f - or BYTE PTR [r15], cl
41 08 17 - or BYTE PTR [r15], dl
41 08 3f - or BYTE PTR [r15], dil
41 08 37 - or BYTE PTR [r15], sil
48 0b 00 - or rax, QWORD PTR [rax]
48 0b 18 - or rbx, QWORD PTR [rax]
48 0b 08 - or rcx, QWORD PTR [rax]
48 0b 10 - or rdx, QWORD PTR [rax]
48 0b 38 - or rdi, QWORD PTR [rax]
48 0b 30 - or rsi, QWORD PTR [rax]
48 0b 20 - or rsp, QWORD PTR [rax]
48 0b 28 - or rbp, QWORD PTR [rax]
4c 0b 00 - or r8, QWORD PTR [rax]
4c 0b 08 - or r9, QWORD PTR [rax]
4c 0b 10 - or r10, QWORD PTR [rax]
4c 0b 18 - or r11, QWORD PTR [rax]
4c 0b 20 - or r12, QWORD PTR [rax]
4c 0b 28 - or r13, QWORD PTR [rax]
4c 0b 30 - or r14, QWORD PTR [rax]
4c 0b 38 - or r15, QWORD PTR [rax]
0b 00 - or eax, DWORD PTR [rax]
0b 18 - or ebx, DWORD PTR [rax]
0b 08 - or ecx, DWORD PTR [rax]
0b 10 - or edx, DWORD PTR [rax]
0b 38 - or edi, DWORD PTR [rax]
0b 30 - or esi, DWORD PTR [rax]
0b 20 - or esp, DWORD PTR [rax]
0b 28 - or ebp, DWORD PTR [rax]
66 0b 00 - or ax, WORD PTR [rax]
66 0b 18 - or bx, WORD PTR [rax]
66 0b 08 - or cx, WORD PTR [rax]
66 0b 10 - or dx, WORD PTR [rax]
66 0b 20 - or sp, WORD PTR [rax]
66 0b 28 - or bp, WORD PTR [rax]
0a 03 - or al, BYTE PTR [rbx]
0a 1b - or bl, BYTE PTR [rbx]
0a 0b - or cl, BYTE PTR [rbx]
0a 13 - or dl, BYTE PTR [rbx]
0a 23 - or ah, BYTE PTR [rbx]
0a 3b - or bh, BYTE PTR [rbx]
0a 2b - or ch, BYTE PTR [rbx]
0a 33 - or dh, BYTE PTR [rbx]
0a 01 - or al, BYTE PTR [rcx]
0a 19 - or bl, BYTE PTR [rcx]
0a 09 - or cl, BYTE PTR [rcx]
0a 11 - or dl, BYTE PTR [rcx]
0a 21 - or ah, BYTE PTR [rcx]
0a 39 - or bh, BYTE PTR [rcx]
0a 29 - or ch, BYTE PTR [rcx]
0a 31 - or dh, BYTE PTR [rcx]
48 0b 02 - or rax, QWORD PTR [rdx]
48 0b 1a - or rbx, QWORD PTR [rdx]
48 0b 0a - or rcx, QWORD PTR [rdx]
48 0b 12 - or rdx, QWORD PTR [rdx]
48 0b 3a - or rdi, QWORD PTR [rdx]
48 0b 32 - or rsi, QWORD PTR [rdx]
48 0b 22 - or rsp, QWORD PTR [rdx]
48 0b 2a - or rbp, QWORD PTR [rdx]
4c 0b 02 - or r8, QWORD PTR [rdx]
4c 0b 0a - or r9, QWORD PTR [rdx]
4c 0b 12 - or r10, QWORD PTR [rdx]
4c 0b 1a - or r11, QWORD PTR [rdx]
4c 0b 22 - or r12, QWORD PTR [rdx]
4c 0b 2a - or r13, QWORD PTR [rdx]
4c 0b 32 - or r14, QWORD PTR [rdx]
4c 0b 3a - or r15, QWORD PTR [rdx]
0b 02 - or eax, DWORD PTR [rdx]
0b 1a - or ebx, DWORD PTR [rdx]
0b 0a - or ecx, DWORD PTR [rdx]
0b 12 - or edx, DWORD PTR [rdx]
0b 3a - or edi, DWORD PTR [rdx]
0b 32 - or esi, DWORD PTR [rdx]
0b 22 - or esp, DWORD PTR [rdx]
0b 2a - or ebp, DWORD PTR [rdx]
66 0b 02 - or ax, WORD PTR [rdx]
66 0b 1a - or bx, WORD PTR [rdx]
66 0b 0a - or cx, WORD PTR [rdx]
66 0b 12 - or dx, WORD PTR [rdx]
66 0b 22 - or sp, WORD PTR [rdx]
66 0b 2a - or bp, WORD PTR [rdx]
0a 07 - or al, BYTE PTR [rdi]
0a 1f - or bl, BYTE PTR [rdi]
0a 0f - or cl, BYTE PTR [rdi]
0a 17 - or dl, BYTE PTR [rdi]
0a 27 - or ah, BYTE PTR [rdi]
0a 3f - or bh, BYTE PTR [rdi]
0a 2f - or ch, BYTE PTR [rdi]
0a 37 - or dh, BYTE PTR [rdi]
48 0b 06 - or rax, QWORD PTR [rsi]
48 0b 1e - or rbx, QWORD PTR [rsi]
48 0b 0e - or rcx, QWORD PTR [rsi]
48 0b 16 - or rdx, QWORD PTR [rsi]
48 0b 3e - or rdi, QWORD PTR [rsi]
48 0b 36 - or rsi, QWORD PTR [rsi]
48 0b 26 - or rsp, QWORD PTR [rsi]
48 0b 2e - or rbp, QWORD PTR [rsi]
4c 0b 06 - or r8, QWORD PTR [rsi]
4c 0b 0e - or r9, QWORD PTR [rsi]
4c 0b 16 - or r10, QWORD PTR [rsi]
4c 0b 1e - or r11, QWORD PTR [rsi]
4c 0b 26 - or r12, QWORD PTR [rsi]
4c 0b 2e - or r13, QWORD PTR [rsi]
4c 0b 36 - or r14, QWORD PTR [rsi]
4c 0b 3e - or r15, QWORD PTR [rsi]
0b 06 - or eax, DWORD PTR [rsi]
0b 1e - or ebx, DWORD PTR [rsi]
0b 0e - or ecx, DWORD PTR [rsi]
0b 16 - or edx, DWORD PTR [rsi]
0b 3e - or edi, DWORD PTR [rsi]
0b 36 - or esi, DWORD PTR [rsi]
0b 26 - or esp, DWORD PTR [rsi]
0b 2e - or ebp, DWORD PTR [rsi]
66 0b 06 - or ax, WORD PTR [rsi]
66 0b 1e - or bx, WORD PTR [rsi]
66 0b 0e - or cx, WORD PTR [rsi]
66 0b 16 - or dx, WORD PTR [rsi]
66 0b 26 - or sp, WORD PTR [rsi]
66 0b 2e - or bp, WORD PTR [rsi]
0a 45 00 - or al, BYTE PTR [rbp+0x0]
0a 5d 00 - or bl, BYTE PTR [rbp+0x0]
0a 4d 00 - or cl, BYTE PTR [rbp+0x0]
0a 55 00 - or dl, BYTE PTR [rbp+0x0]
0a 65 00 - or ah, BYTE PTR [rbp+0x0]
0a 7d 00 - or bh, BYTE PTR [rbp+0x0]
0a 6d 00 - or ch, BYTE PTR [rbp+0x0]
0a 75 00 - or dh, BYTE PTR [rbp+0x0]
41 0a 01 - or al, BYTE PTR [r9]
41 0a 19 - or bl, BYTE PTR [r9]
41 0a 09 - or cl, BYTE PTR [r9]
41 0a 11 - or dl, BYTE PTR [r9]
41 0a 39 - or dil, BYTE PTR [r9]
41 0a 31 - or sil, BYTE PTR [r9]
41 0a 03 - or al, BYTE PTR [r11]
41 0a 1b - or bl, BYTE PTR [r11]
41 0a 0b - or cl, BYTE PTR [r11]
41 0a 13 - or dl, BYTE PTR [r11]
41 0a 3b - or dil, BYTE PTR [r11]
41 0a 33 - or sil, BYTE PTR [r11]
41 0a 45 00 - or al, BYTE PTR [r13+0x0]
41 0a 5d 00 - or bl, BYTE PTR [r13+0x0]
41 0a 4d 00 - or cl, BYTE PTR [r13+0x0]
41 0a 55 00 - or dl, BYTE PTR [r13+0x0]
41 0a 7d 00 - or dil, BYTE PTR [r13+0x0]
41 0a 75 00 - or sil, BYTE PTR [r13+0x0]
41 0a 07 - or al, BYTE PTR [r15]
41 0a 1f - or bl, BYTE PTR [r15]
41 0a 0f - or cl, BYTE PTR [r15]
41 0a 17 - or dl, BYTE PTR [r15]
41 0a 3f - or dil, BYTE PTR [r15]
41 0a 37 - or sil, BYTE PTR [r15]




48 31 c0 - xor rax, rax
48 31 d8 - xor rax, rbx
48 31 c8 - xor rax, rcx
48 31 d0 - xor rax, rdx
48 31 f8 - xor rax, rdi
48 31 f0 - xor rax, rsi
48 31 e0 - xor rax, rsp
48 31 e8 - xor rax, rbp
4c 31 c0 - xor rax, r8
4c 31 c8 - xor rax, r9
4c 31 d0 - xor rax, r10
4c 31 d8 - xor rax, r11
4c 31 e0 - xor rax, r12
4c 31 e8 - xor rax, r13
4c 31 f0 - xor rax, r14
4c 31 f8 - xor rax, r15
48 31 c2 - xor rdx, rax
48 31 da - xor rdx, rbx
48 31 ca - xor rdx, rcx
48 31 d2 - xor rdx, rdx
48 31 fa - xor rdx, rdi
48 31 f2 - xor rdx, rsi
48 31 e2 - xor rdx, rsp
48 31 ea - xor rdx, rbp
4c 31 c2 - xor rdx, r8
4c 31 ca - xor rdx, r9
4c 31 d2 - xor rdx, r10
4c 31 da - xor rdx, r11
4c 31 e2 - xor rdx, r12
4c 31 ea - xor rdx, r13
4c 31 f2 - xor rdx, r14
4c 31 fa - xor rdx, r15
48 31 c6 - xor rsi, rax
48 31 de - xor rsi, rbx
48 31 ce - xor rsi, rcx
48 31 d6 - xor rsi, rdx
48 31 fe - xor rsi, rdi
48 31 f6 - xor rsi, rsi
48 31 e6 - xor rsi, rsp
48 31 ee - xor rsi, rbp
4c 31 c6 - xor rsi, r8
4c 31 ce - xor rsi, r9
4c 31 d6 - xor rsi, r10
4c 31 de - xor rsi, r11
4c 31 e6 - xor rsi, r12
4c 31 ee - xor rsi, r13
4c 31 f6 - xor rsi, r14
4c 31 fe - xor rsi, r15
48 31 c4 - xor rsp, rax
48 31 dc - xor rsp, rbx
48 31 cc - xor rsp, rcx
48 31 d4 - xor rsp, rdx
48 31 fc - xor rsp, rdi
48 31 f4 - xor rsp, rsi
48 31 e4 - xor rsp, rsp
48 31 ec - xor rsp, rbp
4c 31 c4 - xor rsp, r8
4c 31 cc - xor rsp, r9
4c 31 d4 - xor rsp, r10
4c 31 dc - xor rsp, r11
4c 31 e4 - xor rsp, r12
4c 31 ec - xor rsp, r13
4c 31 f4 - xor rsp, r14
4c 31 fc - xor rsp, r15
31 c0 - xor eax, eax
31 d8 - xor eax, ebx
31 c8 - xor eax, ecx
31 d0 - xor eax, edx
31 f8 - xor eax, edi
31 f0 - xor eax, esi
31 e0 - xor eax, esp
31 e8 - xor eax, ebp
31 c2 - xor edx, eax
31 da - xor edx, ebx
31 ca - xor edx, ecx
31 d2 - xor edx, edx
31 fa - xor edx, edi
31 f2 - xor edx, esi
31 e2 - xor edx, esp
31 ea - xor edx, ebp
31 c6 - xor esi, eax
31 de - xor esi, ebx
31 ce - xor esi, ecx
31 d6 - xor esi, edx
31 fe - xor esi, edi
31 f6 - xor esi, esi
31 e6 - xor esi, esp
31 ee - xor esi, ebp
31 c4 - xor esp, eax
31 dc - xor esp, ebx
31 cc - xor esp, ecx
31 d4 - xor esp, edx
31 fc - xor esp, edi
31 f4 - xor esp, esi
31 e4 - xor esp, esp
31 ec - xor esp, ebp
66 31 c0 - xor ax, ax
66 31 d8 - xor ax, bx
66 31 c8 - xor ax, cx
66 31 d0 - xor ax, dx
66 31 e0 - xor ax, sp
66 31 e8 - xor ax, bp
66 31 c2 - xor dx, ax
66 31 da - xor dx, bx
66 31 ca - xor dx, cx
66 31 d2 - xor dx, dx
66 31 e2 - xor dx, sp
66 31 ea - xor dx, bp
66 31 c4 - xor sp, ax
66 31 dc - xor sp, bx
66 31 cc - xor sp, cx
66 31 d4 - xor sp, dx
66 31 e4 - xor sp, sp
66 31 ec - xor sp, bp
30 c3 - xor bl, al
30 db - xor bl, bl
30 cb - xor bl, cl
30 d3 - xor bl, dl
30 e3 - xor bl, ah
30 fb - xor bl, bh
30 eb - xor bl, ch
30 f3 - xor bl, dh
30 c1 - xor cl, al
30 d9 - xor cl, bl
30 c9 - xor cl, cl
30 d1 - xor cl, dl
30 e1 - xor cl, ah
30 f9 - xor cl, bh
30 e9 - xor cl, ch
30 f1 - xor cl, dh
30 c7 - xor bh, al
30 df - xor bh, bl
30 cf - xor bh, cl
30 d7 - xor bh, dl
30 e7 - xor bh, ah
30 ff - xor bh, bh
30 ef - xor bh, ch
30 f7 - xor bh, dh
30 c5 - xor ch, al
30 dd - xor ch, bl
30 cd - xor ch, cl
30 d5 - xor ch, dl
30 e5 - xor ch, ah
30 fd - xor ch, bh
30 ed - xor ch, ch
30 f5 - xor ch, dh
80 f3 7e - xor bl, 0x7e
80 f1 7e - xor cl, 0x7e
80 f7 7e - xor bh, 0x7e
80 f5 7e - xor ch, 0x7e
48 83 f0 7f - xor rax, 0x7f
48 83 f2 7f - xor rdx, 0x7f
48 83 f6 7f - xor rsi, 0x7f
48 83 f4 7f - xor rsp, 0x7f
83 f0 7f - xor eax, 0x7f
83 f2 7f - xor edx, 0x7f
83 f6 7f - xor esi, 0x7f
83 f4 7f - xor esp, 0x7f
66 83 f0 7f - xor ax, 0x7f
66 83 f2 7f - xor dx, 0x7f
66 83 f4 7f - xor sp, 0x7f
34 7f - xor al, 0x7f
48 31 00 - xor QWORD PTR [rax], rax
48 31 18 - xor QWORD PTR [rax], rbx
48 31 08 - xor QWORD PTR [rax], rcx
48 31 10 - xor QWORD PTR [rax], rdx
48 31 38 - xor QWORD PTR [rax], rdi
48 31 30 - xor QWORD PTR [rax], rsi
48 31 20 - xor QWORD PTR [rax], rsp
48 31 28 - xor QWORD PTR [rax], rbp
4c 31 00 - xor QWORD PTR [rax], r8
4c 31 08 - xor QWORD PTR [rax], r9
4c 31 10 - xor QWORD PTR [rax], r10
4c 31 18 - xor QWORD PTR [rax], r11
4c 31 20 - xor QWORD PTR [rax], r12
4c 31 28 - xor QWORD PTR [rax], r13
4c 31 30 - xor QWORD PTR [rax], r14
4c 31 38 - xor QWORD PTR [rax], r15
31 00 - xor DWORD PTR [rax], eax
31 18 - xor DWORD PTR [rax], ebx
31 08 - xor DWORD PTR [rax], ecx
31 10 - xor DWORD PTR [rax], edx
31 38 - xor DWORD PTR [rax], edi
31 30 - xor DWORD PTR [rax], esi
31 20 - xor DWORD PTR [rax], esp
31 28 - xor DWORD PTR [rax], ebp
66 31 00 - xor WORD PTR [rax], ax
66 31 18 - xor WORD PTR [rax], bx
66 31 08 - xor WORD PTR [rax], cx
66 31 10 - xor WORD PTR [rax], dx
66 31 20 - xor WORD PTR [rax], sp
66 31 28 - xor WORD PTR [rax], bp
30 03 - xor BYTE PTR [rbx], al
30 1b - xor BYTE PTR [rbx], bl
30 0b - xor BYTE PTR [rbx], cl
30 13 - xor BYTE PTR [rbx], dl
30 23 - xor BYTE PTR [rbx], ah
30 3b - xor BYTE PTR [rbx], bh
30 2b - xor BYTE PTR [rbx], ch
30 33 - xor BYTE PTR [rbx], dh
30 01 - xor BYTE PTR [rcx], al
30 19 - xor BYTE PTR [rcx], bl
30 09 - xor BYTE PTR [rcx], cl
30 11 - xor BYTE PTR [rcx], dl
30 21 - xor BYTE PTR [rcx], ah
30 39 - xor BYTE PTR [rcx], bh
30 29 - xor BYTE PTR [rcx], ch
30 31 - xor BYTE PTR [rcx], dh
48 31 02 - xor QWORD PTR [rdx], rax
48 31 1a - xor QWORD PTR [rdx], rbx
48 31 0a - xor QWORD PTR [rdx], rcx
48 31 12 - xor QWORD PTR [rdx], rdx
48 31 3a - xor QWORD PTR [rdx], rdi
48 31 32 - xor QWORD PTR [rdx], rsi
48 31 22 - xor QWORD PTR [rdx], rsp
48 31 2a - xor QWORD PTR [rdx], rbp
4c 31 02 - xor QWORD PTR [rdx], r8
4c 31 0a - xor QWORD PTR [rdx], r9
4c 31 12 - xor QWORD PTR [rdx], r10
4c 31 1a - xor QWORD PTR [rdx], r11
4c 31 22 - xor QWORD PTR [rdx], r12
4c 31 2a - xor QWORD PTR [rdx], r13
4c 31 32 - xor QWORD PTR [rdx], r14
4c 31 3a - xor QWORD PTR [rdx], r15
31 02 - xor DWORD PTR [rdx], eax
31 1a - xor DWORD PTR [rdx], ebx
31 0a - xor DWORD PTR [rdx], ecx
31 12 - xor DWORD PTR [rdx], edx
31 3a - xor DWORD PTR [rdx], edi
31 32 - xor DWORD PTR [rdx], esi
31 22 - xor DWORD PTR [rdx], esp
31 2a - xor DWORD PTR [rdx], ebp
66 31 02 - xor WORD PTR [rdx], ax
66 31 1a - xor WORD PTR [rdx], bx
66 31 0a - xor WORD PTR [rdx], cx
66 31 12 - xor WORD PTR [rdx], dx
66 31 22 - xor WORD PTR [rdx], sp
66 31 2a - xor WORD PTR [rdx], bp
30 07 - xor BYTE PTR [rdi], al
30 1f - xor BYTE PTR [rdi], bl
30 0f - xor BYTE PTR [rdi], cl
30 17 - xor BYTE PTR [rdi], dl
30 27 - xor BYTE PTR [rdi], ah
30 3f - xor BYTE PTR [rdi], bh
30 2f - xor BYTE PTR [rdi], ch
30 37 - xor BYTE PTR [rdi], dh
48 31 06 - xor QWORD PTR [rsi], rax
48 31 1e - xor QWORD PTR [rsi], rbx
48 31 0e - xor QWORD PTR [rsi], rcx
48 31 16 - xor QWORD PTR [rsi], rdx
48 31 3e - xor QWORD PTR [rsi], rdi
48 31 36 - xor QWORD PTR [rsi], rsi
48 31 26 - xor QWORD PTR [rsi], rsp
48 31 2e - xor QWORD PTR [rsi], rbp
4c 31 06 - xor QWORD PTR [rsi], r8
4c 31 0e - xor QWORD PTR [rsi], r9
4c 31 16 - xor QWORD PTR [rsi], r10
4c 31 1e - xor QWORD PTR [rsi], r11
4c 31 26 - xor QWORD PTR [rsi], r12
4c 31 2e - xor QWORD PTR [rsi], r13
4c 31 36 - xor QWORD PTR [rsi], r14
4c 31 3e - xor QWORD PTR [rsi], r15
31 06 - xor DWORD PTR [rsi], eax
31 1e - xor DWORD PTR [rsi], ebx
31 0e - xor DWORD PTR [rsi], ecx
31 16 - xor DWORD PTR [rsi], edx
31 3e - xor DWORD PTR [rsi], edi
31 36 - xor DWORD PTR [rsi], esi
31 26 - xor DWORD PTR [rsi], esp
31 2e - xor DWORD PTR [rsi], ebp
66 31 06 - xor WORD PTR [rsi], ax
66 31 1e - xor WORD PTR [rsi], bx
66 31 0e - xor WORD PTR [rsi], cx
66 31 16 - xor WORD PTR [rsi], dx
66 31 26 - xor WORD PTR [rsi], sp
66 31 2e - xor WORD PTR [rsi], bp
30 45 00 - xor BYTE PTR [rbp+0x0], al
30 5d 00 - xor BYTE PTR [rbp+0x0], bl
30 4d 00 - xor BYTE PTR [rbp+0x0], cl
30 55 00 - xor BYTE PTR [rbp+0x0], dl
30 65 00 - xor BYTE PTR [rbp+0x0], ah
30 7d 00 - xor BYTE PTR [rbp+0x0], bh
30 6d 00 - xor BYTE PTR [rbp+0x0], ch
30 75 00 - xor BYTE PTR [rbp+0x0], dh
41 30 01 - xor BYTE PTR [r9], al
41 30 19 - xor BYTE PTR [r9], bl
41 30 09 - xor BYTE PTR [r9], cl
41 30 11 - xor BYTE PTR [r9], dl
41 30 39 - xor BYTE PTR [r9], dil
41 30 31 - xor BYTE PTR [r9], sil
41 30 03 - xor BYTE PTR [r11], al
41 30 1b - xor BYTE PTR [r11], bl
41 30 0b - xor BYTE PTR [r11], cl
41 30 13 - xor BYTE PTR [r11], dl
41 30 3b - xor BYTE PTR [r11], dil
41 30 33 - xor BYTE PTR [r11], sil
41 30 45 00 - xor BYTE PTR [r13+0x0], al
41 30 5d 00 - xor BYTE PTR [r13+0x0], bl
41 30 4d 00 - xor BYTE PTR [r13+0x0], cl
41 30 55 00 - xor BYTE PTR [r13+0x0], dl
41 30 7d 00 - xor BYTE PTR [r13+0x0], dil
41 30 75 00 - xor BYTE PTR [r13+0x0], sil
41 30 07 - xor BYTE PTR [r15], al
41 30 1f - xor BYTE PTR [r15], bl
41 30 0f - xor BYTE PTR [r15], cl
41 30 17 - xor BYTE PTR [r15], dl
41 30 3f - xor BYTE PTR [r15], dil
41 30 37 - xor BYTE PTR [r15], sil
48 33 00 - xor rax, QWORD PTR [rax]
48 33 18 - xor rbx, QWORD PTR [rax]
48 33 08 - xor rcx, QWORD PTR [rax]
48 33 10 - xor rdx, QWORD PTR [rax]
48 33 38 - xor rdi, QWORD PTR [rax]
48 33 30 - xor rsi, QWORD PTR [rax]
48 33 20 - xor rsp, QWORD PTR [rax]
48 33 28 - xor rbp, QWORD PTR [rax]
4c 33 00 - xor r8, QWORD PTR [rax]
4c 33 08 - xor r9, QWORD PTR [rax]
4c 33 10 - xor r10, QWORD PTR [rax]
4c 33 18 - xor r11, QWORD PTR [rax]
4c 33 20 - xor r12, QWORD PTR [rax]
4c 33 28 - xor r13, QWORD PTR [rax]
4c 33 30 - xor r14, QWORD PTR [rax]
4c 33 38 - xor r15, QWORD PTR [rax]
33 00 - xor eax, DWORD PTR [rax]
33 18 - xor ebx, DWORD PTR [rax]
33 08 - xor ecx, DWORD PTR [rax]
33 10 - xor edx, DWORD PTR [rax]
33 38 - xor edi, DWORD PTR [rax]
33 30 - xor esi, DWORD PTR [rax]
33 20 - xor esp, DWORD PTR [rax]
33 28 - xor ebp, DWORD PTR [rax]
66 33 00 - xor ax, WORD PTR [rax]
66 33 18 - xor bx, WORD PTR [rax]
66 33 08 - xor cx, WORD PTR [rax]
66 33 10 - xor dx, WORD PTR [rax]
66 33 20 - xor sp, WORD PTR [rax]
66 33 28 - xor bp, WORD PTR [rax]
32 03 - xor al, BYTE PTR [rbx]
32 1b - xor bl, BYTE PTR [rbx]
32 0b - xor cl, BYTE PTR [rbx]
32 13 - xor dl, BYTE PTR [rbx]
32 23 - xor ah, BYTE PTR [rbx]
32 3b - xor bh, BYTE PTR [rbx]
32 2b - xor ch, BYTE PTR [rbx]
32 33 - xor dh, BYTE PTR [rbx]
32 01 - xor al, BYTE PTR [rcx]
32 19 - xor bl, BYTE PTR [rcx]
32 09 - xor cl, BYTE PTR [rcx]
32 11 - xor dl, BYTE PTR [rcx]
32 21 - xor ah, BYTE PTR [rcx]
32 39 - xor bh, BYTE PTR [rcx]
32 29 - xor ch, BYTE PTR [rcx]
32 31 - xor dh, BYTE PTR [rcx]
48 33 02 - xor rax, QWORD PTR [rdx]
48 33 1a - xor rbx, QWORD PTR [rdx]
48 33 0a - xor rcx, QWORD PTR [rdx]
48 33 12 - xor rdx, QWORD PTR [rdx]
48 33 3a - xor rdi, QWORD PTR [rdx]
48 33 32 - xor rsi, QWORD PTR [rdx]
48 33 22 - xor rsp, QWORD PTR [rdx]
48 33 2a - xor rbp, QWORD PTR [rdx]
4c 33 02 - xor r8, QWORD PTR [rdx]
4c 33 0a - xor r9, QWORD PTR [rdx]
4c 33 12 - xor r10, QWORD PTR [rdx]
4c 33 1a - xor r11, QWORD PTR [rdx]
4c 33 22 - xor r12, QWORD PTR [rdx]
4c 33 2a - xor r13, QWORD PTR [rdx]
4c 33 32 - xor r14, QWORD PTR [rdx]
4c 33 3a - xor r15, QWORD PTR [rdx]
33 02 - xor eax, DWORD PTR [rdx]
33 1a - xor ebx, DWORD PTR [rdx]
33 0a - xor ecx, DWORD PTR [rdx]
33 12 - xor edx, DWORD PTR [rdx]
33 3a - xor edi, DWORD PTR [rdx]
33 32 - xor esi, DWORD PTR [rdx]
33 22 - xor esp, DWORD PTR [rdx]
33 2a - xor ebp, DWORD PTR [rdx]
66 33 02 - xor ax, WORD PTR [rdx]
66 33 1a - xor bx, WORD PTR [rdx]
66 33 0a - xor cx, WORD PTR [rdx]
66 33 12 - xor dx, WORD PTR [rdx]
66 33 22 - xor sp, WORD PTR [rdx]
66 33 2a - xor bp, WORD PTR [rdx]
32 07 - xor al, BYTE PTR [rdi]
32 1f - xor bl, BYTE PTR [rdi]
32 0f - xor cl, BYTE PTR [rdi]
32 17 - xor dl, BYTE PTR [rdi]
32 27 - xor ah, BYTE PTR [rdi]
32 3f - xor bh, BYTE PTR [rdi]
32 2f - xor ch, BYTE PTR [rdi]
32 37 - xor dh, BYTE PTR [rdi]
48 33 06 - xor rax, QWORD PTR [rsi]
48 33 1e - xor rbx, QWORD PTR [rsi]
48 33 0e - xor rcx, QWORD PTR [rsi]
48 33 16 - xor rdx, QWORD PTR [rsi]
48 33 3e - xor rdi, QWORD PTR [rsi]
48 33 36 - xor rsi, QWORD PTR [rsi]
48 33 26 - xor rsp, QWORD PTR [rsi]
48 33 2e - xor rbp, QWORD PTR [rsi]
4c 33 06 - xor r8, QWORD PTR [rsi]
4c 33 0e - xor r9, QWORD PTR [rsi]
4c 33 16 - xor r10, QWORD PTR [rsi]
4c 33 1e - xor r11, QWORD PTR [rsi]
4c 33 26 - xor r12, QWORD PTR [rsi]
4c 33 2e - xor r13, QWORD PTR [rsi]
4c 33 36 - xor r14, QWORD PTR [rsi]
4c 33 3e - xor r15, QWORD PTR [rsi]
33 06 - xor eax, DWORD PTR [rsi]
33 1e - xor ebx, DWORD PTR [rsi]
33 0e - xor ecx, DWORD PTR [rsi]
33 16 - xor edx, DWORD PTR [rsi]
33 3e - xor edi, DWORD PTR [rsi]
33 36 - xor esi, DWORD PTR [rsi]
33 26 - xor esp, DWORD PTR [rsi]
33 2e - xor ebp, DWORD PTR [rsi]
66 33 06 - xor ax, WORD PTR [rsi]
66 33 1e - xor bx, WORD PTR [rsi]
66 33 0e - xor cx, WORD PTR [rsi]
66 33 16 - xor dx, WORD PTR [rsi]
66 33 26 - xor sp, WORD PTR [rsi]
66 33 2e - xor bp, WORD PTR [rsi]
32 45 00 - xor al, BYTE PTR [rbp+0x0]
32 5d 00 - xor bl, BYTE PTR [rbp+0x0]
32 4d 00 - xor cl, BYTE PTR [rbp+0x0]
32 55 00 - xor dl, BYTE PTR [rbp+0x0]
32 65 00 - xor ah, BYTE PTR [rbp+0x0]
32 7d 00 - xor bh, BYTE PTR [rbp+0x0]
32 6d 00 - xor ch, BYTE PTR [rbp+0x0]
32 75 00 - xor dh, BYTE PTR [rbp+0x0]
41 32 01 - xor al, BYTE PTR [r9]
41 32 19 - xor bl, BYTE PTR [r9]
41 32 09 - xor cl, BYTE PTR [r9]
41 32 11 - xor dl, BYTE PTR [r9]
41 32 39 - xor dil, BYTE PTR [r9]
41 32 31 - xor sil, BYTE PTR [r9]
41 32 03 - xor al, BYTE PTR [r11]
41 32 1b - xor bl, BYTE PTR [r11]
41 32 0b - xor cl, BYTE PTR [r11]
41 32 13 - xor dl, BYTE PTR [r11]
41 32 3b - xor dil, BYTE PTR [r11]
41 32 33 - xor sil, BYTE PTR [r11]
41 32 45 00 - xor al, BYTE PTR [r13+0x0]
41 32 5d 00 - xor bl, BYTE PTR [r13+0x0]
41 32 4d 00 - xor cl, BYTE PTR [r13+0x0]
41 32 55 00 - xor dl, BYTE PTR [r13+0x0]
41 32 7d 00 - xor dil, BYTE PTR [r13+0x0]
41 32 75 00 - xor sil, BYTE PTR [r13+0x0]
41 32 07 - xor al, BYTE PTR [r15]
41 32 1f - xor bl, BYTE PTR [r15]
41 32 0f - xor cl, BYTE PTR [r15]
41 32 17 - xor dl, BYTE PTR [r15]
41 32 3f - xor dil, BYTE PTR [r15]
41 32 37 - xor sil, BYTE PTR [r15]




48 21 c0 - and rax, rax
48 21 d8 - and rax, rbx
48 21 c8 - and rax, rcx
48 21 d0 - and rax, rdx
48 21 f8 - and rax, rdi
48 21 f0 - and rax, rsi
48 21 e0 - and rax, rsp
48 21 e8 - and rax, rbp
4c 21 c0 - and rax, r8
4c 21 c8 - and rax, r9
4c 21 d0 - and rax, r10
4c 21 d8 - and rax, r11
4c 21 e0 - and rax, r12
4c 21 e8 - and rax, r13
4c 21 f0 - and rax, r14
4c 21 f8 - and rax, r15
48 21 c2 - and rdx, rax
48 21 da - and rdx, rbx
48 21 ca - and rdx, rcx
48 21 d2 - and rdx, rdx
48 21 fa - and rdx, rdi
48 21 f2 - and rdx, rsi
48 21 e2 - and rdx, rsp
48 21 ea - and rdx, rbp
4c 21 c2 - and rdx, r8
4c 21 ca - and rdx, r9
4c 21 d2 - and rdx, r10
4c 21 da - and rdx, r11
4c 21 e2 - and rdx, r12
4c 21 ea - and rdx, r13
4c 21 f2 - and rdx, r14
4c 21 fa - and rdx, r15
48 21 c6 - and rsi, rax
48 21 de - and rsi, rbx
48 21 ce - and rsi, rcx
48 21 d6 - and rsi, rdx
48 21 fe - and rsi, rdi
48 21 f6 - and rsi, rsi
48 21 e6 - and rsi, rsp
48 21 ee - and rsi, rbp
4c 21 c6 - and rsi, r8
4c 21 ce - and rsi, r9
4c 21 d6 - and rsi, r10
4c 21 de - and rsi, r11
4c 21 e6 - and rsi, r12
4c 21 ee - and rsi, r13
4c 21 f6 - and rsi, r14
4c 21 fe - and rsi, r15
48 21 c4 - and rsp, rax
48 21 dc - and rsp, rbx
48 21 cc - and rsp, rcx
48 21 d4 - and rsp, rdx
48 21 fc - and rsp, rdi
48 21 f4 - and rsp, rsi
48 21 e4 - and rsp, rsp
48 21 ec - and rsp, rbp
4c 21 c4 - and rsp, r8
4c 21 cc - and rsp, r9
4c 21 d4 - and rsp, r10
4c 21 dc - and rsp, r11
4c 21 e4 - and rsp, r12
4c 21 ec - and rsp, r13
4c 21 f4 - and rsp, r14
4c 21 fc - and rsp, r15
21 c0 - and eax, eax
21 d8 - and eax, ebx
21 c8 - and eax, ecx
21 d0 - and eax, edx
21 f8 - and eax, edi
21 f0 - and eax, esi
21 e0 - and eax, esp
21 e8 - and eax, ebp
21 c2 - and edx, eax
21 da - and edx, ebx
21 ca - and edx, ecx
21 d2 - and edx, edx
21 fa - and edx, edi
21 f2 - and edx, esi
21 e2 - and edx, esp
21 ea - and edx, ebp
21 c6 - and esi, eax
21 de - and esi, ebx
21 ce - and esi, ecx
21 d6 - and esi, edx
21 fe - and esi, edi
21 f6 - and esi, esi
21 e6 - and esi, esp
21 ee - and esi, ebp
21 c4 - and esp, eax
21 dc - and esp, ebx
21 cc - and esp, ecx
21 d4 - and esp, edx
21 fc - and esp, edi
21 f4 - and esp, esi
21 e4 - and esp, esp
21 ec - and esp, ebp
66 21 c0 - and ax, ax
66 21 d8 - and ax, bx
66 21 c8 - and ax, cx
66 21 d0 - and ax, dx
66 21 e0 - and ax, sp
66 21 e8 - and ax, bp
66 21 c2 - and dx, ax
66 21 da - and dx, bx
66 21 ca - and dx, cx
66 21 d2 - and dx, dx
66 21 e2 - and dx, sp
66 21 ea - and dx, bp
66 21 c4 - and sp, ax
66 21 dc - and sp, bx
66 21 cc - and sp, cx
66 21 d4 - and sp, dx
66 21 e4 - and sp, sp
66 21 ec - and sp, bp
20 c3 - and bl, al
20 db - and bl, bl
20 cb - and bl, cl
20 d3 - and bl, dl
20 e3 - and bl, ah
20 fb - and bl, bh
20 eb - and bl, ch
20 f3 - and bl, dh
20 c1 - and cl, al
20 d9 - and cl, bl
20 c9 - and cl, cl
20 d1 - and cl, dl
20 e1 - and cl, ah
20 f9 - and cl, bh
20 e9 - and cl, ch
20 f1 - and cl, dh
20 c7 - and bh, al
20 df - and bh, bl
20 cf - and bh, cl
20 d7 - and bh, dl
20 e7 - and bh, ah
20 ff - and bh, bh
20 ef - and bh, ch
20 f7 - and bh, dh
20 c5 - and ch, al
20 dd - and ch, bl
20 cd - and ch, cl
20 d5 - and ch, dl
20 e5 - and ch, ah
20 fd - and ch, bh
20 ed - and ch, ch
20 f5 - and ch, dh
80 e3 7e - and bl, 0x7e
80 e1 7e - and cl, 0x7e
80 e7 7e - and bh, 0x7e
80 e5 7e - and ch, 0x7e
48 83 e0 7f - and rax, 0x7f
48 83 e2 7f - and rdx, 0x7f
48 83 e6 7f - and rsi, 0x7f
48 83 e4 7f - and rsp, 0x7f
83 e0 7f - and eax, 0x7f
83 e2 7f - and edx, 0x7f
83 e6 7f - and esi, 0x7f
83 e4 7f - and esp, 0x7f
66 83 e0 7f - and ax, 0x7f
66 83 e2 7f - and dx, 0x7f
66 83 e4 7f - and sp, 0x7f
24 7f - and al, 0x7f
48 21 00 - and QWORD PTR [rax], rax
48 21 18 - and QWORD PTR [rax], rbx
48 21 08 - and QWORD PTR [rax], rcx
48 21 10 - and QWORD PTR [rax], rdx
48 21 38 - and QWORD PTR [rax], rdi
48 21 30 - and QWORD PTR [rax], rsi
48 21 20 - and QWORD PTR [rax], rsp
48 21 28 - and QWORD PTR [rax], rbp
4c 21 00 - and QWORD PTR [rax], r8
4c 21 08 - and QWORD PTR [rax], r9
4c 21 10 - and QWORD PTR [rax], r10
4c 21 18 - and QWORD PTR [rax], r11
4c 21 20 - and QWORD PTR [rax], r12
4c 21 28 - and QWORD PTR [rax], r13
4c 21 30 - and QWORD PTR [rax], r14
4c 21 38 - and QWORD PTR [rax], r15
21 00 - and DWORD PTR [rax], eax
21 18 - and DWORD PTR [rax], ebx
21 08 - and DWORD PTR [rax], ecx
21 10 - and DWORD PTR [rax], edx
21 38 - and DWORD PTR [rax], edi
21 30 - and DWORD PTR [rax], esi
21 20 - and DWORD PTR [rax], esp
21 28 - and DWORD PTR [rax], ebp
66 21 00 - and WORD PTR [rax], ax
66 21 18 - and WORD PTR [rax], bx
66 21 08 - and WORD PTR [rax], cx
66 21 10 - and WORD PTR [rax], dx
66 21 20 - and WORD PTR [rax], sp
66 21 28 - and WORD PTR [rax], bp
20 03 - and BYTE PTR [rbx], al
20 1b - and BYTE PTR [rbx], bl
20 0b - and BYTE PTR [rbx], cl
20 13 - and BYTE PTR [rbx], dl
20 23 - and BYTE PTR [rbx], ah
20 3b - and BYTE PTR [rbx], bh
20 2b - and BYTE PTR [rbx], ch
20 33 - and BYTE PTR [rbx], dh
20 01 - and BYTE PTR [rcx], al
20 19 - and BYTE PTR [rcx], bl
20 09 - and BYTE PTR [rcx], cl
20 11 - and BYTE PTR [rcx], dl
20 21 - and BYTE PTR [rcx], ah
20 39 - and BYTE PTR [rcx], bh
20 29 - and BYTE PTR [rcx], ch
20 31 - and BYTE PTR [rcx], dh
48 21 02 - and QWORD PTR [rdx], rax
48 21 1a - and QWORD PTR [rdx], rbx
48 21 0a - and QWORD PTR [rdx], rcx
48 21 12 - and QWORD PTR [rdx], rdx
48 21 3a - and QWORD PTR [rdx], rdi
48 21 32 - and QWORD PTR [rdx], rsi
48 21 22 - and QWORD PTR [rdx], rsp
48 21 2a - and QWORD PTR [rdx], rbp
4c 21 02 - and QWORD PTR [rdx], r8
4c 21 0a - and QWORD PTR [rdx], r9
4c 21 12 - and QWORD PTR [rdx], r10
4c 21 1a - and QWORD PTR [rdx], r11
4c 21 22 - and QWORD PTR [rdx], r12
4c 21 2a - and QWORD PTR [rdx], r13
4c 21 32 - and QWORD PTR [rdx], r14
4c 21 3a - and QWORD PTR [rdx], r15
21 02 - and DWORD PTR [rdx], eax
21 1a - and DWORD PTR [rdx], ebx
21 0a - and DWORD PTR [rdx], ecx
21 12 - and DWORD PTR [rdx], edx
21 3a - and DWORD PTR [rdx], edi
21 32 - and DWORD PTR [rdx], esi
21 22 - and DWORD PTR [rdx], esp
21 2a - and DWORD PTR [rdx], ebp
66 21 02 - and WORD PTR [rdx], ax
66 21 1a - and WORD PTR [rdx], bx
66 21 0a - and WORD PTR [rdx], cx
66 21 12 - and WORD PTR [rdx], dx
66 21 22 - and WORD PTR [rdx], sp
66 21 2a - and WORD PTR [rdx], bp
20 07 - and BYTE PTR [rdi], al
20 1f - and BYTE PTR [rdi], bl
20 0f - and BYTE PTR [rdi], cl
20 17 - and BYTE PTR [rdi], dl
20 27 - and BYTE PTR [rdi], ah
20 3f - and BYTE PTR [rdi], bh
20 2f - and BYTE PTR [rdi], ch
20 37 - and BYTE PTR [rdi], dh
48 21 06 - and QWORD PTR [rsi], rax
48 21 1e - and QWORD PTR [rsi], rbx
48 21 0e - and QWORD PTR [rsi], rcx
48 21 16 - and QWORD PTR [rsi], rdx
48 21 3e - and QWORD PTR [rsi], rdi
48 21 36 - and QWORD PTR [rsi], rsi
48 21 26 - and QWORD PTR [rsi], rsp
48 21 2e - and QWORD PTR [rsi], rbp
4c 21 06 - and QWORD PTR [rsi], r8
4c 21 0e - and QWORD PTR [rsi], r9
4c 21 16 - and QWORD PTR [rsi], r10
4c 21 1e - and QWORD PTR [rsi], r11
4c 21 26 - and QWORD PTR [rsi], r12
4c 21 2e - and QWORD PTR [rsi], r13
4c 21 36 - and QWORD PTR [rsi], r14
4c 21 3e - and QWORD PTR [rsi], r15
21 06 - and DWORD PTR [rsi], eax
21 1e - and DWORD PTR [rsi], ebx
21 0e - and DWORD PTR [rsi], ecx
21 16 - and DWORD PTR [rsi], edx
21 3e - and DWORD PTR [rsi], edi
21 36 - and DWORD PTR [rsi], esi
21 26 - and DWORD PTR [rsi], esp
21 2e - and DWORD PTR [rsi], ebp
66 21 06 - and WORD PTR [rsi], ax
66 21 1e - and WORD PTR [rsi], bx
66 21 0e - and WORD PTR [rsi], cx
66 21 16 - and WORD PTR [rsi], dx
66 21 26 - and WORD PTR [rsi], sp
66 21 2e - and WORD PTR [rsi], bp
20 45 00 - and BYTE PTR [rbp+0x0], al
20 5d 00 - and BYTE PTR [rbp+0x0], bl
20 4d 00 - and BYTE PTR [rbp+0x0], cl
20 55 00 - and BYTE PTR [rbp+0x0], dl
20 65 00 - and BYTE PTR [rbp+0x0], ah
20 7d 00 - and BYTE PTR [rbp+0x0], bh
20 6d 00 - and BYTE PTR [rbp+0x0], ch
20 75 00 - and BYTE PTR [rbp+0x0], dh
41 20 01 - and BYTE PTR [r9], al
41 20 19 - and BYTE PTR [r9], bl
41 20 09 - and BYTE PTR [r9], cl
41 20 11 - and BYTE PTR [r9], dl
41 20 39 - and BYTE PTR [r9], dil
41 20 31 - and BYTE PTR [r9], sil
41 20 03 - and BYTE PTR [r11], al
41 20 1b - and BYTE PTR [r11], bl
41 20 0b - and BYTE PTR [r11], cl
41 20 13 - and BYTE PTR [r11], dl
41 20 3b - and BYTE PTR [r11], dil
41 20 33 - and BYTE PTR [r11], sil
41 20 45 00 - and BYTE PTR [r13+0x0], al
41 20 5d 00 - and BYTE PTR [r13+0x0], bl
41 20 4d 00 - and BYTE PTR [r13+0x0], cl
41 20 55 00 - and BYTE PTR [r13+0x0], dl
41 20 7d 00 - and BYTE PTR [r13+0x0], dil
41 20 75 00 - and BYTE PTR [r13+0x0], sil
41 20 07 - and BYTE PTR [r15], al
41 20 1f - and BYTE PTR [r15], bl
41 20 0f - and BYTE PTR [r15], cl
41 20 17 - and BYTE PTR [r15], dl
41 20 3f - and BYTE PTR [r15], dil
41 20 37 - and BYTE PTR [r15], sil
48 23 00 - and rax, QWORD PTR [rax]
48 23 18 - and rbx, QWORD PTR [rax]
48 23 08 - and rcx, QWORD PTR [rax]
48 23 10 - and rdx, QWORD PTR [rax]
48 23 38 - and rdi, QWORD PTR [rax]
48 23 30 - and rsi, QWORD PTR [rax]
48 23 20 - and rsp, QWORD PTR [rax]
48 23 28 - and rbp, QWORD PTR [rax]
4c 23 00 - and r8, QWORD PTR [rax]
4c 23 08 - and r9, QWORD PTR [rax]
4c 23 10 - and r10, QWORD PTR [rax]
4c 23 18 - and r11, QWORD PTR [rax]
4c 23 20 - and r12, QWORD PTR [rax]
4c 23 28 - and r13, QWORD PTR [rax]
4c 23 30 - and r14, QWORD PTR [rax]
4c 23 38 - and r15, QWORD PTR [rax]
23 00 - and eax, DWORD PTR [rax]
23 18 - and ebx, DWORD PTR [rax]
23 08 - and ecx, DWORD PTR [rax]
23 10 - and edx, DWORD PTR [rax]
23 38 - and edi, DWORD PTR [rax]
23 30 - and esi, DWORD PTR [rax]
23 20 - and esp, DWORD PTR [rax]
23 28 - and ebp, DWORD PTR [rax]
66 23 00 - and ax, WORD PTR [rax]
66 23 18 - and bx, WORD PTR [rax]
66 23 08 - and cx, WORD PTR [rax]
66 23 10 - and dx, WORD PTR [rax]
66 23 20 - and sp, WORD PTR [rax]
66 23 28 - and bp, WORD PTR [rax]
22 03 - and al, BYTE PTR [rbx]
22 1b - and bl, BYTE PTR [rbx]
22 0b - and cl, BYTE PTR [rbx]
22 13 - and dl, BYTE PTR [rbx]
22 23 - and ah, BYTE PTR [rbx]
22 3b - and bh, BYTE PTR [rbx]
22 2b - and ch, BYTE PTR [rbx]
22 33 - and dh, BYTE PTR [rbx]
22 01 - and al, BYTE PTR [rcx]
22 19 - and bl, BYTE PTR [rcx]
22 09 - and cl, BYTE PTR [rcx]
22 11 - and dl, BYTE PTR [rcx]
22 21 - and ah, BYTE PTR [rcx]
22 39 - and bh, BYTE PTR [rcx]
22 29 - and ch, BYTE PTR [rcx]
22 31 - and dh, BYTE PTR [rcx]
48 23 02 - and rax, QWORD PTR [rdx]
48 23 1a - and rbx, QWORD PTR [rdx]
48 23 0a - and rcx, QWORD PTR [rdx]
48 23 12 - and rdx, QWORD PTR [rdx]
48 23 3a - and rdi, QWORD PTR [rdx]
48 23 32 - and rsi, QWORD PTR [rdx]
48 23 22 - and rsp, QWORD PTR [rdx]
48 23 2a - and rbp, QWORD PTR [rdx]
4c 23 02 - and r8, QWORD PTR [rdx]
4c 23 0a - and r9, QWORD PTR [rdx]
4c 23 12 - and r10, QWORD PTR [rdx]
4c 23 1a - and r11, QWORD PTR [rdx]
4c 23 22 - and r12, QWORD PTR [rdx]
4c 23 2a - and r13, QWORD PTR [rdx]
4c 23 32 - and r14, QWORD PTR [rdx]
4c 23 3a - and r15, QWORD PTR [rdx]
23 02 - and eax, DWORD PTR [rdx]
23 1a - and ebx, DWORD PTR [rdx]
23 0a - and ecx, DWORD PTR [rdx]
23 12 - and edx, DWORD PTR [rdx]
23 3a - and edi, DWORD PTR [rdx]
23 32 - and esi, DWORD PTR [rdx]
23 22 - and esp, DWORD PTR [rdx]
23 2a - and ebp, DWORD PTR [rdx]
66 23 02 - and ax, WORD PTR [rdx]
66 23 1a - and bx, WORD PTR [rdx]
66 23 0a - and cx, WORD PTR [rdx]
66 23 12 - and dx, WORD PTR [rdx]
66 23 22 - and sp, WORD PTR [rdx]
66 23 2a - and bp, WORD PTR [rdx]
22 07 - and al, BYTE PTR [rdi]
22 1f - and bl, BYTE PTR [rdi]
22 0f - and cl, BYTE PTR [rdi]
22 17 - and dl, BYTE PTR [rdi]
22 27 - and ah, BYTE PTR [rdi]
22 3f - and bh, BYTE PTR [rdi]
22 2f - and ch, BYTE PTR [rdi]
22 37 - and dh, BYTE PTR [rdi]
48 23 06 - and rax, QWORD PTR [rsi]
48 23 1e - and rbx, QWORD PTR [rsi]
48 23 0e - and rcx, QWORD PTR [rsi]
48 23 16 - and rdx, QWORD PTR [rsi]
48 23 3e - and rdi, QWORD PTR [rsi]
48 23 36 - and rsi, QWORD PTR [rsi]
48 23 26 - and rsp, QWORD PTR [rsi]
48 23 2e - and rbp, QWORD PTR [rsi]
4c 23 06 - and r8, QWORD PTR [rsi]
4c 23 0e - and r9, QWORD PTR [rsi]
4c 23 16 - and r10, QWORD PTR [rsi]
4c 23 1e - and r11, QWORD PTR [rsi]
4c 23 26 - and r12, QWORD PTR [rsi]
4c 23 2e - and r13, QWORD PTR [rsi]
4c 23 36 - and r14, QWORD PTR [rsi]
4c 23 3e - and r15, QWORD PTR [rsi]
23 06 - and eax, DWORD PTR [rsi]
23 1e - and ebx, DWORD PTR [rsi]
23 0e - and ecx, DWORD PTR [rsi]
23 16 - and edx, DWORD PTR [rsi]
23 3e - and edi, DWORD PTR [rsi]
23 36 - and esi, DWORD PTR [rsi]
23 26 - and esp, DWORD PTR [rsi]
23 2e - and ebp, DWORD PTR [rsi]
66 23 06 - and ax, WORD PTR [rsi]
66 23 1e - and bx, WORD PTR [rsi]
66 23 0e - and cx, WORD PTR [rsi]
66 23 16 - and dx, WORD PTR [rsi]
66 23 26 - and sp, WORD PTR [rsi]
66 23 2e - and bp, WORD PTR [rsi]
22 45 00 - and al, BYTE PTR [rbp+0x0]
22 5d 00 - and bl, BYTE PTR [rbp+0x0]
22 4d 00 - and cl, BYTE PTR [rbp+0x0]
22 55 00 - and dl, BYTE PTR [rbp+0x0]
22 65 00 - and ah, BYTE PTR [rbp+0x0]
22 7d 00 - and bh, BYTE PTR [rbp+0x0]
22 6d 00 - and ch, BYTE PTR [rbp+0x0]
22 75 00 - and dh, BYTE PTR [rbp+0x0]
41 22 01 - and al, BYTE PTR [r9]
41 22 19 - and bl, BYTE PTR [r9]
41 22 09 - and cl, BYTE PTR [r9]
41 22 11 - and dl, BYTE PTR [r9]
41 22 39 - and dil, BYTE PTR [r9]
41 22 31 - and sil, BYTE PTR [r9]
41 22 03 - and al, BYTE PTR [r11]
41 22 1b - and bl, BYTE PTR [r11]
41 22 0b - and cl, BYTE PTR [r11]
41 22 13 - and dl, BYTE PTR [r11]
41 22 3b - and dil, BYTE PTR [r11]
41 22 33 - and sil, BYTE PTR [r11]
41 22 45 00 - and al, BYTE PTR [r13+0x0]
41 22 5d 00 - and bl, BYTE PTR [r13+0x0]
41 22 4d 00 - and cl, BYTE PTR [r13+0x0]
41 22 55 00 - and dl, BYTE PTR [r13+0x0]
41 22 7d 00 - and dil, BYTE PTR [r13+0x0]
41 22 75 00 - and sil, BYTE PTR [r13+0x0]
41 22 07 - and al, BYTE PTR [r15]
41 22 1f - and bl, BYTE PTR [r15]
41 22 0f - and cl, BYTE PTR [r15]
41 22 17 - and dl, BYTE PTR [r15]
41 22 3f - and dil, BYTE PTR [r15]
41 22 37 - and sil, BYTE PTR [r15]




48 d3 e0 - shl rax, cl
48 d3 e2 - shl rdx, cl
48 d3 e6 - shl rsi, cl
48 d3 e4 - shl rsp, cl
d3 e0 - shl eax, cl
d3 e2 - shl edx, cl
d3 e6 - shl esi, cl
d3 e4 - shl esp, cl
66 d3 e0 - shl ax, cl
66 d3 e2 - shl dx, cl
66 d3 e4 - shl sp, cl
d2 e3 - shl bl, cl
d2 e1 - shl cl, cl
d2 e7 - shl bh, cl
d2 e5 - shl ch, cl
48 c1 e0 ff - shl rax, 0xff
48 c1 e2 ff - shl rdx, 0xff
48 c1 e6 ff - shl rsi, 0xff
48 c1 e4 ff - shl rsp, 0xff
c1 e0 ff - shl eax, 0xff
c1 e2 ff - shl edx, 0xff
c1 e6 ff - shl esi, 0xff
c1 e4 ff - shl esp, 0xff
66 c1 e0 ff - shl ax, 0xff
66 c1 e2 ff - shl dx, 0xff
66 c1 e4 ff - shl sp, 0xff

48 d3 e8 - shr rax, cl
48 d3 ea - shr rdx, cl
48 d3 ee - shr rsi, cl
48 d3 ec - shr rsp, cl
d3 e8 - shr eax, cl
d3 ea - shr edx, cl
d3 ee - shr esi, cl
d3 ec - shr esp, cl
66 d3 e8 - shr ax, cl
66 d3 ea - shr dx, cl
66 d3 ec - shr sp, cl
d2 eb - shr bl, cl
d2 e9 - shr cl, cl
d2 ef - shr bh, cl
d2 ed - shr ch, cl
48 c1 e8 ff - shr rax, 0xff
48 c1 ea ff - shr rdx, 0xff
48 c1 ee ff - shr rsi, 0xff
48 c1 ec ff - shr rsp, 0xff
c1 e8 ff - shr eax, 0xff
c1 ea ff - shr edx, 0xff
c1 ee ff - shr esi, 0xff
c1 ec ff - shr esp, 0xff
66 c1 e8 ff - shr ax, 0xff
66 c1 ea ff - shr dx, 0xff
66 c1 ec ff - shr sp, 0xff

48 d3 c8 - ror rax, cl
48 d3 ca - ror rdx, cl
48 d3 ce - ror rsi, cl
48 d3 cc - ror rsp, cl
d3 c8 - ror eax, cl
d3 ca - ror edx, cl
d3 ce - ror esi, cl
d3 cc - ror esp, cl
66 d3 c8 - ror ax, cl
66 d3 ca - ror dx, cl
66 d3 cc - ror sp, cl
d2 cb - ror bl, cl
d2 c9 - ror cl, cl
d2 cf - ror bh, cl
d2 cd - ror ch, cl
48 c1 c8 ff - ror rax, 0xff
48 c1 ca ff - ror rdx, 0xff
48 c1 ce ff - ror rsi, 0xff
48 c1 cc ff - ror rsp, 0xff
c1 c8 ff - ror eax, 0xff
c1 ca ff - ror edx, 0xff
c1 ce ff - ror esi, 0xff
c1 cc ff - ror esp, 0xff
66 c1 c8 ff - ror ax, 0xff
66 c1 ca ff - ror dx, 0xff
66 c1 cc ff - ror sp, 0xff

48 d3 c0 - rol rax, cl
48 d3 c2 - rol rdx, cl
48 d3 c6 - rol rsi, cl
48 d3 c4 - rol rsp, cl
d3 c0 - rol eax, cl
d3 c2 - rol edx, cl
d3 c6 - rol esi, cl
d3 c4 - rol esp, cl
66 d3 c0 - rol ax, cl
66 d3 c2 - rol dx, cl
66 d3 c4 - rol sp, cl
d2 c3 - rol bl, cl
d2 c1 - rol cl, cl
d2 c7 - rol bh, cl
d2 c5 - rol ch, cl
48 c1 c0 ff - rol rax, 0xff
48 c1 c2 ff - rol rdx, 0xff
48 c1 c6 ff - rol rsi, 0xff
48 c1 c4 ff - rol rsp, 0xff
c1 c0 ff - rol eax, 0xff
c1 c2 ff - rol edx, 0xff
c1 c6 ff - rol esi, 0xff
c1 c4 ff - rol esp, 0xff
66 c1 c0 ff - rol ax, 0xff
66 c1 c2 ff - rol dx, 0xff
66 c1 c4 ff - rol sp, 0xff

41 50 - push r8
41 52 - push r10
41 54 - push r12
41 56 - push r14
41 50 - push r8
41 52 - push r10
41 54 - push r12
41 56 - push r14

41 58 - pop r8
41 5a - pop r10
41 5c - pop r12
41 5e - pop r14
41 58 - pop r8
41 5a - pop r10
41 5c - pop r12
41 5e - pop r14

48 ff c0 - inc rax
48 ff c2 - inc rdx
48 ff c6 - inc rsi
48 ff c4 - inc rsp
ff c0 - inc eax
ff c2 - inc edx
ff c6 - inc esi
ff c4 - inc esp
66 ff c0 - inc ax
66 ff c2 - inc dx
66 ff c4 - inc sp
fe c3 - inc bl
fe c1 - inc cl
fe c7 - inc bh
fe c5 - inc ch

48 ff c8 - dec rax
48 ff ca - dec rdx
48 ff ce - dec rsi
48 ff cc - dec rsp
ff c8 - dec eax
ff ca - dec edx
ff ce - dec esi
ff cc - dec esp
66 ff c8 - dec ax
66 ff ca - dec dx
66 ff cc - dec sp
fe cb - dec bl
fe c9 - dec cl
fe cf - dec bh
fe cd - dec ch
