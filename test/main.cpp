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

void cout_callback(TreeNode<int>* cur) { std::cout << cur->val << std::endl; };

int main(int argc, char ** argv)
{
	TreeNode<int> n1(2);
	TreeNode<int> n2(3);
	TreeNode<int> *n3 = new TreeNode<int>(1, &n1, &n2);

	
	BinaryTree<int> tmp(n3);


	tmp.set_callback(cout_callback);
	
	tmp.inorder();

	system("pause");
	return 0;
}

//====================================================================================================

