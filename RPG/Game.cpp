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

//キャラクターの位置に関する変数
static int chara_box_x1;
static int chara_box_x2;
static int chara_box_y1;
static int chara_box_y2;
//キャラクターの移動速度に関する変数
static int chara_box_vx;
static int chara_box_vy;
//エンカウントに関する変数
static int i_encount;
//結果画面に行くフラグ
static bool game_end_flag;
//バトルに行くフラグ
static bool game_battle_flag;
//ステージの階層を記憶しておく変数
static int count_stage;
//経験値を記憶しておく変数
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
	DrawString(0, 0, "ゲーム画面", WHITE);
	if (game_battle_flag == true){ //バトルのフラグが立ったらバトル画面の関数を呼び出す
		DrawString(0, 150, "バトルのフラグが立ちました", WHITE);
		Game_Battle();
	}
	Check_Game_End(); //Battle.cppの中のgame_end変数の状態を確認する関数
	DrawFormatString(0, 180, WHITE, "count_stage = %d", count_stage);






	switch (stage){
	case STAGE1:
		Game_Chara();
		if (experience_point >= 30){ //経験値が３０以上になったらステージ上昇
			experience_point = 0;
			stage = STAGE2;
		}
		count_stage = 1;
		Game_Stage1(); //ステージ１に関する関数の呼び出し
		break;
	case STAGE2:
		Game_Chara();
		if (experience_point >= 30){ //経験値が３０以上になったらステージ上昇
			experience_point = 0;
			stage = STAGE3;
		}
		if (count_stage == 1){
			count_stage = 2;
		}
		Game_Stage2(); //ステージ２に関する関数の呼び出し
		break;
	case STAGE3:
		Game_Chara();
		if (experience_point >= 30){ //経験値が３０以上になったらステージ上昇
			experience_point = 0;
			stage = STAGE4;
		}
		if (count_stage == 2){
			count_stage = 3;
		}
		Game_Stage3(); //ステージ３に関する関数の呼び出し
		break;
	case STAGE4:
		Game_Chara();
		if (experience_point >= 30){ //経験値が３０以上になったらステージ上昇
			experience_point = 0;
			stage = STAGE5;
		}
		if (count_stage == 3){
			count_stage = 4;
		}
		Game_Stage4(); //ステージ４に関する関数の呼び出し
		break;
	case STAGE5:
		Game_Chara();
		if (experience_point >= 30){ //経験値が３０以上になったら結果画面に移動
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



void Game_Init(){ //ゲームで使う変数の初期化
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






void Game_Chara(){ //ステージで使うキャラの関数を呼び出す関数
	Chara_Draw(); //描画
	Chara_Move(); //動き
	Chara_Detection(); //当たり判定
	Chara_Encount(); //エンカウント
	DrawFormatString(0, 210, WHITE, "経験値：%d", experience_point);
	DrawBox(100, 210, 130, 230, RED, false);
	DrawBox(100, 210, 100 + experience_point, 230, RED, true);
}


void Chara_Draw(){ //キャラクターの描画
	DrawBox(chara_box_x1, chara_box_y1, chara_box_x2, chara_box_y2, WHITE, true);
}

void Chara_Move(){ //動きに関しての関数
	if (Key_Get(KEY_INPUT_RIGHT) > 0 ){ //右ボタンを押したときに右に動かす
		chara_box_x1 += chara_box_vx;
		chara_box_x2 += chara_box_vx;
		i_encount = rand() % 50;
		DrawString(0, 60, "右が押されています", WHITE);
	}
	if (Key_Get(KEY_INPUT_LEFT) > 0){ //左ボタンを押したときに左に動かす
		chara_box_x1 -= chara_box_vx;
		chara_box_x2 -= chara_box_vx;
		i_encount = rand() % 50;
		DrawString(0, 60, "左が押されています", WHITE);
	}
	if (Key_Get(KEY_INPUT_UP) > 0){ //上ボタンを押したときに上に動かす
		chara_box_y1 -= chara_box_vy;
		chara_box_y2 -= chara_box_vy;
		i_encount = rand() % 50;
		DrawString(0, 60, "上が押されています", WHITE);
	}
	if (Key_Get(KEY_INPUT_DOWN) > 0){ //下ボタンを押したときに下に動かす
		chara_box_y1 += chara_box_vy;
		chara_box_y2 += chara_box_vy;
		i_encount = rand() % 50;
		DrawString(0, 60, "下が押されています", WHITE);
	}


}

void Chara_Detection(){ //当たり判定に関しての関数
	if (chara_box_x1 <= 0){ //画面左側の当たり判定
		chara_box_x1 = 0;
		chara_box_x2 = 10;
		DrawString(0, 90, "衝突しています", WHITE);
	}
	if (chara_box_y1 <= 0){ //画面上側の当たり判定
		chara_box_y1 = 0;
		chara_box_y2 = 10;
		DrawString(0, 90, "衝突しています", WHITE);
	}
	if (chara_box_x2 >= WIN_WIDTH){ //画面右側の当たり判定
		chara_box_x2 = WIN_WIDTH;
		chara_box_x1 = WIN_WIDTH - 10;
		DrawString(0, 90, "衝突しています", WHITE);
	}
	if (chara_box_y2 >= WIN_HEIGHT){ //画面下側の当たり判定
		chara_box_y2 = WIN_HEIGHT;
		chara_box_y1 = WIN_HEIGHT - 10;
		DrawString(0, 90, "衝突しています", WHITE);
	}
}

void Chara_Encount(){ //敵とのエンカウントに関しての関数
	DrawFormatString(0, 120, WHITE, "%d" , i_encount);
	if (i_encount == 1){
		//stage = STAGE1;
		//Get_State();
		game_battle_flag = true; //Game_Battleを呼び出した
		stage = BATTLE;
	}
}


bool Get_Game_End_Flag(){ //ゲームが終わりに関するフラグを返す関数
	return game_end_flag;
}


int Get_Count_Stage(){ //count_stageの値を渡すだけの関数
	return count_stage;
}


void Check_Game_End(){
	if (Get_Game_End() == 1){
		if (count_stage == 1){ //game_endが１になったのでステージをその前にいたステージにする
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
		game_battle_flag = false; //Game_Battleを呼び出さないようにした
		Game_Battle_Init(); //Game_Battleの初期化を行い、game_endを０にした
		i_encount = 0; //i_encountが１のままでまたバトル画面に入ることを防ぐ
		experience_point += 10; //バトルが終わったら経験値を１０増やす
	}
}


