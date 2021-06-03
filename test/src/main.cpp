// main.cpp


/* Header */
//====================================================================================================
#include <DS_Common/Test/UnitTest.h>
#include <string>
//====================================================================================================


#include <iostream>     // cout
#include <math.h>       // acos
#include <float.h>      // DBL_MAX
#include <limits>       // numeric_limits


/* Public Function */
//====================================================================================================

int main(int argc, char ** argv)
{
	// create google UT.
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

//====================================================================================================
