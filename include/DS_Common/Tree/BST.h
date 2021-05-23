// BST.h

#ifndef __DS_COMMON_BINARY_SEARCH_TREE_H__
#define __DS_COMMON_BINARY_SEARCH_TREE_H__

/* Information */
//====================================================================================================

/*!
*  @file   BST.h
*
*  @brief  The Definition of Binary Search Tree
*
*  @author Po-Wei Huang
*
*  @date   2021/04/25
*/

//====================================================================================================


/* Header */
//====================================================================================================

#include <iostream>
#include <vector>
#include <utility>
#include <condition_variable>

#include <DS_Common/LibSetting/LibSetting.h>
#include <DS_Common/Tree/BinaryTree.h>
//====================================================================================================



/* Class */
//====================================================================================================

namespace DS_Common {
	template<typename K, typename E>
	class  DS_COMMON_EXPORTS BST
	{
	
	private: // variable
		using BST_pair = std::pair<K, E>;
		BTreeNode<BST_pair>* root;
	public:
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default Constructor
		*
		*/
		BST() {}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      top
		*
		*/
		BST_pair get(const K&k) {
			BTreeNode<BST_pair>* tmp = get(root,k);
			BST_pair empty;
			if (tmp == nullptr)
				return empty;
			else 
				return tmp->val;
		};
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Recursive top
		*
		*/
		BTreeNode<BST_pair>* get(BTreeNode<BST_pair>*p, const K&k) {
			if (!p) return nullptr;
			if (k < p->val.first) return get(p->left, k);
			if (k > p->val.first) return get(p->right, k);
			return p;
		};
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      push
		*/
		void push(const BST_pair& input)
		{
			BTreeNode<BST_pair>*p = root, *pp = nullptr;
			while (p!=nullptr)
			{
				pp = p;
				if (input.first < p->val.first) p = p->left;
				else if (input.first > p->val.first) p = p->right;
				else {
					p->val.second = input.second; // repeated key, update the element.
					return;
				}
			}

			p = new BTreeNode<BST_pair>(input);
			if (root)
				if (input.first < pp->val.first) pp->left = p;
				else pp->right = p;
			else
				root = p;
		}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      remove
		*/
		bool remove(const K&k) {
			remove(this->root, k);
			return true;
		}
		//-----------------------------------------------------------------------------------------

		BTreeNode<BST_pair>* minValueNode(BTreeNode<BST_pair>* node)
		{
			BTreeNode<BST_pair>* current = node;

			/* loop down to find the leftmost leaf */
			while (current && current->left != nullptr)
				current = current->left;

			return current;
		}

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      remove
		*/
		BTreeNode<BST_pair> * remove(BTreeNode<BST_pair> *root, const K&k) {
			if (!root) return nullptr;

			if (k < root->val.first)
				root->left = remove(root->left, k);
			else if (k > root->val.first)
				root->right = remove(root->right, k);
			else {
				if (root->left == nullptr && root->right == nullptr)
				{
					delete root;
					return nullptr;
				}
				else if (root->left == nullptr)
				{
					BTreeNode<BST_pair>* p = root->right;
					delete root;
					return p;
				}
				else if (root->right == nullptr)
				{
					BTreeNode<BST_pair>*p = root->left;
					delete root;
					return p;
				}
				BTreeNode<BST_pair>*p = minValueNode(root->right);

				root->val.first = p->val.first;
				root->val.second = p->val.second;
				root->right = remove(root->right,p->val.first);
			}
			return root;
		}
		//-----------------------------------------------------------------------------------------
		
	};
	//--------------------------------------------------------------------------------------------
}
//====================================================================================================

#endif /* __DS_COMMON_BINARY_SEARCH_TREE_H__ */
