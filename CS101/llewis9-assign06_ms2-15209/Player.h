#ifndef PLAYER_H
#define PLAYER_H

#include <stdlib.h>
#include "Const.h"
#include "Console.h"

// TODO MS1: Add player structure
struct Player {
	int x, y;
	int dx, dy;
	char player;
	int color;
	int score=0;
};

// TODO MS1: Add player function prototypes
void initialize_Player(struct Player *p, int x, int y, int dx, int dy, char symbol, int color);
void draw_Player(struct Player *p);
void player_AI(struct Player *p, int board[HEIGHT][WIDTH]);
void ghost_AI(struct Player *p, int board[HEIGHT][WIDTH]);
void check_Player_Move(struct Player *p, int board[HEIGHT][WIDTH]);
void update_Player(struct Player *p);

#endif // PLAYER_H
