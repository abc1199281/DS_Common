// TestBinaryTree.h


/* Header */
//====================================================================================================
#include <iostream>
#include <windows.h>
#include <string>
#include <condition_variable>

#include <DS_Common/Tree/BinaryTree.h>
#include <DS_Common/Queue/PriorityQueue.h>

using namespace DS_Common;
//====================================================================================================

/* Definition Function */
//====================================================================================================
void basicTest();
//====================================================================================================

/* Public Function */
//====================================================================================================
void TestPriorityQueue()
{

	basicTest();
}
//====================================================================================================


/* Private Function */
//====================================================================================================

void basicTest()
{
	int N = 100;

	PriorityQueue<int> q;
	for (int i = 0; i < N; i++)
	{
		q.push(i);
	}

	while(!q.isempty())
	{
		std::cout << q.top() << std::endl;
		q.pop();
	}

}
//-------------------------------------------------------------------------------------------------

//====================================================================================================

