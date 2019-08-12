#include <cstdio>
#include <cstring>

bool visitado[30][30];
int pixels[30][30];

int tem,n;

void solve(int lin,int col)
{
	if(!visitado[lin][col])
	{
		visitado[lin][col] = true;
		
		if(pixels[lin][col] == 0) return;
		else
		{
			tem++;

			if(lin - 1 >= 0) solve(lin-1,col);
			if(lin - 1 >= 0 && col - 1 >= 0) solve(lin-1,col-1);
			if(lin - 1 >= 0 && col +1 < n) solve(lin-1,col+1);
			if(col + 1 < n) solve(lin,col+1);
			if(col + 1 < n && lin + 1 < n) solve(lin + 1, col + 1);
			if(lin + 1 < n) solve(lin + 1,col);
			if(lin + 1 < n && col - 1 >=0) solve(lin + 1,col - 1);
			if(col - 1 >= 0) solve(lin,col-1);
		}
	}
}

int main()
{
	int image = 0;

	while(scanf("%d",&n) == 1)
	{
		memset(visitado,0,30*30*sizeof(bool));
		memset(pixels,0,30*30*sizeof(bool));
		int eagle = 0;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%01d",&pixels[i][j]);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				tem = 0;
				solve(i,j);
				if(tem) eagle++;
			}

		printf("Image number %d contains %d war eagles.\n",++image,eagle);
	}


	return 0;
}
