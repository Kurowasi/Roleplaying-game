#include<DxLib.h>
#include"Stage5.h"
#include"Config.h"


void Game_Stage5(){ //ステージ５に関しての関数を呼び出す関数
	Draw_Stage5();
}

void Draw_Stage5(){ //ステージ５の描画に関する関数
	DrawString(0, 30, "ステージ５です。", WHITE);
	DrawBox(320, 120, 380, 180, PINK, true);
	DrawBox(520, 320, 580, 380, PINK, true);
	DrawBox(600, 0, 640, 70, PINK, true);
}