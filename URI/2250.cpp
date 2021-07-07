#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

bool cmp(pair <int,string> p1, pair <int,string> p2){
  return p1.f > p2.f || (p1.f == p2.f && p1.s < p2.s);
}

int main(){
  fastio;

  int n;
  int teste = 1;

  while(cin >> n && n){

    vector <pair <int,string> > players;
    cout << "Teste " << teste++ << endl;

    for(int i=0;i<n;i++){
      string name;
      cin >> name;

      vi tmp(12);
      for(int j=0;j<12;j++)
        cin >> tmp[j];

      sort(all(tmp));
      int pont = 0;

      for(int j=1;j<11;j++)
        pont += tmp[j];

      players.pb({pont,name});  
    }

    sort(all(players),cmp);
    
    for(int i=0;i<n;){
      int cur = players[i].f;
      int j = i;

      while(j < n && cur == players[j].f)
        cout << i+1 << " " << players[j].f << " " << players[j].s << endl,j++;
      i = j;
    }

    cout << endl;
  }


  return 0;
}