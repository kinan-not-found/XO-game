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
	system("cls");
	do
	{
		moving();
	} while (round != 10);
	boardShow();
	std::cout << "end.." << std::endl;
}
void XOboard::boardInit()
{
	turn = 0;
	round = 1;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			boardArray[i][j] = emptyChar;
	position_y = 0;
	position_x = 0;
}
void XOboard::boardShow()
{
	if (round == 1)
	{
		std::cout << "  <-Keyboard buttons->" << std::endl << std::endl;
		std::cout << "  Moving : w, s, a, d" << std::endl << std::endl;
		std::cout << "  Placing : -space button-" << std::endl << std::endl;
		std::cout << "  Restarting : r" << std::endl << std::endl;
	}
	std::cout << "               round : " << round;
	if (turn % 2 == 0)
		std::cout << " ( player-1 )" << std::endl << std::endl;
	else
		std::cout << " ( player-2 )" << std::endl << std::endl;
	std::cout << "                    ( " << position_x << " , " << position_y << " )" << std::endl << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << boardArray[i][j] << "			";
		}
		std::cout << std::endl << std::endl << std::endl << std::endl;
	}
}
void XOboard::set(char XO)
{
	if (boardArray[position_y][position_x] == '*')
	{
		turn++;
		round++;
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
		break;
	case 'r':
		boardInit();
	default:
		break;
	}
	system("cls");
}
bool XOboard::winChecker()
{
	//if ((boardArray[0][0] != emptyChar) == (boardArray[1][1] != emptyChar) == (boardArray[2][2] != emptyChar))
	//	if (boardArray[0][0] == boardArray[1][1] == boardArray[2][2])
	//		return true;
	//if (boardArray[2][2] == boardArray[2][1] == boardArray[2][0] != emptyChar)
	//	return true;
	//if (boardArray[0][0] == boardArray[0][1] == boardArray[0][2] != emptyChar)
	//	return true;
	//if (boardArray[1][0] == boardArray[1][1] == boardArray[1][2] != emptyChar)
	//	return true;
	//if (boardArray[2][0] == boardArray[2][1] == boardArray[2][2] != emptyChar)
	//	return true;
	//if (boardArray[0][0] == boardArray[1][0] == boardArray[2][0] != emptyChar)
	//	return true;
	//if (boardArray[0][1] == boardArray[1][1] == boardArray[2][1] != emptyChar)
	//	return true;
	//if (boardArray[0][2] == boardArray[1][2] == boardArray[2][2] != emptyChar)
	//	return true;
	//return false;
	return true;
}