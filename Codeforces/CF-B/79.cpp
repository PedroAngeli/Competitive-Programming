#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int mod(int j,int waste){
  return (((j%3)-waste)%3 + 3)%3;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k,t;

  cin >> n >> m >> k >> t;

  map <char, string> caracter;
  map <char, string> fruit;

  caracter['C'] = "CKG";
  caracter['K'] = "KGC";
  caracter['G'] = "GCK";

  fruit['C'] = "Carrots";
  fruit['K'] = "Kiwis";
  fruit['G'] = "Grapes";

  vector <int> linhas[n];
  char start[n][1];


  for(int i=0;i<k;i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    linhas[a].push_back(b);
  }

  char last = 0;

  for(int i=0;i<n;i++){
    if(m-linhas[i].size() == 0){
      start[i][0] = 'L';
    }else{
        start[i][0] = caracter['C'][last];
        last = mod(last+m-linhas[i].size(),0);
    }

  }

  while(t--){
    int a,b;
    cin >> a >> b;
    a--,b--;
    int waste = 0;
    bool flag = true;

    for(int i=0;i<linhas[a].size();i++){
      int x = linhas[a][i];
      if(x == b){
        cout << "Waste" << endl;
        flag = false;
        break;
      }

      if(b > x){
        waste++;
      }
    }

    if(flag){
      cout << fruit[caracter[start[a][0]][mod(b,waste)]] << endl;
    }
  }


  return 0;
}