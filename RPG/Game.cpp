#include<DxLib.h>
#include"Game.h"
#include"Key.h"
#include"Config.h"
#include<time.h>
#include <stdlib.h>
#include"Stage1.h"
#include"Stage2.h"
#include"Stage3.h"
#include"Stage4.h"
#include"Stage5.h"
#include"Battle.h"

//�L�����N�^�[�̈ʒu�Ɋւ���ϐ�
static int chara_box_x1;
static int chara_box_x2;
static int chara_box_y1;
static int chara_box_y2;
//�L�����N�^�[�̈ړ����x�Ɋւ���ϐ�
static int chara_box_vx;
static int chara_box_vy;
//�G���J�E���g�Ɋւ���ϐ�
static int i_encount;
//���ʉ�ʂɍs���t���O
static bool game_end_flag;
//�o�g���ɍs���t���O
static bool game_battle_flag;
//�X�e�[�W�̊K�w���L�����Ă����ϐ�
static int count_stage;
//�o���l���L�����Ă����ϐ�
static int experience_point;



enum{
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5,
	BATTLE
}stage;


void Game_Main(){
	DrawString(0, 0, "�Q�[�����", WHITE);
	if (game_battle_flag == true){ //�o�g���̃t���O����������o�g����ʂ̊֐����Ăяo��
		DrawString(0, 150, "�o�g���̃t���O�������܂���", WHITE);
		Game_Battle();
	}
	Check_Game_End(); //Battle.cpp�̒���game_end�ϐ��̏�Ԃ��m�F����֐�
	DrawFormatString(0, 180, WHITE, "count_stage = %d", count_stage);






	switch (stage){
	case STAGE1:
		Game_Chara();
		if (experience_point >= 30){ //�o���l���R�O�ȏ�ɂȂ�����X�e�[�W�㏸
			experience_point = 0;
			stage = STAGE2;
		}
		count_stage = 1;
		Game_Stage1(); //�X�e�[�W�P�Ɋւ���֐��̌Ăяo��
		break;
	case STAGE2:
		Game_Chara();
		if (experience_point >= 30){ //�o���l���R�O�ȏ�ɂȂ�����X�e�[�W�㏸
			experience_point = 0;
			stage = STAGE3;
		}
		if (count_stage == 1){
			count_stage = 2;
		}
		Game_Stage2(); //�X�e�[�W�Q�Ɋւ���֐��̌Ăяo��
		break;
	case STAGE3:
		Game_Chara();
		if (experience_point >= 30){ //�o���l���R�O�ȏ�ɂȂ�����X�e�[�W�㏸
			experience_point = 0;
			stage = STAGE4;
		}
		if (count_stage == 2){
			count_stage = 3;
		}
		Game_Stage3(); //�X�e�[�W�R�Ɋւ���֐��̌Ăяo��
		break;
	case STAGE4:
		Game_Chara();
		if (experience_point >= 30){ //�o���l���R�O�ȏ�ɂȂ�����X�e�[�W�㏸
			experience_point = 0;
			stage = STAGE5;
		}
		if (count_stage == 3){
			count_stage = 4;
		}
		Game_Stage4(); //�X�e�[�W�S�Ɋւ���֐��̌Ăяo��
		break;
	case STAGE5:
		Game_Chara();
		if (experience_point >= 30){ //�o���l���R�O�ȏ�ɂȂ����猋�ʉ�ʂɈړ�
			game_end_flag = true;
		}
		if (count_stage == 4){
			count_stage = 5;
		}
		Game_Stage5();
		break;
	case BATTLE:
		break;
	}
}



void Game_Init(){ //�Q�[���Ŏg���ϐ��̏�����
	chara_box_x1 = 300;
	chara_box_x2 = 310;
	chara_box_y1 = 200;
	chara_box_y2 = 210;
	chara_box_vx = 10;
	chara_box_vy = 5;

	i_encount = 0;
	count_stage;
	experience_point = 0;

	game_end_flag = false;
	game_battle_flag = false;

	srand((unsigned)time(NULL));
}






void Game_Chara(){ //�X�e�[�W�Ŏg���L�����̊֐����Ăяo���֐�
	Chara_Draw(); //�`��
	Chara_Move(); //����
	Chara_Detection(); //�����蔻��
	Chara_Encount(); //�G���J�E���g
	DrawFormatString(0, 210, WHITE, "�o���l�F%d", experience_point);
	DrawBox(100, 210, 130, 230, RED, false);
	DrawBox(100, 210, 100 + experience_point, 230, RED, true);
}


