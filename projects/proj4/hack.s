	.file	"hack.c"
	.text
	.globl	alterGrades
	.type	alterGrades, @function
alterGrades:
.LFB0:
	.cfi_startproc
	movl 	$0xffffcfd8, %ebp
	movl	$0xffffce1b, %esp
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
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
	movl	$7, -4(%ebp)
	movl	-4(%ebp), %eax
	imull	$400, %eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
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
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	movl 	$0xffffcfb0, %esp
	movl	$0x55747000, %ebx
	addl	-0x4, %esp
	movl 	$0x08048792, (%esp)
	ret
	.cfi_endproc
.LFE0:
	.size	alterGrades, .-alterGrades
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
