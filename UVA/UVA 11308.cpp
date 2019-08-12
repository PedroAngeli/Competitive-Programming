#include <cstdio>
#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t,teste=0;

	scanf("%d%*c",&t);

	while(t--)
	{
		string binder;
		
		getline(cin,binder);

		//cout << binder;
		int m,n,b;

		scanf("%d %d %d%*c",&m,&n,&b);

		map <string,int> ingredients;

		while(m--)
		{
			int c;
			string ing;
		
			cin >> ing;
			//cout << ing << '\n';
			scanf("%d%*c",&c);

			ingredients[ing] = c;
		}
		
		vector < pair <int,string> > vet;

		while(n--)
		{
			string recipe;
			int k;

			getline(cin,recipe);

			//cout << recipe << '\n';
			scanf("%d%*c",&k);
	
			long long soma = 0;

			while(k--)
			{
				int c;
				string ing;

				cin >> ing;
				scanf("%d%*c",&c);

				soma+=(c*ingredients[ing]);
			}
	
			if(soma <= b)
			{
				pair <int,string> par(soma,recipe);
				vet.push_back(par);
			}
		}
	
		transform(binder.begin(), binder.end(), binder.begin(), ::toupper);
		cout << binder << "\n";

		if(vet.size() == 0) printf("Too expensive!\n");
		else 
		{
			sort(vet.begin(),vet.end());
			for(int i=0;i<vet.size();i++)
				cout << vet[i].second << "\n";
		}

		printf("\n");
	}	


	return 0;
}
