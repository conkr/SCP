/*
 *  interpolate.cpp
 *  interpolate
 *
 *  Created by Run Su on 7/7/17.
 *  Copyright © 2017 run. All rights reserved.
 *
 */

#include <iostream>
#include "interpolate.hpp"
#include "interpolatePriv.hpp"

void interpolate::HelloWorld(const char * s)
{
    interpolatePriv *theObj = new interpolatePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void interpolatePriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

