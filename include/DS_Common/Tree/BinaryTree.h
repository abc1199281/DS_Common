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
#include <vector>
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
}
//====================================================================================================


/* Class */
//====================================================================================================

namespace DS_Common {
	template<typename T>
	class  BinaryTree
	{
	
	private: // variable
		using visit_callback = std::function< void(BTreeNode<T>* cur) >;
		visit_callback visit_call_back_func;
	public:

		BTreeNode<T>* root;
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default Constructor
		*
		*/
		BinaryTree() {}
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default Constructor
		*
		*/
		BinaryTree(std::string str, std::function<T(const std::string & input)> );
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Constructor with Root
		*
		*/
		BinaryTree(const BinaryTree<T> & src) {	
			visit_call_back_func = [](BTreeNode<T>* cur)-> void {std::cout << cur->val << std::endl; };
			this->root = copyBinaryTree(src.root);
		}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Constructor with Root
		*
		*/
		BTreeNode<T> * copyBinaryTree(BTreeNode<T> *src)
		{
			if (src == nullptr)
			{
				return nullptr;
			}
			
			return new BTreeNode<T>(src->val,
									copyBinaryTree(src->left),
									copyBinaryTree(src->right));
		}
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
		*  @brief      level order Traversal
		*
		*/
		void levelorder(BTreeNode<T>* cur);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      level order Traversal
		*
		*/
		void levelorder() { levelorder(root); };
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
		bool isEqual(BTreeNode<T>* r1, BTreeNode<T>* r2) {
			if ((!r1) && (!r2)) return true;
			return (r1 && r2
				&& (r1->val == r2->val)
				&& isEqual(r1->left, r2->left)
				&& isEqual(r1->right, r2->right));
		};
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Check is Equal
		*
		*/
		bool BinaryTree<T>::operator==(const BinaryTree<T>& r2) { return isEqual(this->root, r2.root); };
		//-----------------------------------------------------------------------------------------


		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Check is Equal
		*
		*/
		void DestroyRecursive(BTreeNode<T>*  node)
		{
			if (node!=nullptr)
			{
				DestroyRecursive(node->left);
				DestroyRecursive(node->right);
				delete node;
			}
		}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Destructor
		*
		*/
		~BinaryTree()
		{
			DestroyRecursive(this->root);
		}
		//-----------------------------------------------------------------------------------------

	private: // function
		BTreeNode<T>* insertLevelOrder(std::vector<T>& arr, std::vector<int>& flag, int i);
	};
	//--------------------------------------------------------------------------------------------
}
//====================================================================================================


/* Public Function */
//====================================================================================================

namespace DS_Common {
	//-----------------------------------------------------------------------------------------
	template<typename T>
	BinaryTree<T>::BinaryTree(std::string s, std::function<T(const std::string & input)> funct){
		visit_call_back_func = [](BTreeNode<T>* cur)-> void {std::cout << cur->val << std::endl; };
		int n = s.size();

		std::vector<T> arr;
		std::vector<int> flag;
		std::string local;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '[' || s[i] == ']' || s[i]==',' || s[i] == '.' || s[i] == ' ') continue;
			if (s[i] == 'n')
			{
				i += 3;
				T empty_ele;
				flag.push_back(0);
				arr.push_back(empty_ele);
				continue;
			}
			else {

				std::size_t found = s.find(',');
				if (found == std::string::npos)
					found = s.find(']');
				if (found == std::string::npos)
					continue;
				s[found] = '.';
				local = s.substr(i, found - i);

				arr.push_back(funct(local));
				flag.push_back(1);
			}
		}
		this->root = insertLevelOrder(arr, flag, 0);
	}
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::levelorder(BTreeNode<T>* root)
	{
		if (!root) return;
		std::queue<BTreeNode<T>*> q;
		BTreeNode<T>* cur = root;
		q.push(cur);
		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			visit_call_back_func(cur);
			if (cur->left) q.push(cur->left);			
			if (cur->right) q.push(cur->right);
		}
	}
	//-----------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------
	template<typename T>
	void BinaryTree<T>::inorder(BTreeNode<T>* cur)
	{
		if (cur==nullptr) return;
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



/* Private Function */
//====================================================================================================

namespace DS_Common {
	//-----------------------------------------------------------------------------------------
	template<typename T>
	BTreeNode<T>* BinaryTree<T>::insertLevelOrder(std::vector<T> &arr, std::vector<int>& flag, int i) {
		BTreeNode<T>* tmp = nullptr;
		if (i < arr.size())
		{
			if (flag[i] == 1)
				tmp = new BTreeNode<T>(arr[i]);
			else
				tmp= nullptr;

			if (tmp != nullptr)
			{
				tmp->left = insertLevelOrder(arr, flag, 2 * i + 1);
			}
			if (tmp != nullptr)
			{
				tmp->right = insertLevelOrder(arr, flag, 2 * i + 2);
			}
		}
		return tmp;
	}
	//-----------------------------------------------------------------------------------------
}
//====================================================================================================
#endif /* __DS_COMMON_BINARY_TREE_H__ */
