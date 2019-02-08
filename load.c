#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include"load.h"

/*
[注意]
stage-?-data.txtのマップの高さと幅は、1から数えて入力すること！
それ以外の値(座標)は、0から数えて入力する。
*/

void Loadstage(FILE *stagedata, FILE *stagemap, Player *player, Map *map)
{
	char	a[256];
	int	x, y;

	fgets(a, 256, stagedata);
	player->y = atoi(strtok(a, "\n"));  		//スタート位置のy座標
	fgets(a, 256, stagedata);
	player->x = atoi(strtok(a, "\n"));		//スタート位置のx座標
	fgets(a, 256, stagedata);
	map->h = atoi(strtok(a, "\n"));			//マップの高さ	
	fgets(a, 256, stagedata);
	map->w = atoi(strtok(a, "\n"));			//マップの幅

	for (y=0; y<map->h; y++) {
		for (x=0; x<map->w+1; x++){
			map->wall[y][x] = fgetc(stagemap);
		}
	}
}

void Loadenemy(FILE *enemydata, Enemy *enemy)
{
	char    a[256];
	int	i=0, j=0;

	fgets(a, 256, enemydata);
        enemy->y = atoi(strtok(a, "\n"));  	//enemyの初期y座標
	fgets(a, 256, enemydata);
        enemy->x = atoi(strtok(a, "\n"));  	//enemyの初期x座標	
	fgets(a, 256, enemydata);
        while(1) {
        	enemy->move[i] = a[j];
		i++;
		j++;
		if (a[j] == '\n') break;
    	}
}
