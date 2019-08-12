#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;


int main()
{
	int n;

	scanf("%d%*c%*c",&n);
	
	int teste = 0;

	while(n--)
	{
		map <string,double> trees;

		string tree;
		int count = 0;

		if(teste) cout << endl;
		teste++;

		while(getline(cin,tree))
		{
			if(tree == "") break;

			count++;

			if(trees.find(tree) != trees.end()) trees[tree]++;
			else trees[tree] = 1;

		}

		map <string,double> :: iterator it;
		
		for(it = trees.begin();it!=trees.end();it++)
		{
			double porcentagem = (it->second/count) * 100;

			cout << it->first + " ";
			printf("%.4lf\n",porcentagem);
		}

		
	}
	return 0;
}
