// props.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <typeinfo>
#include <boost/python.hpp>


using namespace boost::python;

class Num
{
public:
	Num()
		: rovalue(3.14)
	{
	}
	float getRW() const{return rwvalue;}
	void setRW(float value){rwvalue=value;}
	float getRO() const{return rovalue;}
	void setRO(float value){rovalue=value;}

private:
	float rwvalue;
	float rovalue;
};

BOOST_PYTHON_MODULE(props)
{
	class_<Num>(typeid(Num).name() + 6)
		.def(init<>())
		.add_property("rovalue", &Num::getRO)
		.add_property("rwvalue", &Num::getRW, &Num::setRW)
		;
}
