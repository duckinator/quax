#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#define WINDOW_LIMIT 500	// 500 windows maximum
#define PATH_MAX 1000		// Maximum number of characters a file path can be
#define FG_OFFSET 30		// Offset for the foreground color
#define BG_OFFSET 40		// Offset for the background color
 
typedef enum colors {
	black,
	red,
	green,
	brown,
	blue,
	purple,
	cyan,
	white
} colors_t;
 
typedef enum attrs {
	reset,
	bright,
	dim,
	underscore = 4,
	blink,
	reverse,
	hidden
} attrs_t;
 
typedef enum direction {
	up = 'A',
	down = 'B',
	right = 'C',
	left = 'D'
} direction_t;

typedef struct _window {
	char *title;
	char *content;
	colors_t *foreground;
	colors_t *background;
	attrs_t *attributes;
	int top;
	int left;
	int width;
	int height;
} Window;

class Quax {
public:
	void color(colors_t fg, colors_t bg, attrs_t e);
	void cursor_set(unsigned int row, unsigned int column);
	void cursor_move(unsigned int count, direction_t dir);
	void reset_term();
	void clear_term();
	void hline(int x, int y, int length);
	void box(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	void draw_window(Window *window);
	Window *new_window(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char *text);
};

#endif
