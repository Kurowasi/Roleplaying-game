#include<DxLib.h>
#include"Stage2.h"
#include"Config.h"



void Game_Stage2(){ //ステージ１に関しての関数を呼び出す関数
	Draw_Stage2();
}

void Draw_Stage2(){ //ステージ１の描画に関する関数
	DrawString(0, 30, "ステージ２です。", WHITE);
	DrawBox(320, 120, 380, 180, BLUE, true);
	DrawBox(520, 320, 580, 380, BLUE, true);
	DrawBox(600, 0, 640, 70, BLUE, true);

}
