#include "item_manager.h"

void item_options()
{
	std::string answer_string = "ok";
	int answer = -1;
	ItemVector item_selected;
	do{
		int items_number = 0;
		
		//SHOWING ITEMS CREATED
		std::cout << "ITEMS LIST" << std::endl;
		for (const auto& elem : list_vec_items)
		{
			std::cout << items_number << ". " << elem.at(0)->GetName() << std::endl;
			++items_number;
		}
	
		
		
		std::cout << "Select the item" << std::endl;
		std::cout << "You can go back typing \"back\" or quit typing \"exit\""<< std::endl;
		std::cin >> answer_string;
		std::cout << "\n\n\n";
		std::for_each(answer_string.begin(), answer_string.end(), [](char& c) { c = ::tolower(c); }); //answer all lowercase
		if (answer_string == "exit")
			std::exit(0);
		else if (answer_string == "back")
			print_list();
		else
		{
			answer = atoi(answer_string.c_str());
			if (answer < 0 || answer > items_number)
			{
				std::cout << "wtf are you doing, try again\n\n\n";
			}
		}
	}while(answer_string == "ok");
	int i = 0;
	for (const auto& elem : list_vec_items)
	{
		if (i == answer)
		{
			item_selected.reserve(elem.size());
			item_selected = elem;
			std::cout << "You selected: " << item_selected.at(0)->GetName() << std::endl;
			selected_item_options(std::move(item_selected));
			//for (const auto& e : elem)
				//item_selected.emplace_back(std::make_unique<Item>(*e)); //in case of unique_ptrs, with shared_ptr we get pointers to the obejcts instead of creating new ones
		}
		++i;
	}
}

void selected_item_options(ItemVector item_selected)
{
	int answer = 0;
	do {
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "0: Save/Show Created Item" << std::endl;
		std::cout << "1: Print Values Only" << std::endl;
		std::cout << "2: Print Real Values Only" << std::endl;
		std::cout << "3: Go back" << std::endl;
		std::cout << "4: Main Menu" << std::endl;
		std::cout << "5: Exit" << std::endl;
		std::cin >> answer;
		switch (answer)
		{
			case 0:
			{
				save_single_item(std::move(item_selected));
			}break;
			case 1:
			{
				int up = 0;
				for(const auto&x : item_selected)
				{
					std::cout << x->GetName() << "+" << up << " Real Values: \n";
					x->PrintItemValues();
					std::cout<<"\n";
					++up;
				}
			}break;
			case 2:
			{
				int up = 0;
				for(const auto&x : item_selected)
				{
					std::cout << x->GetName() << "+" << up << " Real Values: \n";
					x->PrintRealValues();
					std::cout<<"\n";
					++up;
				}
			}break;
			case 3:
			{
				std::cout << "\n\n\n\n";
				item_options();
			}break;
			case 4:
			{
				std::cout << "\n\n\n\n";
				ItemValuesGenerator();
			}break;
			case 5:
			{
				std::exit(0);
			}break;
		}
		
	} while (answer != 5);
}