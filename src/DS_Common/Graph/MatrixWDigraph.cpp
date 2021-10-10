// MatrixWDigraph.cpp

/* Header */
//====================================================================================================
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

#include <DS_Common/Graph/MatrixWDigraph.h>
#include <DS_Common/Set/DisjointSetArray.h>
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

	int MatrixWDigraph::Degree(int u ) const
	{
		if (this->is_directional)
			return InDegree(u) + OutDegree(u);
		else
			return InDegree(u);
	}
	//------------------------------------------------------------------------------------------------

	int MatrixWDigraph::InDegree(int u) const
	{
		int degree = 0;
		for (int i = 0; i < numVer; i++)
		{
			degree += this->adj_edge[i][u];
		}
		return degree;
	}
	//------------------------------------------------------------------------------------------------

	int MatrixWDigraph::OutDegree(int u) const
	{
		int degree = 0;
		for (int i = 0; i < numVer; i++)
		{
			degree += this->adj_edge[u][i];
		}
		return degree;
	}
	//------------------------------------------------------------------------------------------------

	bool MatrixWDigraph::ExistsEdge(int u, int v) const
	{
		if (u > numVer || v > numVer)
		{
			std::cout << "warning: out of range. " << std::endl;
			return false;
		}
		return adj_edge[u][v] == 1 || adj_edge[v][u] == 1;
	}

	//------------------------------------------------------------------------------------------------

	void MatrixWDigraph::LoadFile(const std::string& file_name) 
	{
		
		std::fstream infile;
		infile.open(file_name, std::ios::in);
		std::cout << file_name << std::endl;
		if (!infile.is_open())
		{
			std::cout << "warning: not open file. " << std::endl;
			infile.close();
			return;
		}
			
		int a, b, cost;
		infile >> this->is_weight >> this->is_directional;
		std::cout << "Weighted: " << is_weight << "& directional:" << is_directional << std::endl;
		infile >> this->numVer >> this->numEdge;
		std::cout << "V: " << numVer << "& Edge:" << numEdge << std::endl;

		this->adj_edge = std::vector<std::vector<int>>(numVer, std::vector<int>(numVer, 0));
		this->adj_weight = std::vector<std::vector<double>>(numVer, std::vector<double>(numVer, 0));

		for (int i = 0; i < numEdge; i++)
		{
			if (is_weight == 1)
			{
				infile >> a >> b >> cost;
				this->adj_edge[a][b] = 1;
				this->adj_weight[a][b] = cost;
				if (is_directional == 0)
				{
					this->adj_edge[b][a] = 1;
					this->adj_weight[b][a] = cost;
				}
				//std::cout << "Add V: " << a << "& " << b << ", cost" << cost << std::endl;
			}else {
				infile >> a >> b;
				this->adj_edge[a][b] = 1;
				this->adj_weight[a][b] = 1;
				if (is_directional == 0)
				{
					this->adj_edge[b][a] = 1;
					this->adj_weight[b][a] = 1;
				}					
				//std::cout << "Add V: " << a << "& " << b << std::endl;
			}
		}
		infile.close();
	}

	//------------------------------------------------------------------------------------------------

	void MatrixWDigraph::InsertVertex(int v)	
	{
		
	}

	//------------------------------------------------------------------------------------------------
	void MatrixWDigraph::InsertEdge(int u, int v, int cost)	
	{
		if (u > numVer || v > numVer)
		{
			std::cout << "warning: out of range. u:"<<u <<", v:"<<v<<",num of V:"<< numVer << std::endl;
			return;
		}
		adj_edge[u][v] = 1;
		adj_weight[u][v] = cost;
	}

    //------------------------------------------------------------------------------------------------

	void MatrixWDigraph::DeleteVertex(int v)
    {
        
    }

	//------------------------------------------------------------------------------------------------

	void MatrixWDigraph::DeleteEdge(int u, int v)
	{
		if (u > numVer || v > numVer)
		{
			std::cout << "warning: out of range. " << std::endl;
			return;
		}
		adj_edge[u][v] = 0;
		adj_weight[u][v] = 0;
	}

	//------------------------------------------------------------------------------------------------


	void MatrixWDigraph::DFS(const int v)
	{
		if (v > numVer) return;

		visited = new bool[numVer];
		std::fill(visited, visited + numVer, false);
		std::stack<int> s;
		s.push(v);
		while (!s.empty())
		{
			int tmp_v = s.top();
			s.pop();

			if (!visited[tmp_v])
			{
				visit_call_back_func(tmp_v);
				visited[tmp_v] = true;

				for (int w = 0; w < numVer; w++)
				{
					if (this->adj_edge[tmp_v][w] == 1)
					{
						if (!visited[w]) {
							s.push(w);
						}
					}
				}
			}
		}
		delete visited;
	}
	//------------------------------------------------------------------------------------------------

	void MatrixWDigraph::DFS_share_visit(const int v)
	{
		if (v > numVer) return;

		visit_call_back_func(v);
		visited[v] = true;

		for (int w = 0; w < numVer; w++)
		{
			if (this->adj_edge[v][w] == 1)
			{
				if (!visited[w])
				{
					DFS_share_visit(w);
				}
			}			
		}
	}
	//------------------------------------------------------------------------------------------------

	void MatrixWDigraph::BFS(const int v)
	{
		if (v > numVer) return;

		visited = new bool[numVer];
		std::fill(visited, visited + numVer, false);

		visit_call_back_func(v);
		visited[v] = true;

		std::queue<int> q;
		q.push(v);
		int tmp_v;
		while (!q.empty())
		{
			tmp_v = q.front();
			q.pop();
			for (int w = 0; w < numVer; w++)
			{
				if (this->adj_edge[tmp_v][w] == 1)
				{
					if (!visited[w]) {
						visit_call_back_func(w);
						q.push(w);	
						visited[w] = true;
					}
				}
			}
		}
		delete visited;
	}
	//------------------------------------------------------------------------------------------------
	double MatrixWDigraph::shortest_path_BellmanFord(const int src, const int dest)
	{
		std::priority_queue<std::pair<double, int>> edges_heap; //dist, vertice
		std::vector<double> dist(numVer, INT_MAX);

		// initialize dist
		dist[src] = 0;
		for (int i = 0; i < numVer; i++)
		{
			if (adj_edge[src][i] == 1)
				dist[i] = adj_weight[src][i];
		}

		// debug
		/*
		std::cout << "iter:" << 1;
		for (int i = 0; i < numVer; i++)
			std::cout << ", dist[" << i << "]:" << dist[i];
		std::cout << std::endl;
		*/

		// relax (numVer-1 times)
		for (int k=2; k <=numVer - 1; k++)
		{
			for (int i = 0; i < numVer; i++) // each edge
			{
				for (int j = 0; j < numVer; j++) // each edge
				{
					if (adj_edge[i][j] == 1)
					{
						if (dist[j] > dist[i] + adj_weight[i][j])
							dist[j] = dist[i] + adj_weight[i][j];
					}
				}
			}

			// debug
			/*std::cout << "iter:" << k;
			for (int i = 0; i < numVer; i++)
				std::cout << ", dist[" << i << "]:" << dist[i];
			std::cout << std::endl;*/
		}

		if (dist[dest] != INT_MAX)
			return dist[dest];
		else
			return -1;
	}
	//------------------------------------------------------------------------------------------------

	double MatrixWDigraph::shortest_path_Dijkstras(const int src, const int dest)
	{
		
		std::priority_queue<std::pair<double, int>> edges_heap; //dist, vertice
		std::vector<double> dist(numVer, INT_MAX);

		std::vector<bool> marked(numVer, false);

		edges_heap.push({ 0, src}); // dist of src = 0
		dist[src] = 0;

		while (!edges_heap.empty())
		{
			int current_dist = -1*edges_heap.top().first;
			int v = edges_heap.top().second;

			edges_heap.pop();

			for (int i = 0; i < numVer; i++)
			{
				if (adj_edge[v][i] == 1 && marked[i]==false)
				{
					if (current_dist + adj_weight[v][i] < dist[i])
					{
						dist[i] = current_dist + adj_weight[v][i];
						edges_heap.push({ -1 * dist[i], i});
					}
				}
			}
			marked[v] == true;
		}
		
		if (dist[dest] != INT_MAX)
			return dist[dest];
		else
			return -1;
	}
	//------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================