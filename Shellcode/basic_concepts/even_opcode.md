00 c0 - add al, al
00 d8 - add al, bl
00 c8 - add al, cl
00 d0 - add al, dl
00 e0 - add al, ah
00 f8 - add al, bh
00 e8 - add al, ch
00 f0 - add al, dh
40 00 f8 - add al, dil
40 00 f0 - add al, sil
00 c2 - add dl, al
00 da - add dl, bl
00 ca - add dl, cl
00 d2 - add dl, dl
00 e2 - add dl, ah
00 fa - add dl, bh
00 ea - add dl, ch
00 f2 - add dl, dh
40 00 fa - add dl, dil
40 00 f2 - add dl, sil
00 c4 - add ah, al
00 dc - add ah, bl
00 cc - add ah, cl
00 d4 - add ah, dl
00 e4 - add ah, ah
00 fc - add ah, bh
00 ec - add ah, ch
00 f4 - add ah, dh
00 c6 - add dh, al
00 de - add dh, bl
00 ce - add dh, cl
00 d6 - add dh, dl
00 e6 - add dh, ah
00 fe - add dh, bh
00 ee - add dh, ch
00 f6 - add dh, dh
40 00 c6 - add sil, al
40 00 de - add sil, bl
40 00 ce - add sil, cl
40 00 d6 - add sil, dl
40 00 fe - add sil, dil
40 00 f6 - add sil, sil
04 7e - add al, 0x7e
80 c2 7e - add dl, 0x7e
80 c4 7e - add ah, 0x7e
80 c6 7e - add dh, 0x7e
40 80 c6 7e - add sil, 0x7e
00 00 - add BYTE PTR [rax], al
00 18 - add BYTE PTR [rax], bl
00 08 - add BYTE PTR [rax], cl
00 10 - add BYTE PTR [rax], dl
00 20 - add BYTE PTR [rax], ah
00 38 - add BYTE PTR [rax], bh
00 28 - add BYTE PTR [rax], ch
00 30 - add BYTE PTR [rax], dh
40 00 38 - add BYTE PTR [rax], dil
40 00 30 - add BYTE PTR [rax], sil
00 02 - add BYTE PTR [rdx], al
00 1a - add BYTE PTR [rdx], bl
00 0a - add BYTE PTR [rdx], cl
00 12 - add BYTE PTR [rdx], dl
00 22 - add BYTE PTR [rdx], ah
00 3a - add BYTE PTR [rdx], bh
00 2a - add BYTE PTR [rdx], ch
00 32 - add BYTE PTR [rdx], dh
40 00 3a - add BYTE PTR [rdx], dil
40 00 32 - add BYTE PTR [rdx], sil
00 06 - add BYTE PTR [rsi], al
00 1e - add BYTE PTR [rsi], bl
00 0e - add BYTE PTR [rsi], cl
00 16 - add BYTE PTR [rsi], dl
00 26 - add BYTE PTR [rsi], ah
00 3e - add BYTE PTR [rsi], bh
00 2e - add BYTE PTR [rsi], ch
00 36 - add BYTE PTR [rsi], dh
40 00 3e - add BYTE PTR [rsi], dil
40 00 36 - add BYTE PTR [rsi], sil
00 04 24 - add BYTE PTR [rsp], al
00 1c 24 - add BYTE PTR [rsp], bl
00 0c 24 - add BYTE PTR [rsp], cl
00 14 24 - add BYTE PTR [rsp], dl
00 24 24 - add BYTE PTR [rsp], ah
00 3c 24 - add BYTE PTR [rsp], bh
00 2c 24 - add BYTE PTR [rsp], ch
00 34 24 - add BYTE PTR [rsp], dh
40 00 3c 24 - add BYTE PTR [rsp], dil
40 00 34 24 - add BYTE PTR [rsp], sil
02 00 - add al, BYTE PTR [rax]
02 18 - add bl, BYTE PTR [rax]
02 08 - add cl, BYTE PTR [rax]
02 10 - add dl, BYTE PTR [rax]
02 20 - add ah, BYTE PTR [rax]
02 38 - add bh, BYTE PTR [rax]
02 28 - add ch, BYTE PTR [rax]
02 30 - add dh, BYTE PTR [rax]
40 02 38 - add dil, BYTE PTR [rax]
40 02 30 - add sil, BYTE PTR [rax]
02 02 - add al, BYTE PTR [rdx]
02 1a - add bl, BYTE PTR [rdx]
02 0a - add cl, BYTE PTR [rdx]
02 12 - add dl, BYTE PTR [rdx]
02 22 - add ah, BYTE PTR [rdx]
02 3a - add bh, BYTE PTR [rdx]
02 2a - add ch, BYTE PTR [rdx]
02 32 - add dh, BYTE PTR [rdx]
40 02 3a - add dil, BYTE PTR [rdx]
40 02 32 - add sil, BYTE PTR [rdx]
02 06 - add al, BYTE PTR [rsi]
02 1e - add bl, BYTE PTR [rsi]
02 0e - add cl, BYTE PTR [rsi]
02 16 - add dl, BYTE PTR [rsi]
02 26 - add ah, BYTE PTR [rsi]
02 3e - add bh, BYTE PTR [rsi]
02 2e - add ch, BYTE PTR [rsi]
02 36 - add dh, BYTE PTR [rsi]
40 02 3e - add dil, BYTE PTR [rsi]
40 02 36 - add sil, BYTE PTR [rsi]
02 04 24 - add al, BYTE PTR [rsp]
02 1c 24 - add bl, BYTE PTR [rsp]
02 0c 24 - add cl, BYTE PTR [rsp]
02 14 24 - add dl, BYTE PTR [rsp]
02 24 24 - add ah, BYTE PTR [rsp]
02 3c 24 - add bh, BYTE PTR [rsp]
02 2c 24 - add ch, BYTE PTR [rsp]
02 34 24 - add dh, BYTE PTR [rsp]
40 02 3c 24 - add dil, BYTE PTR [rsp]
40 02 34 24 - add sil, BYTE PTR [rsp]




