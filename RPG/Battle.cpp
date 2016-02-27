#include<DxLib.h>
#include"Config.h"
#include"Key.h"
#include"Game.h"
#include"Battle.h"



static int game_end; //ゲームが終わったかどうかの状態を入れておく変数

static int my_life; //自分のHP
static int my_offensive_power; //自分の攻撃力
static int my_defense; //自分の防御力
static int my_recovery; //自分の回復量を入れておく

static int enemy_life; //敵のHP
static int enemy_offensive_power; //敵の攻撃力
static int enemy_defense; //敵の防御力
static int enemy_recovery; //敵の回復量を入れておく



enum{
	MY_TURN,
	ENEMY_TURN
}turn;


void Game_Battle_Init(){ //Game_Battleで使う変数の初期化
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


void Game_Battle(){ //バトル画面の関数
	DrawString(140, 30,           "バトル画面", WHITE);
	DrawFormatString(0, 30, WHITE, "game_end = %d", game_end);
	Draw_Battle();


	switch (turn){ //ターンのチェンジ
	case MY_TURN:
		DrawString(100, 0, "自分のターン", WHITE);
		My_Turn();
		break;
	case ENEMY_TURN:
		DrawString(100, 0, "敵のターン", WHITE);
		Enemy_Turn();
		break;
	}





	if (my_life <= 0){ //自分の体力が０以下になったらバトルを終わらせる
		game_end = 1;
	}

	if (enemy_life <= 0){ //敵の体力が０以下になったらバトルを終わらせる
		game_end = 1;
	}

	if (my_life > 100){ //自分のライフが最初のライフ以上にならないようにする
		my_life = 100;
	}
	if (enemy_life > 20){ //敵のライフが最初のライフ以上にならないようにする
		enemy_life = 20;
	}
}

void Draw_Battle(){ //バトルの画面の描画する関数
	DrawBox(0, 380, WIN_WIDTH, WIN_HEIGHT, RED, false);
	DrawString(0, 390, "０で攻撃", BLUE);
	DrawString(0, 420, "１で防御", BLUE);
	DrawString(0, 450, "２で回復", BLUE);


	DrawFormatString(300, 390, YELLOW, "自分の体力：%d", my_life);
	DrawFormatString(300, 420, YELLOW, "敵の体力：%d", enemy_life);

	DrawBox(450, 390, 450 + my_life, 410, RED, true);
	DrawBox(450, 420, 450 + enemy_life, 440, RED, true);



	DrawBox(70, 270, 150, 370, GREEN, true);
	DrawBox(470, 10, 550, 119, PINK, true);
}




int Get_Game_End(){ //game_endの値を返すだけの関数
	return game_end;
}


void My_Turn(){ //自分のターンになったらできること関数
	if (Key_Get(KEY_INPUT_0) == 1){ //０を押したら相手に攻撃、その後相手のターンに
		enemy_life -= my_offensive_power;
		turn = ENEMY_TURN;
	}
	if (Key_Get(KEY_INPUT_1) == 1){ //未実装

	}
	if (Key_Get(KEY_INPUT_2) == 1){ //２を押したら自分の体力が回復、その後相手のターンに
		my_life += my_recovery;
		turn = ENEMY_TURN;
	}

}


void Enemy_Turn(){ //敵のターンで起こる関数
	my_life -= enemy_offensive_power; //今は、自分の体力を削ってくるだけ。その後自分のターンに
	turn = MY_TURN;

}