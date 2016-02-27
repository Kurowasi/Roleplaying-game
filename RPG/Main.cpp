//�ǂɏՓ˂��Ă��āA�����ĂȂ��Ă��G���J�E���g����
//�o�g���Ɋւ��Ă̓��e���{���{��
//�X�e�[�W�ł̃t�B�[���h�ɂ�����̂̓����蔻������Ă��Ȃ�



#include<DxLib.h>
#include"Config.h"
#include"Key.h"
#include"Game.h"
#include"Battle.h"
bool Process_Loop(char key[256]){
	if (ScreenFlip() != 0) return false;
	if (ProcessMessage() != 0) return false;
	if (ClearDrawScreen() != 0) return false;
	if (GetHitKeyStateAll(key)) return false;

	return true;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 16);
	enum {
		TITLE,
		GAME,
		RESULT
	}state = TITLE;
	char key[256];
	Game_Init();
	Game_Battle_Init();
	while (Process_Loop(key)){
		Key_Update();
		switch (state){
		case TITLE:
			if (Key_Get(KEY_INPUT_RETURN) == 1){
				state = GAME;
			}
			DrawString(0, 0, "�^�C�g�����", WHITE);
			break;
		case GAME:
			Game_Main();
			if (Get_Game_End_Flag() == true){
				state = RESULT;
			}
			break;
		case RESULT:
			DrawString(0, 0, "���ʉ��", WHITE);
			break;
		}
	}

	WaitKey();
	DxLib_End();
	return 0;
}


int Get_State(){
	int i = 0;
	return i;
}