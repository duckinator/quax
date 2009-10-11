#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
 
#define PATH_MAX 1000
#define FG_OFFSET 30
#define BG_OFFSET 40
 
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

#endif
