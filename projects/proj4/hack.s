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
	movl	$0x0, %edi
	movl	$0x0, %esi
	movl	$0x5570aff4, %ebx
	movl	$0x804b780, %eax
	movl	$100, 64(%eax)
	movl	$0x804b780, %eax
	addl	$400, %eax
	movl	$100, 64(%eax)
	movl	$0x804b780, %eax
	addl	$800, %eax
	movl	$100, 64(%eax)
	movl	$0x804b780, %eax
	addl	$1200, %eax
	movl	$100, 64(%eax)
	movl	$0x804b780, %eax
	addl	$1600, %eax
	movl	$9, 64(%eax)
	addl	$1, 64(%eax)
	movl	$0x804b780, %eax
	addl	$2000, %eax
	movl	$9, 64(%eax)
	addl	$1, 64(%eax)	
	movl	$0x804b780, %eax
	addl	$2400, %eax
	movl	$9, 64(%eax)
	addl	$1, 64(%eax)	
	movl	$0, %eax
	movl	$9, 0x804c2b0(%eax)
	addl	$1, 0x804c2b0(%eax)
	movl	$0x804b780, %eax
	addl	$3200, %eax
	movl	$100, 64(%eax)
	movl	$0x804b780, %eax
	addl	$3600, %eax
	movl	$100, 64(%eax)
	movl	$0x804b780, %eax
	addl	$4000, %eax
	movl	$100, 64(%eax)
	movl	$0x804b000, %eax
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	pushl	$0x08048792
	ret
	
	.cfi_endproc
.LFE0:
	.size	alterGrades, .-alterGrades
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
