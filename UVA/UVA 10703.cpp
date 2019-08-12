#include <cstdio>


int main()
{
	int w,h,n;


	while(scanf("%d %d %d",&w,&h,&n) == 3 && w && h)
	{
		int x1,x2,y1,y2;
		bool board[h+10][w+10];

		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				board[i][j]=0;

		//printf("cu\n");
		while(n--)	
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			
			int maiorx = x1 > x2 ? x1:x2;
			int menorx = x1 < x2 ? x1:x2;

			int maiory = y1 > y2 ? y1:y2;
			int menory = y1 < y2 ? y1:y2;

			//printf("%d %d\n",menorx,maiorx);

			for(int i=menory;i<=maiory;i++)
				for(int j=menorx;j<=maiorx;j++)
					board[i][j]=1;
		}

		int count = 0;

		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				if(board[i][j] == 0) count++;


		//printf("%d\n",count);

		if(count == 0) printf("There is no empty spots.\n");
		else if(count == 1) printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n",count);
	}

	//printf("\n");

	return 0;
}	
