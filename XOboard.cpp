#include "XOboard.h"
#include <iostream>
const char emptyChar = '-';
XOboard::XOboard()
{
	boardInit();
}
void XOboard::boardInit()
{
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			boardArray[i][j] = emptyChar;
	positionX = 0;
	positionY = 0;
}
void XOboard::boardShow()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << boardArray[i][j] << "		";
		}
		std::cout << std::endl;
	}
}
void XOboard::nextPosition(unsigned int pX, unsigned int pY)
{
	if (0 <= pX && pX < 3 && 0 <= pY && pY < 3)
	{
		positionX = pX;
		positionY = pY;
	}
	else
		std::cout << std::endl << "Unvalid position!" << std::endl;
}
void XOboard::set(char XO)
{
	if (boardArray[positionX][positionY] == emptyChar)
		boardArray[positionX][positionY] = XO;
	else
		std::cout << std::endl << "you can't overwrite a sign!" << std::endl;
}
void XOboard::winChecker()
{
}