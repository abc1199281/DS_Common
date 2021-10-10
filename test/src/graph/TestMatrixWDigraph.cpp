// TestMatrixWDigraph.cpp

/* Header */
//====================================================================================================
#include <iostream>
#include <string>
#include <memory>

#include <DS_Common/Test/UnitTest.h>

#include <DS_Common/Graph/MatrixWDigraph.h>
//====================================================================================================


/* Definition */
//====================================================================================================
namespace UnitTest {
	class TestMatrixWDigraph :public UnitTest::Test {
	protected:
        std::string MODULE_NAME = "Graph";
		std::shared_ptr<DS_Common::MatrixWDigraph> matrix_w_digraph;
		virtual void SetUp()
		{
			this->update(MODULE_NAME);
			matrix_w_digraph = std::make_shared<DS_Common::MatrixWDigraph>();
		}

		virtual void TearDown()
		{
		}
	};
}
//====================================================================================================


/* Function */
//====================================================================================================
namespace UnitTest {

	//------------------------------------------------------------------------------------------------
	TEST_F(TestMatrixWDigraph, 6_1_3_basic_operation) {
		int u = 0, v = 1;

		std::string loaded_file = TestMatrixWDigraph::DATA_PATH + "\\graph_6_17.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_digraph->LoadFile(loaded_file);

		std::cout << "IsEmpty:" << matrix_w_digraph->IsEmpty() << std::endl;
		std::cout << "Number of Vertices:" << matrix_w_digraph->NumberOfVertices() << std::endl;
		std::cout << "Number of Edges:" << matrix_w_digraph->NumberOfEdges() << std::endl;
		std::cout << "Degree of "<< u << ": "<< matrix_w_digraph->Degree(u) << std::endl;
		std::cout << "In Degree of " << u << ": " << matrix_w_digraph->InDegree(u) << std::endl;
		std::cout << "Out Degree of " << u << ": " << matrix_w_digraph->OutDegree(u) << std::endl;
		
	}
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	TEST_F(TestMatrixWDigraph, 6_2_1_and_6_2_2_DFS_BFS) {
		int u = 0, v = 1;

		std::string loaded_file = TestMatrixWDigraph::DATA_PATH + "\\graph_6_17.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_digraph->LoadFile(loaded_file);


		std::cout << "DFS of " << std::endl;
		matrix_w_digraph->DFS(0);

		std::cout << "BFS of " << std::endl;
		matrix_w_digraph->BFS(0);
	}
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	TEST_F(TestMatrixWDigraph, 6_2_3_Components) {		
		std::string loaded_file = TestMatrixWDigraph::DATA_PATH + "\\graph_6_17_plus.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_digraph->LoadFile(loaded_file);

		matrix_w_digraph->Components();

	}
	//------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------
	TEST_F(TestMatrixWDigraph, 6_4_1_shortest_path_Dijkstras) {
		std::string loaded_file = TestMatrixWDigraph::DATA_PATH + "\\WDigraph_6_26.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_digraph->LoadFile(loaded_file);

		std::cout <<"Shortest from 0 to 1 in Graph 6.26: "<< matrix_w_digraph->shortest_path_Dijkstras(0, 1) << std::endl;

		loaded_file = TestMatrixWDigraph::DATA_PATH + "\\WDigraph_6_27.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_digraph->LoadFile(loaded_file);

		for (int i = 0; i < 8; i++)
		{
			std::cout << "Shortest from 4 to "<<i<<" in Graph 6.27: " << matrix_w_digraph->shortest_path_Dijkstras(4, i) << std::endl;
		}
	}
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	TEST_F(TestMatrixWDigraph, 6_4_2_shortest_path_BellmanFord) {		
		std::string loaded_file = TestMatrixWDigraph::DATA_PATH + "\\WDigraph_6_31.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_digraph->LoadFile(loaded_file);

		for (int i = 0; i < 7; i++)
		{
			std::cout << "Shortest from 0 to " << i << " in Graph 6.31: "
				<< matrix_w_digraph->shortest_path_BellmanFord(0, i) << std::endl;
		}
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================