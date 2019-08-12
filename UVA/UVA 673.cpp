#include <cstdio>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
	int n;

	scanf("%d%*c",&n);

	while(n--)
	{
		stack <char> abre;

		string exp;		

		getline(cin,exp);
		int tam = exp.size();

		//printf("%d\n",tam);
		if(exp == "")
		{
			printf("Yes\n");
			continue;
		}

		int count = 0;

		for(int i=0;i<tam;i++)
		{
			char atual = exp[i];

			if(atual == '(' || atual == '[') abre.push(atual);
			else 
			{
				if(!abre.empty())
				{
					if(abre.top() == '(' && atual == ')') abre.pop();
					else if(abre.top() == '[' && atual == ']') abre.pop();
					else count++;
				}
				else count++;
			}

			if(count) break;
		}

		if(abre.empty() && !count) printf("Yes\n");
		else printf("No\n");
		
	}

	return 0;
}
