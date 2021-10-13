#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
   int t;
   cin >> t;
   while(t--){
     int n,m,k;
     cin >> n >> m >> k;
     int qtd = n/k;
     int win = min(qtd,m);
     int sec = ceil((double)(m-win)/(k-1));
    //  cout << win << " " << sec << endl;
     cout << win - sec << endl;
   } 

  return 0;
}