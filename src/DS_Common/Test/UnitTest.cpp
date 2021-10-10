// UnitTest.cpp

/* Header */
//====================================================================================================
#include <iostream>
#include <gtest/gtest.h>
#include <DS_Common/Test/UnitTest.h>
//====================================================================================================



/* Public Function */
//====================================================================================================
namespace UnitTest {
	//------------------------------------------------------------------------------------------------
	template<typename T>
	testing::AssertionResult ValueMatch(const T  const& expected, const T const& actual)
	{
		return ValueMatch(expected, actual, 1e-3);
	}

	template testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const int  const& expected, const int const& actual);
	template testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const float const& expected, const float const& actual);
	template testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const double  const& expected, const double const& actual);

	//------------------------------------------------------------------------------------------------

	template<typename T>
	testing::AssertionResult ValueMatch(const T  const& expected, const T const& actual, double tolerance)
	{
		if (abs(expected - actual)>tolerance) {
			return testing::AssertionFailure() << actual << " != expected" << expected << "\n";
		}
		return testing::AssertionSuccess();
	}

	template testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const int  const& expected,
												 const int const& actual, 
												 double tolerance);
	template testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const float const& expected,
												 const float const& actual, 
												 double tolerance);
	template testing::AssertionResult DS_COMMON_EXPORTS ValueMatch(const double  const& expected,
												 const double const& actual, 
												 double tolerance);
	//------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------
	template<typename T>
	testing::AssertionResult ArraysMatch(const std::vector<T>  const& expected,
		const std::vector<T> const& actual)
	{
		return ArraysMatch(expected, actual, 1e-3);
	}

	template testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<int>  const& expected,
		const std::vector<int> const& actual);
	template testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<double>  const& expected,
		const std::vector<double> const& actual);
	template testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<float>  const& expected,
		const std::vector<float> const& actual);

	//------------------------------------------------------------------------------------------------

	template<typename T>
	testing::AssertionResult ArraysMatch(const std::vector<T>  const& expected,
		const std::vector<T> const& actual,
		double tolerance)
	{
		if (expected.size() != actual.size())
			return testing::AssertionFailure() << "expected.size()=" << expected.size()
			<< " != actual.size() " << actual.size();
		for (size_t i(0); i < expected.size(); ++i) {
			if (abs(expected[i] - actual[i])>tolerance) {
				return testing::AssertionFailure() << "array[" << i
					<< "] (" << actual[i] << ") != expected[" << i
					<< "] (" << expected[i] << ")";
			}
		}
		return testing::AssertionSuccess();
	}

	template testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<int>  const& expected,
											const std::vector<int> const& actual,
											double tolerance);

	template testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<double>  const& expected,
											const std::vector<double> const& actual,
											double tolerance);

	template testing::AssertionResult DS_COMMON_EXPORTS ArraysMatch(const std::vector<float>  const& expected,
											const std::vector<float> const& actual,
											double tolerance);
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================