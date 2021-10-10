// MatrixWDigraph.h

#ifndef __DS_COMMON_MATRIXWDIGRAPH_H__
#define __DS_COMMON_MATRIXWDIGRAPH_H__

/* Information */
//====================================================================================================

/*!
*  @file   MatrixWDigraph.h
*
*  @brief  The Definition of Graph and its template
*
*  @author Po-Wei Huang
*
*  @date   2021/09/28
*/

//====================================================================================================

/* Header */
//====================================================================================================

#include <iostream>
#include <vector>
#include <condition_variable>

#include <DS_Common/Graph/Graph.h>
#include <DS_Common/LibSetting/LibSetting.h>
//====================================================================================================


/* Definition */
//====================================================================================================

namespace DS_Common {

}
//====================================================================================================


/* Class */
//====================================================================================================
namespace DS_Common {
	class  DS_COMMON_EXPORTS MatrixWDigraph: public Graph
	{
	protected: // variables
		std::vector< std::vector<int> > adj_edge;
		std::vector< std::vector<double> > adj_weight;
	public:
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default destructor
		*
		*/
		MatrixWDigraph(int n = 1):Graph(n) {
			this->adj_edge = std::vector<std::vector<int>>(numVer, std::vector<int>(numVer, 0));
			this->adj_weight = std::vector<std::vector<double>>(numVer, std::vector<double>(numVer, 0));
		}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default destructor
		*
		*/
		~MatrixWDigraph() {}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      return the degree for the vertice u
		*
		*/
		int Degree(int u) const;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      return the degree for the vertice u
		*
		*/
		int InDegree(int u) const;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      return the degree for the vertice u
		*
		*/
		int OutDegree(int u) const;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Return True if u,v, is a edge in this graph
		*
		*/
		bool ExistsEdge(int u, int v) const;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Load file
		*
		*/
		void LoadFile(const std::string & file_name);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      insert a vertex without any connection
		*
		*/
		void InsertVertex(int v);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      insert a edge u and v
		*
		*/
		void InsertEdge(int u, int v, int cost = 1);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Delete vertex
		*
		*/
		void DeleteVertex(int v);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Delete edge
		*
		*/
		void DeleteEdge(int u, int v);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      depth first traversal
		*
		*/
		void DFS(const int v);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      depth first traversal
		*
		*/
		void DFS_share_visit(const int v);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      bread first traversal
		*
		*/
		void BFS(const int v);
		//-----------------------------------------------------------------------------------------

	};
	//--------------------------------------------------------------------------------------------
}
//====================================================================================================


/* Public Function */
//====================================================================================================

namespace DS_Common {
	//-----------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------
}
//====================================================================================================



/* Private Function */
//====================================================================================================

namespace DS_Common {
	//-----------------------------------------------------------------------------------------
}
//====================================================================================================
#endif /* __DS_COMMON_MATRIXWDIGRAPH_H__ */
