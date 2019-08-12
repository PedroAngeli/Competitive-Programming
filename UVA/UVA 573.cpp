#include <cstdio>



int main()
{
	int h,d;
	float u,f;
	

	while(scanf("%d %f %d %f",&h,&u,&d,&f) == 4 && h)
	{
		int dia = 1;
		float escalado = 0;
		float climb = u;
		float decaimento = u*(f/100);
		
		while(true)
		{
			escalado += climb;
			climb = climb - decaimento;
			if(climb < 0) climb=0;
			 if(escalado > h) 
			{
				printf("success on day %d\n",dia);
				break;
			}

			escalado-=d;

			if(escalado < 0)
			{
				printf("failure on day %d\n",dia);
				break;
			}
			dia++;
		}

		
	}


	return 0;
}
