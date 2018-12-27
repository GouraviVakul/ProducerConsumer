/*
 * Item.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <vector>

using namespace std;

class Item
{
public:
	Item(const char* str);
	bool SplitItem();
	void Sort(const char* algorithm);
	std::string ResultItem();

private:
	std::string m_dataStr;
	std::vector<char> m_dataVector;
};


#endif /* ITEM_H_ */
