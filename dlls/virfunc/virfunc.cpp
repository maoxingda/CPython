// virfunc.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <typeinfo>
#include <boost/python.hpp>


using namespace boost::python;

class Base
{
public:
	virtual ~Base() {}
	virtual int f() = 0;
};

class BaseWrap : public Base, public wrapper<Base>
{
public:
	int f()
	{
		printf("%s\n", __FUNCTION__);
		return this->get_override("f")();
	}
};

void func(Base* b)
{
	printf("%s\n", b->f());
}

BOOST_PYTHON_MODULE(virfunc)
{
	class_<BaseWrap, boost::noncopyable>(typeid(Base).name() + 6)
		.def("f", pure_virtual(&Base::f));
	
	def("func", func);
}
