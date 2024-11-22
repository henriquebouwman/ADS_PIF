#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "cli/screen.h"
#include "cli/keyboard.h"
#include "cli/timer.h"


const char
	left = 'a', right = 'd',
	up = 'w', down = 's',
	space = ' ';
unsigned int
	ROWS = 8, COLS = 16,
	c_y = 0, c_x = 0,
	revealed = 0, mines = 20;

char** board;
char** display;

bool limits(int x, int y) {
	return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

void start_board() {
	board = (char**) malloc(ROWS * sizeof(char*));
	display = (char**) malloc(ROWS * sizeof(char*));
	for(int x = 0; x < ROWS; x++) {
		board[x] = (char*) malloc(COLS * sizeof(char));
		display[x] = (char*) malloc(COLS * sizeof(char));
		for (int y = 0; y < COLS; y++) {
			board[x][y] = '-';
			display[x][y] = '-';
		}
	}
	srand(time(NULL));
	for(int i=0; i < mines; i++) {
		int x = rand() % ROWS;
		int y = rand() % COLS;
		i--;
		if (board[x][y] != 'M') {
			board[x][y] = 'M';
			i++;
		}
	}
}

char select_cell(int x, int y) {
	if (!limits(x, y) || display[x][y] != '-') {
		return -1;
	} else if(board[x][y] == 'M') {
		display[x][y] = 'M';
		return 'M';
	}
	char count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue;
			x += i; y += j;
			if (limits(x, y) && board[x][y] == 'M') {
				count++;
			}
			x -= i; y -= j;
		}
	}
	if (count > 0) {
		count = '0' + count;
		display[x][y] = count;
		revealed++;
		return count;
	}
	display[x][y] = ' ';
	revealed++;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue;
			select_cell(x + i, y + j);
		}
	}
	return ' ';
}

bool print_cell(int x, int y) {
	if(!limits(x, y)) {
		return false;
	}
	char c = display[x][y];
	screenGotoxy(x*2, y+3);

	screenColor fg, bg=BLACK;
	switch(c) {
		case 'M':	fg = RED; break;
		case '-':	fg = CYAN; break;
		case '.':	fg = GREEN; break;
		default:	fg = YELLOW; break;
	}
	screenSetColor(fg, bg);
	printf(" ");
	if(c_x == x && c_y == y) {
		bg = LIGHTGRAY;
	}
	screenSetColor(fg, bg);
	printf("%c", c);
	return true;
}

void tell(char* message, bool reveal) {
	screenGotoxy(3, 1);
	screenSetColor(WHITE, BLACK);
	printf("%s", message);
	if(reveal) {
		for(int i = 0; reveal && i < ROWS; i++) {
			for(int j = 0; j < COLS; j++) {
				if(board[i][j] == 'M') {
					display[i][j] = 'M';
				}
			}
		}
	}
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			print_cell(i, j);
		}
	}
	screenUpdate();
}

bool move_cursor(int dx, int dy) {
	c_x += dx;
	c_y += dy;
	if(!limits(c_x, c_y)) {
		c_x -= dx;
		c_y -= dy;
		return false;
	}
	print_cell(c_x, c_y);
	print_cell(c_x - dx, c_y - dy);
	return true;
}

int main() {
	screenInit(0);
	keyboardInit();
	timerInit(50);

	int game_status = 0;
	char ch;

	start_board();
	move_cursor(ROWS/2, COLS/2);
	while(true) {
		tell("Encontre   ", false);
		ch = readch();
		switch (ch) {
			case left:
				move_cursor(-1, 0);
				continue;
			case right:
				move_cursor(+1, 0);
				continue;
			case up:
				move_cursor(0, -1);
				continue;
			case down:
				move_cursor(0, +1);
				continue;
			case space:
				if(select_cell(c_x, c_y) == 'M') {
					game_status = -1;
				}
				break;
			case '0':
				game_status = -2;
				break;
			default:
				continue;
		}

		if(game_status == -2) {
			tell("Fraco!      ", true);
			break;
		} else if(game_status == -1) {
			tell("Perdeu!     ", true);
			break;
		} else if (revealed + mines >= ROWS * COLS) {
			tell("Venceu!     ", true);
			break;
		}
	}

	for(int i=0; i<5; i++) {
		readch();
	}
	keyboardDestroy();
	screenDestroy();
	timerDestroy();
	return 0;
}