28 c0 - sub al, al
28 d8 - sub al, bl
28 c8 - sub al, cl
28 d0 - sub al, dl
28 e0 - sub al, ah
28 f8 - sub al, bh
28 e8 - sub al, ch
28 f0 - sub al, dh
40 28 f8 - sub al, dil
40 28 f0 - sub al, sil
28 c2 - sub dl, al
28 da - sub dl, bl
28 ca - sub dl, cl
28 d2 - sub dl, dl
28 e2 - sub dl, ah
28 fa - sub dl, bh
28 ea - sub dl, ch
28 f2 - sub dl, dh
40 28 fa - sub dl, dil
40 28 f2 - sub dl, sil
28 c4 - sub ah, al
28 dc - sub ah, bl
28 cc - sub ah, cl
28 d4 - sub ah, dl
28 e4 - sub ah, ah
28 fc - sub ah, bh
28 ec - sub ah, ch
28 f4 - sub ah, dh
28 c6 - sub dh, al
28 de - sub dh, bl
28 ce - sub dh, cl
28 d6 - sub dh, dl
28 e6 - sub dh, ah
28 fe - sub dh, bh
28 ee - sub dh, ch
28 f6 - sub dh, dh
40 28 c6 - sub sil, al
40 28 de - sub sil, bl
40 28 ce - sub sil, cl
40 28 d6 - sub sil, dl
40 28 fe - sub sil, dil
40 28 f6 - sub sil, sil
2c 7e - sub al, 0x7e
80 ea 7e - sub dl, 0x7e
80 ec 7e - sub ah, 0x7e
80 ee 7e - sub dh, 0x7e
40 80 ee 7e - sub sil, 0x7e
28 00 - sub BYTE PTR [rax], al
28 18 - sub BYTE PTR [rax], bl
28 08 - sub BYTE PTR [rax], cl
28 10 - sub BYTE PTR [rax], dl
28 20 - sub BYTE PTR [rax], ah
28 38 - sub BYTE PTR [rax], bh
28 28 - sub BYTE PTR [rax], ch
28 30 - sub BYTE PTR [rax], dh
40 28 38 - sub BYTE PTR [rax], dil
40 28 30 - sub BYTE PTR [rax], sil
28 02 - sub BYTE PTR [rdx], al
28 1a - sub BYTE PTR [rdx], bl
28 0a - sub BYTE PTR [rdx], cl
28 12 - sub BYTE PTR [rdx], dl
28 22 - sub BYTE PTR [rdx], ah
28 3a - sub BYTE PTR [rdx], bh
28 2a - sub BYTE PTR [rdx], ch
28 32 - sub BYTE PTR [rdx], dh
40 28 3a - sub BYTE PTR [rdx], dil
40 28 32 - sub BYTE PTR [rdx], sil
28 06 - sub BYTE PTR [rsi], al
28 1e - sub BYTE PTR [rsi], bl
28 0e - sub BYTE PTR [rsi], cl
28 16 - sub BYTE PTR [rsi], dl
28 26 - sub BYTE PTR [rsi], ah
28 3e - sub BYTE PTR [rsi], bh
28 2e - sub BYTE PTR [rsi], ch
28 36 - sub BYTE PTR [rsi], dh
40 28 3e - sub BYTE PTR [rsi], dil
40 28 36 - sub BYTE PTR [rsi], sil
28 04 24 - sub BYTE PTR [rsp], al
28 1c 24 - sub BYTE PTR [rsp], bl
28 0c 24 - sub BYTE PTR [rsp], cl
28 14 24 - sub BYTE PTR [rsp], dl
28 24 24 - sub BYTE PTR [rsp], ah
28 3c 24 - sub BYTE PTR [rsp], bh
28 2c 24 - sub BYTE PTR [rsp], ch
28 34 24 - sub BYTE PTR [rsp], dh
40 28 3c 24 - sub BYTE PTR [rsp], dil
40 28 34 24 - sub BYTE PTR [rsp], sil
2a 00 - sub al, BYTE PTR [rax]
2a 18 - sub bl, BYTE PTR [rax]
2a 08 - sub cl, BYTE PTR [rax]
2a 10 - sub dl, BYTE PTR [rax]
2a 20 - sub ah, BYTE PTR [rax]
2a 38 - sub bh, BYTE PTR [rax]
2a 28 - sub ch, BYTE PTR [rax]
2a 30 - sub dh, BYTE PTR [rax]
40 2a 38 - sub dil, BYTE PTR [rax]
40 2a 30 - sub sil, BYTE PTR [rax]
2a 02 - sub al, BYTE PTR [rdx]
2a 1a - sub bl, BYTE PTR [rdx]
2a 0a - sub cl, BYTE PTR [rdx]
2a 12 - sub dl, BYTE PTR [rdx]
2a 22 - sub ah, BYTE PTR [rdx]
2a 3a - sub bh, BYTE PTR [rdx]
2a 2a - sub ch, BYTE PTR [rdx]
2a 32 - sub dh, BYTE PTR [rdx]
40 2a 3a - sub dil, BYTE PTR [rdx]
40 2a 32 - sub sil, BYTE PTR [rdx]
2a 06 - sub al, BYTE PTR [rsi]
2a 1e - sub bl, BYTE PTR [rsi]
2a 0e - sub cl, BYTE PTR [rsi]
2a 16 - sub dl, BYTE PTR [rsi]
2a 26 - sub ah, BYTE PTR [rsi]
2a 3e - sub bh, BYTE PTR [rsi]
2a 2e - sub ch, BYTE PTR [rsi]
2a 36 - sub dh, BYTE PTR [rsi]
40 2a 3e - sub dil, BYTE PTR [rsi]
40 2a 36 - sub sil, BYTE PTR [rsi]
2a 04 24 - sub al, BYTE PTR [rsp]
2a 1c 24 - sub bl, BYTE PTR [rsp]
2a 0c 24 - sub cl, BYTE PTR [rsp]
2a 14 24 - sub dl, BYTE PTR [rsp]
2a 24 24 - sub ah, BYTE PTR [rsp]
2a 3c 24 - sub bh, BYTE PTR [rsp]
2a 2c 24 - sub ch, BYTE PTR [rsp]
2a 34 24 - sub dh, BYTE PTR [rsp]
40 2a 3c 24 - sub dil, BYTE PTR [rsp]
40 2a 34 24 - sub sil, BYTE PTR [rsp]




