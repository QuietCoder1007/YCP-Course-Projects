		//Le Quient Lewis II
	//5-02-2019
//Welcome to making a rip-off Pacman. Implement five functions that use pointers and and, two of the, arrays
//to get the player to be able to move around the board.


		//Le Quient Lewis II
	//5-09-2019
//Welcome to making a rip-off Pacman. Implement a function that updates the movement for the ghosts and their collision detection.
// You can also try to be superman and go for the extra stuff, but that's not fun at all

#include "Player.h"
// TODO MS1: Add player functions

//function for assigning int and char values into correlating pointer instances
void initialize_Player(struct Player *p, int x, int y, int dx, int dy, char symbol, int color){
	p->x=x;
	p->y=y;
	p->dx=dx;
	p->dy=dy;
	p->player = symbol;
	p->color=color;
}

//Draw the player with assigned values from initialize_Player function
void draw_Player(struct Player *p){
	cons_move_cursor(p->y , p->x);
	cons_change_color(p->color, BLACK);
	cons_printw("%c", p->player);
}

//Function for determining key inputs for player movement
void player_AI(struct Player *p, int board[HEIGHT][WIDTH]){
	int key = cons_get_keypress();
	//if up key is pressed, then decrease y velocity by 1
	if (key == UP_ARROW) {
		p->dy = -1;
		p->dx += 0;
	}
	//if down key is pressed, then increase y velocity by 1	
	else if (key == DOWN_ARROW) {
		p->dy = 1;
		p->dx = 0;
	}
	//if left key is pressed, then decrease x velocity by 1
	else if (key == LEFT_ARROW) {
		p->dy = 0;
		p->dx = -1;
	}
	//if right key is pressed, then increase y velocity by 1
	else if (key == RIGHT_ARROW) {
		p->dy = 0;
		p->dx = 1;
	}
	//if no key is pressed, then set velocities to zero
	else{
		p->dy = 0;
		p->dx = 0;
	}
	//Call function to check the position of the player
	check_Player_Move(p, board);
}
//Function for randomizing ghost velocities
void ghost_AI(struct Player *p, int board[HEIGHT][WIDTH]){
	//Variable for velocities
	int v = (rand()%3) - 1;

	//Variable for determining if you have
	int xchancey = rand()%2;

	int random = (rand()%100);

	if(random > 75  or (p->dx == 0 and p->dy == 0)){
		if (xchancey == 0){
			p->dx = v;
			p->dy = 0;
		}
		else{
			p->dx = 0;
			p->dy = v;
		}
	}
	check_Player_Move(p, board);
}
//Function for determining collision detection for barriers, or if the player loops in a tunnel
void check_Player_Move(struct Player *p, int board[HEIGHT][WIDTH]){
	if(p->x == WIDTH-1 and p->dx == 1 and p->y == TUNNEL_Y){
		p->x=0;
		p->dx=0;
	}
	else if(p->x == 0 and p->dx == -1 and p->y == TUNNEL_Y){
		p->x=27;
		p->dx=0;
	}
	if(board[p->y + p->dy][p->x + p->dx] == WALL){
		p->dy = 0;
		p->dx = 0;
	}

}

//Update player's position with the the velocity by increments of 1
void update_Player(struct Player *p){
	p->x += p->dx;
	p->y += p->dy;
}

