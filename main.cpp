#include "vi.h"



using namespace std;


int main()
{
	

	MDP mdp = loadNet("navigation01.net");


	vector<state> S = get<0>(mdp);
	auto A = get<1>(mdp);
	auto T = get<2>(mdp);
	auto C = get<3>(mdp);
	auto Ap = get<4>(mdp);
	Sucessors Su = get<5>(mdp);



	auto v_p = valueIteration(mdp, 0.00);


	auto V = get<0>(v_p);
	auto P = get<1>(v_p);

	cout<<"Policy"<<endl;
	cout<<"++++++++++++++++++++++++++++"<<endl;
	for(auto s: S)
	{
		cout<<s<<" -> "<<P[s]<<endl;
	} 

	return 0;
}