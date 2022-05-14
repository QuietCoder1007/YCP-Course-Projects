#include "Console.h"

// Definition of the Scene struct type
struct Scene {
	int x, y;
	int dx, dy;
};

// Function prototypes
void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
	struct Scene myScene;

	scene_init(&myScene);

	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		scene_render(&myScene);

		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		scene_update(&myScene);

		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

// TODO: add definitions for scene_init, scene_render, and scene_update
void scene_init(struct Scene *s){
	s->x=0;
	s->y=0;
	s->dx=1;
	s->dy=1;
}
void scene_render(const struct Scene *s){
	cons_move_cursor(s->y, s->x);
	cons_change_color(RED+INTENSE, BLACK);
	cons_printw("*");
}
void scene_update(struct Scene *s){
	s->x += s->dx;
	s->y += s->dy;
	s->dx = s->dx;
	s->dy = s->dy;
	
	if(s->x==0 || s->x==79){
		s->dx *=-1;
	}
	if(s->y==0 || s->y==23){
		s->dy *=-1;
	}
}