88 c0 - mov al, al
88 d8 - mov al, bl
88 c8 - mov al, cl
88 d0 - mov al, dl
88 e0 - mov al, ah
88 f8 - mov al, bh
88 e8 - mov al, ch
88 f0 - mov al, dh
40 88 f8 - mov al, dil
40 88 f0 - mov al, sil
88 c2 - mov dl, al
88 da - mov dl, bl
88 ca - mov dl, cl
88 d2 - mov dl, dl
88 e2 - mov dl, ah
88 fa - mov dl, bh
88 ea - mov dl, ch
88 f2 - mov dl, dh
40 88 fa - mov dl, dil
40 88 f2 - mov dl, sil
88 c4 - mov ah, al
88 dc - mov ah, bl
88 cc - mov ah, cl
88 d4 - mov ah, dl
88 e4 - mov ah, ah
88 fc - mov ah, bh
88 ec - mov ah, ch
88 f4 - mov ah, dh
88 c6 - mov dh, al
88 de - mov dh, bl
88 ce - mov dh, cl
88 d6 - mov dh, dl
88 e6 - mov dh, ah
88 fe - mov dh, bh
88 ee - mov dh, ch
88 f6 - mov dh, dh
40 88 c6 - mov sil, al
40 88 de - mov sil, bl
40 88 ce - mov sil, cl
40 88 d6 - mov sil, dl
40 88 fe - mov sil, dil
40 88 f6 - mov sil, sil
b8 7e 00 00 00 - mov eax, 0x7e
ba 7e 00 00 00 - mov edx, 0x7e
be 7e 00 00 00 - mov esi, 0x7e
bc 7e 00 00 00 - mov esp, 0x7e
66 b8 7e 00 - mov ax, 0x7e
66 ba 7e 00 - mov dx, 0x7e
66 bc 7e 00 - mov sp, 0x7e
b0 7e - mov al, 0x7e
b2 7e - mov dl, 0x7e
b4 7e - mov ah, 0x7e
b6 7e - mov dh, 0x7e
40 b6 7e - mov sil, 0x7e
88 00 - mov BYTE PTR [rax], al
88 18 - mov BYTE PTR [rax], bl
88 08 - mov BYTE PTR [rax], cl
88 10 - mov BYTE PTR [rax], dl
88 20 - mov BYTE PTR [rax], ah
88 38 - mov BYTE PTR [rax], bh
88 28 - mov BYTE PTR [rax], ch
88 30 - mov BYTE PTR [rax], dh
40 88 38 - mov BYTE PTR [rax], dil
40 88 30 - mov BYTE PTR [rax], sil
88 02 - mov BYTE PTR [rdx], al
88 1a - mov BYTE PTR [rdx], bl
88 0a - mov BYTE PTR [rdx], cl
88 12 - mov BYTE PTR [rdx], dl
88 22 - mov BYTE PTR [rdx], ah
88 3a - mov BYTE PTR [rdx], bh
88 2a - mov BYTE PTR [rdx], ch
88 32 - mov BYTE PTR [rdx], dh
40 88 3a - mov BYTE PTR [rdx], dil
40 88 32 - mov BYTE PTR [rdx], sil
88 06 - mov BYTE PTR [rsi], al
88 1e - mov BYTE PTR [rsi], bl
88 0e - mov BYTE PTR [rsi], cl
88 16 - mov BYTE PTR [rsi], dl
88 26 - mov BYTE PTR [rsi], ah
88 3e - mov BYTE PTR [rsi], bh
88 2e - mov BYTE PTR [rsi], ch
88 36 - mov BYTE PTR [rsi], dh
40 88 3e - mov BYTE PTR [rsi], dil
40 88 36 - mov BYTE PTR [rsi], sil
88 04 24 - mov BYTE PTR [rsp], al
88 1c 24 - mov BYTE PTR [rsp], bl
88 0c 24 - mov BYTE PTR [rsp], cl
88 14 24 - mov BYTE PTR [rsp], dl
88 24 24 - mov BYTE PTR [rsp], ah
88 3c 24 - mov BYTE PTR [rsp], bh
88 2c 24 - mov BYTE PTR [rsp], ch
88 34 24 - mov BYTE PTR [rsp], dh
40 88 3c 24 - mov BYTE PTR [rsp], dil
40 88 34 24 - mov BYTE PTR [rsp], sil
8a 00 - mov al, BYTE PTR [rax]
8a 18 - mov bl, BYTE PTR [rax]
8a 08 - mov cl, BYTE PTR [rax]
8a 10 - mov dl, BYTE PTR [rax]
8a 20 - mov ah, BYTE PTR [rax]
8a 38 - mov bh, BYTE PTR [rax]
8a 28 - mov ch, BYTE PTR [rax]
8a 30 - mov dh, BYTE PTR [rax]
40 8a 38 - mov dil, BYTE PTR [rax]
40 8a 30 - mov sil, BYTE PTR [rax]
8a 02 - mov al, BYTE PTR [rdx]
8a 1a - mov bl, BYTE PTR [rdx]
8a 0a - mov cl, BYTE PTR [rdx]
8a 12 - mov dl, BYTE PTR [rdx]
8a 22 - mov ah, BYTE PTR [rdx]
8a 3a - mov bh, BYTE PTR [rdx]
8a 2a - mov ch, BYTE PTR [rdx]
8a 32 - mov dh, BYTE PTR [rdx]
40 8a 3a - mov dil, BYTE PTR [rdx]
40 8a 32 - mov sil, BYTE PTR [rdx]
8a 06 - mov al, BYTE PTR [rsi]
8a 1e - mov bl, BYTE PTR [rsi]
8a 0e - mov cl, BYTE PTR [rsi]
8a 16 - mov dl, BYTE PTR [rsi]
8a 26 - mov ah, BYTE PTR [rsi]
8a 3e - mov bh, BYTE PTR [rsi]
8a 2e - mov ch, BYTE PTR [rsi]
8a 36 - mov dh, BYTE PTR [rsi]
40 8a 3e - mov dil, BYTE PTR [rsi]
40 8a 36 - mov sil, BYTE PTR [rsi]
8a 04 24 - mov al, BYTE PTR [rsp]
8a 1c 24 - mov bl, BYTE PTR [rsp]
8a 0c 24 - mov cl, BYTE PTR [rsp]
8a 14 24 - mov dl, BYTE PTR [rsp]
8a 24 24 - mov ah, BYTE PTR [rsp]
8a 3c 24 - mov bh, BYTE PTR [rsp]
8a 2c 24 - mov ch, BYTE PTR [rsp]
8a 34 24 - mov dh, BYTE PTR [rsp]
40 8a 3c 24 - mov dil, BYTE PTR [rsp]
40 8a 34 24 - mov sil, BYTE PTR [rsp]




