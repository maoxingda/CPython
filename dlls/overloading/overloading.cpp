// overloading.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <boost/python.hpp>


using namespace boost::python;

bool f(int a)
{
	printf("%s\n", __FUNCSIG__);
	return true;
}

bool f(int a, double b)
{
	printf("%s\n", __FUNCSIG__);
	return true;
}

bool f(int a, double b, char c)
{
	printf("%s\n", __FUNCSIG__);
	return true;
}

int f(int a, int b, int c)
{
	printf("%s\n", __FUNCSIG__);
	return a + b + c;
};

bool    (*fx1)(int)              = &f;
bool    (*fx2)(int, double)      = &f;
bool    (*fx3)(int, double, char)= &f;
int     (*fx4)(int, int, int)    = &f;

BOOST_PYTHON_MODULE(overloading)
{
	def("f", fx1);
	def("f", fx2);
	def("f", fx3);
	def("f", fx4);
}
