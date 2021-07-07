#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  char s1[1010],s2[1010];

  scanf("%[^.].%s",s1,s2);

  string integer = s1;
  string frac = s2;

  int n = integer.size();
  int m = frac.size();

  if(integer[n-1] == '9'){
    cout << "GOTO Vasilisa." << endl;
    return 0;
  }

  string aux;
  aux.push_back('5');
  for(int i=0;i<m-1;i++)
    aux.push_back('0');
    
  if(frac < aux)
    cout << integer << endl;
  else{
    integer[n-1]++;
    cout << integer << endl;
  }
  return 0;
}