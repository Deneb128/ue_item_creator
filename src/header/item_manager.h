#pragma once
#include "item.h"

using ItemVector = std::vector<std::shared_ptr<Item>>;
using ItemsList = std::list< std::vector<std::shared_ptr<Item>>>;

//ITEM_CREATE
ItemType item_type = ItemType::UNKNOWN_TYPE;
int save_value = 0;
std::string item_name = "";
std::vector<int> vec_values{};
int value5_value = 0;
ItemVector vec_items{};
ItemsList list_vec_items{};
bool response = true;
extern int last_value5 = 0;

//ITEM_SAVE
bool toFile = false;
bool isNew = true;
int item_up = 0;





void save_items();
void create_items();
void values_evaluator(std::vector<int>& vec_values, ItemType item_type);
void print_list();
void ItemValuesGeneratorMenu();
void item_options();
void save_single_item(ItemVector item_selected);
void selected_item_options(ItemVector item_selected);