#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include<vector>
# include<string>
# include<numeric>
# include<algorithm>
# include<array>
#include <map>
# include <tuple>
#include "Netradiationequivalentevaporation.h"
using namespace std;

Netradiationequivalentevaporation::Netradiationequivalentevaporation() { }
float Netradiationequivalentevaporation::getlambdaV() {return this-> lambdaV; }
void Netradiationequivalentevaporation::setlambdaV(float _lambdaV) { this->lambdaV = _lambdaV; }
void Netradiationequivalentevaporation::Calculate_Model(EnergybalanceState& s, EnergybalanceState& s1, EnergybalanceRate& r, EnergybalanceAuxiliary& a)
{
    //- Name: NetRadiationEquivalentEvaporation -Version: 1.0, -Time step: 1
    //- Description:
    //            * Title: NetRadiationEquivalentEvaporation Model
    //            * Author: Pierre Martre
    //            * Reference: Modelling energy balance in the wheat crop model SiriusQuality2:
    //            Evapotranspiration and canopy and soil temperature calculations
    //            * Institution: INRA/LEPSE Montpellier
    //            * Abstract:  It is given by dividing net radiation by latent heat of vaporization of water 
    //- inputs:
    //            * name: lambdaV
    //                          ** description : latent heat of vaporization of water
    //                          ** parametercategory : constant
    //                          ** datatype : DOUBLE
    //                          ** default : 2.454
    //                          ** min : 0
    //                          ** max : 10
    //                          ** unit : MJ kg-1
    //                          ** uri : http://www1.clermont.inra.fr/siriusquality/?page_id=547
    //                          ** inputtype : parameter
    //            * name: netRadiation
    //                          ** description : net radiation
    //                          ** variablecategory : state
    //                          ** datatype : DOUBLE
    //                          ** default : 1.566
    //                          ** min : 0
    //                          ** max : 5000
    //                          ** unit : MJ m-2 d-1
    //                          ** uri : http://www1.clermont.inra.fr/siriusquality/?page_id=547
    //                          ** inputtype : variable
    //- outputs:
    //            * name: netRadiationEquivalentEvaporation
    //                          ** variablecategory : auxiliary
    //                          ** description : net Radiation in Equivalent Evaporation 
    //                          ** datatype : DOUBLE
    //                          ** min : 0
    //                          ** max : 5000
    //                          ** unit : g m-2 d-1
    //                          ** uri : http://www1.clermont.inra.fr/siriusquality/?page_id=547
    float netRadiation = s.getnetRadiation();
    float netRadiationEquivalentEvaporation;
    netRadiationEquivalentEvaporation = netRadiation / lambdaV * 1000.0f;
    a.setnetRadiationEquivalentEvaporation(netRadiationEquivalentEvaporation);
}