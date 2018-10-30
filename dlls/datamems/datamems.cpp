// datamems.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <typeinfo>
#include <boost/python.hpp>


using namespace boost::python;

class Var
{
public:
	Var(){}
	Var(std::string name) : name(name), value() {}
	std::string const name;
	float value;
};

BOOST_PYTHON_MODULE(datamems)
{
	class_<Var>(typeid(Var).name() + 6)
		.def(init<>())
		.def(init<std::string>())
		.def_readonly("name", &Var::name)
		.def_readwrite("value", &Var::value)
		;
}
