/*
 *  interpolate.hpp
 *  interpolate
 *
 *  Created by Run Su on 7/7/17.
 *  Copyright © 2017 run. All rights reserved.
 *
 */


#ifndef interpolate_
#define interpolate_

/* The classes below are exported */
#pragma GCC visibility push(default)

class Interpolate
{
    public:
    void HelloWorld(const char *);
    void CreateGrid_EvenlySpaced(int npts, double *x, double a, double b);
    double LagrangePoly(double x, int pt, int npts, double * xpts);
    double LagrangeInterpolant(double x, int npts, double *xpts, double * funcvals);
};
    
#pragma GCC visibility pop
#endif
