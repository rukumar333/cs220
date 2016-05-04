	.file	"hack.c"
	.text
	.globl	alterGrades
	.type	alterGrades, @function
alterGrades:
.LFB0:
	.cfi_startproc

	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$284, %esp
	movl	$0x0804c8c0, %eax
	movl	$90, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$400, %eax
	movl	$80, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$800, %eax
	movl	$90, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$1200, %eax
	movl	$100, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$1600, %eax
	movl	$9, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$2000, %eax
	movl	$9, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$2400, %eax
	movl	$9, 64(%eax)
	movl	$7, -4(%ebp)
	movl	-4(%ebp), %eax
	imull	$400, %eax, %edx
	movl	$0x0804c8c0, %eax
	addl	%edx, %eax
	movl	$9, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$3200, %eax
	movl	$95, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$3600, %eax
	movl	$95, 64(%eax)
	movl	$0x0804c8c0, %eax
	addl	$4000, %eax
	movl	$93, 64(%eax)
	addl	$284, %esp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	pushl	$0x08048792
	ret
	.cfi_endproc
.LFE0:
	.size	alterGrades, .-alterGrades
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
