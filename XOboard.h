#pragma once
class XOboard
{
private:
	int turn;
	unsigned int position_y, position_x;
	char boardArray[3][3], sign_1, sign_2, emptyChar, inputKey;
public:
	XOboard();
	void boardInit();
	void boardShow();
	void nextPosition(unsigned int, unsigned int);
	void moving();
	void set(char);
};
