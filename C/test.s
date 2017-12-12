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
  11              		.file	"player.c"
  12              		.text
  13              	.Ltext0:
  14              		.cfi_sections	.debug_frame
  15              		.global	__aeabi_idivmod
  16              		.align	1
  17              		.global	playerUpdate
  18              		.syntax unified
  19              		.code	16
  20              		.thumb_func
  21              		.fpu softvfp
  23              	playerUpdate:
  24              	.LFB0:
  25              		.file 1 "C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C/player.c"
   1:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** #include "gpio.h"
   2:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** #include "controls.h"
   3:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** #include "gameobject.h"
   4:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** #include "player.h"
   5:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 
   6:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** void playerUpdate(GameObject *this) {
  26              		.loc 1 6 0
  27              		.cfi_startproc
  28              		@ args = 0, pretend = 0, frame = 8
  29              		@ frame_needed = 1, uses_anonymous_args = 0
  30 0000 80B5     		push	{r7, lr}
  31              		.cfi_def_cfa_offset 8
  32              		.cfi_offset 7, -8
  33              		.cfi_offset 14, -4
  34 0002 82B0     		sub	sp, sp, #8
  35              		.cfi_def_cfa_offset 16
  36 0004 00AF     		add	r7, sp, #0
  37              		.cfi_def_cfa_register 7
  38 0006 7860     		str	r0, [r7, #4]
   7:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	this->animation_counter++;
  39              		.loc 1 7 0
  40 0008 7B68     		ldr	r3, [r7, #4]
  41 000a 1B6A     		ldr	r3, [r3, #32]
  42 000c 5A1C     		adds	r2, r3, #1
  43 000e 7B68     		ldr	r3, [r7, #4]
  44 0010 1A62     		str	r2, [r3, #32]
   8:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	if (this->animation_counter == this->animation_speed) {
  45              		.loc 1 8 0
  46 0012 7B68     		ldr	r3, [r7, #4]
  47 0014 1A6A     		ldr	r2, [r3, #32]
  48 0016 7B68     		ldr	r3, [r7, #4]
  49 0018 DB69     		ldr	r3, [r3, #28]
  50 001a 9A42     		cmp	r2, r3
  51 001c 0FD1     		bne	.L2
   9:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 		this->animation_counter = 0;
  52              		.loc 1 9 0
  53 001e 7B68     		ldr	r3, [r7, #4]
  54 0020 0022     		movs	r2, #0
  55 0022 1A62     		str	r2, [r3, #32]
  10:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 		this->current_frame = (this->current_frame + 1) % this->n_frames;
  56              		.loc 1 10 0
  57 0024 7B68     		ldr	r3, [r7, #4]
  58 0026 5B69     		ldr	r3, [r3, #20]
  59 0028 5A1C     		adds	r2, r3, #1
  60 002a 7B68     		ldr	r3, [r7, #4]
  61 002c 9B69     		ldr	r3, [r3, #24]
  62 002e 1900     		movs	r1, r3
  63 0030 1000     		movs	r0, r2
  64 0032 FFF7FEFF 		bl	__aeabi_idivmod
  65              	.LVL0:
  66 0036 0B00     		movs	r3, r1
  67 0038 1A00     		movs	r2, r3
  68 003a 7B68     		ldr	r3, [r7, #4]
  69 003c 5A61     		str	r2, [r3, #20]
  70              	.L2:
  11:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	}
  12:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	
  13:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	static lastRightValue = 0;
  14:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	static lastLeftValue = 0; 
  15:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	static speed = 0;
  16:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	
  17:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	if (!lastRightValue && read_DIL_single(RIGHT_TRIGGER)){
  71              		.loc 1 17 0
  72 003e 234B     		ldr	r3, .L7
  73 0040 1B68     		ldr	r3, [r3]
  74 0042 002B     		cmp	r3, #0
  75 0044 09D1     		bne	.L3
  76              		.loc 1 17 0 is_stmt 0 discriminator 1
  77 0046 0020     		movs	r0, #0
  78 0048 FFF7FEFF 		bl	read_DIL_single
  79 004c 031E     		subs	r3, r0, #0
  80 004e 04D0     		beq	.L3
  18:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 		speed += SPEED_ADD;
  81              		.loc 1 18 0 is_stmt 1
  82 0050 1F4B     		ldr	r3, .L7+4
  83 0052 1B68     		ldr	r3, [r3]
  84 0054 DA1C     		adds	r2, r3, #3
  85 0056 1E4B     		ldr	r3, .L7+4
  86 0058 1A60     		str	r2, [r3]
  87              	.L3:
  19:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	}
  20:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	
  21:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	if (!lastLeftValue && read_DIL_single(LEFT_TRIGGER)){
  88              		.loc 1 21 0
  89 005a 1E4B     		ldr	r3, .L7+8
  90 005c 1B68     		ldr	r3, [r3]
  91 005e 002B     		cmp	r3, #0
  92 0060 09D1     		bne	.L4
  93              		.loc 1 21 0 is_stmt 0 discriminator 1
  94 0062 0720     		movs	r0, #7
  95 0064 FFF7FEFF 		bl	read_DIL_single
  96 0068 031E     		subs	r3, r0, #0
  97 006a 04D0     		beq	.L4
  22:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 		speed -= SPEED_ADD;
  98              		.loc 1 22 0 is_stmt 1
  99 006c 184B     		ldr	r3, .L7+4
 100 006e 1B68     		ldr	r3, [r3]
 101 0070 DA1E     		subs	r2, r3, #3
 102 0072 174B     		ldr	r3, .L7+4
 103 0074 1A60     		str	r2, [r3]
 104              	.L4:
  23:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	}
  24:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	
  25:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	this->xPos += speed;
 105              		.loc 1 25 0
 106 0076 7B68     		ldr	r3, [r7, #4]
 107 0078 5A68     		ldr	r2, [r3, #4]
 108 007a 154B     		ldr	r3, .L7+4
 109 007c 1B68     		ldr	r3, [r3]
 110 007e D218     		adds	r2, r2, r3
 111 0080 7B68     		ldr	r3, [r7, #4]
 112 0082 5A60     		str	r2, [r3, #4]
  26:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	
  27:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	if (speed > 0){
 113              		.loc 1 27 0
 114 0084 124B     		ldr	r3, .L7+4
 115 0086 1B68     		ldr	r3, [r3]
 116 0088 002B     		cmp	r3, #0
 117 008a 05DD     		ble	.L5
  28:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 		speed--;
 118              		.loc 1 28 0
 119 008c 104B     		ldr	r3, .L7+4
 120 008e 1B68     		ldr	r3, [r3]
 121 0090 5A1E     		subs	r2, r3, #1
 122 0092 0F4B     		ldr	r3, .L7+4
 123 0094 1A60     		str	r2, [r3]
 124 0096 08E0     		b	.L6
 125              	.L5:
  29:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	}
  30:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	else if (speed < 0){
 126              		.loc 1 30 0
 127 0098 0D4B     		ldr	r3, .L7+4
 128 009a 1B68     		ldr	r3, [r3]
 129 009c 002B     		cmp	r3, #0
 130 009e 04DA     		bge	.L6
  31:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 		speed++;
 131              		.loc 1 31 0
 132 00a0 0B4B     		ldr	r3, .L7+4
 133 00a2 1B68     		ldr	r3, [r3]
 134 00a4 5A1C     		adds	r2, r3, #1
 135 00a6 0A4B     		ldr	r3, .L7+4
 136 00a8 1A60     		str	r2, [r3]
 137              	.L6:
  32:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	}
  33:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	
  34:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	lastRightValue = read_DIL_single(RIGHT_TRIGGER);
 138              		.loc 1 34 0
 139 00aa 0020     		movs	r0, #0
 140 00ac FFF7FEFF 		bl	read_DIL_single
 141 00b0 0200     		movs	r2, r0
 142 00b2 064B     		ldr	r3, .L7
 143 00b4 1A60     		str	r2, [r3]
  35:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	lastLeftValue = read_DIL_single(LEFT_TRIGGER);
 144              		.loc 1 35 0
 145 00b6 0720     		movs	r0, #7
 146 00b8 FFF7FEFF 		bl	read_DIL_single
 147 00bc 0200     		movs	r2, r0
 148 00be 054B     		ldr	r3, .L7+8
 149 00c0 1A60     		str	r2, [r3]
  36:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** 	
  37:C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C\player.c **** }...
 150              		.loc 1 37 0
 151 00c2 C046     		nop
 152 00c4 BD46     		mov	sp, r7
 153 00c6 02B0     		add	sp, sp, #8
 154              		@ sp needed
 155 00c8 80BD     		pop	{r7, pc}
 156              	.L8:
 157 00ca C046     		.align	2
 158              	.L7:
 159 00cc 00000000 		.word	lastRightValue.4092
 160 00d0 04000000 		.word	speed.4094
 161 00d4 08000000 		.word	lastLeftValue.4093
 162              		.cfi_endproc
 163              	.LFE0:
 165              		.bss
 166              		.align	2
 167              	lastRightValue.4092:
 168 0000 00000000 		.space	4
 170              		.align	2
 171              	speed.4094:
 172 0004 00000000 		.space	4
 174              		.align	2
 175              	lastLeftValue.4093:
 176 0008 00000000 		.space	4
 178              		.text
 179              	.Letext0:
 180              		.file 2 "C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C/sprite.h"
 181              		.file 3 "C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C/image.h"
 182              		.file 4 "C:/Users/Kraft/Desktop/DAT017/hemuppgifter/DIPs-Witch/C/gameobject.h"
