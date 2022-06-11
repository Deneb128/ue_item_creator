#include "stdafx.h"

enum class ItemType { WEAPON, ARMOR, UNKNOWN_TYPE };
std::istream& operator>>(std::istream& is, ItemType& item_type)
{
	int a;
	is >> a;
	item_type = static_cast<ItemType>(a);
	return is;
}
std::ostream& operator<<(std::ostream& os, const ItemType& item_type)
{
	os << static_cast<int>(item_type);
	return os;
}


constexpr int MAX_VALUES = 5;
constexpr int MAX_UPGRADE = 2;
constexpr int MIN_PHYS_WEAPON_POS = 3;
constexpr int MAX_PHYS_WEAPON_POS = 4;
constexpr int MIN_MAGIC_WEAPON_POS = 1;
constexpr int MAX_MAGIC_WEAPON_POS = 2;

constexpr int MIN_PHYS_ARMOR_POS = 2;
constexpr int MAX_PHYS_ARMOR_POS = 4;
constexpr int MIN_MAGIC_ARMOR_POS = 0;
constexpr int MAX_MAGIC_ARMOR_POS = 1;

class Item
{
	public:
		Item(std::vector<int> vec_values, ItemType item_type);
		~Item();
		void SetValues(std::vector<int> vec_values) { m_vec_values = vec_values; };
		void SetType(ItemType item_type) { m_item_type = item_type; };

		int GetValue(int value);
		void SetValue(int position, int value);
		std::vector<int> GetValuesVector();
		void GenerateRealValues(int value5);
		ItemType GetItemType() { return m_item_type; };
		void PrintRealValues();
		void PrintValues(bool toFile = false);
		int GetMinPhysValue() { return real_phys_min_value; };
		int GetMinMagicValue() { return real_magic_min_value; };
		int GetMaxPhysValue() { return real_phys_max_value; };
		int GetMaxMagicValue() { return real_magic_max_value; };
		void SetName(std::string item_name) { m_item_name = item_name; }
		std::string GetName() { return m_item_name; }
		void PrintItemValues();

	private:
		std::vector<int> m_vec_values;
		ItemType m_item_type;
		int real_phys_min_value = 0;
		int real_magic_min_value = 0;
		int real_phys_max_value = 0;
		int real_magic_max_value = 0;
		std::string m_item_name = "";
};