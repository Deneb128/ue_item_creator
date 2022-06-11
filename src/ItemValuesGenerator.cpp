// ItemValuesGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "header/item_manager.h"

void ItemValuesGenerator()
{
	int answer = 0;
	do {
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "0: Create Items" << std::endl;
		std::cout << "1: Print List Created Items" << std::endl;
		std::cout << "2: Save/Show Created Items" << std::endl;
		std::cout << "3: Exit" << std::endl;
		std::cin >> answer;
		switch (answer)
		{
			case 0:
			{
				create_items();
			}break;
			case 1:
			{
				print_list();
			}break;
			case 2:
			{
				save_items();
			}break;
		}
	} while (answer != 3);
}

int main()
{
	ItemValuesGenerator();
	return 0;
}