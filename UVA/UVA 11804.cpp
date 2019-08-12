#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef struct
{
	string nome;
	int atk,def;
}Jogador;

bool melhorordem(Jogador a,Jogador b)
{
	return (a.atk > b.atk) ||
		   (a.atk == b.atk && a.def < b.def) ||
		   (a.atk == b.atk && a.def == b.def && a.nome < b.nome);
}

bool alfa(Jogador a,Jogador b)
{
	return a.nome < b.nome;
}

int main()
{
	int t;
	scanf("%d",&t);
	int teste = 1;
	
	while(t--)
	{
		vector <Jogador> jog;
		Jogador jogador;

		printf("Case %d:\n(",teste++);

		for(int i=0;i<10;i++)
			cin >> jogador.nome >> jogador.atk >> jogador.def , jog.push_back(jogador);

		sort(jog.begin(),jog.end(),melhorordem);
		sort(jog.begin(),jog.begin() + 5,alfa);
		sort(jog.begin() + 5,jog.end(),alfa);

		for(int i=0;i<5;i++)
		{
			if(i!=4) cout << jog[i].nome << ", ";
			else cout << jog[i].nome << ")\n(";
		}

		for(int i=5;i<10;i++)
		{
			if(i!=9) cout << jog[i].nome << ", ";
			else cout << jog[i].nome << ")\n";
		}

		

		
			
	}


	return 0;
}
