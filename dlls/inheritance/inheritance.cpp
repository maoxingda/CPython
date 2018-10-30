// inheritance.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <typeinfo>
#include <boost/python.hpp>


using namespace boost::python;


class Base
{
public:
	virtual ~Base() {printf("%s\n", __FUNCTION__);}
};

class Derived : public Base
{
public:
	~Derived() {printf("%s\n", __FUNCTION__);}
};

void b(Base*){};
void d(Derived*){};
Base* factory() { return new Derived; }

BOOST_PYTHON_MODULE(inheritance)
{
	class_<Base>(typeid(Base).name() + 6);
	class_< Derived, bases<Base> >(typeid(Derived).name() + 6);
	def("b", b);
	def("d", d);
	def("factory", factory,
		return_value_policy<manage_new_object>());
}
