#include "XOboard.h"
#include <iostream>
#include <conio.h>
XOboard::XOboard()
{
	emptyChar = '_';
	boardInit();
	std::cout << "Player 1 : Enter the sign you want to use : ";
	std::cin >> sign_1;
	std::cout << "Player 2 : Enter the sign you want to use : ";
	std::cin >> sign_2;
	for (size_t i = 0; i < 100; i++)
	{
		moving();
	}
	std::cout << "end.." << std::endl;
}
void XOboard::boardInit()
{
	turn = 0;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			boardArray[i][j] = emptyChar;
	position_y = 0;
	position_x = 0;
}
void XOboard::boardShow()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << boardArray[i][j] << "		";
		}
		std::cout << std::endl << std::endl;
	}
}
void XOboard::nextPosition(unsigned int pX, unsigned int pY)
{
	if (0 <= pX && pX < 3 && 0 <= pY && pY < 3)
	{
		position_y = pX;
		position_x = pY;
	}
	else
		std::cout << std::endl << "Unvalid position!" << std::endl;
}
void XOboard::set(char XO)
{
	if (boardArray[position_y][position_x] == '*')
	{
		boardArray[position_y][position_x] = XO;
	}
	else
	{
		std::cout << "You can not overright a sign ! press any key to continue..." << std::endl;
		char temp = _getch();
	}
}
void XOboard::moving()
{
	if (boardArray[position_y][position_x] != sign_1 && boardArray[position_y][position_x] != sign_2)
	{
		boardArray[position_y][position_x] = '*';
	}
	boardShow();
	char nowPosition = _getch();
	switch (nowPosition)
	{
	case 'w':
		if (boardArray[position_y][position_x] != sign_1 && boardArray[position_y][position_x] != sign_2)
		{
			boardArray[position_y][position_x] = emptyChar;
		}
		position_y = (position_y == 0) ? 2 : --position_y;
		break;
	case 's':
		if (boardArray[position_y][position_x] != sign_1 && boardArray[position_y][position_x] != sign_2)
		{
			boardArray[position_y][position_x] = emptyChar;
		}
		position_y = (position_y == 2) ? 0 : ++position_y;
		break;
	case 'a':
		if (boardArray[position_y][position_x] != sign_1 && boardArray[position_y][position_x] != sign_2)
			boardArray[position_y][position_x] = emptyChar;
		position_x = (position_x == 0) ? 2 : --position_x;
		break;
	case 'd':
		if (boardArray[position_y][position_x] != sign_1 && boardArray[position_y][position_x] != sign_2)
			boardArray[position_y][position_x] = emptyChar;
		position_x = (position_x == 2) ? 0 : ++position_x;
		break;
	case ' ':
		if (turn % 2 == 0)
		{
			set(sign_1);
		}
		else
		{
			set(sign_2);
		}
		turn++;
		break;
	default:
		break;
	}
	system("cls");
}