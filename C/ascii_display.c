#include "graphics.h"

#define STK_CTRL ((volatile unsigned int *) (0xE000E010))
#define STK_LOAD ((volatile unsigned int *) (0xE000E014))
#define STK_VAL ((volatile unsigned int *) (0xE000E018))

#define PORT_BASE 0x40021000 //port E
// Definera word-adresser fÃ¶r initieringar
#define portModer ((volatile unsigned int*) (PORT_BASE))
#define portOtyper ((volatile unsigned short*) (PORT_BASE+0x4))
#define portPupdr ((volatile unsigned int*) (PORT_BASE+0xC))
// Definera byte-adresser fÃ¶r data- och styrregister
#define portIdrLow ((volatile unsigned short*) (PORT_BASE+0x10))
#define portIdrHigh ((volatile unsigned char*) (PORT_BASE+0x11))
#define portOdrLow ((volatile unsigned char*) (PORT_BASE+0x14))
#define portOdrHigh ((volatile unsigned char*) (PORT_BASE+0x15))
//Bitarna i styrregistret
#define B_E 0x40
#define B_SELECT 4
#define B_RW 2
#define B_RS 1

//Displaymodulen ska anslutas till Port E sÃ¥ att:
// bit 15-8 = dataregister
// bit  7-0 = styrregister

/*
void startup(void) __attribute__((naked)) __attribute__((section (".start_section")) );

void startup ( void ){
	__asm volatile(
		" LDR R0,=0x2001C000\n"		/* set stack */
		//" MOV SP,R0\n"
		//" BL main\n"				/* call main */
		//"_exit: B .\n"				/* never return */
	/*) ;
}*/

void ascii_write_controller(unsigned char c);
unsigned char ascii_read_controller(void);
void ascii_write_cmd(unsigned char command);
void ascii_write_data(unsigned char data);
unsigned char ascii_read_status(void);
unsigned char ascii_read_data(void);


void ascii_ctrl_bit_set(unsigned char x){
//adressera ASCii-displayen och ettstÃƒÂ¤ll de bitar som ÃƒÂ¤r 1 i x
	unsigned char c;
	c = *portOdrLow;
	c |= (B_SELECT | x);
	*portOdrLow = c;
}

void ascii_ctrl_bit_clear(unsigned char x){
//adressera ASCii-displayen och nollstÃ¤ll de bitar som Ã¤r 1 i x
	unsigned char c;
	c = *portOdrLow;
	c = (B_SELECT | c & ~x);
	*portOdrLow = c;
}

void ascii_write_cmd(unsigned char command){
	ascii_ctrl_bit_clear(B_RS);
	ascii_ctrl_bit_clear(B_RW);
	ascii_write_controller(command);
}

void ascii_write_data(unsigned char data){
	ascii_ctrl_bit_set(B_RS);
	ascii_ctrl_bit_clear(B_RW);
	ascii_write_controller(data);
}

unsigned char ascii_read_status(void){
	//sÃƒÂ¤tt Port E bit15-8 som ingÃƒÂ¥ngar
	*portModer &= 0x0000FFFF;
	ascii_ctrl_bit_clear(B_RS);
	ascii_ctrl_bit_set(B_RW);
	unsigned char rv = ascii_read_controller();
	//sÃƒÂ¤tt Port E bit15-8 som utgÃƒÂ¥ngar
	*portModer &= 0x0000FFFF;
	*portModer |= 0x55550000;
	return rv;
}

unsigned char ascii_read_data(void){
	//sÃƒÂ¤tt Port E bit15-8 som ingÃƒÂ¥ngar
	*portModer &= 0x0000FFFF;
	ascii_ctrl_bit_set(B_RS);
	ascii_ctrl_bit_set(B_RW);
	unsigned char rv = ascii_read_controller();
	//sÃƒÂ¤tt Port E bit15-8 som utgÃƒÂ¥ngar
	*portModer &= 0x0000FFFF;
	*portModer |= 0x55550000;
	return rv;
}

void ascii_write_controller(unsigned char c){
	ascii_ctrl_bit_set(B_E);
	*portOdrHigh = c;
	delay_250ns();
	ascii_ctrl_bit_clear(B_E);
}

unsigned char ascii_read_controller(void){
	unsigned char c;
	ascii_ctrl_bit_set(B_E);
	delay_250ns();
	delay_250ns();
	c = *portIdrHigh;
	ascii_ctrl_bit_clear(B_E);
	return c;
}

