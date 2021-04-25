// TestBinarySearchTree.h


/* Header */
//====================================================================================================
#include <iostream>
#include <windows.h>
#include <string>
#include <condition_variable>

#include <DS_Common/Tree/BST.h>

using namespace DS_Common;
//====================================================================================================

/* Definition Function */
//====================================================================================================
namespace T_BST {

	void basicTest();
}
//====================================================================================================

/* Public Function */
//====================================================================================================
void TestBST()
{

	T_BST::basicTest();
}
//====================================================================================================


/* Private Function */
//====================================================================================================

namespace T_BST {
	void basicTest()
	{

		BST<int, int> bst;
		int N = 6;
		for (int i = 0; i < N; i++)
		{
			bst.push(std::pair<int, int>(i, 100 - i));
		}

		std::cout << "BST.second " << std::endl;
		for (int i = 0; i < N; i++)
		{
			std::pair<int, int> tmp = bst.get(i);
			std::cout << tmp.second << std::endl;
		}

		std::cout << "BST remove " << std::endl;

		int key = 3;
		bool result = bst.remove_ele(key);
		std::cout << "delete result -== " << result << std::endl;
		for (int i = 0; i < N; i++)
		{
			std::pair<int, int> tmp = bst.get(i);
			std::cout << tmp.second << std::endl;
		}


	}
}
//-------------------------------------------------------------------------------------------------

//====================================================================================================

