#include<DxLib.h>
#include"Config.h"
#include"Key.h"
#include"Game.h"
#include"Battle.h"



static int game_end; //�Q�[�����I��������ǂ����̏�Ԃ����Ă����ϐ�

static int my_life; //������HP
static int my_offensive_power; //�����̍U����
static int my_defense; //�����̖h���
static int my_recovery; //�����̉񕜗ʂ����Ă���

static int enemy_life; //�G��HP
static int enemy_offensive_power; //�G�̍U����
static int enemy_defense; //�G�̖h���
static int enemy_recovery; //�G�̉񕜗ʂ����Ă���



enum{
	MY_TURN,
	ENEMY_TURN
}turn;


void Game_Battle_Init(){ //Game_Battle�Ŏg���ϐ��̏�����
	game_end = 0;
	my_life = 100;
	my_offensive_power = 5;
	my_defense = 20;
	my_recovery = 50;

	enemy_life = 20;
	enemy_offensive_power = 10;
	enemy_defense = 10;
	enemy_recovery = 20;

	

}


void Game_Battle(){ //�o�g����ʂ̊֐�
	DrawString(140, 30,           "�o�g�����", WHITE);
	DrawFormatString(0, 30, WHITE, "game_end = %d", game_end);
	Draw_Battle();


	switch (turn){ //�^�[���̃`�F���W
	case MY_TURN:
		DrawString(100, 0, "�����̃^�[��", WHITE);
		My_Turn();
		break;
	case ENEMY_TURN:
		DrawString(100, 0, "�G�̃^�[��", WHITE);
		Enemy_Turn();
		break;
	}





	if (my_life <= 0){ //�����̗̑͂��O�ȉ��ɂȂ�����o�g�����I��点��
		game_end = 1;
	}

	if (enemy_life <= 0){ //�G�̗̑͂��O�ȉ��ɂȂ�����o�g�����I��点��
		game_end = 1;
	}

	if (my_life > 100){ //�����̃��C�t���ŏ��̃��C�t�ȏ�ɂȂ�Ȃ��悤�ɂ���
		my_life = 100;
	}
	if (enemy_life > 20){ //�G�̃��C�t���ŏ��̃��C�t�ȏ�ɂȂ�Ȃ��悤�ɂ���
		enemy_life = 20;
	}
}

void Draw_Battle(){ //�o�g���̉�ʂ̕`�悷��֐�
	DrawBox(0, 380, WIN_WIDTH, WIN_HEIGHT, RED, false);
	DrawString(0, 390, "�O�ōU��", BLUE);
	DrawString(0, 420, "�P�Ŗh��", BLUE);
	DrawString(0, 450, "�Q�ŉ�", BLUE);


	DrawFormatString(300, 390, YELLOW, "�����̗̑́F%d", my_life);
	DrawFormatString(300, 420, YELLOW, "�G�̗̑́F%d", enemy_life);

	DrawBox(450, 390, 450 + my_life, 410, RED, true);
	DrawBox(450, 420, 450 + enemy_life, 440, RED, true);



	DrawBox(70, 270, 150, 370, GREEN, true);
	DrawBox(470, 10, 550, 119, PINK, true);
}




int Get_Game_End(){ //game_end�̒l��Ԃ������̊֐�
	return game_end;
}


void My_Turn(){ //�����̃^�[���ɂȂ�����ł��邱�Ɗ֐�
	if (Key_Get(KEY_INPUT_0) == 1){ //�O���������瑊��ɍU���A���̌㑊��̃^�[����
		enemy_life -= my_offensive_power;
		turn = ENEMY_TURN;
	}
	if (Key_Get(KEY_INPUT_1) == 1){ //������

	}
	if (Key_Get(KEY_INPUT_2) == 1){ //�Q���������玩���̗̑͂��񕜁A���̌㑊��̃^�[����
		my_life += my_recovery;
		turn = ENEMY_TURN;
	}

}


void Enemy_Turn(){ //�G�̃^�[���ŋN����֐�
	my_life -= enemy_offensive_power; //���́A�����̗̑͂�����Ă��邾���B���̌㎩���̃^�[����
	turn = MY_TURN;

}