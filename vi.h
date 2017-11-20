#ifndef VI_H
#define VI_H

#include "types.h"



using namespace namespace_MDP;


 MDP loadNet(string name_file)
{
    
    string cmd = "grep -o -c action " + name_file + " > n_actions.info";
    system(cmd.c_str());

    ifstream ac("n_actions.info");


    MDP mdp;
    fstream file(name_file.c_str());
    
    string keyword;
    state s;
    action a;
    cost c;
    probability p;
    
        
    vector<state> S;
    vector <action> A;
    TransitionF T;
    CostF C;
    RewardF R;
    App Ap;
    Sucessors Suc;



    map<action, cost> implicitC;
    
    
    //read 'state' keyword
    file>>keyword;
    
    while(true)
    {
        file>>s;
        

       // //cout<<s<<endl;
        if(s=="endstates")
            break;

        if(s[s.size()-1]==',')
        {
        	S.push_back(s.substr(0,s.size()-1));
        }else{
        	S.push_back(s);
        }
    }
    
    //HERE! SET DEPEND NUMBER OF ACTIONS OF PROBLEMS!!!!!!!<<<<<<<<<<
    // 4 for NAVIGATION
    // 5 for TRIANGLE




    int acts;

    ac>>acts;
    acts = acts/2;
    
    for(int i=0; i<acts ;i++)
    {
        //read 'action' keyword
        file>>keyword;
        file>>a;
        state s1,s2;
        A.push_back(a);
        ////cout<<"   "<<a<<endl;
        while(true)
        {
            file>>s1;
            
            if(s1=="endaction")
                break;
            
            
            file>>s2;
            file>>p;
            
            T[make_tuple(s1,a,s2)] = p;
            if ( find(Ap[s1].begin(), Ap[s1].end(), a) == Ap[s1].end())
            {
            	Ap[s1].push_back(a);
            }

            if ( find(Suc[make_tuple(s1, a)].begin(), Suc[make_tuple(s1, a)].end(), s) == Suc[make_tuple(s1, a)].end())
            {
            	Suc[make_tuple(s1, a)].push_back(s2);
            }

            C[make_tuple(s1,a)] = 1;
            	
            ////cout<<s1<<" "<<s2<<" "<<p<<endl;
            
            
        }
    }
    
    //read 'reward' keyward
    file>>keyword;


    
    while(true)
    {

    	file>>s;

    	if(s=="endreward")
            break;

        double r;
        file>>r;

        R[s] = r;

    }


    //read 'cost' keyword

    file>>keyword;
    ////cout<<keyword<<endl;
    
    while(true)
    {
    	action a;
        file>>a;
            
        if(a=="endcost")
            break;
           
        file>>c;

        

        implicitC[a] = c;
        ////cout<<s<<" "<<a<<" "<<c<<endl;
    }
    
   
    
    double diFactor;
    file>>keyword>>keyword>>diFactor;
    //cout<<diFactor<<endl;
    
    state s0;
    file>>keyword>>s0>>keyword;
    //cout<<s0<<endl;
    
    state sg;
    file>>keyword>>sg>>keyword;
    //cout<<sg<<endl;



    for(auto a:A)
    {
    	C[make_tuple(sg,a)]= 0;
    }

    
    mdp = forward_as_tuple(S,A,T,C, Ap, Suc, R, s0, sg, diFactor);
    
    return mdp;
}



tuple<cost,action> min_cost(state s, App& Ap,CostF& C, TransitionF& T, ValueF& V, Sucessors& Suc, dFactor dF){

	vector<cost> possV;
	vector<action> ac;
	for (auto a:Ap[s]){

		//cout<<"action > "<<a<<endl;
		cost c = C[make_tuple(s, a)];
		double soma = 0;
		for (auto s1:Suc[make_tuple(s, a)]){
			soma += T[make_tuple(s, a, s1)] * V[s1];

		}

		possV.push_back(c + dF* soma);
		ac.push_back(a);
	}

	cost minV = possV[0];
	action bestA;

	for (int i=0; i<possV.size(); i++)
	{
		if (possV[i] <= minV) 
		{
			minV = possV[i];
			bestA = ac[i];
		}
	}

	//cout<<"MinV "<<minV<<" "<<bestA<<endl;

	return make_tuple(minV,bestA);
}

tuple<ValueF,Policy> valueIteration(MDP& mdp, treshold t)
{

	Policy P;
	vector<state> S = get<0>(mdp);
	auto A = get<1>(mdp);
	auto T = get<2>(mdp);
	auto C = get<3>(mdp);
	auto Ap = get<4>(mdp);
	Sucessors Su = get<5>(mdp);
	dFactor dF = get<9>(mdp);

	ValueF lastV;
	ValueF V;
	BellmanResidual B;

 
	for (state s: S){
		V[s] = 0;
	}

	int counter = 0;

	while(true){

		lastV = V;
		//cout<<counter<<endl;

		error bellman_error = 0;

		for (state s:S){
			cost oldV = V[s];
			auto v_a = min_cost(s, Ap, C, T, lastV, Su, dF );

			V[s] = get<0>(v_a);
			P[s] = get<1>(v_a);

			B[s] = abs(V[s] - oldV);
			bellman_error = max(bellman_error, B[s]);

		}
		//cout<<"bellman error: "<<bellman_error<<endl;

		/*
		for(auto s:S)
			cout<<setw(15)<<s<<" ";
		cout<<endl;

		for(auto s:S)
			cout<<setw(15)<<setprecision(3)<<V[s]<<" ";
		cout<<endl;
		*/

		if (bellman_error<=t){

			break;
		}

		counter++;

	}

	//cout<<"it "<<counter<<endl;
	return make_tuple(V,P);

}


#endif 