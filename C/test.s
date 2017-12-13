   1              		.arch armv6-m
   2              		.eabi_attribute 20, 1
   3              		.eabi_attribute 21, 1
   4              		.eabi_attribute 23, 3
   5              		.eabi_attribute 24, 1
   6              		.eabi_attribute 25, 1
   7              		.eabi_attribute 26, 1
   8              		.eabi_attribute 30, 6
   9              		.eabi_attribute 34, 0
  10              		.eabi_attribute 18, 4
  11              		.file	"gpio.c"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.align	1
  16              		.global	set_up_DIL
  17              		.syntax unified
  18              		.code	16
  19              		.thumb_func
  20              		.fpu softvfp
  22              	set_up_DIL:
  23              	.LFB0:
  24              		.file 1 "C:/mop/c/Moplaborationer/DIPs-Witch/C/gpio.c"
   1:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** #include "gpio.h"
   2:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 
   3:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** /** Sets up PE0-7 as inports and PE8-15 as outports. */
   4:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** void set_up_DIL( void ) {
  25              		.loc 1 4 0
  26              		.cfi_startproc
  27              		@ args = 0, pretend = 0, frame = 0
  28              		@ frame_needed = 1, uses_anonymous_args = 0
  29 0000 80B5     		push	{r7, lr}
  30              		.cfi_def_cfa_offset 8
  31              		.cfi_offset 7, -8
  32              		.cfi_offset 14, -4
  33 0002 00AF     		add	r7, sp, #0
  34              		.cfi_def_cfa_register 7
   5:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 	GPIO_D.Moder = 0x55550000;
  35              		.loc 1 5 0
  36 0004 024B     		ldr	r3, .L2
  37 0006 034A     		ldr	r2, .L2+4
  38 0008 1A60     		str	r2, [r3]
   6:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** }
  39              		.loc 1 6 0
  40 000a C046     		nop
  41 000c BD46     		mov	sp, r7
  42              		@ sp needed
  43 000e 80BD     		pop	{r7, pc}
  44              	.L3:
  45              		.align	2
  46              	.L2:
  47 0010 000C0240 		.word	1073875968
  48 0014 00005555 		.word	1431633920
  49              		.cfi_endproc
  50              	.LFE0:
  52              		.align	1
  53              		.global	read_DIL
  54              		.syntax unified
  55              		.code	16
  56              		.thumb_func
  57              		.fpu softvfp
  59              	read_DIL:
  60              	.LFB1:
   7:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 
   8:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** char read_DIL( void ) {
  61              		.loc 1 8 0
  62              		.cfi_startproc
  63              		@ args = 0, pretend = 0, frame = 0
  64              		@ frame_needed = 1, uses_anonymous_args = 0
  65 0018 80B5     		push	{r7, lr}
  66              		.cfi_def_cfa_offset 8
  67              		.cfi_offset 7, -8
  68              		.cfi_offset 14, -4
  69 001a 00AF     		add	r7, sp, #0
  70              		.cfi_def_cfa_register 7
   9:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 	GPIO_D.idrHigh = GPIO_D.idrLow; //Show on bargraph
  71              		.loc 1 9 0
  72 001c 054B     		ldr	r3, .L6
  73 001e 054A     		ldr	r2, .L6
  74 0020 127C     		ldrb	r2, [r2, #16]
  75 0022 D2B2     		uxtb	r2, r2
  76 0024 5A74     		strb	r2, [r3, #17]
  10:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 	return GPIO_D.idrLow;
  77              		.loc 1 10 0
  78 0026 034B     		ldr	r3, .L6
  79 0028 1B7C     		ldrb	r3, [r3, #16]
  80 002a DBB2     		uxtb	r3, r3
  11:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** }
  81              		.loc 1 11 0
  82 002c 1800     		movs	r0, r3
  83 002e BD46     		mov	sp, r7
  84              		@ sp needed
  85 0030 80BD     		pop	{r7, pc}
  86              	.L7:
  87 0032 C046     		.align	2
  88              	.L6:
  89 0034 000C0240 		.word	1073875968
  90              		.cfi_endproc
  91              	.LFE1:
  93              		.align	1
  94              		.global	read_DIL_single
  95              		.syntax unified
  96              		.code	16
  97              		.thumb_func
  98              		.fpu softvfp
 100              	read_DIL_single:
 101              	.LFB2:
  12:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 
  13:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 
  14:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** int read_DIL_single( int bit ) {
 102              		.loc 1 14 0
 103              		.cfi_startproc
 104              		@ args = 0, pretend = 0, frame = 16
 105              		@ frame_needed = 1, uses_anonymous_args = 0
 106 0038 90B5     		push	{r4, r7, lr}
 107              		.cfi_def_cfa_offset 12
 108              		.cfi_offset 4, -12
 109              		.cfi_offset 7, -8
 110              		.cfi_offset 14, -4
 111 003a 85B0     		sub	sp, sp, #20
 112              		.cfi_def_cfa_offset 32
 113 003c 00AF     		add	r7, sp, #0
 114              		.cfi_def_cfa_register 7
 115 003e 7860     		str	r0, [r7, #4]
  15:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 	char DIL = read_DIL();
 116              		.loc 1 15 0
 117 0040 0F23     		movs	r3, #15
 118 0042 FC18     		adds	r4, r7, r3
 119 0044 FFF7FEFF 		bl	read_DIL
 120 0048 0300     		movs	r3, r0
 121 004a 2370     		strb	r3, [r4]
  16:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 	if (DIL & (1<<bit)) {
 122              		.loc 1 16 0
 123 004c 0F23     		movs	r3, #15
 124 004e FB18     		adds	r3, r7, r3
 125 0050 1A78     		ldrb	r2, [r3]
 126 0052 7B68     		ldr	r3, [r7, #4]
 127 0054 1A41     		asrs	r2, r2, r3
 128 0056 1300     		movs	r3, r2
 129 0058 0122     		movs	r2, #1
 130 005a 1340     		ands	r3, r2
 131 005c 01D0     		beq	.L9
  17:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 		return 1;
 132              		.loc 1 17 0
 133 005e 0123     		movs	r3, #1
 134 0060 00E0     		b	.L10
 135              	.L9:
  18:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 	} else {
  19:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 		return 0;
 136              		.loc 1 19 0
 137 0062 0023     		movs	r3, #0
 138              	.L10:
  20:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** 	}
  21:C:/mop/c/Moplaborationer/DIPs-Witch/C\gpio.c **** }...
 139              		.loc 1 21 0
 140 0064 1800     		movs	r0, r3
 141 0066 BD46     		mov	sp, r7
 142 0068 05B0     		add	sp, sp, #20
 143              		@ sp needed
 144 006a 90BD     		pop	{r4, r7, pc}
 145              		.cfi_endproc
 146              	.LFE2:
 148              	.Letext0:
 149              		.file 2 "C:/mop/c/Moplaborationer/DIPs-Witch/C/gpio.h"
