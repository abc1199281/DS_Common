// TestDisjointSetArray.cpp

/* Header */
//====================================================================================================
#include <iostream>
#include <string>
#include <memory>

#include <DS_Common/Test/UnitTest.h>

#include <DS_Common/Set/DisjointSetArray.h>
//====================================================================================================


/* Definition */
//====================================================================================================
namespace UnitTest {
	class TestDisjointSetArray :public UnitTest::Test {
	protected:
        std::string MODULE_NAME = "Set";
		std::shared_ptr<DS_Common::DisjointSetArray> disjoint_set;
		virtual void SetUp()
		{
			this->update(MODULE_NAME);			
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
	TEST_F(TestDisjointSetArray, find) {

		disjoint_set = std::make_shared<DS_Common::DisjointSetArray>();
		disjoint_set->initialize(10);
		
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================