30 c0 - xor al, al
30 d8 - xor al, bl
30 c8 - xor al, cl
30 d0 - xor al, dl
30 e0 - xor al, ah
30 f8 - xor al, bh
30 e8 - xor al, ch
30 f0 - xor al, dh
40 30 f8 - xor al, dil
40 30 f0 - xor al, sil
30 c2 - xor dl, al
30 da - xor dl, bl
30 ca - xor dl, cl
30 d2 - xor dl, dl
30 e2 - xor dl, ah
30 fa - xor dl, bh
30 ea - xor dl, ch
30 f2 - xor dl, dh
40 30 fa - xor dl, dil
40 30 f2 - xor dl, sil
30 c4 - xor ah, al
30 dc - xor ah, bl
30 cc - xor ah, cl
30 d4 - xor ah, dl
30 e4 - xor ah, ah
30 fc - xor ah, bh
30 ec - xor ah, ch
30 f4 - xor ah, dh
30 c6 - xor dh, al
30 de - xor dh, bl
30 ce - xor dh, cl
30 d6 - xor dh, dl
30 e6 - xor dh, ah
30 fe - xor dh, bh
30 ee - xor dh, ch
30 f6 - xor dh, dh
40 30 c6 - xor sil, al
40 30 de - xor sil, bl
40 30 ce - xor sil, cl
40 30 d6 - xor sil, dl
40 30 fe - xor sil, dil
40 30 f6 - xor sil, sil
34 7e - xor al, 0x7e
80 f2 7e - xor dl, 0x7e
80 f4 7e - xor ah, 0x7e
80 f6 7e - xor dh, 0x7e
40 80 f6 7e - xor sil, 0x7e
30 00 - xor BYTE PTR [rax], al
30 18 - xor BYTE PTR [rax], bl
30 08 - xor BYTE PTR [rax], cl
30 10 - xor BYTE PTR [rax], dl
30 20 - xor BYTE PTR [rax], ah
30 38 - xor BYTE PTR [rax], bh
30 28 - xor BYTE PTR [rax], ch
30 30 - xor BYTE PTR [rax], dh
40 30 38 - xor BYTE PTR [rax], dil
40 30 30 - xor BYTE PTR [rax], sil
30 02 - xor BYTE PTR [rdx], al
30 1a - xor BYTE PTR [rdx], bl
30 0a - xor BYTE PTR [rdx], cl
30 12 - xor BYTE PTR [rdx], dl
30 22 - xor BYTE PTR [rdx], ah
30 3a - xor BYTE PTR [rdx], bh
30 2a - xor BYTE PTR [rdx], ch
30 32 - xor BYTE PTR [rdx], dh
40 30 3a - xor BYTE PTR [rdx], dil
40 30 32 - xor BYTE PTR [rdx], sil
30 06 - xor BYTE PTR [rsi], al
30 1e - xor BYTE PTR [rsi], bl
30 0e - xor BYTE PTR [rsi], cl
30 16 - xor BYTE PTR [rsi], dl
30 26 - xor BYTE PTR [rsi], ah
30 3e - xor BYTE PTR [rsi], bh
30 2e - xor BYTE PTR [rsi], ch
30 36 - xor BYTE PTR [rsi], dh
40 30 3e - xor BYTE PTR [rsi], dil
40 30 36 - xor BYTE PTR [rsi], sil
30 04 24 - xor BYTE PTR [rsp], al
30 1c 24 - xor BYTE PTR [rsp], bl
30 0c 24 - xor BYTE PTR [rsp], cl
30 14 24 - xor BYTE PTR [rsp], dl
30 24 24 - xor BYTE PTR [rsp], ah
30 3c 24 - xor BYTE PTR [rsp], bh
30 2c 24 - xor BYTE PTR [rsp], ch
30 34 24 - xor BYTE PTR [rsp], dh
40 30 3c 24 - xor BYTE PTR [rsp], dil
40 30 34 24 - xor BYTE PTR [rsp], sil
32 00 - xor al, BYTE PTR [rax]
32 18 - xor bl, BYTE PTR [rax]
32 08 - xor cl, BYTE PTR [rax]
32 10 - xor dl, BYTE PTR [rax]
32 20 - xor ah, BYTE PTR [rax]
32 38 - xor bh, BYTE PTR [rax]
32 28 - xor ch, BYTE PTR [rax]
32 30 - xor dh, BYTE PTR [rax]
40 32 38 - xor dil, BYTE PTR [rax]
40 32 30 - xor sil, BYTE PTR [rax]
32 02 - xor al, BYTE PTR [rdx]
32 1a - xor bl, BYTE PTR [rdx]
32 0a - xor cl, BYTE PTR [rdx]
32 12 - xor dl, BYTE PTR [rdx]
32 22 - xor ah, BYTE PTR [rdx]
32 3a - xor bh, BYTE PTR [rdx]
32 2a - xor ch, BYTE PTR [rdx]
32 32 - xor dh, BYTE PTR [rdx]
40 32 3a - xor dil, BYTE PTR [rdx]
40 32 32 - xor sil, BYTE PTR [rdx]
32 06 - xor al, BYTE PTR [rsi]
32 1e - xor bl, BYTE PTR [rsi]
32 0e - xor cl, BYTE PTR [rsi]
32 16 - xor dl, BYTE PTR [rsi]
32 26 - xor ah, BYTE PTR [rsi]
32 3e - xor bh, BYTE PTR [rsi]
32 2e - xor ch, BYTE PTR [rsi]
32 36 - xor dh, BYTE PTR [rsi]
40 32 3e - xor dil, BYTE PTR [rsi]
40 32 36 - xor sil, BYTE PTR [rsi]
32 04 24 - xor al, BYTE PTR [rsp]
32 1c 24 - xor bl, BYTE PTR [rsp]
32 0c 24 - xor cl, BYTE PTR [rsp]
32 14 24 - xor dl, BYTE PTR [rsp]
32 24 24 - xor ah, BYTE PTR [rsp]
32 3c 24 - xor bh, BYTE PTR [rsp]
32 2c 24 - xor ch, BYTE PTR [rsp]
32 34 24 - xor dh, BYTE PTR [rsp]
40 32 3c 24 - xor dil, BYTE PTR [rsp]
40 32 34 24 - xor sil, BYTE PTR [rsp]




