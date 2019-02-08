#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct {
	int	x, y;		//自キャラの座標
} Player;

typedef struct {
	double	x, y;		//敵キャラ1の座標
	char	move[256];	//敵キャラの動き
} Enemy;

typedef struct {
	int	w, h;		//端末の幅と高さ
	char	*pixel;		//端末に表示する文字列
} Img;

typedef struct {
	int	w, h;		//ステージの幅と高さ
	char	wall[256][256];		//ステージの壁
} Map;

#endif
