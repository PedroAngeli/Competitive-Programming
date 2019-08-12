#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 105

int mat[MAXN][MAXN];
int alt;

void FloodFill(int r,int c,int count,int tamr,int tamc)
{
	if(r - 1 >= 0 && mat[r-1][c] < mat[r][c]) FloodFill(r-1,c,count+1,tamr,tamc);
	
	if(r + 1 < tamr && mat[r+1][c] < mat[r][c]) FloodFill(r+1,c,count+1,tamr,tamc);

	if(c + 1 < tamc && mat[r][c+1] < mat[r][c]) FloodFill(r,c + 1,count+1,tamr,tamc);

	if(c - 1 >= 0 && mat[r][c-1] < mat[r][c]) FloodFill(r,c - 1,count+1,tamr,tamc);

	if(count > alt) alt = count;
}

int main()
{
	int n;

	scanf("%d",&n);

	while(n--)
	{
		string nome;
		cin >> nome;
		int r,c;
		scanf("%d %d",&r,&c);
		
		alt = 0;
		int maior = 0;
		int x,y;

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				int temp;
				scanf("%d",&temp), mat[i][j]=temp;
				if(temp > maior)
				{
					maior = temp;
					x = i,y = j;
				}
			}

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				FloodFill(i,j,1,r,c);
	
		cout << nome + ": " << alt << endl;

	}

	return 0;
}
