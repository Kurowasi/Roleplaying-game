#include<DxLib.h>
#include"Stage3.h"
#include"Config.h"

void Game_Stage3(){
	Draw_Stage3();
}

void Draw_Stage3(){
	DrawString(0, 30, "ステージ３です。", WHITE);
	DrawBox(320, 120, 380, 180, YELLOW, true);
	DrawBox(520, 320, 580, 380, YELLOW, true);
	DrawBox(600, 0, 640, 70, YELLOW, true);
}