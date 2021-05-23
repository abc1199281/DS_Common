// main.cpp


/* Header */
//====================================================================================================
#include <iostream>
#include <windows.h>

#include <DS_Common/Tree/BinaryTree.h>
#include <DS_Common/Tree/BST.h>
#include <TestBinaryTree.h>
#include <TestPriorityQueue.h>
#include <TestBST.h>

using namespace DS_Common;
//====================================================================================================


/* Public Function */
//====================================================================================================
int main(int argc, char ** argv)
{
	TestBinaryTree();
	TestPriorityQueue();
	//TestBST();	

	system("pause");
	return 0;
}

//====================================================================================================

