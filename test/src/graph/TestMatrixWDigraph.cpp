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
	TEST_F(TestMatrixWDigraph, load_data) {
		std::string loaded_file = TestMatrixWDigraph::DATA_PATH + "\\WDigraph_6_26.txt";
		std::cout << loaded_file <<std::endl;

		matrix_w_digraph->LoadFile(loaded_file);

	}

	//------------------------------------------------------------------------------------------------
	TEST_F(TestMatrixWDigraph, basic_operation) {
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
		
		std::cout << "DFS of " << std::endl;
		matrix_w_digraph->DFS(0);

		std::cout << "BFS of " << std::endl;
		matrix_w_digraph->BFS(0);
	}
	//------------------------------------------------------------------------------------------------


}
//====================================================================================================