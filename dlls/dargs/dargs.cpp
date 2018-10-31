// dargs.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <boost/python.hpp>


using namespace boost::python;

int f(int a = 0)
{
	return a;
}

BOOST_PYTHON_FUNCTION_OVERLOADS(f_overloads, f, 0, 1)

BOOST_PYTHON_MODULE(dargs)
{
	def("f", f, f_overloads());
}
