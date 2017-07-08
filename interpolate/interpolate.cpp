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

void Interpolate::HelloWorld(const char * s)
{
    InterpolatePriv *theObj = new InterpolatePriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void InterpolatePriv::HelloWorldPriv(const char * s)
{
    std::cout << s << std::endl;
};
 //create equidistant grid
void Interpolate::CreateGrid_EvenlySpaced(int npts, double *x, double a, double b){
    double dx = (b-a)/(npts-1.0);
    for(int i=0;i<npts;i++)
        x[i] = a + i*dx;
    return; }
// lagrangeinterpolant
double Interpolate::LagrangeInterpolant(double x, int npts, double *xpts, double * funcvals){
    int i;
    double sum = 0.0;
    for(i=0;i<npts;i++){
        sum = sum + funcvals[i]*LagrangePoly(x,i,npts,xpts);
    }
    return sum; }
// lagrangeploy base function
double Interpolate::LagrangePoly(double x, int pt, int npts, double * xpts){
    int i;
    double h=1.0;
    for(i=0;i<pt;i++)
        h = h * (x - xpts[i])/(xpts[pt]-xpts[i]);
    for(i=pt+1;i<npts;i++)
        h = h * (x - xpts[i])/(xpts[pt]-xpts[i]);
    return h; }
