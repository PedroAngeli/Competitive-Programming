#include <cstdio>


int main()
{
	int a,b;

	while(scanf("%d %d",&a,&b)==2)
	{
		int maior = 0,count=1;

		for(int i=a;i<=b;i++)
		{
			while(i!=1)
			{
				if(i%2==0) i/=2;
				else i = i*3 + 1;
				count++;
			}

			if(count>maior) maior = count;
		}

		printf("%d %d %d\n",a,b,maior);
	}


	return 0;
}
