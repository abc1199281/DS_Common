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
				if(is_directional ==0)
					this->adj_edge[b][a] = 1;
					this->adj_weight[a][b] = cost;
				std::cout << "Add V: " << a << "& " << b << ", cost" << cost << std::endl;
			}else {
				infile >> a >> b;
				this->adj_edge[a][b] = 1;
				this->adj_weight[a][b] = 1;
				if (is_directional == 0)
					this->adj_edge[b][a] = 1;
					this->adj_weight[a][b] = 1;
				std::cout << "Add V: " << a << "& " << b << std::endl;
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
			std::cout << "warning: out of range. " << std::endl;
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
				std::cout << "Visit ver: " << tmp_v << std::endl;
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


	void MatrixWDigraph::BFS(const int v)
	{
		if (v > numVer) return;

		visited = new bool[numVer];
		std::fill(visited, visited + numVer, false);

		std::cout << "Visit ver: " << v << std::endl;
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
						q.push(w);
						std::cout << "Visit ver: " << w << std::endl;
						visited[w] = true;
					}
				}
			}
		}
		delete visited;
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