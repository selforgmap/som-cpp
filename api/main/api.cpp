//
// Created by Sumedhe Dissanayake on 11/5/18.
//

#include "api.h"


#include <boost/python.hpp>
#include "../../src/main.h"

char const* run()
{
    return "api works!";
}

BOOST_PYTHON_MODULE(api)
{

    using namespace boost::python;
    def("run", run);
}
