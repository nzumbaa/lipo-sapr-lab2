#include <cstdlib>
#include <iostream>		// I/O Stream Library
#include "stdio.h"
#include <string>
#include <pcrecpp.h>	// PCRE library
#include <sstream>		// std::stringstream
#include <algorithm>    // std::find
#include <iterator>		// std::vector::iterator
#include <vector>		// std::vector
#include "ErrorFinder.h"

using namespace std;

ErrorFinder::ErrorFinder()
{
	mainRegexp = "^.*:\\d+:(\\d+:)?\\s(fatal\\s)?error:\\s(.+)$";
}

int ErrorFinder::GetErrorsCount()
{
	string input;
	string errorPartString;
	string nullArg;
	pcrecpp::RE mainPattern(mainRegexp);
	
	vector<string>array;
	vector<string>::iterator arrayIterator;
	
	while ( !cin.eof() )
	{
		input += cin.get();
		if ( input.find("\n") != -1 )
		{
			pcrecpp::StringPiece piece(input);
			
			if ( (mainPattern.Consume(&piece, &nullArg, &nullArg, &errorPartString)) && 
				( errorPartString != ErrorFinder::noteStart ) &&
				( errorPartString != ErrorFinder::noteEnd )
			)
			{
				array.push_back(input);
			}
			input = "";
			errorPartString = "";
			std::cin.clear();
		}
	}
	
	return array.size();
}