#include <cstdio>
#include <map>
#include <iostream>
#include <string>

using namespace std;


map <char,char> tabela;


void FillTabela()
{
	tabela['B'] = '1' ,tabela['P'] = '1', tabela['F'] = '1', tabela['V'] = '1' , tabela['C'] = '2' , tabela['S'] = '2' ;
	tabela['K'] = '2' , tabela['G'] = '2', tabela['J'] = '2' , tabela['Q'] = '2', tabela['X'] = '2' , tabela['Z'] = '2';
	tabela['D'] = '3' , tabela['T'] = '3' , tabela['L'] = '4' , tabela['M'] = '5' ,tabela['N'] = '5' , tabela['R'] = '6';
}
int main()
{

	FillTabela();
	string input;
	
	cout << "         NAME                     SOUNDEX CODE\n";

	while(cin >> input)
	{
		string output;
		
		output+=input[0];
		
		for(int i=1;i<input.size();i++)
		{
			char atual = input[i];
			char ant = input[i-1];

			if(output.size() < 4)
				if(tabela.find(atual) != tabela.end())
				{
					if(tabela.find(ant) == tabela.end()) output+=tabela[atual];	
					else if(tabela[ant] != tabela[atual]) output+=tabela[atual];
				}
		}

		while(output.size()<4) output+='0';

		cout <<"         " << input;
			
		int aux = 25-input.size();
		 
		while(aux--) cout << " ";
		cout << output << "\n";
	}


	cout << "                   END OF OUTPUT" <<  endl;


	return 0;
}
