#ifndef TEXT
#define TEXT

typedef struct tSlowText {
	char		*row1;
	char		*row2;

	int			counter;
	int			speed;

    // methods:
    void        (*display) (struct tSlowText *this, int length_of_row1);
} SlowText;

void display(SlowText *this, int length_of_row1);

void init_slow_text(SlowText *obj, char *row1, char *row2, int speed);


#endif //TEXT