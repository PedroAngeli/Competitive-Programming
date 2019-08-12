#include "competitive.h"


void ContaXO(char tic[][4],int *x,int *o)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(tic[i][j]=='X') (*x)++;
			else if (tic[i][j]=='O') (*o)++;
		}
	}

}

int XVenceu(char tic[][4])
{
	int count=0;

	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<3;j++)
			if(tic[i][j]=='X') count++;

		if(count==3) return 1;

		count=0;
	}

	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<3;j++)
			if(tic[j][i]=='X') count++;

		if(count==3) return 1;

		count=0;
	}

	int k,l;

	for(k=0,l=0;k<3 && l<3;k++,l++) if(tic[k][l]=='X') count++;

	if(count==3) return 1;

	count=0;


	for(k=0,l=2;k<3 && l>=0;k++,l--) if(tic[k][l]=='X') count++;

	if(count==3) return 1;

	return 0;

}

int OVenceu(char tic[][4])
{
	int count=0;

	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<3;j++)
			if(tic[i][j]=='O') count++;

		if(count==3) return 1;

		count=0;
	}

	for(int i=0;i<3;i++) 
	{
		for(int j=0;j<3;j++)
			if(tic[j][i]=='O') count++;

		if(count==3) return 1;

		count=0;
	}

	int k,l;

	for(k=0,l=0;k<3 && l<3;k++,l++) if(tic[k][l]=='O') count++;

	if(count==3) return 1;

	count=0;


	for(k=0,l=2;k<3 && l>=0;k++,l--) if(tic[k][l]=='O') count++;

	if(count==3) return 1;

	return 0;
}
int main()
{
	int n;

	scanf("%d",&n);
	scanf("%*c");

	for(int i=0;i<n;i++)
	{
		char tic[4][4];
		int x=0,o=0,ganhouX,ganhouO;

		for(int j=0;j<3;j++)
		{
			scanf("%[XO.]",tic[j]);
			scanf("%*c");
		}
		
		scanf("%*c");

		ContaXO(tic,&x,&o);
		ganhouX=XVenceu(tic);
		ganhouO=OVenceu(tic);

		if(o>x) printf("no\n");
		else if(x-o>1) printf("no\n");
		else if(ganhouX && x>o && !ganhouO) printf("yes\n");
		else if(ganhouO && o==x && !ganhouX) printf("yes\n");
		else if(x>o && !ganhouO) printf("yes\n");
		else if(x==o && !ganhouX) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}