08 c0 - or al, al
08 d8 - or al, bl
08 c8 - or al, cl
08 d0 - or al, dl
08 e0 - or al, ah
08 f8 - or al, bh
08 e8 - or al, ch
08 f0 - or al, dh
40 08 f8 - or al, dil
40 08 f0 - or al, sil
08 c2 - or dl, al
08 da - or dl, bl
08 ca - or dl, cl
08 d2 - or dl, dl
08 e2 - or dl, ah
08 fa - or dl, bh
08 ea - or dl, ch
08 f2 - or dl, dh
40 08 fa - or dl, dil
40 08 f2 - or dl, sil
08 c4 - or ah, al
08 dc - or ah, bl
08 cc - or ah, cl
08 d4 - or ah, dl
08 e4 - or ah, ah
08 fc - or ah, bh
08 ec - or ah, ch
08 f4 - or ah, dh
08 c6 - or dh, al
08 de - or dh, bl
08 ce - or dh, cl
08 d6 - or dh, dl
08 e6 - or dh, ah
08 fe - or dh, bh
08 ee - or dh, ch
08 f6 - or dh, dh
40 08 c6 - or sil, al
40 08 de - or sil, bl
40 08 ce - or sil, cl
40 08 d6 - or sil, dl
40 08 fe - or sil, dil
40 08 f6 - or sil, sil
0c 7e - or al, 0x7e
80 ca 7e - or dl, 0x7e
80 cc 7e - or ah, 0x7e
80 ce 7e - or dh, 0x7e
40 80 ce 7e - or sil, 0x7e
08 00 - or BYTE PTR [rax], al
08 18 - or BYTE PTR [rax], bl
08 08 - or BYTE PTR [rax], cl
08 10 - or BYTE PTR [rax], dl
08 20 - or BYTE PTR [rax], ah
08 38 - or BYTE PTR [rax], bh
08 28 - or BYTE PTR [rax], ch
08 30 - or BYTE PTR [rax], dh
40 08 38 - or BYTE PTR [rax], dil
40 08 30 - or BYTE PTR [rax], sil
08 02 - or BYTE PTR [rdx], al
08 1a - or BYTE PTR [rdx], bl
08 0a - or BYTE PTR [rdx], cl
08 12 - or BYTE PTR [rdx], dl
08 22 - or BYTE PTR [rdx], ah
08 3a - or BYTE PTR [rdx], bh
08 2a - or BYTE PTR [rdx], ch
08 32 - or BYTE PTR [rdx], dh
40 08 3a - or BYTE PTR [rdx], dil
40 08 32 - or BYTE PTR [rdx], sil
08 06 - or BYTE PTR [rsi], al
08 1e - or BYTE PTR [rsi], bl
08 0e - or BYTE PTR [rsi], cl
08 16 - or BYTE PTR [rsi], dl
08 26 - or BYTE PTR [rsi], ah
08 3e - or BYTE PTR [rsi], bh
08 2e - or BYTE PTR [rsi], ch
08 36 - or BYTE PTR [rsi], dh
40 08 3e - or BYTE PTR [rsi], dil
40 08 36 - or BYTE PTR [rsi], sil
08 04 24 - or BYTE PTR [rsp], al
08 1c 24 - or BYTE PTR [rsp], bl
08 0c 24 - or BYTE PTR [rsp], cl
08 14 24 - or BYTE PTR [rsp], dl
08 24 24 - or BYTE PTR [rsp], ah
08 3c 24 - or BYTE PTR [rsp], bh
08 2c 24 - or BYTE PTR [rsp], ch
08 34 24 - or BYTE PTR [rsp], dh
40 08 3c 24 - or BYTE PTR [rsp], dil
40 08 34 24 - or BYTE PTR [rsp], sil
0a 00 - or al, BYTE PTR [rax]
0a 18 - or bl, BYTE PTR [rax]
0a 08 - or cl, BYTE PTR [rax]
0a 10 - or dl, BYTE PTR [rax]
0a 20 - or ah, BYTE PTR [rax]
0a 38 - or bh, BYTE PTR [rax]
0a 28 - or ch, BYTE PTR [rax]
0a 30 - or dh, BYTE PTR [rax]
40 0a 38 - or dil, BYTE PTR [rax]
40 0a 30 - or sil, BYTE PTR [rax]
0a 02 - or al, BYTE PTR [rdx]
0a 1a - or bl, BYTE PTR [rdx]
0a 0a - or cl, BYTE PTR [rdx]
0a 12 - or dl, BYTE PTR [rdx]
0a 22 - or ah, BYTE PTR [rdx]
0a 3a - or bh, BYTE PTR [rdx]
0a 2a - or ch, BYTE PTR [rdx]
0a 32 - or dh, BYTE PTR [rdx]
40 0a 3a - or dil, BYTE PTR [rdx]
40 0a 32 - or sil, BYTE PTR [rdx]
0a 06 - or al, BYTE PTR [rsi]
0a 1e - or bl, BYTE PTR [rsi]
0a 0e - or cl, BYTE PTR [rsi]
0a 16 - or dl, BYTE PTR [rsi]
0a 26 - or ah, BYTE PTR [rsi]
0a 3e - or bh, BYTE PTR [rsi]
0a 2e - or ch, BYTE PTR [rsi]
0a 36 - or dh, BYTE PTR [rsi]
40 0a 3e - or dil, BYTE PTR [rsi]
40 0a 36 - or sil, BYTE PTR [rsi]
0a 04 24 - or al, BYTE PTR [rsp]
0a 1c 24 - or bl, BYTE PTR [rsp]
0a 0c 24 - or cl, BYTE PTR [rsp]
0a 14 24 - or dl, BYTE PTR [rsp]
0a 24 24 - or ah, BYTE PTR [rsp]
0a 3c 24 - or bh, BYTE PTR [rsp]
0a 2c 24 - or ch, BYTE PTR [rsp]
0a 34 24 - or dh, BYTE PTR [rsp]
40 0a 3c 24 - or dil, BYTE PTR [rsp]
40 0a 34 24 - or sil, BYTE PTR [rsp]




