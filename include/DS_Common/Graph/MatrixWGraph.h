// MatrixWGraph.h

#ifndef __DS_COMMON_MATRIXWGRAPH_H__
#define __DS_COMMON_MATRIXWGRAPH_H__

/* Information */
//====================================================================================================

/*!
*  @file   MatrixWGraph.h
*
*  @brief  The Definition of Graph and its template
*
*  @author Po-Wei Huang
*
*  @date   2021/10/09
*/

//====================================================================================================

/* Header */
//====================================================================================================

#include <iostream>
#include <vector>


#include <DS_Common/Graph/MatrixWDigraph.h>
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
	class DS_COMMON_EXPORTS MatrixWGraph: public MatrixWDigraph
	{
	public:

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default destructor
		*
		*/
		MatrixWGraph(int n = 1):MatrixWDigraph(n){
			this->adj_edge = std::vector<std::vector<int>>(numVer, std::vector<int>(numVer, 0));
			this->adj_weight = std::vector<std::vector<double>>(numVer, std::vector<double>(numVer, 0));
		}
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default destructor
		*
		*/
		~MatrixWGraph() {}
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
		int InDegree(int u) const = delete;
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
		*  @brief      Delete edge
		*
		*/
		void DeleteEdge(int u, int v);
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      return the degree for the vertice u
		*
		*/
		int OutDegree(int u) const = delete;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      minimal spanning tree Kruskal
		*
		*/
		std::shared_ptr<MatrixWGraph> kruskal_MST();
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
#endif /* __DS_COMMON_MATRIXWGRAPH_H__ */