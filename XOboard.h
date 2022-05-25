#pragma once
class XOboard
{
private:
	unsigned int positionX, positionY;
	char boardArray[3][3];
public:
	XOboard();
	void boardInit();
	void boardShow();
	void nextPosition(unsigned int, unsigned int);
	void set(char);
	void winChecker();
};
