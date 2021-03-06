// Graph.h

#ifndef __DS_COMMON_GRAPH_H__
#define __DS_COMMON_GRAPH_H__

/* Information */
//====================================================================================================

/*!
*  @file   Graph.h
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

#include <DS_Common/Stack/stack.h>
#include <DS_Common/Queue/queue.h>
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
	class  DS_COMMON_EXPORTS Graph
	{
	protected: // functions

	protected: // variable
		int numVer; // number of vertices
		int numEdge; // number of edges
		int is_weight;
		int is_directional;
	
		bool * visited;
		bool * visited_cycle_check;

		using visit_callback = std::function< void(const int cur_v) >;
		visit_callback visit_call_back_func;

	public: // functions

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default constructor
		*
		*/
		Graph(int n=1): numVer(n), numEdge(0),is_weight(0), is_directional(0) {
			visit_call_back_func = [](const int cur_v)-> void {std::cout << "Visited V:" << cur_v << std::endl; };
		}
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default destructor
		*
		*/
		virtual ~Graph() {}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      is empty
		*
		*/
		bool IsEmpty() const { return numVer == 0; }
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      NumberOfVertices
		*
		*/
		int NumberOfVertices()const {
			return numVer;
		}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      NumberOfVertices
		*
		*/
		void SetCallBack(std::function< void (const int cur_v)> _funct ) {
			visit_call_back_func = _funct;
		}
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Load file
		*
		*/
		virtual void LoadFile(const std::string & file_name) = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Number Of Edge
		*
		*/
		int NumberOfEdges()const {
			return numEdge;
		}

		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      return the degree for the vertice u
		*
		*/
		virtual int Degree(int u) const = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Return True is u,v, is a edge in this graph
		*
		*/
		virtual bool ExistsEdge(int u, int v) const = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      insert a vertex without any connection
		*
		*/
		virtual void InsertVertex(int v) = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      insert a edge u and v
		*
		*/
		virtual void InsertEdge(int u, int v, int cost =1) = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Delete vertex
		*
		*/
		virtual void DeleteVertex(int v) = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Pre order Traversal
		*
		*/
		virtual void DeleteEdge(int u, int v) = 0;
		//-----------------------------------------------------------------------------------------


		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      depth first traversal
		*
		*/
		virtual void DFS(const int v) = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      bread first traversal
		*
		*/
		virtual void BFS(const int v) =0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      depth first traversal share_visit, cycle check is also included.
		*
		*/
		virtual bool DFS_share_visit(const int v) = 0;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Component
		*
		*/
		void Components()
		{
			visited = new bool[numVer];
			visited_cycle_check = new bool[numVer];
			std::fill(visited, visited + numVer, false);
			std::fill(visited_cycle_check, visited_cycle_check + numVer, false);

			int numComponent = 0;
			for (int i = 0; i < numVer; i++)
			{
				if (!visited[i]) {
					numComponent++;
					std::cout << "Component idx: " << numComponent << std::endl;
					DFS_share_visit(i);
				}
			}
			delete visited;
			delete visited_cycle_check;
		}
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
#endif /* __DS_COMMON_BINARY_TREE_H__ */
