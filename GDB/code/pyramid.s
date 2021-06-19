section .data
	STAR db '*'
	EMPTY db 0x0a

section .text
	global _start

_start:
	mov rax, 1 ; WRITE 시스템 콜 설정
	mov rdi, 1 ; 파일디스크립터(기본 출력)
	mov rdx, 1 ; 출력 길이
	mov r10, 0 ; 인덱스
	mov r9, [rsp +16] ; 입력 된 문자열 찾기

	cmp r9, 0; 입력이 없는 경우
	je _done ; 프로그램 종료

	mov cl, [r9] ; 한 바이트만 cl에 저장
	movzx r9, cl ; 문자 형태의 cl을 r9에 저장
	sub r9, 0x30 ; ascii 30 = '0'

	mov r8, r9
	xor r9, r9
	call _syscall

_small:
	cmp r10, r9
	je _up
	mov rsi, STAR ; 별 출력
	syscall
	mov rax, 1 ; WRITE 시스템 콜
	inc r10 ; j를 1 증가
	jmp _small ; 다시 출력

_up:
	cmp r9, r8 ; i == n인 경우
	je _down ; 내려가는 함수 실행
	mov rsi, EMPTY ; 줄바꿈
	syscall ; 출력 함수 실행
	mov rax, 1
	mov r10, 0
	add r9, 1
	jmp _small

_down:
	cmp r9, 0 ; i가 0이 된 경우
	je _done
	mov rsi, EMPTY ; 줄바꿈
	syscall
	mov rax, 1 ; WRITE 시스템 콜
	mov r10, 0 ; j 초기화
	sub r9, 1 ; i를 1 감소
	jmp _big ; 다시 출력

_big:
	cmp r10, r9 ; i == j
	je _down
	mov rsi, STAR ; 별 출력 
	syscall
	mov rax, 1
	inc r10
	jmp _big
_done: 
	mov rax, 60
	mov rdi, 0
	syscall

_syscall:
	syscall
	ret
