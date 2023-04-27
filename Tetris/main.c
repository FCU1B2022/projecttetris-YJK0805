#include <stdio.h>

typedef enum{
	RED = 41,
	GREEN,YELLOW,BLUE,PURPLE,CYAN,WHITE,BLACK = 0,
}Color;

typedef enum {
	EMPTY = -1, I, J, L, O, S, T, Z,
}ShapeId;

typedef struct {
	ShapeId shape;
	Color color;
	int size;
	char rotates[4][4][4];
}Shape;

Shape shape[7] = {
	{
		.shape = I,
		.color = CYAN,
		.size = 4,
		.rotates = {
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,0,1,0},
				{0,0,1,0},
				{0,0,1,0},
				{0,0,1,0}
			},
			{
				{0,0,0,0},
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0}
			}
		}
	},
	{
		.shape = J,
		.color = BLUE,
		.size = 3,
		.rotates = {
			{
				{1,0,0},
				{1,1,1},
				{0,0,0}
			},
			{
				{0,1,1},
				{0,1,0},
				{0,1,0}
			},
			{
				{0,0,0},
				{1,1,1},
				{0,0,1}
			},
			{
				{0,1,0},
				{0,1,0},
				{1,1,0}
			}
		}
	},
	{
		.shape = L,
		.color = YELLOW,
		.size = 3,
		.rotates = {
			{
				{0,0,1},
				{1,1,1},
				{0,0,0}
			},
			{
				{0,1,0},
				{0,1,0},
				{0,1,1}
			},
			{
				{0,0,0},
				{1,1,1},
				{1,0,0}
			},
			{
				{1,1,0},
				{0,1,0},
				{0,1,0}
			}
		}
	},
	{
		.shape = O,
		.color = GREEN,
		.size = 2,
		.rotates = {
			{
				{1,1},
				{1,1}
			},
			{
				{1,1},
				{1,1}
			},
			{
				{1,1},
				{1,1}
			},
			{
				{1,1},
				{1,1}
			}
		}
	},
	{
		.shape = S,
		.color = PURPLE,
		.size = 3,
		.rotates = {
			{
				{0,1,1},
				{1,1,0},
				{0,0,0}
			},
			{
				{0,1,0},
				{0,1,1},
				{0,0,1}
			},
			{
				{0,0,0},
				{0,1,1},
				{1,1,0}
			},
			{
				{1,0,0},
				{1,1,0},
				{0,1,0}
			}
		}
	},
	{
		.shape = T,
		.color = RED,
		.size = 3,
		.rotates = {
			{
				{0,1,0},
				{1,1,1},
				{0,0,0}
			},
			{
				{0,1,0},
				{0,1,1},
				{0,1,0}
			},
			{
				{0,0,0},
				{1,1,1},
				{0,1,0}
			},
			{
				{0,1,0},
				{1,1,0},
				{0,1,0}
			}
		}
	},
	{
		.shape = Z,
		.color = WHITE,
		.size = 3,
		.rotates = {
			{
				{1,1,0},
				{0,1,1},
				{0,0,0}
			},
			{
				{0,0,1},
				{0,1,1},
				{0,1,0}
			},
			{
				{0,0,0},
				{1,1,0},
				{0,1,1}
			},
			{
				{0,1,0},
				{1,1,0},
				{1,0,0}
			}
		}
	}
};

typedef struct {
	Color color;
	ShapeId shape;
}Block;
int main(){
	Color cur;
	for (int i = 0; i < 7; i++) {
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				for (int k = 0; k < 4; k++) {
					if (shape[i].rotates[r][c][k] == 1) {
						cur = shape[i].color;
					}else {
						cur = BLACK;
					}
					printf("\033[%dm  \033[0m", cur);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}