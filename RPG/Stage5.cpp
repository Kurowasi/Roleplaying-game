#include<DxLib.h>
#include"Stage5.h"
#include"Config.h"


void Game_Stage5(){ //�X�e�[�W�T�Ɋւ��Ă̊֐����Ăяo���֐�
	Draw_Stage5();
}

void Draw_Stage5(){ //�X�e�[�W�T�̕`��Ɋւ���֐�
	DrawString(0, 30, "�X�e�[�W�T�ł��B", WHITE);
	DrawBox(320, 120, 380, 180, PINK, true);
	DrawBox(520, 320, 580, 380, PINK, true);
	DrawBox(600, 0, 640, 70, PINK, true);
}