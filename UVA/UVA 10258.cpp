#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;


typedef struct
{
	int penalidade;
	int problems;
	int id;
	int time;
	bitset <10> bit;
	bitset <10> errou;

}Competidor;

Competidor competidores[101];

bool cmp(Competidor a,Competidor b)
{
	int tempoa = a.time + a.penalidade;
	int tempob = b.penalidade + b.time;

	return (a.problems > b.problems) 
		|| (a.problems == b.problems && tempoa < tempob) 
		|| (a.problems == b.problems && tempoa == tempob && a.id < b.id);     	
}

void ZeraCompetidor()
{
	for(int i=0;i<101;i++)
	{
		competidores[i].id = 0;
		competidores[i].problems = 0;
		competidores[i].time = 0;
		competidores[i].penalidade = 0;
		competidores[i].bit = 0;
	}
}

int main()
{
	int n;

	scanf("%d%*c%*c",&n);

	int teste = 0;

	char linha[50];

	while(n--)
	{
		ZeraCompetidor();

		if(teste) printf("\n");
		teste++;
		
		while(scanf("%[^\n]%*c",linha) == 1)
		{
			int id, problem, time;
			char op;

			
			if(sscanf(linha,"%d %d %d %c",&id,&problem,&time,&op)!= 4) break;

			competidores[id].id = id;

			if(competidores[id].bit[problem] == 0 && op == 'C')
			{
				competidores[id].bit[problem] = 1;
				if(competidores[id].errou[problem]) competidores[id].penalidade+=20;
				competidores[id].time+=time;
				competidores[id].problems++;
			}

			if (competidores[id].bit[problem] == 0 && op == 'I')
					competidores[id].errou[problem] = 1;
		}

		scanf("%*c");
		sort(competidores,competidores+101,cmp);
		
		for(int i=0;i<101;i++)
			if(competidores[i].id) printf("%d %d %d\n",competidores[i].id,competidores[i].problems,competidores[i].time + competidores[i].penalidade);


	}
		

	
	

	return 0;
}
