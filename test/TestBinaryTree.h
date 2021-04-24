// TestBinaryTree.h


/* Header */
//====================================================================================================
#include <iostream>
#include <windows.h>

#include <DS_Common/Tree/BinaryTree.h>

using namespace DS_Common;
//====================================================================================================

/* Definition Function */
//====================================================================================================
void basicTraversal(BinaryTree<int>& root);
void IterativeTraversal(BinaryTree<int>& tmp);
//====================================================================================================

/* Public Function */
//====================================================================================================
void TestBinaryTree()
{

	BTreeNode<int> n1(2);
	BTreeNode<int> n2(3);
	BTreeNode<int> *n3 = new BTreeNode<int>(1, &n1, &n2);
	BinaryTree<int> tmp(n3);

	basicTraversal(tmp);
	IterativeTraversal(tmp);
}
//====================================================================================================


/* Private Function */
//====================================================================================================


//-------------------------------------------------------------------------------------------------
void cout_callback(BTreeNode<int>* cur) { std::cout << cur->val << std::endl; };
void basicTraversal(BinaryTree<int>& tmp) {
	tmp.set_callback(cout_callback);
	std::cout << "in order" << std::endl;
	tmp.inorder();

	std::cout << "pre order" << std::endl;
	tmp.preorder();

	std::cout << "post order" << std::endl;
	tmp.postorder();
}

//-------------------------------------------------------------------------------------------------
void IterativeTraversal(BinaryTree<int>& tmp) {

	std::cout << "in order" << std::endl;
	tmp.iterative_in_order();
}
//-------------------------------------------------------------------------------------------------

//====================================================================================================

