// MatrixWDigraph.cpp

/* Header */
//====================================================================================================
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

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
		return 1;
	}
	//------------------------------------------------------------------------------------------------

	bool MatrixWDigraph::ExistsEdge(int u, int v) const
	{
		return true;
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
		int directional, weighted;
		infile >> weighted >> directional;
		std::cout << "Weighted: " << weighted << "& directional:" << directional << std::endl;
		infile >> this->numVer >> this->numEdge;
		std::cout << "V: " << numVer << "& Edge:" << numEdge << std::endl;
		this->adj = std::vector<std::vector<double>>(numVer, std::vector<double>(numVer, 0));
		for (int i = 0; i < numEdge; i++)
		{
			if (weighted == 1)
			{
				infile >> a >> b >> cost;
				this->adj[a][b] = cost;
				if(directional==0)
					this->adj[b][a] = cost;
				std::cout << "Add V: " << a << "& " << b << ", cost" << cost << std::endl;
			}else {
				infile >> a >> b;
				this->adj[a][b] = 1;
				if (directional == 0)
					this->adj[b][a] = 1;
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
	void MatrixWDigraph::InsertEdge(int u, int v)	
	{
		
	}

    //------------------------------------------------------------------------------------------------

	void MatrixWDigraph::DeleteVertex(int v)
    {
        
    }

	//------------------------------------------------------------------------------------------------

	void MatrixWDigraph::DeleteEdge(int u, int v)
	{

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