#include<DxLib.h>
#include"Stage4.h"
#include"Config.h"


void Game_Stage4(){ //�X�e�[�W�S�Ɋւ��Ă̊֐����Ăяo���֐�
	Draw_Stage4();
}

void Draw_Stage4(){ //�X�e�[�W�S�̕`��Ɋւ���֐�
	DrawString(0, 30, "�X�e�[�W�S�ł��B", WHITE);
	DrawBox(320, 120, 380, 180, GREEN, true);
	DrawBox(520, 320, 580, 380, GREEN, true);
	DrawBox(600, 0, 640, 70, GREEN, true);
}