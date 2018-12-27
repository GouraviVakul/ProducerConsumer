/*
 * Item.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#include "Item.h"
#include "Sort.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Item::Item(const char* data):m_dataStr(data)
{

}

bool Item::SplitItem()
{
	bool found = m_dataStr.find(" ")!=string::npos;
	if(found){
		m_dataStr.erase(std::remove(m_dataStr.begin(), m_dataStr.end(), ' '), m_dataStr.end());
	}
	m_dataVector.assign(m_dataStr.begin(), m_dataStr.end());
	return found;
}

void Item::Sort(const char* alg)
{
	SortAlgorithm *ptr = GetSortAlgorithm(alg);
	if(!ptr) cout<<"Getptr is null"<<endl;	
	ptr->Sort(m_dataVector);
}

std::string Item::ResultItem()
{
	std::ostringstream vts;

	// Convert all but the last element to avoid a trailing ","
	std::copy(m_dataVector.begin(), m_dataVector.end()-1, std::ostream_iterator<char>(vts, ","));

	// Now add the last element with no delimiter
	vts << m_dataVector.back();
	cout<<vts.str()<<endl;
	return vts.str();
}

