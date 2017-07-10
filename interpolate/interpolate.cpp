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
}

void InterpolatePriv::HelloWorldPriv(const char * s)
{
    std::cout << s << std::endl;
}
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
double Interpolate::NewtonDiffFunction(int start_index, int ending_index, double * xpts, double * funcvals){
    double val;
    int diff = ending_index-start_index;
    if(diff == 0){
        val = funcvals[start_index];
    } else{
        val = (NewtonDiffFunction(start_index,ending_index-1, xpts,funcvals) -
               NewtonDiffFunction(start_index+1,ending_index, xpts,funcvals))/
        (xpts[start_index]-xpts[ending_index]);
    }
    return val; }
void Interpolate::NewtonDiffTable(int npts, double *xpts, double *funcvals, double * newton_coeffs){
    int i;
    for(i=0;i<npts;i++)
        newton_coeffs[i] = NewtonDiffFunction(0,i, xpts, funcvals); }
double Interpolate::NewtonInterpolant(double x, int npts, double * xpts, double * newton_coeffs){
    int i,j;
    double sum = 0.0, xval;
    for(i=0;i<npts;i++){
        xval = 1.0;
        for(j=0;j<i;j++)
            xval = xval*(x-xpts[j]);
        sum = sum + newton_coeffs[i]*xval;
    }
    return sum; }
