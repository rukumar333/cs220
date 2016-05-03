	.file	"hack.c"
	.text
	.globl	alterGrades
	.type	alterGrades, @function
alterGrades:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	$90, 64(%eax)
	movl	8(%ebp), %eax
	addl	$400, %eax
	movl	$80, 64(%eax)
	movl	8(%ebp), %eax
	addl	$800, %eax
	movl	$90, 64(%eax)
	movl	8(%ebp), %eax
	addl	$1200, %eax
	movl	$100, 64(%eax)
	movl	8(%ebp), %eax
	addl	$1600, %eax
	movl	$9, 64(%eax)
	movl	8(%ebp), %eax
	addl	$2000, %eax
	movl	$9, 64(%eax)
	movl	8(%ebp), %eax
	addl	$2400, %eax
	movl	$9, 64(%eax)
	movl	8(%ebp), %eax
	addl	$2800, %eax
	movl	$9, 64(%eax)
	movl	8(%ebp), %eax
	addl	$3200, %eax
	movl	$95, 64(%eax)
	movl	8(%ebp), %eax
	addl	$3600, %eax
	movl	$95, 64(%eax)
	movl	8(%ebp), %eax
	addl	$4000, %eax
	movl	$93, 64(%eax)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	alterGrades, .-alterGrades
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
