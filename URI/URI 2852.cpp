#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string palavra;

bool consoante()
{
	if(palavra[0] == 'a' || palavra[0] == 'e' || palavra[0] == 'i' || palavra[0] == 'o' || palavra[0] == 'u') return false;

	return true;
}

int main()
{
	string chave;

	cin >> chave;
	
	int n;
	
	scanf("%d%*c",&n);

	char c;
	int j = 0;
	while(cin >> palavra)
	{
		scanf("%c",&c);

		if(consoante())
		{
			int tam = palavra.size();
			int ch = chave.size();

			for(int i=0;i<tam;i++)
			{
				char at = chave[(j%ch)];
				int dif = palavra[i] - 'a';
				unsigned char resp = at + dif;
				int dif2 = 0;

				if(resp > 'z') 
				{
					dif2 = resp - 'z';
					resp = 'a' + dif2 - 1;
				}
				
				cout << resp;
	
				j++;
			}
		}
		else cout << palavra;

		printf("%c",c);

		if(c == '\n') j = 0;
	}

	return 0;
}
