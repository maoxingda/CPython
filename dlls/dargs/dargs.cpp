// dargs.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <typeinfo>
#include <boost/python.hpp>


using namespace boost::python;

int f(int a = 0)
{
	return a;
}
//
//char f(char a = 'x', char b = 'y')
//{
//	return a;
//}

class george
{
public:
	void wack_em(int a, int b = 0, char c = 'x')
	{
		printf("%d, %d, %c\n", a, b, c);
	}
};

BOOST_PYTHON_FUNCTION_OVERLOADS(f_overloads, f, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(george_overloads, wack_em, 1, 3)

BOOST_PYTHON_MODULE(dargs)
{
	def("f", f, f_overloads());

	class_<george>(typeid(george).name() + 6)
		.def("wack_em", &george::wack_em, george_overloads())
		;
}
