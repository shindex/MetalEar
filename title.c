#include<ncurses.h>
#include<string.h>
#include"title.h"

int Warning(Img *img)
{
	int	sx, sy;
	sx = img->w / 2;
        sy = img->h / 2;

	mvaddstr(sy, sx, "SHAKE IS DEAD");
	mvaddstr(sy+1, sx-9, "press space key to go back to menu");
	refresh();
	return(getch());
}	

int Ocelot(Img *img)
{
	int	sx1, sx2, sy;
	sx1 = img->w / 2 - 22;
	sx2 = img->w / 2 - 18;
	sy = img->h / 2 - 9;
	
	mvaddstr(sy, sx1, "| ##    ## ####  ##  ##  ##  #####  ######  |");
	mvaddstr(sy+1, sx1, "|  ##  ## ##  ## ##  ##  ##      ##         |");
	mvaddstr(sy+2, sx1, "|   ####  ##  ## ##  ##      #####  ######  |");
	mvaddstr(sy+3, sx1, "|    ##   ##  ## ##  ##      ## ##  ##      |");
	mvaddstr(sy+4, sx1, "|    ##    ####   ####       ##  ## ######  |");
	mvaddstr(sy+6, sx1, "|#####  #####  ###### ###### ###### ##    ##|");
	mvaddstr(sy+7, sx1, "|##  ##     ##          ##     ##    ##  ## |");
	mvaddstr(sy+8, sx1, "|#####  #####  ######   ##     ##     ####  |");
	mvaddstr(sy+9, sx1, "|##     ## ##  ##       ##     ##      ##   |");
	mvaddstr(sy+10, sx1, "|##     ##  ## ######   ##     ##      ##   |");
	mvaddstr(sy+12, sx1, "| ######  #####   #####  ######    ###  ### |");
	mvaddstr(sy+13, sx1, "|##      ##   ## ##   ## ##  ###   ###  ### |");
	mvaddstr(sy+14, sx1, "|## #### ##   ## ##   ## ##   ###  ###  ### |");
	mvaddstr(sy+15, sx1, "|##   ## ##   ## ##   ## ##  ###            |");
	mvaddstr(sy+16, sx1, "| ######  #####   #####  ######    ###  ### |");
	mvaddstr(sy+19, sx2, "Press space key to go to mission menu");
	refresh();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);         //通常の色
	attrset(COLOR_PAIR(1));	
	return(getch());
}

int Title1(Img *img)
{
	int 	sx1, sx3, sy;
	
	clear();
	sx1 = (img->w / 2) - 36;		//タイトルの真ん中決め
	sx3 = (img->w / 2) - 5;
	sy = (img->h / 2) - 7;

          mvaddstr(sy, sx1, "      ##    ##  ######  ######    ##   ##     ######      ##   #####   ");
	mvaddstr(sy+1, sx1, "     ###   ###            ##     ###   ##                ###       ##  ");
	mvaddstr(sy+2, sx1, "    ## # ## ##  ######    ##    ## ##  ##     ######    ## ##  #####   ");
	mvaddstr(sy+3, sx1, "   ##  ##   ##  ##        ##   ##  ##  ##     ##       ##  ##  ## ##   ");
	mvaddstr(sy+4, sx1, "  ##   #    ##  ######    ##  ##   ##  #####  ######  ##   ##  ##  ##  ");
	mvaddstr(sy+5, sx1, " ##                                                                 ## ");
	mvaddstr(sy+6, sx1, "##                                                                   ##");
	mvaddstr(sy+8, sx3, "press space key");
	refresh();
	return(getch());
}

int Title2(Img *img)
{
	int	sx, sy;

	clear();
	sx = (img->w / 2) - 21;
	sy = (img->h / 2) - 7;

	mvaddstr(sy, sx, "                  [Missions]                   ");
	mvaddstr(sy+2, sx, "|   Your missions are to go to 'G' from 'S'   |");
	mvaddstr(sy+3, sx, "|          Must not be found by enemy         |");
	mvaddstr(sy+4, sx, "|        There is no support from here        |");
	mvaddstr(sy+5, sx, "|             Good luck with that             |");
	mvaddstr(sy+7, sx, "Press 'WASD' to move");
	mvaddstr(sy+8, sx, "Press '1' to go ahead 'LOADING DOCK' [ME]");
	mvaddstr(sy+9, sx, "Press '2' to go ahead 'PUETRO DE ALAMA' [MEPW]");
	mvaddstr(sy+10, sx, "Press 's' to go ahead 'SPECIAL STAGE' [created by Shin]");
	mvaddstr(sy+11, sx, "Press 'q' to back to title");
	return(getch());
}
