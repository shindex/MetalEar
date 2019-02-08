#include<ncurses.h>
#include<string.h>
#include"ctrlshow.h"

void CtrlPlayer(Player *player, Map *map, int key)
{
	switch (key) {
	case 'a': {
		if (map->wall[player->y][player->x-1] == '#') break;
		(player->x)--;	break;
	}
	case 's': {
		if (map->wall[player->y+1][player->x] == '#') break;
		(player->y)++;	break;
	}
	case 'w': {
		if (map->wall[player->y-1][player->x] == '#') break;
		(player->y)--;	break;
	}
	case 'd': {
		if (map->wall[player->y][player->x+1] == '#') break;
		(player->x)++;	break;
	}
	}	
}

void CtrlEnemy(Enemy *enemy, int *i)
{
	switch (enemy->move[*i]) {
	case 'a': {
		(enemy->x) = (enemy->x - 1);	break;
	}
	case 's': {
		(enemy->y) = (enemy->y + 1);	break;
	}	
	case 'w': {
		(enemy->y) = (enemy->y - 1);	break;
	}
	case 'd': {
		(enemy->x) = (enemy->x + 1);	break;
	}
	default:
		*i = 0;
	}
}

void ShowPlayer(Player *player)
{
	mvaddch(player->y, player->x, '$');
}

void ShowEnemy(Enemy *enemy, Map *map, int *i)
{
	int	a;

	start_color();
        init_pair(4, COLOR_RED, COLOR_BLACK);           //敵の色
        init_pair(5, COLOR_BLUE, COLOR_BLUE);           //敵の視界の色
	
	switch (enemy->move[*i]) {
        case 'a': {
		attrset(COLOR_PAIR(5));
		for (a=1; a<=6; a++) {
                        if (map->wall[(int)enemy->y-2][(int)enemy->x-(11-a)] == '#') continue;
                        mvaddch(enemy->y-2, enemy->x-(11-a), '*');
                }
		for (a=1; a<=8; a++) {
			if (map->wall[(int)enemy->y-1][(int)enemy->x-(11-a)] == '#') continue;
			mvaddch(enemy->y-1, enemy->x-(11-a), '*');
		}
		for (a=1; a<=10; a++) {
			if (map->wall[(int)enemy->y][(int)enemy->x-(11-a)] == '#') continue;
			mvaddch(enemy->y, enemy->x-(11-a), '*');
		}
		attrset(COLOR_PAIR(4));
		mvaddch(enemy->y, enemy->x, '@');
		attrset(COLOR_PAIR(5));
		for (a=1; a<=8; a++) {
			if (map->wall[(int)enemy->y+1][(int)enemy->x-(11-a)] == '#') continue;
			mvaddch(enemy->y+1, enemy->x-(11-a), '*');
		}
		for (a=1; a<=6; a++) {
                        if (map->wall[(int)enemy->y+2][(int)enemy->x-(11-a)] == '#') continue;
                        mvaddch(enemy->y+2, enemy->x-(11-a), '*');
                }
		break;
        }
        case 's': {
		attrset(COLOR_PAIR(4));
                mvaddch(enemy->y, enemy->x, '@');
		attrset(COLOR_PAIR(5));
		for (a=1; a<=3; a++) {
			if (map->wall[(int)enemy->y+1][(int)enemy->x-(2-a)] == '#') continue;
			mvaddch(enemy->y+1, enemy->x-(2-a), '*');
		}
		for (a=1; a<=5; a++) {
			if (map->wall[(int)enemy->y+2][(int)enemy->x-(3-a)] == '#') continue;
			mvaddch(enemy->y+2, enemy->x-(3-a), '*');
		}
		for (a=1; a<=7; a++) {
			if (map->wall[(int)enemy->y+3][(int)enemy->x-(4-a)] == '#') continue;
			mvaddch(enemy->y+3, enemy->x-(4-a), '*');
		}
		for (a=1; a<=9; a++) {
			if (map->wall[(int)enemy->y+4][(int)enemy->x-(5-a)] == '#') continue;
			mvaddch(enemy->y+4, enemy->x-(5-a), '*');
		}
		break;
        }
        case 'w': {
		attrset(COLOR_PAIR(5));
		for (a=1; a<=9; a++) {
			if (map->wall[(int)enemy->y-4][(int)enemy->x-(5-a)] == '#') continue;
			mvaddch(enemy->y-4, enemy->x-(5-a), '*');
		}
		for (a=1; a<=7; a++) {
			if (map->wall[(int)enemy->y-3][(int)enemy->x-(4-a)] == '#') continue;
			mvaddch(enemy->y-3, enemy->x-(4-a), '*');
		}
		for (a=1; a<=5; a++) {
			if (map->wall[(int)enemy->y-2][(int)enemy->x-(3-a)] == '#') continue;
			mvaddch(enemy->y-2, enemy->x-(3-a), '*');
		}
		for (a=1; a<=3; a++) {
			if (map->wall[(int)enemy->y-1][(int)enemy->x-(2-a)] == '#') continue;
			mvaddch(enemy->y-1, enemy->x-(2-a), '*');
		}
		attrset(COLOR_PAIR(4));
		mvaddch(enemy->y, enemy->x, '@');
		break;
        }
        case 'd': {
		attrset(COLOR_PAIR(5));
		for (a=1; a<=6; a++) {
			if (map->wall[(int)enemy->y-2][(int)enemy->x+(4+a)] == '#') continue;
			mvaddch(enemy->y-2, enemy->x+(4+a), '*');
		}
		for (a=1; a<=8; a++) {
			if (map->wall[(int)enemy->y-1][(int)enemy->x+(2+a)] == '#') continue;
			mvaddch(enemy->y-1, enemy->x+(2+a), '*');
		}
		attrset(COLOR_PAIR(4));
		mvaddch(enemy->y, enemy->x, '@');
		attrset(COLOR_PAIR(5));
		for (a=1; a<=10; a++) {
			if (map->wall[(int)enemy->y][(int)enemy->x+a] == '#') continue;
			mvaddch(enemy->y, enemy->x+a, '*');
		}
		for (a=1; a<=8; a++) {
			if (map->wall[(int)enemy->y+1][(int)enemy->x+(2+a)] == '#') continue;
			mvaddch(enemy->y+1, enemy->x+(2+a), '*');
		}
		for (a=1; a<=6; a++) {
                        if (map->wall[(int)enemy->y+2][(int)enemy->x+(4+a)] == '#') continue;
                        mvaddch(enemy->y+2, enemy->x+(4+a), '*');
		}
		break;
	}
	}
}



int DrawMap(Map *map)
{
	int	x, y;

	for (y = 0; y < map->h; y++) {
		for (x = 0; x < map->w; x++) {
			move(y, x);
			addch(map->wall[y][x]);
		}
	}
	return (0);
}

int Discovery(Player *player)
{
	char	c[1];
	int	a;

	move(player->y, player->x);
	innstr(c, 1);
	if (c[0] == '*') {
		a = 1;
		return(a);			//発見された
	} else {
		a = 0;
		return(a);			//発見されてない
	}
}