void Chara_Draw(){ //�L�����N�^�[�̕`��
	DrawBox(chara_box_x1, chara_box_y1, chara_box_x2, chara_box_y2, WHITE, true);
}

void Chara_Move(){ //�����Ɋւ��Ă̊֐�
	if (Key_Get(KEY_INPUT_RIGHT) > 0 ){ //�E�{�^�����������Ƃ��ɉE�ɓ�����
		chara_box_x1 += chara_box_vx;
		chara_box_x2 += chara_box_vx;
		i_encount = rand() % 50;
		DrawString(0, 60, "�E��������Ă��܂�", WHITE);
	}
	if (Key_Get(KEY_INPUT_LEFT) > 0){ //���{�^�����������Ƃ��ɍ��ɓ�����
		chara_box_x1 -= chara_box_vx;
		chara_box_x2 -= chara_box_vx;
		i_encount = rand() % 50;
		DrawString(0, 60, "����������Ă��܂�", WHITE);
	}
	if (Key_Get(KEY_INPUT_UP) > 0){ //��{�^�����������Ƃ��ɏ�ɓ�����
		chara_box_y1 -= chara_box_vy;
		chara_box_y2 -= chara_box_vy;
		i_encount = rand() % 50;
		DrawString(0, 60, "�オ������Ă��܂�", WHITE);
	}
	if (Key_Get(KEY_INPUT_DOWN) > 0){ //���{�^�����������Ƃ��ɉ��ɓ�����
		chara_box_y1 += chara_box_vy;
		chara_box_y2 += chara_box_vy;
		i_encount = rand() % 50;
		DrawString(0, 60, "����������Ă��܂�", WHITE);
	}


}

void Chara_Detection(){ //�����蔻��Ɋւ��Ă̊֐�
	if (chara_box_x1 <= 0){ //��ʍ����̓����蔻��
		chara_box_x1 = 0;
		chara_box_x2 = 10;
		DrawString(0, 90, "�Փ˂��Ă��܂�", WHITE);
	}
	if (chara_box_y1 <= 0){ //��ʏ㑤�̓����蔻��
		chara_box_y1 = 0;
		chara_box_y2 = 10;
		DrawString(0, 90, "�Փ˂��Ă��܂�", WHITE);
	}
	if (chara_box_x2 >= WIN_WIDTH){ //��ʉE���̓����蔻��
		chara_box_x2 = WIN_WIDTH;
		chara_box_x1 = WIN_WIDTH - 10;
		DrawString(0, 90, "�Փ˂��Ă��܂�", WHITE);
	}
	if (chara_box_y2 >= WIN_HEIGHT){ //��ʉ����̓����蔻��
		chara_box_y2 = WIN_HEIGHT;
		chara_box_y1 = WIN_HEIGHT - 10;
		DrawString(0, 90, "�Փ˂��Ă��܂�", WHITE);
	}
}

void Chara_Encount(){ //�G�Ƃ̃G���J�E���g�Ɋւ��Ă̊֐�
	DrawFormatString(0, 120, WHITE, "%d" , i_encount);
	if (i_encount == 1){
		//stage = STAGE1;
		//Get_State();
		game_battle_flag = true; //Game_Battle���Ăяo����
		stage = BATTLE;
	}
}


bool Get_Game_End_Flag(){ //�Q�[�����I���Ɋւ���t���O��Ԃ��֐�
	return game_end_flag;
}


int Get_Count_Stage(){ //count_stage�̒l��n�������̊֐�
	return count_stage;
}


void Check_Game_End(){
	if (Get_Game_End() == 1){
		if (count_stage == 1){ //game_end���P�ɂȂ����̂ŃX�e�[�W�����̑O�ɂ����X�e�[�W�ɂ���
			stage = STAGE1;
		}
		else if (count_stage == 2){
			stage = STAGE2;
		}
		else if (count_stage == 3){
			stage = STAGE3;
		}
		else if (count_stage == 4){
			stage = STAGE4;
		}
		else if (count_stage == 5){
			stage = STAGE5;
		}
		game_battle_flag = false; //Game_Battle���Ăяo���Ȃ��悤�ɂ���
		Game_Battle_Init(); //Game_Battle�̏��������s���Agame_end���O�ɂ���
		i_encount = 0; //i_encount���P�̂܂܂ł܂��o�g����ʂɓ��邱�Ƃ�h��
		experience_point += 10; //�o�g�����I�������o���l���P�O���₷
	}
}


