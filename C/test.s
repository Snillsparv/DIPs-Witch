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
  25              		.file 1 "C:/mop/c/Moplaborationer/DIPs-Witch/C/player.c"
   1:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** #include "gpio.h"
   2:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** #include "controls.h"
   3:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** #include "gameobject.h"
   4:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** #include "player.h"
   5:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 
   6:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** void playerUpdate(GameObject *this) {
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
   7:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
   8:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	// Animate
   9:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	this->animation_counter++;
  39              		.loc 1 9 0
  40 0008 7B68     		ldr	r3, [r7, #4]
  41 000a 1B6A     		ldr	r3, [r3, #32]
  42 000c 5A1C     		adds	r2, r3, #1
  43 000e 7B68     		ldr	r3, [r7, #4]
  44 0010 1A62     		str	r2, [r3, #32]
  10:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	if (this->animation_counter == this->animation_speed) {
  45              		.loc 1 10 0
  46 0012 7B68     		ldr	r3, [r7, #4]
  47 0014 1A6A     		ldr	r2, [r3, #32]
  48 0016 7B68     		ldr	r3, [r7, #4]
  49 0018 DB69     		ldr	r3, [r3, #28]
  50 001a 9A42     		cmp	r2, r3
  51 001c 0FD1     		bne	.L2
  11:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		this->animation_counter = 0;
  52              		.loc 1 11 0
  53 001e 7B68     		ldr	r3, [r7, #4]
  54 0020 0022     		movs	r2, #0
  55 0022 1A62     		str	r2, [r3, #32]
  12:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		this->current_frame = (this->current_frame + 1) % this->n_frames;
  56              		.loc 1 12 0
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
  13:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  14:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  15:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	// Variables
  16:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	static lastJumpValue = 0;
  17:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	static lastRightValue = 0;
  18:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	static lastLeftValue = 0; 
  19:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	static xSpeed = 0;
  20:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	static ySpeed = 0;
  21:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  22:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	// Y position changes
  23:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  24:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	if (lastJumpValue != read_DIL_single(JUMP_TRIGGER) && (this->yPos == LIMIT_DOWN || this->yPos == P
  71              		.loc 1 24 0
  72 003e 0520     		movs	r0, #5
  73 0040 FFF7FEFF 		bl	read_DIL_single
  74 0044 0200     		movs	r2, r0
  75 0046 4F4B     		ldr	r3, .L14
  76 0048 1B68     		ldr	r3, [r3]
  77 004a 9A42     		cmp	r2, r3
  78 004c 0BD0     		beq	.L3
  79              		.loc 1 24 0 is_stmt 0 discriminator 1
  80 004e 7B68     		ldr	r3, [r7, #4]
  81 0050 9B68     		ldr	r3, [r3, #8]
  82 0052 272B     		cmp	r3, #39
  83 0054 03D0     		beq	.L4
  84              		.loc 1 24 0 discriminator 2
  85 0056 7B68     		ldr	r3, [r7, #4]
  86 0058 9B68     		ldr	r3, [r3, #8]
  87 005a 052B     		cmp	r3, #5
  88 005c 03D1     		bne	.L3
  89              	.L4:
  25:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		ySpeed = -(SPEED_ADD_Y);
  90              		.loc 1 25 0 is_stmt 1
  91 005e 4A4B     		ldr	r3, .L14+4
  92 0060 0422     		movs	r2, #4
  93 0062 5242     		rsbs	r2, r2, #0
  94 0064 1A60     		str	r2, [r3]
  95              	.L3:
  26:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  27:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  28:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	if (this->yPos + ySpeed > LIMIT_DOWN){
  96              		.loc 1 28 0
  97 0066 7B68     		ldr	r3, [r7, #4]
  98 0068 9A68     		ldr	r2, [r3, #8]
  99 006a 474B     		ldr	r3, .L14+4
 100 006c 1B68     		ldr	r3, [r3]
 101 006e D318     		adds	r3, r2, r3
 102 0070 272B     		cmp	r3, #39
 103 0072 06DD     		ble	.L5
  29:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		this->yPos = LIMIT_DOWN;
 104              		.loc 1 29 0
 105 0074 7B68     		ldr	r3, [r7, #4]
 106 0076 2722     		movs	r2, #39
 107 0078 9A60     		str	r2, [r3, #8]
  30:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		ySpeed = 0;
 108              		.loc 1 30 0
 109 007a 434B     		ldr	r3, .L14+4
 110 007c 0022     		movs	r2, #0
 111 007e 1A60     		str	r2, [r3]
 112 0080 20E0     		b	.L6
 113              	.L5:
  31:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  32:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	else if (this->yPos + ySpeed > PLATFORM_Y - PLAYER_HEIGHT && this->yPos + ySpeed < PLATFORM_Y - PL
 114              		.loc 1 32 0
 115 0082 7B68     		ldr	r3, [r7, #4]
 116 0084 9A68     		ldr	r2, [r3, #8]
 117 0086 404B     		ldr	r3, .L14+4
 118 0088 1B68     		ldr	r3, [r3]
 119 008a D318     		adds	r3, r2, r3
 120 008c 052B     		cmp	r3, #5
 121 008e 0DDD     		ble	.L7
 122              		.loc 1 32 0 is_stmt 0 discriminator 1
 123 0090 7B68     		ldr	r3, [r7, #4]
 124 0092 9A68     		ldr	r2, [r3, #8]
 125 0094 3C4B     		ldr	r3, .L14+4
 126 0096 1B68     		ldr	r3, [r3]
 127 0098 D318     		adds	r3, r2, r3
 128 009a 0C2B     		cmp	r3, #12
 129 009c 06DC     		bgt	.L7
  33:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		this->yPos = PLATFORM_Y - PLAYER_HEIGHT;
 130              		.loc 1 33 0 is_stmt 1
 131 009e 7B68     		ldr	r3, [r7, #4]
 132 00a0 0522     		movs	r2, #5
 133 00a2 9A60     		str	r2, [r3, #8]
  34:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		ySpeed = 0;
 134              		.loc 1 34 0
 135 00a4 384B     		ldr	r3, .L14+4
 136 00a6 0022     		movs	r2, #0
 137 00a8 1A60     		str	r2, [r3]
 138 00aa 0BE0     		b	.L6
 139              	.L7:
  35:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  36:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	else{
  37:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		this->yPos+=ySpeed;
 140              		.loc 1 37 0
 141 00ac 7B68     		ldr	r3, [r7, #4]
 142 00ae 9A68     		ldr	r2, [r3, #8]
 143 00b0 354B     		ldr	r3, .L14+4
 144 00b2 1B68     		ldr	r3, [r3]
 145 00b4 D218     		adds	r2, r2, r3
 146 00b6 7B68     		ldr	r3, [r7, #4]
 147 00b8 9A60     		str	r2, [r3, #8]
  38:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		ySpeed++;
 148              		.loc 1 38 0
 149 00ba 334B     		ldr	r3, .L14+4
 150 00bc 1B68     		ldr	r3, [r3]
 151 00be 5A1C     		adds	r2, r3, #1
 152 00c0 314B     		ldr	r3, .L14+4
 153 00c2 1A60     		str	r2, [r3]
 154              	.L6:
  39:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  40:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 
  41:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	// X position changes
  42:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  43:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	if (!lastRightValue && read_DIL_single(RIGHT_TRIGGER)){
 155              		.loc 1 43 0
 156 00c4 314B     		ldr	r3, .L14+8
 157 00c6 1B68     		ldr	r3, [r3]
 158 00c8 002B     		cmp	r3, #0
 159 00ca 09D1     		bne	.L8
 160              		.loc 1 43 0 is_stmt 0 discriminator 1
 161 00cc 0020     		movs	r0, #0
 162 00ce FFF7FEFF 		bl	read_DIL_single
 163 00d2 031E     		subs	r3, r0, #0
 164 00d4 04D0     		beq	.L8
  44:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		xSpeed += SPEED_ADD_X;
 165              		.loc 1 44 0 is_stmt 1
 166 00d6 2E4B     		ldr	r3, .L14+12
 167 00d8 1B68     		ldr	r3, [r3]
 168 00da DA1C     		adds	r2, r3, #3
 169 00dc 2C4B     		ldr	r3, .L14+12
 170 00de 1A60     		str	r2, [r3]
 171              	.L8:
  45:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  46:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  47:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	if (!lastLeftValue && read_DIL_single(LEFT_TRIGGER)){
 172              		.loc 1 47 0
 173 00e0 2C4B     		ldr	r3, .L14+16
 174 00e2 1B68     		ldr	r3, [r3]
 175 00e4 002B     		cmp	r3, #0
 176 00e6 09D1     		bne	.L9
 177              		.loc 1 47 0 is_stmt 0 discriminator 1
 178 00e8 0720     		movs	r0, #7
 179 00ea FFF7FEFF 		bl	read_DIL_single
 180 00ee 031E     		subs	r3, r0, #0
 181 00f0 04D0     		beq	.L9
  48:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		xSpeed -= SPEED_ADD_X;
 182              		.loc 1 48 0 is_stmt 1
 183 00f2 274B     		ldr	r3, .L14+12
 184 00f4 1B68     		ldr	r3, [r3]
 185 00f6 DA1E     		subs	r2, r3, #3
 186 00f8 254B     		ldr	r3, .L14+12
 187 00fa 1A60     		str	r2, [r3]
 188              	.L9:
  49:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  50:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  51:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	if (this->xPos + xSpeed > LIMIT_RIGHT || this->xPos + xSpeed < LIMIT_LEFT){
 189              		.loc 1 51 0
 190 00fc 7B68     		ldr	r3, [r7, #4]
 191 00fe 5A68     		ldr	r2, [r3, #4]
 192 0100 234B     		ldr	r3, .L14+12
 193 0102 1B68     		ldr	r3, [r3]
 194 0104 D318     		adds	r3, r2, r3
 195 0106 6E2B     		cmp	r3, #110
 196 0108 06DC     		bgt	.L10
 197              		.loc 1 51 0 is_stmt 0 discriminator 1
 198 010a 7B68     		ldr	r3, [r7, #4]
 199 010c 5A68     		ldr	r2, [r3, #4]
 200 010e 204B     		ldr	r3, .L14+12
 201 0110 1B68     		ldr	r3, [r3]
 202 0112 D318     		adds	r3, r2, r3
 203 0114 002B     		cmp	r3, #0
 204 0116 04DA     		bge	.L11
 205              	.L10:
  52:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		xSpeed *= -1;	
 206              		.loc 1 52 0 is_stmt 1
 207 0118 1D4B     		ldr	r3, .L14+12
 208 011a 1B68     		ldr	r3, [r3]
 209 011c 5A42     		rsbs	r2, r3, #0
 210 011e 1C4B     		ldr	r3, .L14+12
 211 0120 1A60     		str	r2, [r3]
 212              	.L11:
  53:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  54:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  55:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	this->xPos += xSpeed;	
 213              		.loc 1 55 0
 214 0122 7B68     		ldr	r3, [r7, #4]
 215 0124 5A68     		ldr	r2, [r3, #4]
 216 0126 1A4B     		ldr	r3, .L14+12
 217 0128 1B68     		ldr	r3, [r3]
 218 012a D218     		adds	r2, r2, r3
 219 012c 7B68     		ldr	r3, [r7, #4]
 220 012e 5A60     		str	r2, [r3, #4]
  56:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  57:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	if (xSpeed > 0){
 221              		.loc 1 57 0
 222 0130 174B     		ldr	r3, .L14+12
 223 0132 1B68     		ldr	r3, [r3]
 224 0134 002B     		cmp	r3, #0
 225 0136 05DD     		ble	.L12
  58:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		xSpeed--;
 226              		.loc 1 58 0
 227 0138 154B     		ldr	r3, .L14+12
 228 013a 1B68     		ldr	r3, [r3]
 229 013c 5A1E     		subs	r2, r3, #1
 230 013e 144B     		ldr	r3, .L14+12
 231 0140 1A60     		str	r2, [r3]
 232 0142 08E0     		b	.L13
 233              	.L12:
  59:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  60:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	else if (xSpeed < 0){
 234              		.loc 1 60 0
 235 0144 124B     		ldr	r3, .L14+12
 236 0146 1B68     		ldr	r3, [r3]
 237 0148 002B     		cmp	r3, #0
 238 014a 04DA     		bge	.L13
  61:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 		xSpeed++;
 239              		.loc 1 61 0
 240 014c 104B     		ldr	r3, .L14+12
 241 014e 1B68     		ldr	r3, [r3]
 242 0150 5A1C     		adds	r2, r3, #1
 243 0152 0F4B     		ldr	r3, .L14+12
 244 0154 1A60     		str	r2, [r3]
 245              	.L13:
  62:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	}
  63:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  64:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	// Prepare values
  65:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	lastRightValue = read_DIL_single(RIGHT_TRIGGER);
 246              		.loc 1 65 0
 247 0156 0020     		movs	r0, #0
 248 0158 FFF7FEFF 		bl	read_DIL_single
 249 015c 0200     		movs	r2, r0
 250 015e 0B4B     		ldr	r3, .L14+8
 251 0160 1A60     		str	r2, [r3]
  66:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	lastLeftValue = read_DIL_single(LEFT_TRIGGER);
 252              		.loc 1 66 0
 253 0162 0720     		movs	r0, #7
 254 0164 FFF7FEFF 		bl	read_DIL_single
 255 0168 0200     		movs	r2, r0
 256 016a 0A4B     		ldr	r3, .L14+16
 257 016c 1A60     		str	r2, [r3]
  67:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	lastJumpValue = read_DIL_single(JUMP_TRIGGER);
 258              		.loc 1 67 0
 259 016e 0520     		movs	r0, #5
 260 0170 FFF7FEFF 		bl	read_DIL_single
 261 0174 0200     		movs	r2, r0
 262 0176 034B     		ldr	r3, .L14
 263 0178 1A60     		str	r2, [r3]
  68:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** 	
  69:C:/mop/c/Moplaborationer/DIPs-Witch/C\player.c **** }...
 264              		.loc 1 69 0
 265 017a C046     		nop
 266 017c BD46     		mov	sp, r7
 267 017e 02B0     		add	sp, sp, #8
 268              		@ sp needed
 269 0180 80BD     		pop	{r7, pc}
 270              	.L15:
 271 0182 C046     		.align	2
 272              	.L14:
 273 0184 00000000 		.word	lastJumpValue.4092
 274 0188 04000000 		.word	ySpeed.4096
 275 018c 08000000 		.word	lastRightValue.4093
 276 0190 0C000000 		.word	xSpeed.4095
 277 0194 10000000 		.word	lastLeftValue.4094
 278              		.cfi_endproc
 279              	.LFE0:
 281              		.bss
 282              		.align	2
 283              	lastJumpValue.4092:
 284 0000 00000000 		.space	4
 286              		.align	2
 287              	ySpeed.4096:
 288 0004 00000000 		.space	4
 290              		.align	2
 291              	lastRightValue.4093:
 292 0008 00000000 		.space	4
 294              		.align	2
 295              	xSpeed.4095:
 296 000c 00000000 		.space	4
 298              		.align	2
 299              	lastLeftValue.4094:
 300 0010 00000000 		.space	4
 302              		.text
 303              	.Letext0:
 304              		.file 2 "C:/mop/c/Moplaborationer/DIPs-Witch/C/sprite.h"
 305              		.file 3 "C:/mop/c/Moplaborationer/DIPs-Witch/C/image.h"
 306              		.file 4 "C:/mop/c/Moplaborationer/DIPs-Witch/C/gameobject.h"