void ascii_write_char(unsigned char c){
		while((ascii_read_status() & 0x80) == 0x80){} //VÃƒÂ¤nta tills displayed ÃƒÂ¤r redo
		delay_micro(8); //latenstid
		ascii_write_data(c);
		delay_micro(50); //istÃƒÂ¤llet fÃƒÂ¶r 43us
}

void ascii_goToXY(unsigned char row, unsigned char column){
	unsigned char address = row-1;
	if(column == 2){
		address += 0x40;
	}
	ascii_write_cmd(0x80 | address);
}

void ascii_init(void){
	//initiera displayen:
		while((ascii_read_status() & 0x80) == 0x80){} //VÃ¤nta tills displayed Ã¤r redo
		delay_micro(20); //latenstid 
		ascii_write_cmd(0x38); //Function set (39us), 000011NFXX, N = antal rader = 2, F = -->0=5x8<--, 1=5x11
		delay_micro(100); //istÃƒÂ¤llet fÃƒÂ¶r 39us
		
	// clear display
		while((ascii_read_status() & 0x80) == 0x80){} //VÃƒÂ¤nta tills displayed ÃƒÂ¤r redo
		delay_micro(20); //latenstid
		ascii_write_cmd(0x01); 
		delay_micro(100); //istÃƒÂ¤llet fÃƒÂ¶r 39us

	//display control:
		while((ascii_read_status() & 0x80) == 0x80){} //VÃƒÂ¤nta tills displayed ÃƒÂ¤r redo
		delay_micro(20); //latenstid
		ascii_write_cmd(0x0C); //000001 + XXX. X:ena = 0:av / 1:pÃƒÂ¥ -  SkÃƒÂ¤rm/MarkÃƒÂ¶r/BlinkaMarkÃƒÂ¶ren
		delay_micro(100); //istÃƒÂ¤llet fÃƒÂ¶r 39us
		
	// entry mode set
		while((ascii_read_status() & 0x80) == 0x80){} //VÃƒÂ¤nta tills displayed ÃƒÂ¤r redo
		delay_micro(20); //latenstid
		ascii_write_cmd(0x06); //00000001 + XY. X=0: markÃƒÂ¶ren vÃƒÂ¤nst. || X=1: marÃƒÂ¶kren hÃƒÂ¶g. - Y=0: skift av || Y=1: skift pÃƒÂ¥
		delay_micro(100); //istÃƒÂ¤llet fÃƒÂ¶r 39us
		
		
}

void init_application(void){
	#ifdef USBDM
		*((unsigned long *) 0x40023830) = 0x18; //startar klockor pÃ¥ port D och E
		//__asm volatile ("LDR R0, =0x08000209\n BLX R0 \n"); //initiera PLL
	#endif
	//"initierar Port E med anvÃƒÂ¤ndning med LCD-modulen, dvs. sÃƒÂ¥vÃƒÂ¤l port E0-7 som E8-15 sÃƒÂ¤tts till utgÃƒÂ¥ngar
	* portModer = 0x55555555;
}

void set_up_ascii( void ) {
	init_application();
	ascii_init();
}

void clear_ascii( void ) {
	char *s;
	char clear[] = "                    ";
	
	s = clear;
	ascii_goToXY(1,1);
	while(*s){
		ascii_write_char(*s++);
	}
	s = clear;
	ascii_goToXY(1,2);
	while(*s){
		ascii_write_char(*s++);
	}
}

void ascii_write(char *row1, char *row2) {
	clear_ascii();
	
	ascii_goToXY(1,1);
	while(*row1){
		ascii_write_char(*row1++);
	}	
	ascii_goToXY(1,2);
	while(*row2){
		ascii_write_char(*row2++);
	}
	
	ascii_goToXY(21,1);
}

void ascii_write_part(char *row1, char *row2, int limit1, int limit2) {
	clear_ascii();
	
	ascii_goToXY(1,1);
	int i = 0;
	if(limit1 > 0) {
		while(*row1 && (i++ < limit1)){
			ascii_write_char(*row1++);
		}			
	}

	ascii_goToXY(1,2);
	i = 0;
	if(limit2 > 0) {
		while(*row2 && (i++ < limit2)){
			ascii_write_char(*row2++);
		}
	}
	
	ascii_goToXY(21,1);
}



void ascii_test(void) {
	char *s;
	char test1[] = "Alfanumerisk";
	char test2[] = "hardåäöare suger";
	
	init_application();
	ascii_init();
	ascii_goToXY(1,1);
	s = test1;
	while(*s){
		ascii_write_char(*s++);
	}
	ascii_goToXY(1,2);
	s = test2;
	while(*s){
		ascii_write_char(*s++);
	}
	return 0;
}