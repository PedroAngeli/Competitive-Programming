#include <map>
#include <cstdio>
#include <iostream>

using namespace std;


int main()
{
	int n;
	map <string,int> conquistas;
	map <string,int> :: iterator it;
	string pais;	
	string nome;

	scanf("%d",&n);
	
	while(n--)
	{
		cin >> pais;
		getline(cin,nome);

		if(conquistas.find(pais) != conquistas.end()) conquistas[pais]++;
		else conquistas[pais]=1;
	}

	
	for(it = conquistas.begin();it!=conquistas.end();it++)
		cout << it->first << ' ' << it->second << '\n';

	return 0;
}
