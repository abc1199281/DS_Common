// TestMatrixWGraph.cpp

/* Header */
//====================================================================================================
#include <iostream>
#include <string>
#include <memory>

#include <DS_Common/Test/UnitTest.h>

#include <DS_Common/Graph/MatrixWGraph.h>
//====================================================================================================


/* Definition */
//====================================================================================================
namespace UnitTest {
	class TestMatrixWGraph :public UnitTest::Test {
	protected:
        std::string MODULE_NAME = "Graph";
		std::shared_ptr<DS_Common::MatrixWGraph> matrix_w_graph;
		virtual void SetUp()
		{
			this->update(MODULE_NAME);
			matrix_w_graph = std::make_shared<DS_Common::MatrixWGraph>();
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
	TEST_F(TestMatrixWGraph, basic_operation) {
		int u = 0, v = 1;

		std::string loaded_file = TestMatrixWGraph::DATA_PATH + "\\Wgraph_6_23.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_graph->LoadFile(loaded_file);

		std::cout << "IsEmpty:" << matrix_w_graph->IsEmpty() << std::endl;
		std::cout << "Number of Vertices:" << matrix_w_graph->NumberOfVertices() << std::endl;
		std::cout << "Number of Edges:" << matrix_w_graph->NumberOfEdges() << std::endl;
		std::cout << "Degree of "<< u << ": "<< matrix_w_graph->Degree(u) << std::endl;
	}
	//------------------------------------------------------------------------------------------------

	TEST_F(TestMatrixWGraph, 6_3_1_Kruskal_MinSpanningTree) {
		std::string loaded_file = TestMatrixWGraph::DATA_PATH + "\\Wgraph_6_23.txt";
		std::cout << loaded_file << std::endl;

		matrix_w_graph->LoadFile(loaded_file);

		std::shared_ptr<DS_Common::MatrixWGraph> result = matrix_w_graph->kruskal_MST();

		result->DFS(0);
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================