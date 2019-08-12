#include <cstdio>
#include <string>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

map <char,int> tab;

bool IsNum(char c)
{
	if(c>='0' && c<='9') return true;

	return false;
}

bool cmp(char c,char top)
{
	//printf("c:%c,top:%c\n",c,top);

	if(c!='(' && c!=')') 
		if(tab[c]<=tab[top]) return true;
	
	return false;
}

int main()
{

	int n;
	int teste=0;

	tab['+']=1;tab['-']=1;tab['*']=2;tab['/']=2;

	while(scanf("%d",&n) == 1)
	{
		scanf("%*c%*c");

		while(n--)
		{
			if(teste) printf("\n");

			teste++;
	
			char c;
			string post;
			stack <char> pilha;

			while(scanf("%c",&c) == 1 && c!='\n')
			{
				scanf("%*c");

				//printf("char:%c\n",c);

				if(IsNum(c))
					post+=c;
				else 	
				{
					if(!pilha.empty()) 
					{
						if(c==')')
						{
							while(pilha.top() != '(')
							{
								post+=pilha.top();
								pilha.pop();
							}
							 pilha.pop();

							continue;
						}
					
						while(!pilha.empty() && cmp(c,pilha.top()))
						{
							post+=pilha.top();
							pilha.pop();
						}

						pilha.push(c);

					}
					else pilha.push(c);
				}
			}

			while(!pilha.empty()) 
			{
				if(pilha.top()!='(') post+=pilha.top();
				pilha.pop();
			}

			cout << post << "\n";
		   }
	}
	return 0;
}
