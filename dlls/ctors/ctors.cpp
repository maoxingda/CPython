// ctors.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <typeinfo>
#include <boost/python.hpp>


using namespace boost::python;

class World
{
public:
	// ctors
	World()
	{
	}

	World(int val)
	{
	}

	World(float val)
	{
	}
};

BOOST_PYTHON_MODULE(ctors)
{
	class_<World>(typeid(World).name() + 6)
		//ctors
		.def(init<>())
		.def(init<int>())
		.def(init<float>())
		;
}