// virfunc.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <typeinfo>
#include <boost/python.hpp>


using namespace boost::python;

class Base
{
public:
	virtual ~Base()
	{
		printf("%s\n", __FUNCTION__);
	}

	virtual int f()
	{
		printf("%s\n", __FUNCTION__);
		return 123;
	}
};

class BaseWrap : public Base, public wrapper<Base>
{
public:
	int f()
	{
		printf("%s\n", __FUNCTION__);
		if (override f = this->get_override("f"))
		{
			printf("%s override\n", __FUNCTION__);
			return f();
		}
		else
		{
			printf("%s not override\n", __FUNCTION__);
			return Base::f();
		}
	}

	int f_default()
	{
		printf("%s\n", __FUNCTION__);
		return this->Base::f();
	}
};

void calls_f(Base& b)
{
	printf("%s\n", __FUNCTION__);
	printf("%d\n", b.f());
}

BOOST_PYTHON_MODULE(virfunc)
{
	def("calls_f", calls_f);

	class_<BaseWrap, boost::noncopyable>(typeid(Base).name() + 6)
		.def("f", &Base::f, &BaseWrap::f_default);
}
