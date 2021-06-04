# 🔍 Disassembly
### 리버싱 공부용이고 선행되는 기초 지식은 TIL로 정리
- - -

```
main()

   0x0000000000001180 <+0>:     endbr64 
   0x0000000000001184 <+4>:     push   rbp                      ; rbp는 스택의 시작 주소를 가르킴(함수의 시작)
   0x0000000000001185 <+5>:     mov    rbp,rsp                  ; rbp와 rsp의 값을 같게 만듦(rsp에 rbp의 값을 덮음)
   0x0000000000001188 <+8>:     sub    rsp,0x10                 ; rsp는 현재 스택의 시작 주소를 가지고 있기 때문에 10(16)을 빼서 16byte만큼의 공간 생성
   0x000000000000118c <+12>:    mov    DWORD PTR [rbp-0xc],0x5  ; 스택의 시작 주소로부터 12만큼 떨어진 곳에 5할당 (a = 5)
   0x0000000000001193 <+19>:    mov    DWORD PTR [rbp-0x8],0xa  ; 스택의 시작 주소로부터 8만큼 떨어진 곳에 10할당 (b = 10)
   0x000000000000119a <+26>:    mov    edx,DWORD PTR [rbp-0xc]  ; edx에 5 할당
   0x000000000000119d <+29>:    mov    eax,DWORD PTR [rbp-0x8]  ; eax에 10 할당 ( 연산을 위해 레지스터에 각각 값 할당)
   0x00000000000011a0 <+32>:    add    eax,edx                  ; eax에 eax와 edx를 더한 값을 저장
   0x00000000000011a2 <+34>:    mov    DWORD PTR [rbp-0x4],eax  ; 스택의 시작 주소로부터 4만큼 떨어진 곳에 연산 결과를 저장 (c = a + b)
   0x00000000000011a5 <+37>:    mov    eax,DWORD PTR [rbp-0x4]
   0x00000000000011a8 <+40>:    mov    edi,eax                  ; 매개변수로 쓸 수 있게 edi에 eax 할당 (loopingFunc(c))
   0x00000000000011aa <+42>:    call   0x1149 <loopingFunc>     ; 함수 호출
   0x00000000000011af <+47>:    mov    eax,0x0                  ; return 0
   0x00000000000011b4 <+52>:    leave                           ; 스택 프레임 종료
   0x00000000000011b5 <+53>:    ret                             ; 종료
```

```
loopingFunc()

   0x0000000000001149 <+0>:     endbr64 
   0x000000000000114d <+4>:     push   rbp
   0x000000000000114e <+5>:     mov    rbp,rsp                          ; - 여기까지 main과 동일
   0x0000000000001151 <+8>:     sub    rsp,0x20                         ; 20byte만큼 공간 생성
   0x0000000000001155 <+12>:    mov    DWORD PTR [rbp-0x14],edi         ; 14만큼 떨어진 곳에 edi 할당 (매개변수 c 받음)
   0x0000000000001158 <+15>:    cmp    DWORD PTR [rbp-0x14],0xf         ; 받은 값과 15를 비교
   0x000000000000115c <+19>:    jne    0x117d <loopingFunc+52>          ; 값이 같지 않다면 nop으로 이동(사실상 종료)
   0x000000000000115e <+21>:    mov    DWORD PTR [rbp-0x4],0x0          ; 스택의 시작 주소로부터 4만큼 떨어진 곳에 0 핧당 (int i = 0)
   0x0000000000001165 <+28>:    jmp    0x1177 <loopingFunc+46>          ; cmp    DWORD PTR [rbp-0x4],0x2으로 이동
   0x0000000000001167 <+30>:    lea    rdi,[rip+0xe96]        # 0x2004
   0x000000000000116e <+37>:    call   0x1050 <puts@plt>                ; printf함수 호출
   0x0000000000001173 <+42>:    add    DWORD PTR [rbp-0x4],0x1          ; i++
   0x0000000000001177 <+46>:    cmp    DWORD PTR [rbp-0x4],0x2          ; i와 2가 같은지 비교
   0x000000000000117b <+50>:    jle    0x1167 <loopingFunc+30>          ; 같거나 작을경우 lea   rdi,[rip+0xe96]으로 이동 (i < 3)
   0x000000000000117d <+52>:    nop
   0x000000000000117e <+53>:    leave                                   ; main과 같음
   0x000000000000117f <+54>:    ret                                     ; call로 함수를 부른 main 다음 명령줄로 이동
```