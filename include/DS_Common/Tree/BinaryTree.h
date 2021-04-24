// BinaryTree.h

#ifndef __DS_COMMON_BINARY_TREE_H__
#define __DS_COMMON_BINARY_TREE_H__

/* Information */
//====================================================================================================

/*!
*  @file   BinaryTree.h
*
*  @brief  The Definition of BinaryTree and its Node Template
*
*  @author Po-Wei Huang
*
*  @date   2021/04/24
*/

//====================================================================================================


/* Header */
//====================================================================================================

#include <iostream>
#include <stack>
#include <queue>
#include <condition_variable>

#include <DS_Common/LibSetting/LibSetting.h>
//====================================================================================================


/* Definition */
//====================================================================================================

namespace DS_Common {

	//--------------------------------------------------------------------------------------------
	/*!
	*  @brief      Tree Node
	*
	*/
	template <class T>
	struct BTreeNode
	{
		T val;
		BTreeNode *left;
		BTreeNode *right;
		BTreeNode() : left(nullptr), right(nullptr) {}
		BTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
		BTreeNode(T x, BTreeNode<T> *left, BTreeNode<T> *right) : val(x), left(left), right(right) {}
	};
	//--------------------------------------------------------------------------------------------

	//--------------------------------------------------------------------------------------------
	/*!
	*  @brief      Binary Tree
	*
	*/
	template<typename T>
	class  BinaryTree
	{
	private:
		BTreeNode<T>* root;
		using visit_callback = std::function< void(BTreeNode<T>* cur) >;
		visit_callback visit_call_back_func;
	public:
		
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default Constructor
		*
		*/
		BinaryTree() {}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Constructor with Root
		*
		*/
		BinaryTree(BTreeNode<T>* r) : root(r) { 
			visit_call_back_func = [](BTreeNode<T>* cur)-> void {std::cout << cur->val << std::endl; };
		}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      In order Traversal
		*
		*/
		void inorder(BTreeNode<T>* cur);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      In order Traversal
		*
		*/
		void inorder() { inorder(root); };
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Pre order Traversal
		*
		*/
		void preorder(BTreeNode<T>* cur);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Pre order Traversal
		*
		*/
		void preorder() { preorder(root); };
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Pre order Traversal
		*
		*/
		void postorder(BTreeNode<T>* cur);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Pre order Traversal
		*
		*/
		void postorder() { postorder(root); };
		//-----------------------------------------------------------------------------------------


		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      iterative_in_order
		*
		*/
		void iterative_in_order(BTreeNode<T>* cur);
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      iterative_in_order
		*
		*/
		void iterative_in_order() { iterative_in_order(root); };
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      iterative_in_order
		*
		*/
		void iterative_pre_order(BTreeNode<T>* cur);
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      iterative_in_order
		*
		*/
		void iterative_pre_order() { iterative_pre_order(root); };
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      iterative_post_order
		*
		*/
		void iterative_post_order(BTreeNode<T>* cur);
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      iterative_post_order
		*
		*/
		void iterative_post_order() { iterative_post_order(root); };
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      set call back function
		*
		*/
		void set_callback(visit_callback  fun) {
			visit_call_back_func = fun;
		}
		//-----------------------------------------------------------------------------------------



		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Check is Equal
		*
		*/
		bool isEqual(BinaryTree<T>* r2) { return true; };
		//-----------------------------------------------------------------------------------------

	};
	//--------------------------------------------------------------------------------------------
}



//====================================================================================================


/* Function */
//====================================================================================================

namespace DS_Common {
	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::inorder(BTreeNode<T>* cur)
	{
		if (!cur) return;
		inorder(cur->left);
		visit_call_back_func(cur);
		inorder(cur->right);
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::postorder(BTreeNode<T>* cur)
	{
		if (!cur) return;
		postorder(cur->left);
		postorder(cur->right);
		visit_call_back_func(cur);
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::preorder(BTreeNode<T>* cur)
	{
		if (!cur) return;
		visit_call_back_func(cur);
		preorder(cur->left);
		preorder(cur->right);
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::iterative_in_order(BTreeNode<T>* root)
	{
		if (!root) return;
		std::stack<BTreeNode<T>*> stk;

		BTreeNode<T>* cur=root;
		while (1)
		{
			while (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			if (stk.empty()) return;

			cur = stk.top(); 
			stk.pop();
			visit_call_back_func(cur);
			
			cur = cur->right;
		}
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::iterative_pre_order(BTreeNode<T>* root)
	{
		if (!root) return;
		std::stack<BTreeNode<T>*> stk;
		BTreeNode<T>* cur = root;
		stk.push(cur);
		while (!stk.empty())
		{
			cur = stk.top(); 
			stk.pop();
			visit_call_back_func(cur);

			if (cur->right!=nullptr)
				stk.push(cur->right);
			if (cur->left!=nullptr)			
				stk.push(cur->left);			
		}
	}
	//-----------------------------------------------------------------------------------------

	/// Version One but not real post order traversal.
	//-----------------------------------------------------------------------------------------
	//template<typename T>
	//void BinaryTree<T>::iterative_post_order(BTreeNode<T>* root)
	//{
	//	if (!root) return;
	//	std::stack<BTreeNode<T>*> stk;
	//	std::stack<BTreeNode<T>*> output_stk;

	//	BTreeNode<T>* cur = root;
	//	stk.push(cur);

	//	while (!stk.empty())
	//	{
	//		cur = stk.top();
	//		stk.pop();
	//		output_stk.push(cur);

	//		if (cur->left != nullptr)
	//			stk.push(cur->left);
	//		if (cur->right != nullptr)
	//			stk.push(cur->right);
	//	}
	//	while (!output_stk.empty())
	//	{
	//		cur = output_stk.top(); output_stk.pop();
	//		visit_call_back_func(cur);
	//	}
	//}
	//-----------------------------------------------------------------------------------------

	/*
	Using 1 Stack. O(n) Time & O(n) Space
	This is similar to Inorder using 1 Stack. 
	The difference is we keep track of the previously printed node in pre. 
	And we only print a node if its right child is null or equal to pre.
	1.	Push all left nodes into the stack till it hits NULL.
	2. root = s.peek()
	3. if root.right = null or pre (Means we have traversed the right subtree already)
	    1. We print root and pop it from s.
	    2. Make pre = root
	    3. root = null (So we dont go down to left child again)
	4. else
	   1. root = root.right (Traverse the right subtree before printing root)
	5. Keep iterating till both the below conditions are met -
	   1. Stack is empty and
	   2. Root is NULL.
	*/
	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::iterative_post_order(BTreeNode<T>* root)
	{
		std::stack<BTreeNode<T>*> stk;
		BTreeNode<T>* last = nullptr;
		BTreeNode<T>* cur = root;
		while (cur || !stk.empty()) {
			if (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			else {
				cur = stk.top();
				if (cur->right==nullptr || last == cur->right) {
					visit_call_back_func(cur);
					last = cur;
					stk.pop();
					cur = nullptr;
				}
				else {
					cur = cur->right;
				}
			}
		}
	}
	//-----------------------------------------------------------------------------------------
}
//====================================================================================================

#endif /* __DS_COMMON_BINARY_TREE_H__ */
