#include <quax.h>

#include <stdio.h>

int main(int argc, char *argv[])
{
	Quax quax;
	Window *win1 = new Window;
	quax.color(black, black, (attrs_t)0);
	quax.clear_term();

	quax.color(white, black, (attrs_t)0);

	quax.cursor_set(0, 0);
	printf("MOO\n");

	quax.cursor_move(10, down);
	printf("MEOW\n");

	quax.cursor_move(2, right);
	quax.cursor_move(2, up);
	printf("MEOW x 2\n");

	win1 = quax.new_window(10, 10, 10, 10, (char*)"meep");
	quax.draw_window(win1);
	/*win1->top = 0;
	quax.reset_term();
	quax.draw_window(win1);*/

	quax.cursor_set(50, 0); 

	return 0;
}
 
