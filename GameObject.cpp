#include "GameObject.h"

using namespace std;

 /*�\����*/
//�ʒu


/*���\�b�h�̒�`*/

/*�w�r�N���X�̃R���X�g���N�^*/
Snake::Snake(int X, int Y,int Moving_vector,int Body_length) {
	snake_before_pos_x = X;
	snake_before_pos_y = Y;
	head_position.X = X;
	head_position.Y = Y;
	moving_vector=Moving_vector;
	body_length= Body_length;
}

/*�w�r�N���X�̃��\�b�h*/
void Snake::add_body() {

}

void Snake::move() {
	snake_before_pos_x = head_position.X;//�O�̍��W���L��
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

/*�ǂƂ̏Փ˔���*/
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
	return true;//�e�X�g
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

/*�ړ��O�̃R���\�[�����Ս폜*/
void Snake::fade_track() {
	setCursorPos(snake_before_pos_x, snake_before_pos_y);
	cout << " ";
}





/*�G�T�N���X�̃R���X�g���N�^*/
Feed::Feed(int X, int Y) {
	position.X = X;
	position.Y = Y;
}


/*�G�T�N���X�̃��\�b�h
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

/*�G�N���X�̒�`*/
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

/*�����_���ɓG�͓���*/
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

/*�ړ��O�̃R���\�[�����Ս폜*/
void Enemy::fade_track() {
	setCursorPos(enemy_before_pos_x, enemy_before_pos_y);
	cout << " ";
}


/*�֐�*/
/// <summary>
/// �R���\�[����ʏ�̍��W�̎w��
/// </summary>
/// <param name="x">x���W</param>
/// <param name="y">y���W</param>
void setCursorPos(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);//window�̃R���\�[��������API
	COORD pos;//�ʒu�̎擾
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);//�J�[�\������ʏ�̎w��ʒu�ɔz�u
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
/// �t�B�[���h�}�b�v�쐬
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

