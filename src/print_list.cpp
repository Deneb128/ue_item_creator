#include "header/item_manager.h"

void print_list()
{
	int n = 0;
	std::cout << "ITEMS LIST\n";
	for (const auto& elem : list_vec_items)
	{
		std::cout << n << ". " << elem.at(0)->GetName() << std::endl;
		++n;
	}
	std::cout << "\n\n\n";

	int answer = 0;
	do {
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "0: Create Items" << std::endl;
		std::cout << "1: Select Item" << std::endl;
		std::cout << "2: Save/Show Created Items" << std::endl;
		std::cout << "3: Go back" << std::endl;
		std::cout << "4: Exit" << std::endl;
		std::cin >> answer;
		switch (answer)
		{
			case 0:
			{
				create_items();
			}break;
			case 1:
			{
				item_options();
			}break;
			case 2:
			{
				save_items();
			}break;
			case 3:
			{
				std::cout << "\n\n\n\n";
				ItemValuesGenerator();
			}break;
			case 4:
			{
				std::exit(0);
			}
		}
		
	} while (answer != 3);
}