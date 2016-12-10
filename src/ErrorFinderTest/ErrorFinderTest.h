/*
ErorrFinderTest header file.
Includes an private array with error strings. The latter have 2 first strings with errors.
*/

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

class ErrorFinderTest : public CppUnit::TestCase
{
	public:
		void TestRegExpr();
		void TestGetErrorsCount();
		
		CPPUNIT_TEST_SUITE( ErrorFinderTest );
		CPPUNIT_TEST( TestRegExpr );
		CPPUNIT_TEST( TestGetErrorsCount );
		CPPUNIT_TEST_SUITE_END();
	private:
		const char *errors[5] = {
			"conftest.c:217: error: 'TIOCSTAT' undeclared (first use in this function)",
			"conftest.c:238: fatal error: 'struct dirent' has no member named 'd_namlen'",
			"conftest.c:217: error: (Each undeclared identifier is reported only once",
			"conftest.c:217: error: for each function it appears in.)",
			"configure: failed program was:"
		};
};