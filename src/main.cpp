#include <cstdlib>
#include <iostream>		// I/O Stream Library
#include "stdio.h"
#include <pcrecpp.h>	// PCRE library
#include <cstring>		// std::string
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ErrorFinder/ErrorFinder.h"
#include "ErrorFinderTest/ErrorFinderTest.h"
#include <ctype.h>

using namespace std;

int main(int argc, char* argv[]) {

	CPPUNIT_TEST_SUITE_REGISTRATION( ErrorFinderTest );
	
	if ( argc >= 2 )
	{
		if ( (strcmp(argv[1], "-t\n") == 0) || (strcmp(argv[1], "--test\n") == 0) ) 
		{
			CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
			CppUnit::TextTestRunner runner;
			runner.addTest(test);
			
			runner.run();
			
			exit(0);
		}
	}
	
	ErrorFinder finder;
	
	std::cout << finder.GetErrorsCount() << std::endl;
}