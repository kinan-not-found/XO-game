#include <iostream>
#include "XOboard.h"
int main()
{
	XOboard board1;
	char p;
	unsigned int win = 1, x, y;
	while (win != 0)
	{
		board1.boardShow();
		std::cout << std::endl;
		std::cout << "Enter : ";
		std::cin >> p;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Enter : ";
		std::cin >> x >> y;
		std::cout << std::endl;
		board1.nextPosition(x, y);
		board1.set(p);
	}
}