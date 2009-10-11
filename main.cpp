#include <quax.h>

#include <stdio.h>

int main(int argc, char *argv[])
{
	Quax quax;
	quax.color(black, black, (attrs_t)0);
	quax.clear_term();
 
	quax.color(white, black, (attrs_t)0);
	//reset_term();
 
	quax.cursor_set(0, 0);
	printf("MOO\n");
 
	quax.cursor_move(10, down);
	printf("MEOW\n");
 
	quax.cursor_move(2, right);
	quax.cursor_move(2, up);
	printf("MEOW x 2\n");
 
	//color(white, black, 0);
	//box(10, 10, 10, 10);
	quax.new_window(10, 10, 10, 10, "meep");
 
	quax.cursor_set(50, 0); 
 
	//c0sleep(2);
	//reset_term();
	return 0;
}
 
