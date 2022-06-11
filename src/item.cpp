#include "header/item.h"

Item::Item(std::vector<int> vec_values, ItemType item_type)
{
	this->SetValues(vec_values);
	this->SetType(item_type);
	this->SetName(std::string("NoName"));
}

Item::~Item()
{
	std::vector<int> m_vec_values{};
	ItemType m_item_type = ItemType::UNKNOWN_TYPE;
	int real_phys_min_value = 0;
	int real_magic_min_value = 0;
	int real_phys_max_value = 0;
	int real_magic_max_value = 0;
}

std::vector<int> Item::GetValuesVector()
{
	return m_vec_values;
}
int Item::GetValue(int value)
{
	return this->GetValuesVector().at(value);
}
void Item::GenerateRealValues(int value5)
{
	if (this->GetItemType() == ItemType::WEAPON)
	{
		this->real_magic_min_value = this->GetValue(1) != 0 ?  (this->GetValue(1) + (value5 * 2)) : 0;
		this->real_phys_min_value = this->GetValue(3) != 0 ?  (this->GetValue(3) + (value5 * 2)) : 0;
		this->real_magic_max_value = this->GetValue(2) != 0 ?  (this->GetValue(2) + (value5 * 2)) : 0;
		this->real_phys_max_value = this->GetValue(4) != 0 ?  (this->GetValue(4) + (value5 * 2)) : 0;
	}
	else if (this->GetItemType() == ItemType::ARMOR)
	{
		this->real_magic_min_value = this->GetValue(2) + (value5 * 2);
		this->real_phys_min_value = this->GetValue(0) + (value5 * 2);
		this->real_magic_max_value = this->GetValue(4) + (value5 * 2);
		this->real_phys_max_value = this->GetValue(1) + (value5 * 2);
	}
	return;
}
void Item::PrintRealValues()
{
	std::cout << "-------------------------------------------"<< std::endl;
	std::cout << "Min Phys Value\tMin Magic Valuelue  Max Phys Value  Max Magic Value" << std::endl;
	std::cout << this->GetMinPhysValue() << "\t\t" << this->GetMinMagicValue() << "\t\t    " << this->GetMaxPhysValue() << "\t\t    " << this->GetMaxMagicValue() << std::endl;

	std::cout << "-------------------------------------------" << std::endl;
	return;
}

void Item::PrintItemValues()
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "Value0\tValue1\tValue2\tValue3\tValue4\tValue5" << std::endl;
	std::cout << this->GetValue(0) << "\t" << this->GetValue(1) << "\t" << this->GetValue(2) << "\t" << this->GetValue(3) << "\t" << this->GetValue(4) << "\t" << this->GetValue(5) << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	return;
}

void Item::PrintValues(bool toFile)
{
	for (const auto& elem : this->GetValuesVector())
	{
		std::cout << elem << "\t";
	}
	if (toFile == true)
	{
		std::ofstream myfile;
		myfile.exceptions(std::ofstream::eofbit | std::ofstream::failbit | std::ofstream::badbit);
		try {
			myfile.open("navicat.txt", std::ios::app);
			int value = 0;
			for (const auto& elem : this->GetValuesVector())
			{
				if(value == 5){
					myfile << elem;
				}else{
					myfile << elem << "\t";
				}	
				++value;
			}
			myfile << "\n";
			myfile.close();
		}
		catch (std::exception const& e) {
			std::cout << "There was an error: " << e.what() << std::endl;
		}
	}

}
void Item::SetValue(int position, int value)
{
	m_vec_values.at(position) = value;
	m_vec_values[position] = value;
	return;
}