20 c0 - and al, al
20 d8 - and al, bl
20 c8 - and al, cl
20 d0 - and al, dl
20 e0 - and al, ah
20 f8 - and al, bh
20 e8 - and al, ch
20 f0 - and al, dh
40 20 f8 - and al, dil
40 20 f0 - and al, sil
20 c2 - and dl, al
20 da - and dl, bl
20 ca - and dl, cl
20 d2 - and dl, dl
20 e2 - and dl, ah
20 fa - and dl, bh
20 ea - and dl, ch
20 f2 - and dl, dh
40 20 fa - and dl, dil
40 20 f2 - and dl, sil
20 c4 - and ah, al
20 dc - and ah, bl
20 cc - and ah, cl
20 d4 - and ah, dl
20 e4 - and ah, ah
20 fc - and ah, bh
20 ec - and ah, ch
20 f4 - and ah, dh
20 c6 - and dh, al
20 de - and dh, bl
20 ce - and dh, cl
20 d6 - and dh, dl
20 e6 - and dh, ah
20 fe - and dh, bh
20 ee - and dh, ch
20 f6 - and dh, dh
40 20 c6 - and sil, al
40 20 de - and sil, bl
40 20 ce - and sil, cl
40 20 d6 - and sil, dl
40 20 fe - and sil, dil
40 20 f6 - and sil, sil
24 7e - and al, 0x7e
80 e2 7e - and dl, 0x7e
80 e4 7e - and ah, 0x7e
80 e6 7e - and dh, 0x7e
40 80 e6 7e - and sil, 0x7e
20 00 - and BYTE PTR [rax], al
20 18 - and BYTE PTR [rax], bl
20 08 - and BYTE PTR [rax], cl
20 10 - and BYTE PTR [rax], dl
20 20 - and BYTE PTR [rax], ah
20 38 - and BYTE PTR [rax], bh
20 28 - and BYTE PTR [rax], ch
20 30 - and BYTE PTR [rax], dh
40 20 38 - and BYTE PTR [rax], dil
40 20 30 - and BYTE PTR [rax], sil
20 02 - and BYTE PTR [rdx], al
20 1a - and BYTE PTR [rdx], bl
20 0a - and BYTE PTR [rdx], cl
20 12 - and BYTE PTR [rdx], dl
20 22 - and BYTE PTR [rdx], ah
20 3a - and BYTE PTR [rdx], bh
20 2a - and BYTE PTR [rdx], ch
20 32 - and BYTE PTR [rdx], dh
40 20 3a - and BYTE PTR [rdx], dil
40 20 32 - and BYTE PTR [rdx], sil
20 06 - and BYTE PTR [rsi], al
20 1e - and BYTE PTR [rsi], bl
20 0e - and BYTE PTR [rsi], cl
20 16 - and BYTE PTR [rsi], dl
20 26 - and BYTE PTR [rsi], ah
20 3e - and BYTE PTR [rsi], bh
20 2e - and BYTE PTR [rsi], ch
20 36 - and BYTE PTR [rsi], dh
40 20 3e - and BYTE PTR [rsi], dil
40 20 36 - and BYTE PTR [rsi], sil
20 04 24 - and BYTE PTR [rsp], al
20 1c 24 - and BYTE PTR [rsp], bl
20 0c 24 - and BYTE PTR [rsp], cl
20 14 24 - and BYTE PTR [rsp], dl
20 24 24 - and BYTE PTR [rsp], ah
20 3c 24 - and BYTE PTR [rsp], bh
20 2c 24 - and BYTE PTR [rsp], ch
20 34 24 - and BYTE PTR [rsp], dh
40 20 3c 24 - and BYTE PTR [rsp], dil
40 20 34 24 - and BYTE PTR [rsp], sil
22 00 - and al, BYTE PTR [rax]
22 18 - and bl, BYTE PTR [rax]
22 08 - and cl, BYTE PTR [rax]
22 10 - and dl, BYTE PTR [rax]
22 20 - and ah, BYTE PTR [rax]
22 38 - and bh, BYTE PTR [rax]
22 28 - and ch, BYTE PTR [rax]
22 30 - and dh, BYTE PTR [rax]
40 22 38 - and dil, BYTE PTR [rax]
40 22 30 - and sil, BYTE PTR [rax]
22 02 - and al, BYTE PTR [rdx]
22 1a - and bl, BYTE PTR [rdx]
22 0a - and cl, BYTE PTR [rdx]
22 12 - and dl, BYTE PTR [rdx]
22 22 - and ah, BYTE PTR [rdx]
22 3a - and bh, BYTE PTR [rdx]
22 2a - and ch, BYTE PTR [rdx]
22 32 - and dh, BYTE PTR [rdx]
40 22 3a - and dil, BYTE PTR [rdx]
40 22 32 - and sil, BYTE PTR [rdx]
22 06 - and al, BYTE PTR [rsi]
22 1e - and bl, BYTE PTR [rsi]
22 0e - and cl, BYTE PTR [rsi]
22 16 - and dl, BYTE PTR [rsi]
22 26 - and ah, BYTE PTR [rsi]
22 3e - and bh, BYTE PTR [rsi]
22 2e - and ch, BYTE PTR [rsi]
22 36 - and dh, BYTE PTR [rsi]
40 22 3e - and dil, BYTE PTR [rsi]
40 22 36 - and sil, BYTE PTR [rsi]
22 04 24 - and al, BYTE PTR [rsp]
22 1c 24 - and bl, BYTE PTR [rsp]
22 0c 24 - and cl, BYTE PTR [rsp]
22 14 24 - and dl, BYTE PTR [rsp]
22 24 24 - and ah, BYTE PTR [rsp]
22 3c 24 - and bh, BYTE PTR [rsp]
22 2c 24 - and ch, BYTE PTR [rsp]
22 34 24 - and dh, BYTE PTR [rsp]
40 22 3c 24 - and dil, BYTE PTR [rsp]
40 22 34 24 - and sil, BYTE PTR [rsp]




