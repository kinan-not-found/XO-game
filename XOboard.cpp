#include "XOboard.h"
#include <iostream>
#include <conio.h>
XOboard::XOboard()
{
	char answer = '\0';
	empty_char = '_';
	hover = '@';
	boardInit();
	std::cout << "Player 1 : Enter the sign you want to use : ";
	std::cin >> sign_1;
	std::cout << "Player 2 : Enter the sign you want to use : ";
	std::cin >> sign_2;
	system("cls");
	do
	{
		do
		{
			moving();
			if (winChecker())
			{
				break;
			}
		} while (round != 10);
		boardShow();
		if (winChecker() == 1)
		{
			std::cout << "Player 1 is the winner " << "( with the sign : " << sign_1 << " )." << std::endl;
		}
		if (winChecker() == 2)
		{
			std::cout << "Player 2 is the winner " << "( with the sign : " << sign_2 << " )." << std::endl;
		}
		if (winChecker() == 0)
		{
			std::cout << "draw." << std::endl;
		}
		while (answer != 'y' && answer != 'n')
		{
			std::cout << "Want to play again ? ( y / n )" << std::endl;
			std::cin >> answer;
			if (answer == 'y')
			{
				boardInit();
			}
			system("cls");
		}
	} while (answer != 'n');
}
void XOboard::boardInit()
{
	turn = 0;
	round = 1;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			board[i][j] = empty_char;
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
			std::cout << board[i][j] << "			";
		}
		if (i != 2)
		{
			std::cout << std::endl << std::endl << std::endl << std::endl;
		}
		else
			std::cout << std::endl << std::endl;
	}
}
void XOboard::set(char XO)
{
	if (board[position_y][position_x] == hover)
	{
		turn++;
		round++;
		board[position_y][position_x] = XO;
	}
	else
	{
		std::cout << "You can not overright a sign ! press any key to continue..." << std::endl;
		char temp = _getch();
	}
}
void XOboard::moving()
{
	if (board[position_y][position_x] != sign_1 && board[position_y][position_x] != sign_2)
	{
		board[position_y][position_x] = hover;
	}
	boardShow();
	char nowPosition = _getch();
	switch (nowPosition)
	{
	case 'w':
		if (board[position_y][position_x] != sign_1 && board[position_y][position_x] != sign_2)
		{
			board[position_y][position_x] = empty_char;
		}
		position_y = (position_y == 0) ? 2 : --position_y;
		break;
	case 's':
		if (board[position_y][position_x] != sign_1 && board[position_y][position_x] != sign_2)
		{
			board[position_y][position_x] = empty_char;
		}
		position_y = (position_y == 2) ? 0 : ++position_y;
		break;
	case 'a':
		if (board[position_y][position_x] != sign_1 && board[position_y][position_x] != sign_2)
			board[position_y][position_x] = empty_char;
		position_x = (position_x == 0) ? 2 : --position_x;
		break;
	case 'd':
		if (board[position_y][position_x] != sign_1 && board[position_y][position_x] != sign_2)
			board[position_y][position_x] = empty_char;
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
int XOboard::winChecker()
{
	int p_1_counter = 0, p_2_counter = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == sign_1)
			{
				p_1_counter++;
			}
			else if (board[i][j] == sign_2)
			{
				p_2_counter++;
			}
		}
		if (p_1_counter == 3)
		{
			return 1;
		}
		else if (p_2_counter == 3)
		{
			return 2;
		}
		p_1_counter = 0;
		p_2_counter = 0;
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (i == j)
			{
				if (board[i][j] == sign_1)
				{
					p_1_counter++;
				}
				else if (board[i][j] == sign_2)
				{
					p_2_counter++;
				}
			}
		}
	}
	if (p_1_counter == 3)
	{
		return 1;
	}
	else if (p_2_counter == 3)
	{
		return 2;
	}
	p_2_counter = 0;
	p_1_counter = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[j][i] == sign_1)
				p_1_counter++;
			else if (board[j][i] == sign_2)
				p_2_counter++;
		}
		if (p_1_counter == 3)
		{
			return 1;
		}
		else if (p_2_counter == 3)
		{
			return 2;
		}
		p_2_counter = 0;
		p_1_counter = 0;
	}
	return 0;
}