// SnakeGame.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "GameObject.h"
using namespace std;


/*グローバル変数*/
extern int const CONS_WD;
extern int const CONS_HT;

int main()
{


	int first_snake_x = 50;
	int first_snake_y = 18;
	int first_snake_vector = 1;
	int first_body_length = 1;

	int first_enemy_x = 40;
	int first_enemy_y = 22;
	int first_enemy_vector = -1;
	char bs = 8;//asciiコード1文字戻る
	/*ヘビオブジェクト（プレイヤー操作）*/
//	Snake snake(first_snake_x,first_snake_y,first_snake_vector,first_body_length);






/*
	int snake_vector = first_snake_vector;//ヘビの移動方向
	int enemy_vector = first_enemy_vector;//敵の移動方向
	bool Game_continue = true;//falseでゲームオーバー
	bool enemy_hit = true;
	bool wall_hit = true;
*/

	char cont = 'y';


	while (cont == 'y') {
		int snake_vector = first_snake_vector;//ヘビの移動方向
		int enemy_vector = first_enemy_vector;//敵の移動方向
		bool Game_continue = true;//falseでゲームオーバー
		bool enemy_hit = true;
		bool wall_hit = true;
		setCursorPos(CONS_HT, CONS_HT / 2);
		cout << "GAMESTART!";
		Sleep(1000);
		system("cls");//コンソール画面クリア
		MakeField(CONS_WD, CONS_HT);
		setCursorPos(CONS_WD + 15, 5);
		cout << "        up:u";
		setCursorPos(CONS_WD + 15, 7);
		cout << "left:h        right:j";
		setCursorPos(CONS_WD + 15, 9);
		cout<<"       down:n";

		/*ヘビオブジェクト（プレイヤー操作）*/
		Snake snake(first_snake_x, first_snake_y, first_snake_vector, first_body_length);
		/*敵オブジェクト*/
		Enemy enemys[] = {
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
			Enemy(first_enemy_x, first_enemy_y, first_enemy_vector),
		};

		int enemys_count = sizeof(enemys) / sizeof(Enemy);
		while (Game_continue) {


			/*壁との衝突判定*/


			/*キーボード読み取り移動*/
			getKeybord(snake_vector);

			/*ヘビのマス目移動*/
			snake.set_moving_vector(snake_vector);
			snake.move();
			setCursorPos(snake.get_position_X(), snake.get_position_Y());
			cout << "*";
			snake.fade_track();

			for (int i = 0; i < enemys_count; i++) {
				/*敵のマス目移動*/
		//		enemy.set_moving_vector(enemy_vector);
				enemys[i].move();
				setCursorPos(enemys[i].get_position_X(), enemys[i].get_position_Y());
				cout << "@";
				enemys[i].fade_track();
				enemy_hit = snake.collision_enemy(enemys[i].get_position_X(), enemys[i].get_position_Y());
				if (enemy_hit == false) { break; }
			}
			wall_hit = snake.collision_wall();
			Game_continue = (enemy_hit & wall_hit);

			/*待機時間*/
			Sleep(200);
		}
		cout << bs << "GameOver!";
		Sleep(500);
		cout << "Continue?(y or n)";
		cin >> setw(1) >>cont;
		system("cls");//コンソール画面クリア
	}
	
	cout << "Good";
	cout << "Bye!!!";
		Sleep(500);

}


