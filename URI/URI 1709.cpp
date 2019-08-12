#include <cstdio>


int main()
{
	int n;
	scanf("%d",&n);
	int pos = 2;
	int resp = 1;

	while(pos != 1)
	{
		if(pos <= n/2) pos = 2*pos;
		else pos = 2*pos - 1 - n;
		resp++;
	}

	printf("%d\n",resp);

	return 0;
}
