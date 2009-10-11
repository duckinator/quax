#include <main.h>
 
void color(colors_t fg, colors_t bg, attrs_t e)
{
	printf("\033[0;%d;%d;%dm", e, FG_OFFSET + fg, BG_OFFSET + bg);
}
 
void cursor_set(unsigned int row, unsigned int column)
{
	printf("\033[%d;%dH", row, column);
}
 
void cursor_move(unsigned int count, direction_t dir)
{
	printf("\033[%d%c", count, dir);
}
 
void reset_term()
{
	printf("\033c");
}
 
void clear_term()
{
	printf("\033[2J");
}

void hline(x, y, length)
{
	printf("\033(0");
	cursor_set(x, y);
 
	printf("t");
 
	int i;
	for (i = 0; i < length; i++)
		printf("q");
 
	printf("u");
 
	printf("\033(B");
}
 
void box(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	int i;
	printf("\033(0\033[%d;%df\033[%ddl\033[1D\033[%ddm", x, y, y, y + height);
 
	for (i = x + 1; i < x + 1 + width; i++)
		printf("\033[%ddq\033[1D\033[%ddq", y, y + height);
 
	printf("\033[%ddk\033[1D\033[%ddj\033[%dG", y, y + height, x);
 
	for (i = y + 1; i < y + height; i++)
		printf("\033[%d;%dfx\033[%dGx", i, x, y + width + 1);
 
	printf("\033(B");
}

void new_window(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char *text)
{
	box(x, y, width, height);
	cursor_set(x+1, y+1);
	printf("%s", text);
 
	hline(x+2, y, width);
} 

int main(int argc, const char *argv[])
{
	color(black, black, 0);
	clear_term();
 
	color(white, black, 0);
	//reset_term();
 
	cursor_set(0, 0);
	printf("MOO\n");
 
	cursor_move(10, down);
	printf("MEOW\n");
 
	cursor_move(2, right);
	cursor_move(2, up);
	printf("MEOW x 2\n");
 
	//color(white, black, 0);
	//box(10, 10, 10, 10);
	new_window(10, 10, 10, 10, "meep");
 
	cursor_set(50, 0); 
 
	//c0sleep(2);
	//reset_term();
	return 0;
}
 
