#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int StringToInt(string input)
{
	int num=0;
	int mult = 1;

	for(int i=input.size()-1;i>=0;i--)
	{
		num+=(input[i]-'0')*mult;
		mult*=10;
	}

	return num;
	
}

int main()
{
	int n;
	int teste = 0;
	scanf("%d%*c%*c",&n);

	while(n--)
	{
		string input;
		vector <int> p;

		if(teste) cout << endl;
		teste++;

		while(cin >> input)
		{
			char c;
			scanf("%c",&c);

			int num = StringToInt(input);
			//printf("%d\n",num);
			p.push_back(num);

			if(c == '\n') break;
		}

		int tam = p.size();
		//printf("%d\n",tam);
		vector <string> vet;
		
		for(int i=0;i<=tam;i++) vet.push_back(" ");

		int j = 0;

		while(cin >> input)
		{
			char c;
			scanf("%c",&c);

			vet[p[j++]] = input;

			if(c == '\n') break;
		}

		scanf("%*c");

		for(int i=1;i<=tam;i++)
		 	cout << vet[i] << endl;

	}

	return 0;
}
