// TestTime.cpp

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


		system("pause");
	}

	//------------------------------------------------------------------------------------------------

}
//====================================================================================================