#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"

// The scene should contain an array of this many Particles
#define NUM_PARTICLES 20

// Definition of the Point struct type
struct Point {
	double x, y;
};

// Definition of the Particle struct type
struct Particle {
	// TODO: add fields
	struct Point d;
	double dx, dy;
	int color;
};

/* // Definition of the Rect struct type
struct Rect {
	// TODO: add fields
}; */

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
	struct Particle p[NUM_PARTICLES];
};

// Function prototypes

void point_init(struct Point *p, double x, double y);
void point_move(struct Point *p, double dx, double dy);

void particle_init(struct Particle *p);
void particle_render(const struct Particle *p);
void particle_update(struct Particle *p);

void rect_init(struct Rect *r, struct Point p1, struct Point p2);
bool rect_contains_point(const struct Rect *r, struct Point p);

void scene_init(struct Scene *s);
void scene_render(const struct Scene *s);
void scene_update(struct Scene *s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
	// NOTE: you don't need to change anything in the main() function
	srand(time(0));
	struct Scene myScene;

	// TODO: add call to scene_init
	scene_init(&myScene);
	

	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		// TODO: add call to scene_render
		scene_render(&myScene);
		
		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		// TODO: add call to scene_update
		scene_update(&myScene);
		
		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

void point_init(struct Point *p, double x, double y){
	p->x = x;
	p->y = y;
}
void point_move(struct Point *p, double dx, double dy){
	p->x += dx;
	p->y += dy;
}

void particle_init(struct Particle *p){
	p -> dx = (rand() % 3)+1;
	p -> dy = (rand() % 3)+1;
	if(p -> dx == 0){
		p-> dx = 1;
	}
	else if(p -> dy == 0){
		p-> dy = 1;
	}
	else if(p -> dx == 2){
		p-> dx = 1;
	}
	else if(p -> dy == 2){
		p-> dy = -1;
	}
	p->d.x = (rand() % 8000) / 100.0;
	p->d.y = ((rand() % 300) / 100.0) - 1.5;
	p->color= (rand() % 15) + 1;
}
void particle_render(const struct Particle *p){
	cons_move_cursor(p->d.y , p->d.x);
	cons_change_color(p->color, BLACK);
	cons_printw("*");
}
void particle_update(struct Particle *p){	
	p->d.x += p->dx;
	p->d.y += p->dy;

	if(p->d.x <= 0 || p->d.x >= 79){
		p->dx *=-1;
	}
	
	if(p->d.y <= 1 || p->d.y >= 23){
		p->dy *=-1;
	}
}
/* void rect_init(struct Rect *r, struct Point p1, struct Point p2){
	
}
bool rect_contains_point(const struct Rect *r, struct Point p){
	
} */

void scene_init(struct Scene *s){
	for(int i=0;i<NUM_PARTICLES;i++)
		particle_init(&(s->p[i]));
}
void scene_render(const struct Scene *s){
	for(int i=0;i<NUM_PARTICLES;i++)
		particle_render(&(s->p[i]));
}
void scene_update(struct Scene *s){
	for(int i=0;i<NUM_PARTICLES;i++)
		particle_update(&(s->p[i]));
}
