#include "header/item_manager.h"

void save_items()
{
	int item_counts = 0;
	std::ofstream myfile;
	for (const auto& elem : list_vec_items)
	{
		std::cout << "Wanna save the data for " << elem.at(item_counts)->GetName() << " to file? Press 0 for NO Press 1 for YES" << std::endl;
		std::cin >> toFile;
		if (toFile)
		{
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << elem.at(item_counts)->GetName() << std::endl;
			myfile.exceptions(std::ofstream::eofbit | std::ofstream::failbit | std::ofstream::badbit);
			try {
				myfile.open("navicat.txt", std::ios::app);
				myfile << elem.at(item_counts)->GetName() << std::endl;
				myfile.close();
			}
			catch (std::exception const& e) {
				std::cout << "There was an error: " << e.what() << std::endl;
			}
			std::cout << "--------------------------------------------------" << std::endl;
		}
		if (item_up > 9)
			item_up = (item_up - MAX_UPGRADE - 1);

		for (const auto& x : elem)
		{
			std::cout << "Real Values at +" << item_up << " for " << x->GetName() << ": " << std::endl;
			x->PrintRealValues();
			x->PrintItemValues();
			std::cout << "Values: ";
			if (toFile) {
				x->PrintValues(true);
			}
			else {
				x->PrintValues();
			}
			std::cout << "\n";
			++item_up;
		}
		++item_counts;
	}
}

void save_single_item(ItemVector item_selected)
{
	std::ofstream myfile;

	std::cout << "Wanna save the data for " << item_selected.at(0)->GetName() << " to file? Press 0 for NO Press 1 for YES" << std::endl;
	std::cin >> toFile;
	if (toFile)
	{
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << item_selected.at(0)->GetName() << std::endl;
		myfile.exceptions(std::ofstream::eofbit | std::ofstream::failbit | std::ofstream::badbit);
		try {
			myfile.open("navicat.txt", std::ios::app);
			myfile << item_selected.at(0)->GetName() << std::endl; //NAME OF ITEM ON TOP
			myfile.close();
		}
		catch (std::exception const& e) {
			std::cout << "There was an error: " << e.what() << std::endl;
		}
		std::cout << "--------------------------------------------------" << std::endl;
	}
	for (const auto& x : item_selected)
	{
		std::cout << "Real Values at +" << item_up << " for " << x->GetName() << ": " << std::endl;
		x->PrintRealValues();
		x->PrintItemValues();
		std::cout << "Values: ";
		if (toFile) {
			x->PrintValues(true);
		}
		else {
			x->PrintValues();
		}
		std::cout << "\n";
		++item_up;
	}
}