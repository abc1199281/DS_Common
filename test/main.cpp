// main.cpp


/* Header */
//====================================================================================================
#include <iostream>
#include <windows.h>

#include <DS_Common/Tree/BinaryTree.h>

using namespace DS_Common;
//====================================================================================================


/* Public Function */
//====================================================================================================

int main(int argc, char ** argv)
{
	TreeNode<int> n1(1);
	TreeNode<int> n2(2);
	TreeNode<int> *n3 = new TreeNode<int>(1, &n1, &n2);
	BinaryTree<int> tmp(n3);
	
	tmp.inorder();

	system("pause");
	return 0;
}

//====================================================================================================

