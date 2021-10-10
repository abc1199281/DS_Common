// MatrixWGraph.cpp

/* Header */
//====================================================================================================
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

#include <DS_Common/Graph/MatrixWGraph.h>
#include <DS_Common/Set/DisjointSetArray.h>
#include <DS_Common/Queue/PriorityQueue.h>
//====================================================================================================

/* Private Mmeber */
//====================================================================================================

namespace DS_Common {
}
//====================================================================================================



/* Public Function */
//====================================================================================================

namespace DS_Common {
	//------------------------------------------------------------------------------------------------


	//------------------------------------------------------------------------------------------------

	int MatrixWGraph::Degree(int u ) const
	{
		int degree = 0;
		for (int i = 0; i < numVer; i++)
		{
			degree += this->adj_edge[i][u];
		}
		return degree;
	}
	//------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------
	void MatrixWGraph::InsertEdge(int u, int v, int cost)
	{
		if (u > numVer || v > numVer)
		{
			std::cout << "warning: out of range. u:" << u << ", v:" << v << ",num of V:" << numVer << std::endl;
			return;
		}
		adj_edge[u][v] = 1;
		adj_weight[u][v] = cost;
		adj_edge[v][u] = 1;
		adj_weight[v][u] = cost;
	}

	//------------------------------------------------------------------------------------------------

	void MatrixWGraph::DeleteEdge(int u, int v)
	{
		if (u > numVer || v > numVer)
		{
			std::cout << "warning: out of range. " << std::endl;
			return;
		}
		adj_edge[u][v] = 0;
		adj_weight[u][v] = 0;
		adj_edge[v][u] = 0;
		adj_weight[v][u] = 0;
	}

	//------------------------------------------------------------------------------------------------

	std::shared_ptr<MatrixWGraph> MatrixWGraph::kruskal_MST()
	{
		typedef  std::pair<int, int> iPair;
		//DS_Common::PriorityQueue<std::pair<double, iPair>> edges_heap;
		std::priority_queue<std::pair<double, iPair>> edges_heap;

		// Insert and sort all edges.
		for (int i = 0; i < numVer; i++)
			for (int j = i; j < numVer; j++)
				if (adj_edge[i][j] != 0)
					edges_heap.push({ -1*adj_weight[i][j], {i, j}});

		// prepare disjoint set for cycle check.
		DisjointSetArray disjoint_set_array;
		disjoint_set_array.initialize(this->numVer);

		std::shared_ptr<MatrixWGraph> MinSpanningTree=std::make_shared<MatrixWGraph>(this->numVer);

		std::pair<int, iPair> edge;
		while (!edges_heap.empty() && MinSpanningTree->NumberOfEdges()<=numVer-1)
		{
			edge = edges_heap.top(); // the edge with lowest cost.			
			edges_heap.pop();

			int cost =-1* edge.first;
			int u = edge.second.first;
			int v = edge.second.second;

			if (!disjoint_set_array.equivlence(u, v))// check no cycle
			{
				std::cout << "Kruskal MST Add u:" << u << ",v:" << v << ",cost:" << cost << std::endl;
				disjoint_set_array.union_member(u, v);
				MinSpanningTree->InsertEdge(u,v,cost);
			}
		}

		return MinSpanningTree;
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================



/* Private Function */
//====================================================================================================

namespace DS_Common {
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
}
//====================================================================================================