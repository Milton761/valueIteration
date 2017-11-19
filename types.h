#ifndef TYPES_H
#define TYPES_H


#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>
#include <stack>


using namespace std;


namespace namespace_MDP
{

    typedef string state;
    typedef string action;
    typedef double cost;
    typedef double probability;
    typedef double error;
    typedef double treshold; 
    typedef double dFactor;

    
    typedef map<state, probability> BellmanResidual;
    typedef map<state, cost> ValueF;
    typedef map<state, action> Policy;

    typedef map<state, vector<action> > App;

    typedef map<tuple<state,action>, cost> CostF;
    typedef map<tuple<state, action, state>, probability> TransitionF;
    typedef map<tuple<state, action>, vector<state>> Sucessors;

    typedef map<state, double> RewardF;


    typedef tuple< vector<state>, vector<action>, TransitionF, CostF, App, Sucessors, RewardF, state, state, dFactor > MDP;

}



#endif