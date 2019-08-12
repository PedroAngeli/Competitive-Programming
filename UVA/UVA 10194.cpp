#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	int pontos;
	int vitoria,empate,derrota;	
	int jogos;
	int golpro,golcontra;
	string nome;
}Team;

string Maiscula(string a)
{
	for(int i=0;i<a.size();i++)
	 	if(a[i] >= 'a' && a[i] <='z')
			a[i]-=32;

	return a;
}
bool cmp(Team a,Team b)
{
	string nomea = Maiscula(a.nome), nomeb = Maiscula(b.nome);
	int difa = a.golpro - a.golcontra;
	int difb = b.golpro - b.golcontra;

	return (a.pontos > b.pontos) || 
	(a.pontos == b.pontos && a.vitoria > b.vitoria) ||
	(a.pontos == b.pontos && a.vitoria == b.vitoria && difa > difb) ||
	(a.pontos == b.pontos && a.vitoria == b.vitoria && difa == difb && a.golpro > b.golpro) ||
	(a.pontos == b.pontos && a.vitoria == b.vitoria && difa == difb && a.golpro == b.golpro && a.jogos < b.jogos) ||
	(a.pontos == b.pontos && a.vitoria == b.vitoria && difa == difb && a.jogos == b.jogos && nomea < nomeb);
}

int main()
{
	int n;

	scanf("%d%*c",&n);
	int teste = 0;

	while(n--)
	{
		if(teste) cout << endl;
		teste ++;
		string nameTour;
		
		getline(cin,nameTour);
		
		int t;

		scanf("%d%*c",&t);

		string team;
		map <string,Team> times;

		for(int i=0;i<t;i++)
		{
			Team time ={0,0,0,0,0,0,0};
			getline(cin,team);
			time.nome = team;
			times[team] = time;
		}
		
		int g;

		scanf("%d%*c",&g);
			
		while(g--)
		{
			char time1[40],time2[40];
			string timea,timeb;
			int gol1,gol2;

			scanf("%[^#]%*c%d%*c%d%*c%[^\n]%*c",time1,&gol1,&gol2,time2);

			timea = time1, timeb=time2;

			times[timea].jogos++;
			times[timeb].jogos++;
			times[timea].golpro+=gol1;
			times[timea].golcontra+=gol2;
			times[timeb].golpro+=gol2;
			times[timeb].golcontra+=gol1;

			if(gol1>gol2)
			{
				times[timea].pontos+=3;
				times[timea].vitoria++;
				times[timeb].derrota++;
			}
			else if(gol1<gol2)
			{
				times[timeb].pontos+=3;
				times[timeb].vitoria++;
				times[timea].derrota++;
			}
			else
			{
				times[timea].empate++;
				times[timeb].empate++;
				times[timea].pontos++;
				times[timeb].pontos++;
			}
		}

		vector <Team> vet;
		map <string,Team> :: iterator it;

		for(it = times.begin();it!=times.end();it++)
			vet.push_back(it->second);

		sort(vet.begin(),vet.end(),cmp);

		cout << nameTour << endl;

		for(int i=0;i<vet.size();i++)
		{
			printf("%d) ",i+1);
			cout << vet[i].nome + " ";
			printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",vet[i].pontos,vet[i].jogos,vet[i].vitoria,vet[i].empate,vet[i].derrota,vet[i].golpro - vet[i].golcontra,vet[i].golpro,vet[i].golcontra);
		}
	
	}

	return 0;
}
