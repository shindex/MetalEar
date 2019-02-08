#include<ncurses.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include"load.h"
#include"ctrlshow.h"
#include"title.h"


int Game(FILE *stagemap, FILE *stagedata, FILE *enemydata1, FILE *enemydata2, FILE *enemydata3)
{
	Player	player;
	Enemy	enemy1, enemy2, enemy3;
	Img	img;
	int	key;
	int	*i1, *i2, *i3;
	int	j1=0, j2=0, j3=0;
	int	a=0;
	Map	map;

	i1 = &j1;
	i2 = &j2;
	i3 = &j3;

	timeout(0.1);
	clear();
	Loadstage(stagedata, stagemap, &player, &map);
	Loadenemy(enemydata1, &enemy1);
	Loadenemy(enemydata2, &enemy2);
	Loadenemy(enemydata3, &enemy3);

	getmaxyx(stdscr, img.h, img.w);
	img.pixel = (char *)malloc(sizeof(char)*img.w*img.h);
	if (img.pixel == NULL) goto ERROR;

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);		//デフォルトの色
	init_pair(2, COLOR_GREEN, COLOR_BLACK);		//ステージの色
	init_pair(3, COLOR_WHITE, COLOR_BLACK);		//スネークの色

	while (1) {
		erase();
		attrset(COLOR_PAIR(2));
		DrawMap(&map);				//ステージ読み込み
		attrset(COLOR_PAIR(3));
                ShowPlayer(&player);                    //スネーク読み込み
		ShowEnemy(&enemy1, &map, i1);		//敵1の表示
		ShowEnemy(&enemy2, &map, i2);		//敵2の表示
		ShowEnemy(&enemy3, &map, i3);		//敵2の表示
		refresh();
		if (a == 10) {
			a=0;
                        j1++; j2++; j3++;               //カウンタアップ
                        CtrlEnemy(&enemy1, i1);         //敵のコントロール
                        CtrlEnemy(&enemy2, i2);         //敵のコントロール
                        CtrlEnemy(&enemy3, i3);         //敵のコントロール
                }
                a++;
		if (map.wall[player.y][player.x] == 'G') goto SUCCESS;
		if (Discovery(&player) == 1) goto FAILURE;
		key = getch();
		CtrlPlayer(&player, &map, key);
		if (key == 'q') {
			attrset(COLOR_PAIR(1));		
			goto END;
		}
		usleep(20000);
	}

END:
	free(img.pixel);
	return(0);

SUCCESS:
	timeout(-1);
	attrset(COLOR_PAIR(1));
	key = Ocelot(&img);
	if (key == ' ') {
		return(0);
	} else {
		goto SUCCESS;
	}

FAILURE:
	timeout(-1);
	attrset(COLOR_PAIR(1));
	key = Warning(&img);
	if (key == ' ') {
		return(0);
	} else {
		goto FAILURE;
	}	

ERROR:
	return(1);
}

int main(void)
{
	FILE	*stagemap;	//ステージマップファイル
	FILE	*stagedata;	//ステージデータファイル
	FILE	*enemydata1;
	FILE	*enemydata2;
	FILE	*enemydata3;
	int	key;		//入力キー
	Img	img;

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	getmaxyx(stdscr, img.h, img.w);

TITLE:
	key = Title1(&img);
	if (key == 'q') {
		goto END;
	} else if (key == ' ') {
		goto GAME;
	} else {
		goto TITLE;
	}
	
GAME:
	while (1) {
		timeout(-1);
		key = Title2(&img);

		switch (key) {
		case 'q':
			goto TITLE;
		case '1':
			if (
			((stagemap = fopen("stage-1-map.txt", "r")) == NULL) ||
			((stagedata = fopen("stage-1-data.txt", "r")) == NULL) ||
			((enemydata1 = fopen("stage-1-enemy1.txt", "r")) == NULL) ||
			((enemydata2 = fopen("stage-1-enemy2.txt", "r")) == NULL) ||
			((enemydata3 = fopen("stage-1-enemy3.txt", "r")) == NULL) )
			goto END;
			break;
		case '2':
			stagemap = fopen("stage-2-map.txt", "r");
			stagedata = fopen("stage-2-data.txt", "r");
			enemydata1 = fopen("stage-2-enemy1.txt", "r");
			enemydata2 = fopen("stage-2-enemy2.txt", "r");
			enemydata3 = fopen("stage-2-enemy3.txt", "r");
			break;
		case 's':
			stagemap = fopen("stage-my1-map.txt", "r");
                	stagedata = fopen("stage-my1-data.txt", "r");
                        enemydata1 = fopen("stage-my1-enemy1.txt", "r");
                        enemydata2 = fopen("stage-my1-enemy2.txt", "r");
                        enemydata3 = fopen("stage-my1-enemy3.txt", "r");
			break;
		default:
			continue;
		}
		Game(stagemap, stagedata, enemydata1, enemydata2, enemydata3);
	}
	fclose(stagemap);
	fclose(stagedata);
	fclose(enemydata1);
	fclose(enemydata2);
	fclose(enemydata3);
	
END:
	endwin();
	return(0);
}
