// DisjointSetArray.cpp

/* Header */
//====================================================================================================
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

#include <DS_Common/Set/DisjointSetArray.h>
//====================================================================================================

/* Public Function */
//====================================================================================================

namespace DS_Common {
	//------------------------------------------------------------------------------------------------
	void DisjointSetArray::initialize(int number)
	{
		group.resize(number, 0);
		group_size.resize(number, 0);
		for (int i = 0; i < number; i++)
		{
			group.at(i) = i;
			group_size.at(i) = 1;
		}
			
	}
	//------------------------------------------------------------------------------------------------
	int DisjointSetArray::find(const int x)	
	{
		if (x > group.size())
			return -1;
		return group.at(x);
	}
	//------------------------------------------------------------------------------------------------

	bool DisjointSetArray::equivlence(const int x, const int y)
	{
		if (x > group.size() || y > group.size())
			return false;
		return group[x]== group[y];
	}
	//------------------------------------------------------------------------------------------------

	void DisjointSetArray::union_member(const int x, const int y)	
	{
		if (group[x] == group[y]) return;

		int glarge = group[x], gsmall = group[y];
		if (group_size[x] < group_size[y]) std::swap(glarge, gsmall);
		for (int i = 0; i<group.size(); i++)
			if (group[i] == gsmall)
			{
				group[i] = glarge;
				group_size[gsmall]--;
				group_size[glarge]++;
			}
	}

	//------------------------------------------------------------------------------------------------

	int DisjointSetArray::cardinality(const int x)	
	{
		return group_size[group[x]];
	}

	//------------------------------------------------------------------------------------------------

	bool DisjointSetArray::sintleton(const int x)
	{
		return group_size[group[x]] == 1;
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================
