// pyebd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <boost/python.hpp>


using namespace boost::python;

int _tmain(int argc, _TCHAR* argv[])
{
	Py_Initialize();

	object mmod = import("__main__");
	object mnsp = mmod.attr("__dict__");

	// call python code
	object igrd = exec("hello = file('hello.txt', 'w')\n"
		"hello.write('Hello world!')\n"
		"hello.close()\n",
		mnsp
		);

	igrd = exec("import sys\n\n"
		"for bmn in sys.builtin_module_names:\n"
		"    print bmn\n",
		mnsp
		);

	try
	{
		exec_file("C:/Users/Administrator/Documents/PythonProjects/Python2/trunk/dlls/Debug/virfunctest.py", mnsp, mnsp);
	}
	catch (error_already_set const&)
	{
		PyErr_Print();
	}

	object result = eval("5 ** 2");
	int five_squared = extract<int>(result);
	std::cout << five_squared << std::endl;

	// exception handling
	try
	{
		result = eval("5/0");
	}
	catch (error_already_set const&)
	{
		PyErr_Print();
	}

	getchar();
	return 0;
}

