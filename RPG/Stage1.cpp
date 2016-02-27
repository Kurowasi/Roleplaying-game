#include<DxLib.h>
#include"Stage1.h"
#include"Config.h"


void Game_Stage1(){ //ステージ１に関しての関数を呼び出す関数
	Draw_Stage1();
}

void Draw_Stage1(){ //ステージ１の描画に関する関数
	DrawString(0, 30, "ステージ１です。", WHITE);
	DrawBox(320, 120, 380, 180, RED, true);
	DrawBox(520, 320, 580, 380, RED, true);
	DrawBox(600, 0, 640, 70, RED, true);
}