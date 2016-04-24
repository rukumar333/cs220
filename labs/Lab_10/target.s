	.file	"target.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"Yech.... you failed to run the target."
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
.L2:
	call	getString
	movb	%al, 31(%esp)
	cmpb	$0, 31(%esp)
	jne	.L2
	movl	$.LC0, (%esp)
	call	puts
	movl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
.LC1:
	.string	"Read line: %s\n"
	.text
	.globl	getString
	.type	getString, @function
getString:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$120, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movb	$0, -93(%ebp)
	leal	-93(%ebp), %eax
	movl	%eax, (%esp)
	call	gets
	leal	-93(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	.L5
	leal	-93(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$1, %eax
	jmp	.L7
.L5:
	movl	$0, %eax
.L7:
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L8
	call	__stack_chk_fail
.L8:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	getString, .-getString
	.section	.rodata
	.align 4
.LC2:
	.string	"Whooopeeee... you ran the target!"
	.text
	.globl	target
	.type	target, @function
target:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC2, (%esp)
	call	puts
	movl	$0, (%esp)
	call	exit
	.cfi_endproc
.LFE4:
	.size	target, .-target
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
