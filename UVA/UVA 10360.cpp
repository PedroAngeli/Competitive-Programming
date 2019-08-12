#include <cstdio>

int killed[1025][1025];

int main()
{
	int cenario;
	scanf("%d",&cenario);

	while(cenario--)
	{
		for(int i=0;i<1025;i++)
			for(int j=0;j<1025;j++)
				killed[i][j]=0;

		int d;
		scanf("%d",&d);
		int n;
		scanf("%d",&n);

		while(n--)
		{
			int x,y,pop;
			scanf("%d %d %d",&x,&y,&pop);
			int vert=x-d,hor=y-d;

			if(vert<0) vert=0;
			if(hor<0) hor=0;
		
			int alcv=((2*d)+vert),alch=((2*d)+hor);

			if(alcv>1024) alcv=1024;
			if(alch>1024) alch=1024;

			for(int i=vert;i<=alcv;i++)
				for(int j=hor;j<=alch;j++)
					killed[i][j]+=pop;
		}

		int maior=0;
		int posx=0,posy=0;
		

		for(int i=0;i<1025;i++)
		{
			for(int j=0;j<1025;j++)
			{
				//printf("%d ",killed[i][j]);
				if(killed[i][j]>maior)
				{
					maior=killed[i][j];
					posx=i;
					posy=j;
					
				}
			}
			//printf("\n");
		}

			printf("%d %d %d\n",posx,posy,maior);
	}


	return 0;
}
