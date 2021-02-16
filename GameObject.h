#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <iomanip> // for setw()
/*�t�B�[���h�}�b�v�̑傫��*/
const int CONS_WD = 80;
const int CONS_HT = 25;

/*�t�B�[���h�}�b�v�̕��s�ړ�*/
const int WIDTH_P_MOVE = 10;
const int HEIGHT_P_MOVE = 3;



/*�Փ˔���p���W*/
const int WALL_X_MIN = WIDTH_P_MOVE;//�ǂ̍��̍��W
const int WALL_X_MAX = CONS_WD + WIDTH_P_MOVE;//�ǂ̉E�̍��W
const int WALL_Y_MIN = HEIGHT_P_MOVE;//�ǂ̏�̍��W
const int WALL_Y_MAX = CONS_HT + HEIGHT_P_MOVE;//�ǂ̉��̍��W

using namespace std;
void setCursorPos(int x, int y);

void getKeybord(int &Vector);

void MakeField(int x, int y);


template <typename T> T random_range(T min, T max) {
	T rand_num;
	rand_num=rand() % (max - min + 1) + min;
	return rand_num;
};

///��Έʒu�\����
struct Position {
	int X;
	int Y;
};

/// <summary>
/// �w�r�N���X
/// </summary>
class Snake {
private:
	Position head_position;
	int body_length;
	int moving_vector;
	int snake_before_pos_x;
	int snake_before_pos_y;
//	vector<int> all_body_position;

public:
	Snake(int X, int Y, int Moving_vector, int body_length);
	void add_body();
	void move();
	bool collision_wall();
	bool collision_body();
	int get_position_X();
	int get_position_Y();
	void set_moving_vector(int now_vector);
	bool collision_enemy(int enemy_X,int enemy_Y);
	void fade_track();
};

///�a�N���X
class Feed {
private:
	Position position;
public:
	Feed(int X, int Y);
//	void set_feed();
//	void fade_feed();
	int get_position_X();
	int get_position_Y();
};

class Enemy{
private:
	Position position;
	int moving_vector;
	int enemy_before_pos_x;
	int enemy_before_pos_y;
public:
	Enemy(int X, int Y, int Moving_vector);
	void move();
	void collision_wall();
	int get_position_X();
	int get_position_Y();
	void set_moving_vector(int now_vector);
	void fade_track();
};