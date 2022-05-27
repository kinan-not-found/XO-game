#pragma once
class XOboard
{
private:
	int round, turn;
	unsigned int position_y, position_x;
	char board[3][3], sign_1, sign_2, empty_char, input_key, hover;
public:
	XOboard();
	void boardInit();
	void boardShow();
	void moving();
	void set(char);
	int winChecker();
};
