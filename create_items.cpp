#include "item_manager.h"

void values_evaluator(std::vector<int>& vec_values, ItemType item_type)
{
	for (int n = 0; n <=MAX_VALUES; n++)
	{
		switch (item_type)
		{
			case ItemType::WEAPON:
			{
				if (n == 0) {
					save_value = 0;
				}
				else if (n == 2)
				{
					do 
					{
						std::cout << "Insert value" << n << " at +0" << std::endl;
						std::cin >> save_value;
						if (save_value < vec_values.at(MIN_MAGIC_WEAPON_POS)) {
							std::cout << "You cannot set the max less than the min value\nInsert a number equal or grater than " << vec_values.at(MIN_MAGIC_WEAPON_POS) << std::endl;
						}
					} while (save_value < vec_values.at(MIN_MAGIC_WEAPON_POS));
				}
				else if (n == 4)
				{
					do
					{
						std::cout << "Insert value" << n << " at +0" << std::endl;
						std::cin >> save_value;
						if (save_value < vec_values.at(MIN_PHYS_WEAPON_POS)) {
							std::cout << "You cannot set the max less than the min value\nInsert a number equal or grater than " << vec_values.at(MIN_PHYS_WEAPON_POS) << std::endl;
						}
					} while (save_value < vec_values.at(MIN_PHYS_WEAPON_POS));
				}
				else if (n == 5)
				{
					std::cout << "Insert value" << n << " at +0" << std::endl;
					std::cin >> save_value;
					last_value5 = save_value;
				}
				else {
					std::cout << "Insert value" << n << " at +0" << std::endl;
					std::cin >> save_value;
				}
				vec_values.emplace_back(save_value);
			}
			break;
			case ItemType::ARMOR:
			{
				if (n == 1)
				{
					do
					{
						std::cout << "Insert value" << n << " at +0" << std::endl;
						std::cin >> save_value;
						if (save_value < vec_values.at(MIN_MAGIC_ARMOR_POS)) {
							std::cout << "You cannot set the max less than the min value\nInsert a number equal or grater than " << vec_values.at(MIN_MAGIC_ARMOR_POS) << std::endl;
						}
					} while (save_value < vec_values.at(MIN_MAGIC_ARMOR_POS));
				}
				else if (n == 4)
				{
					do
					{
						std::cout << "Insert value" << n << " at +0" << std::endl;
						std::cin >> save_value;
						if (save_value < vec_values.at(MIN_PHYS_ARMOR_POS)) {
							std::cout << "You cannot set the max less than the min value\nInsert a number equal or grater than " << vec_values.at(MIN_PHYS_ARMOR_POS) << std::endl;
						}
					} while (save_value < vec_values.at(MIN_PHYS_ARMOR_POS));
				}
				else if (n == 3)
				{
					std::cout << "Insert value" << n << " at +0 [COPY THE ORIGINAL VALUE]" << std::endl;
					std::cin >> save_value;
				}
				else if (n == 5)
				{
					std::cout << "Insert value" << n << " at +0" << std::endl;
					std::cin >> save_value;
					last_value5 = save_value;
				}
				else {
					std::cout << "Insert value" << n << " at +0" << std::endl;
					std::cin >> save_value;
				}
				vec_values.emplace_back(save_value);
			}
			break;
		}
	}
}

void create_items()
{
	std::cout << "CREATING A NEW ITEM\n";
	std::cout << "Insert a name for the item: \n";
	std::cin >> item_name;	
	std::cout << "What you want to work on, weapon or armor?\nPress 0 for WEAPON 1 for ARMOR\n";
	std::cin >> item_type;
	values_evaluator(vec_values, item_type);

	std::shared_ptr<Item> new_item = std::make_shared<Item>(vec_values, item_type);
	new_item->SetName(item_name);
	new_item->GenerateRealValues(value5_value);
	vec_items.emplace_back(std::move(new_item));

	for (int n = 1; n <= MAX_UPGRADE; n++)
	{
		do {
			std::cout << "Insert value5 value for item level+" << n << std::endl;
			std::cin >> value5_value;
			if (value5_value <= last_value5) {
				std::cout << "You cannot set a value5 smaller or equal than the last one\nTry again" << std::endl;
			}
			else {
					
				std::shared_ptr<Item> new_item = std::make_shared<Item>(vec_values, item_type);
				new_item->SetValue(5, value5_value);
				new_item->SetName(item_name);
				new_item->GenerateRealValues(value5_value);
				vec_items.emplace_back(std::move(new_item));
			}
		} while (last_value5 >= value5_value);
		last_value5 = value5_value;
	}
	list_vec_items.emplace_back(std::move(vec_items));
	vec_values.clear();
	std::cout << "\n\n\n";
}