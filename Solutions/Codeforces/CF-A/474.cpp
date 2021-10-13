#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  char vet[] = {'q','w','e','r','t','y','u','i',
  'o','p','a','s','d','f','g','h','j','k','l',';',
  'z','x','c','v','b','n','m',',','.','/'};

  char c;

  cin >> c;

  string s;
  cin >> s;

  for(int i=0;i<s.size();i++){
    if(c == 'R'){
      for(int j=0;j<30;j++)
        if(s[i] == vet[j])
          cout << vet[j-1];
    }else{
      for(int j=0;j<30;j++)
        if(s[i] == vet[j])
          cout << vet[j+1];
    }
  }

  cout << endl;
  return 0;
}