#include<DxLib.h>
#include"Stage1.h"
#include"Config.h"


void Game_Stage1(){ //�X�e�[�W�P�Ɋւ��Ă̊֐����Ăяo���֐�
	Draw_Stage1();
}

void Draw_Stage1(){ //�X�e�[�W�P�̕`��Ɋւ���֐�
	DrawString(0, 30, "�X�e�[�W�P�ł��B", WHITE);
	DrawBox(320, 120, 380, 180, RED, true);
	DrawBox(520, 320, 580, 380, RED, true);
	DrawBox(600, 0, 640, 70, RED, true);
}