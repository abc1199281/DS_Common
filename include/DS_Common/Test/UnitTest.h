// UnitTest.h

#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

/* Information */
//====================================================================================================

/*!
*  @file   UnitTest.h
*
*  @brief  Several tools for unit test using gogle test.
*
*  @author Po-Wei Huang
*
*  @date   2019/02/02
*/

//====================================================================================================


/* Header */
//====================================================================================================
#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <DS_Common/Common/Common.h>
//#include <BIO-Common/File/File.h>
//====================================================================================================

/* Public Function */
//====================================================================================================
namespace UnitTest {

	//------------------------------------------------------------------------------------------------
	/*!
	*  @brief      compare two value with default tolerance e-3 in Unit Test. (int, float, double)
	*
	*  @param[in]  expected   The expected value.
	*  @param[in]  actual	  Actual derived value.
	*
	*  @return     success or not in AssertionResult format.
	*/
	template<typename T>
	testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const T  const& expected, const T const& actual);
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	/*!
	*  @brief      compare two value with tolerance in Unit Test. (int, float, double)
	*
	*  @param[in]  expected   The expected value.
	*  @param[in]  actual	  Actual derived value.
	*  @param[in]  tolerance  The tolerance value.
	*
	*  @return     success or not in AssertionResult format.
	*/
	template<typename T>
	testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const T  const& expected, const T const& actual, double tolerance);
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	/*!
	*  @brief      compare two vector with default tolerance e-3 in Unit Test. (int, float, double)
	*
	*  @param[in]  expected   The expected value.
	*  @param[in]  actual	  Actual derived value.
	*
	*  @return     success or not in AssertionResult format.
	*/
	template<typename T>
	testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<T>  const& expected,
										                 const std::vector<T> const& actual);
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	/*!
	*  @brief      compare two vector with tolerance in Unit Test. (int, float, double)
	*
	*  @param[in]  expected   The expected value.
	*  @param[in]  actual	  Actual derived value.
	*  @param[in]  tolerance  The tolerance value.
	*
	*  @return     success or not in AssertionResult format.
	*/
	template<typename T>
	testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<T>  const& expected,
										                 const std::vector<T> const& actual,
										                 double tolerance);
	//------------------------------------------------------------------------------------------------
}
/* Class */
//====================================================================================================
namespace UnitTest {

	class DS_COMMON_EXPORTS Test :public testing::Test {
	public: // Variable
		std::string DATA_PATH;
		std::string OUTPUT_PATH;

	public: // Function
		//------------------------------------------------------------------------------------------------
		/*!
		*  @brief      update relative path of DATA_PATH/OUTPUT_PATH for derived class.
		*
		*  @param[in]  MODULE_NAME   The post-fix module name.
		*/
		void update(std::string MODULE_NAME, std::string SOLUTIOON_NAME="DS_Common") {
            std::string slash = "\\";
			DATA_PATH =   ".." + slash + ".." + slash + ".." + slash + ".." + slash + SOLUTIOON_NAME + slash + "test" + slash + "data"   + slash + MODULE_NAME;
			OUTPUT_PATH = ".." + slash + ".." + slash + ".." + slash + ".." + slash + SOLUTIOON_NAME + slash + "test" + slash + "output" + slash + MODULE_NAME;
		}
		//------------------------------------------------------------------------------------------------
	};
}

//====================================================================================================

#endif /* __UNIT_TEST_H__ */