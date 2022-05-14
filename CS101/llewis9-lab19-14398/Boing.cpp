#include "Console.h"

void boing_init(int *px, int *py, int *pdx, int *pdy);
void boing_render(int x, int y);
void boing_update(int *px, int *py, int *pdx, int *pdy);

int main(void) {
	int x, y, dx, dy;

	// initialize variables
	boing_init(&x, &y, &dx, &dy);

	int keep_going = 1;
	while (keep_going == 1) {
		// print the character using x and y as its location
		boing_render(x, y);

		// update the terminal window
		cons_update();

		// update the variables so that the character will appear to move
		// the next time the boing_render function is called
		boing_update(&x, &y, &dx, &dy);

		// See if a key has been pressed
		int key = cons_get_keypress();
		if (key >= 0) {
			keep_going = 0;
		}

		// Pause for a short time
		cons_sleep_ms(1000/10);
	}

	return 0;
}

// TODO: add definitions for boing_init, boing_render, and boing_update
struct boing_init(int *px, int *py, int *pdx, int *pdy)
{
	// TODO: initialize fields	
	*p.x=
	s.x=0;
	s.dx=s.x+1;
	s.y=0;
	s.dy=s.y+1;
	
	return s;
}

void boing_render(int x, int y){	

	cons_move_cursor(s.y, s.x);
	cons_change_color(RED+INTENSE, BLACK);
	cons_printw("*");
}

struct boing_update(int *px, int *py, int *pdx, int *pdy)
{
	result.x=s.x + s.dx;
	result.y=s.y + s.dy;
	result.dx=s.dx;
	result.dy=s.dy;
	
	// TODO: update the scene by assigning to the fields of "result"
	if(result.x==0 || result.x==79){
		result.dx=-1*result.dx;
	}
	if(result.y==0 || result.y==23){
		result.dy=-1*result.dy;
	}

	return result;
}