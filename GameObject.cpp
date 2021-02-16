#include "GameObject.h"

using namespace std;

 /*構造体*/
//位置


/*メソッドの定義*/

/*ヘビクラスのコンストラクタ*/
Snake::Snake(int X, int Y,int Moving_vector,int Body_length) {
	snake_before_pos_x = X;
	snake_before_pos_y = Y;
	head_position.X = X;
	head_position.Y = Y;
	moving_vector=Moving_vector;
	body_length= Body_length;
}

/*ヘビクラスのメソッド*/
void Snake::add_body() {

}

void Snake::move() {
	snake_before_pos_x = head_position.X;//前の座標を記憶
	snake_before_pos_y = head_position.Y;
	switch (moving_vector) {
		case(1):
			head_position.Y -= 1;
			break;
		case(2):
			head_position.X += 1;
			break;
		case(-1):
			head_position.Y += 1;
			break;
		case(-2):
			head_position.X -= 1;
			break;
		default:
			break;
	}
}

/*壁との衝突判定*/
bool Snake::collision_wall() {
	if ((WALL_X_MAX <= head_position.X)|| 
		(WALL_X_MIN >= head_position.X)|| 
		(WALL_Y_MAX <= head_position.Y)|| 
		(WALL_Y_MIN >= head_position.Y))
	{
		return false;
	}
	else 
	{
		return true;
	}

}

bool Snake::collision_body(){
	return true;//テスト
}

int Snake::get_position_X() {
	return head_position.X;
}

int Snake::get_position_Y() {
	return head_position.Y;
}

void Snake::set_moving_vector(int now_vector) {
	moving_vector = now_vector;
}

bool Snake::collision_enemy(int enemy_X, int enemy_Y) {
	if (enemy_X == head_position.X && enemy_Y == head_position.Y) {
		return false;
	}
	else
	{
		return true;
	}
}

/*移動前のコンソール足跡削除*/
void Snake::fade_track() {
	setCursorPos(snake_before_pos_x, snake_before_pos_y);
	cout << " ";
}





/*エサクラスのコンストラクタ*/
Feed::Feed(int X, int Y) {
	position.X = X;
	position.Y = Y;
}


/*エサクラスのメソッド
void Feed::set_feed() {

}

void Feed::fade_feed() {

}
*/


int Feed::get_position_X() {

	return position.X;

};
int Feed::get_position_Y() {

	return position.Y;
};

/*敵クラスの定義*/
Enemy::Enemy(int X, int Y, int Moving_vector) {
	position.X = X;
	position.Y = Y;
	enemy_before_pos_x = X;
	enemy_before_pos_y = Y;
	moving_vector = Moving_vector;
}

void Enemy::collision_wall() {
	if (WALL_X_MAX - 1 <= position.X && moving_vector == 2 ||
		WALL_X_MIN + 1 >= position.X && moving_vector == -2 ||
		WALL_Y_MAX - 1 <= position.Y && moving_vector == -1 ||
		WALL_Y_MIN + 1 >= position.Y && moving_vector == 1)
	{
		moving_vector = -moving_vector;
	}
}

/*ランダムに敵は動く*/
void Enemy::move() {
	enemy_before_pos_x = position.X;
	enemy_before_pos_y = position.Y;
	int rand_num=0;
	while (rand_num == 0) {
		rand_num = random_range(-2, 2);
	}
moving_vector = rand_num;
	collision_wall();
	switch (moving_vector) {
	case(1):
		position.Y -= 1;
		break;
	case(2):
		position.X += 1;
		break;
	case(-1):
		position.Y += 1;
		break;
	case(-2):
		position.X -= 1;
		break;
	default:
		break;
	}

}

int Enemy::get_position_X() {
	return position.X;
}

int Enemy::get_position_Y() {
	return position.Y;
}

void Enemy::set_moving_vector(int now_vector) {
	moving_vector = now_vector;
}

/*移動前のコンソール足跡削除*/
void Enemy::fade_track() {
	setCursorPos(enemy_before_pos_x, enemy_before_pos_y);
	cout << " ";
}


/*関数*/
/// <summary>
/// コンソール画面上の座標の指定
/// </summary>
/// <param name="x">x座標</param>
/// <param name="y">y座標</param>
void setCursorPos(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//windowのコンソールを扱うAPI
	COORD pos;//位置の取得
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);//カーソルを画面上の指定位置に配置
}

void getKeybord(int &Vector) {
	char s;
	const char UP = 'u';
	const char RIGHT = 'j';
	const char DOWN = 'n';
	const char LEFT = 'h';

	int up = 1;
	int right = 2;
	int down = -1;
	int left = -2;
	if (_kbhit()) {
		s = _getch();
		switch (s)
		{
			case(UP): 
				Vector = up;
				break;
			case(RIGHT):
				Vector = right;
				break;
			case(DOWN):
				Vector = down;
				break;
			case(LEFT):
				Vector = left;
				break;
			default:
				break;

		}
	}
}

/// <summary>
/// フィールドマップ作成
/// </summary>
/// <param name="Field_Width"></param>
/// <param name="Field_Height"></param>
void MakeField(int Field_Width, int Field_Height) {
	for (int i = 0; i <= Field_Width; i++) {
		for (int j = 0; j <= Field_Height; j++) {
			setCursorPos(i+WIDTH_P_MOVE, j+HEIGHT_P_MOVE);
			if (i == 0 || j == 0 || i==Field_Width ||j==Field_Height) {
				cout << "#";
			}
		}
	}
}

