#include "vi.h"



using namespace std;


int main(int argc, char* argv[])
{
	



	string file_path = argv[1];
	error e = atof(argv[2]);



	MDP mdp = loadNet(file_path);

	



	vector<state> S = get<0>(mdp);
	auto A = get<1>(mdp);
	auto T = get<2>(mdp);
	auto C = get<3>(mdp);
	auto Ap = get<4>(mdp);
	Sucessors Su = get<5>(mdp);


	auto start = std::chrono::system_clock::now();
	auto v_p = valueIteration(mdp, e);
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    cout<<file_path<<" "<<elapsed_seconds.count()<<endl;


	auto V = get<0>(v_p);
	auto P = get<1>(v_p);

/*
	cout<<"Policy"<<endl;
	cout<<"++++++++++++++++++++++++++++"<<endl;
	for(auto s: S)
	{
		cout<<s<<" -> "<<P[s]<<endl;
	} 
*/
	return 0;
}