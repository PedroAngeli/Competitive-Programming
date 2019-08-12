#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

bool cmp(pair <int,string> a, pair <int,string> b)
{
	return a.first < b.first;
}
int main()
{

	int M;

	scanf("%d%*c%*c",&M);

	int teste = 0;
	while(M--)
	{
		int n,m;

		scanf("%d %d%*c",&n,&m);

		vector < pair <int,string> > vet;

		if(teste) cout << endl;
		teste++;

		while(m--)
		{
			string dna;
			cin >> dna;

			int soma = 0;

			for(int i=0;i<n-1;i++)
			{
				char atual = dna[i];

				for(int j=i+1;j<n;j++)
				{
					if(atual > dna[j]) soma++;
				}
			}

			pair <int,string> par;

			//printf("%d\n",soma);

			par.first = soma;
			par.second = dna;

			vet.push_back(par);
		}

		stable_sort(vet.begin(),vet.end(),cmp);

		for(int i=0;i<vet.size();i++)
			cout << vet[i].second << endl;

			

		//scanf("%*c%*c");
		
	}

	return 0;
}
