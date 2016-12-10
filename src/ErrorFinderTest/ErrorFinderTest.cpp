/*
ErrorFinderTest. Tests a class ErrorFinder for errors.
The method TestRegExpr takes an array of strings and checks a regular expression which matches to errors.
The nethod TestGetErrorsCount checks an amount of errors in test input file which redirected to stdin.
*/

#include <pcrecpp.h>	// PCRE library
#include <iostream>		// ifstream/ofstream/fstream
#include "ErrorFinderTest.h"
#include "../ErrorFinder/ErrorFinder.h"

using namespace std;

void ErrorFinderTest::TestRegExpr() 
{
	ErrorFinder finder;
	pcrecpp::RE pattern( finder.mainRegexp );
	const char* errorMessage = "ErrorFinder.cpp: string can't be matched by regular expression!";
	
	bool assert = true;
	for (int i = 0; i < 5; i++) 
	{
		assert = ( (pattern.FullMatch( errors[i] ) == ( (i <= 3) ? 1 : 0) ) && 
			( errors[i] != ErrorFinder::noteStart ) &&
			( errors[i] != ErrorFinder::noteEnd ));
		if ( !assert ) 
		{
			break;
		}
	}
	
	CPPUNIT_ASSERT_MESSAGE(errorMessage, assert);
};

void ErrorFinderTest::TestGetErrorsCount() 
{
	const char* errorMessage = "ErrorFinder::GetErrorsCount: amount of errors isn't equal to real amount";
	
	ErrorFinder finder;
	
	int errorsCount = finder.GetErrorsCount();
	
	CPPUNIT_ASSERT_MESSAGE(errorMessage, errorsCount == 2);
};