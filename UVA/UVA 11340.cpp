#include <map>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;



int main()
{
	int n;
	
	scanf("%d",&n);
	scanf("%*c");

	while(n--)
	{
		map <char,int> tabela;
		int k;
		
		scanf("%d",&k);
		scanf("%*c");

		while(k--)
		{
			char c;
			int valor;
			
			scanf("%c %d",&c,&valor);
			scanf("%*c");
			tabela[c]=valor;
		}

		int m;
		double soma=0;
		string linha;	

		scanf("%d",&m);
		scanf("%*c");
		
		while(m--)
		{
			getline(cin, linha);
			//scanf("%*c");
			
			for(int i=0;i<linha.size();i++)
				if(tabela.find(linha[i]) != tabela.end()) soma+=tabela[linha[i]];
		}
		
		printf("%.2lf$\n",soma/100);
		
		
	}
	

	return 0;
}
