#include<DxLib.h>
#include"Stage2.h"
#include"Config.h"



void Game_Stage2(){ //�X�e�[�W�P�Ɋւ��Ă̊֐����Ăяo���֐�
	Draw_Stage2();
}

void Draw_Stage2(){ //�X�e�[�W�P�̕`��Ɋւ���֐�
	DrawString(0, 30, "�X�e�[�W�Q�ł��B", WHITE);
	DrawBox(320, 120, 380, 180, BLUE, true);
	DrawBox(520, 320, 580, 380, BLUE, true);
	DrawBox(600, 0, 640, 70, BLUE, true);

}
