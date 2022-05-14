#include "Console.h"
#include <stdio.h>
#include <stdlib.h>

#define rows 80
#define cols 25

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
	int x,y;
	int dx,dy;
};

// Function prototypes
struct Scene scene_init(void);
void scene_render(struct Scene s);
struct Scene scene_update(struct Scene s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
	// NOTE: you don't need to change anything in the main() function

	struct Scene myScene;

	myScene = scene_init();

	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		scene_render(myScene);

		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		myScene = scene_update(myScene);

		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

struct Scene scene_init(void)
{
	// TODO: initialize fields	
	struct Scene s;
	s.x=0;
	s.dx=s.x+1;
	s.y=0;
	s.dy=s.y+1;
	
	return s;
}

void scene_render(struct Scene s){	

	cons_move_cursor(s.y, s.x);
	cons_change_color(RED+INTENSE, BLACK);
	cons_printw("*");
}

struct Scene scene_update(struct Scene s)
{
	struct Scene result;
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