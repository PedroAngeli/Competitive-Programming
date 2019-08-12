#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map <int,string> intToRoman; 
map <char,int> romanToInt;
map <int,string> :: iterator it;

void FillintToRoman()
{
	intToRoman[1000] = "M" ,intToRoman[900] = "CM", intToRoman[500] ="D" ,intToRoman[400] ="CD" ,intToRoman[100] ="C" ,intToRoman[90] = "XC";
	intToRoman[50] ="L" , intToRoman[40] ="XL" , intToRoman[10] = "X", intToRoman[9] ="IX" , intToRoman[5] ="V" ,intToRoman[4] ="IV" ,intToRoman[1] ="I";
}

void FillromanToInt()
{
	romanToInt['I'] = 1 , romanToInt['V'] = 5 , romanToInt['X'] = 10, romanToInt['L'] = 50 , romanToInt['C'] = 100 , romanToInt['D'] =500 , romanToInt['M'] =1000 ;
}

bool IsInt(string input)
{
	if(input[0]>='0' && input[0]<='9') return true;

	return false; 
}

int StringToInt(string input)
{
	int num=0;
	int mult = 1;

	for(int i=input.size()-1;i>=0;i--)
	{
		num+=(input[i]-'0')*mult;
		mult*=10;
	}

	//printf("%d\n",num);
	return num;

	
}
int main()
{

	FillintToRoman(),FillromanToInt();
	
	string input;
	
	while(cin >> input)
	{
		if(IsInt(input))
		{
			int num = StringToInt(input);
			string output;
			it = intToRoman.end();
			it--;

			for(;it!=intToRoman.begin();it--)
			{
				int qtd = num/it->first;
				if(qtd) num-=(it->first*qtd);

				for(int i=0;i<qtd;i++)
					output+=it->second;
			}

		 	int qtd = num/it->first;
				if(qtd) num-=it->first;

			for(int i=0;i<qtd;i++)
					output+=it->second;

			cout << output << '\n';
		}
		else
		{
			int resp=0;
			int aux=0;

			for(int i=0;i<input.size()-1;i++)	
			{
				if(romanToInt[input[i]]<romanToInt[input[i+1]]) 
				{
					resp+=(romanToInt[input[i+1]]-romanToInt[input[i]]);
					i++;
					if(i+1 == input.size()) aux++;
					
				}
				else resp+=romanToInt[input[i]];

				//printf("%d\n",resp);
			}

			if(!aux) resp+=romanToInt[input[input.size()-1]];

			printf("%d\n",resp);
		}
	}	
	

	
	

	return 0;
}