48 92 - xchg rdx, rax
48 96 - xchg rsi, rax
48 94 - xchg rsp, rax
92 - xchg edx, eax
96 - xchg esi, eax
94 - xchg esp, eax
66 90 - xchg ax, ax
66 92 - xchg dx, ax
66 94 - xchg sp, ax
86 c0 - xchg al, al
86 d8 - xchg al, bl
86 c8 - xchg al, cl
86 d0 - xchg al, dl
86 e0 - xchg al, ah
86 f8 - xchg al, bh
86 e8 - xchg al, ch
86 f0 - xchg al, dh
40 86 f8 - xchg al, dil
40 86 f0 - xchg al, sil
86 d2 - xchg dl, dl
86 e2 - xchg dl, ah
86 fa - xchg dl, bh
86 ea - xchg dl, ch
86 f2 - xchg dl, dh
40 86 fa - xchg dl, dil
40 86 f2 - xchg dl, sil
86 e4 - xchg ah, ah
86 fc - xchg ah, bh
86 ec - xchg ah, ch
86 f4 - xchg ah, dh
86 f6 - xchg dh, dh
40 86 f6 - xchg sil, sil
86 00 - xchg BYTE PTR [rax], al
86 18 - xchg BYTE PTR [rax], bl
86 08 - xchg BYTE PTR [rax], cl
86 10 - xchg BYTE PTR [rax], dl
86 20 - xchg BYTE PTR [rax], ah
86 38 - xchg BYTE PTR [rax], bh
86 28 - xchg BYTE PTR [rax], ch
86 30 - xchg BYTE PTR [rax], dh
40 86 38 - xchg BYTE PTR [rax], dil
40 86 30 - xchg BYTE PTR [rax], sil
86 02 - xchg BYTE PTR [rdx], al
86 1a - xchg BYTE PTR [rdx], bl
86 0a - xchg BYTE PTR [rdx], cl
86 12 - xchg BYTE PTR [rdx], dl
86 22 - xchg BYTE PTR [rdx], ah
86 3a - xchg BYTE PTR [rdx], bh
86 2a - xchg BYTE PTR [rdx], ch
86 32 - xchg BYTE PTR [rdx], dh
40 86 3a - xchg BYTE PTR [rdx], dil
40 86 32 - xchg BYTE PTR [rdx], sil
86 06 - xchg BYTE PTR [rsi], al
86 1e - xchg BYTE PTR [rsi], bl
86 0e - xchg BYTE PTR [rsi], cl
86 16 - xchg BYTE PTR [rsi], dl
86 26 - xchg BYTE PTR [rsi], ah
86 3e - xchg BYTE PTR [rsi], bh
86 2e - xchg BYTE PTR [rsi], ch
86 36 - xchg BYTE PTR [rsi], dh
40 86 3e - xchg BYTE PTR [rsi], dil
40 86 36 - xchg BYTE PTR [rsi], sil
86 04 24 - xchg BYTE PTR [rsp], al
86 1c 24 - xchg BYTE PTR [rsp], bl
86 0c 24 - xchg BYTE PTR [rsp], cl
86 14 24 - xchg BYTE PTR [rsp], dl
86 24 24 - xchg BYTE PTR [rsp], ah
86 3c 24 - xchg BYTE PTR [rsp], bh
86 2c 24 - xchg BYTE PTR [rsp], ch
86 34 24 - xchg BYTE PTR [rsp], dh
40 86 3c 24 - xchg BYTE PTR [rsp], dil
40 86 34 24 - xchg BYTE PTR [rsp], sil




d2 e0 - shl al, cl
d2 e2 - shl dl, cl
d2 e4 - shl ah, cl
d2 e6 - shl dh, cl
40 d2 e6 - shl sil, cl
d2 e8 - shr al, cl
d2 ea - shr dl, cl
d2 ec - shr ah, cl
d2 ee - shr dh, cl
40 d2 ee - shr sil, cl

fe c8 - dec al
fe ca - dec dl
fe cc - dec ah
fe ce - dec dh
40 fe ce - dec sil

fe c0 - inc al
fe c2 - inc dl
fe c4 - inc ah
fe c6 - inc dh
40 fe c6 - inc sil

50 - push rax
52 - push rdx
56 - push rsi
54 - push rsp
50 - push rax
52 - push rdx
56 - push rsi
54 - push rsp
68 80 00 00 00 - push 0x80
68 08 18 08 08 - push 0x8081808
58 - pop rax
5a - pop rdx
5e - pop rsi
5c - pop rsp
58 - pop rax
5a - pop rdx
5e - pop rsi
5c - pop rsp
