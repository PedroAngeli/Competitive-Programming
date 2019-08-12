#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
	int r,o,y,g,b;
}Lixo;

int main()
{
	string linha;
	bool flag = true;

	while(flag)
	{
		vector <Lixo> lixo;

		while(cin >> linha)
		{
			if(linha[0] == 'e') break;
			if(linha[0] == '#')	
			{
					flag = false;
					 break;
			}
		
			Lixo l;

			for(int i = 0;i<linha.size();i+=4)
			{
				int c = linha[i+2] - 'A';

				if(linha[i] == 'r') l.r = c;
				else if(linha[i] == 'o') l.o = c;
				else if(linha[i] == 'y') l.y = c;
				else if(linha[i] == 'g') l.g = c;
				else if(linha[i] == 'b') l.b = c;
			
				
			}

			lixo.push_back(l);
		}

		if(flag == false) break;

		int menor = 999999999,idx;

		for(int i = 0;i < lixo.size();i++)
		{
			int soma = 0;

			for(int j=0;j < lixo.size();j++)
			{
				Lixo l1 = lixo[i],l2 = lixo[j];

				if(l1.r != l2.r) soma++;
				if(l1.o != l2.o) soma++;
				if(l1.y != l2.y) soma++;
				if(l1.g != l2.g) soma++;
				if(l1.b != l2.b) soma++;
			}

			if(soma < menor) menor = soma, idx = i+1;
		}

		printf("%d\n",idx);
	}

	return 0;
}
