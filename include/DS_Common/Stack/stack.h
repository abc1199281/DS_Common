// Stack.h

#ifndef __DS_COMMON_STACK_H__
#define __DS_COMMON_STACK_H__

/* Information */
//====================================================================================================

/*!
*  @file   stack.h
*
*  @brief  stack.
*
*  @author Po-Wei Huang
*
*  @date   2021/05/22
*/

//====================================================================================================


/* Header */
//====================================================================================================

#include <iostream>
#include <vector>
#include <condition_variable>

#include <DS_Common/Common/Common.h>
#include <DS_Common/LibSetting/LibSetting.h>
//====================================================================================================


/* Definition */
//====================================================================================================
//====================================================================================================

/* Class */
//====================================================================================================

namespace DS_Common {
	template<typename T>
	class  DS_COMMON_EXPORTS stack
	{
	private: // variable
		T* stack_array;
		int top_idx;
		int capacity;

	public: // function

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Constructor
		*
		*/
		stack(int n = 10);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Constructor
		*
		*/
		int size() { return top_idx+1;};
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Access next element
		*
		*/
		const T& top();
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      pop
		*
		*/
		void pop();
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Insert element
		*/
		void push(const T& e);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default Constructor
		*
		*/
		bool empty() const { return top_idx == -1; };
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Destructor
		*
		*/
		~stack() {}
		//-----------------------------------------------------------------------------------------

	};
	//--------------------------------------------------------------------------------------------
}
//====================================================================================================


/* Public Function */
//====================================================================================================

namespace DS_Common {
	//------------------------------------------------------------------------------------------------
	template<typename T>
	stack<T>::stack(int n) :capacity(n)
	{
		if (n < 1) throw "Capacity of stack must be >=1.";
		stack_array = new T[n];
		top_idx = -1;
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	void stack<T>::push(const T& x) {
		if (top_idx == capacity - 1)
		{
			ChangeSize1D(stack_array, capacity, capacity*2);
			capacity *= 2;
		}
		stack_array[++top_idx] = x;
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	void stack<T>::pop() {
		if (empty() == -1) throw "Stack is empty, cannot delete.";
		stack_array[top_idx--].~T();
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	const T&  stack<T>::top() {
		if (empty() == -1) throw "Stack is empty";
		return stack_array[top_idx];
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================
#endif /* __DS_COMMON_STACK_H__ */