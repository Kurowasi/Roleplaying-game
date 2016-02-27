#include<DxLib.h>
#include"Stage4.h"
#include"Config.h"


void Game_Stage4(){ //ステージ４に関しての関数を呼び出す関数
	Draw_Stage4();
}

void Draw_Stage4(){ //ステージ４の描画に関する関数
	DrawString(0, 30, "ステージ４です。", WHITE);
	DrawBox(320, 120, 380, 180, GREEN, true);
	DrawBox(520, 320, 580, 380, GREEN, true);
	DrawBox(600, 0, 640, 70, GREEN, true);
}