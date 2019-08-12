#include <cstdio>



int main()
{

	int k;

	while(scanf("%d",&k) == 1 && k)
	{
		int n,m;
	
		scanf("%d %d",&n,&m);
		
		for(int i=0;i<k;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);

			if(x == n || y == m) printf("divisa\n");
			else if(x > n && y > m) printf("NE\n");
			else if(x < n && y < m) printf("SO\n");
			else if(x > n && y < m) printf("SE\n");
			else printf("NO\n");
		}
	}

	return 0;
}
