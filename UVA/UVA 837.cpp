#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct 
{
	double x,y;
}Ponto;

typedef struct
{
	Ponto a,b;
	double r;
}Reta;

vector <Ponto> pontos;
vector <Reta> retas;


bool cmp(Ponto a,Ponto b)
{
	return a.x < b.x;
}
int main()
{
	int t;
	int aux =1;

	scanf("%d",&t);

	while(t--)
	{
		
		if(!aux) printf("\n");

		aux = 0;

		int nl;

		scanf("%d",&nl);

		while(nl--)
		{
			Ponto a,b;
			Reta r;

			scanf("%lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&r.r);

			pontos.push_back(a);
			pontos.push_back(b);

			Ponto maior = a.x > b.x? a:b;
			Ponto menor = a.x < b.x? a:b;
	
			r.a = menor;
			r.b = maior;

			retas.push_back(r);
		}

		sort(pontos.begin(),pontos.end(),cmp);

		
		printf("%lu\n",pontos.size()+1);

		printf("-inf %.3lf 1.000\n",pontos[0].x);

		for(int i=0;i<pontos.size()-1;i++)
		{
			double ab = pontos[i].x, fe = pontos[i+1].x;
			double factor = 1;

			for(int j=0;j<retas.size();j++)
			{
				Ponto a = retas[j].a;
				Ponto b = retas[j].b;
				double r = retas[j].r;
				
				if(ab >= a.x && fe <= b.x) 
				{
				factor*=r;
				//printf("AAAA: %lf BBBBB: %lf\n",a.x,b.x);
				}
			}

			printf("%.3lf %.3lf %.3lf\n", ab,fe, factor);
		}	

		printf("%.3lf +inf 1.000\n",pontos[pontos.size()-1].x);
		retas.clear();
		pontos.clear();
	}


	return 0;
}
