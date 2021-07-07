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

vi adj[300];
vi matchA;
vi matchB;
vector <bool> visB;
string allocation;
int qtd_applications;

bool dfs(int u){
  for(int v : adj[u]){
    if(visB[v])
      continue;
    visB[v] = true;
    
    if(matchB[v] == -1 || dfs(matchB[v])){
      matchA[u] = v;
      matchB[v] = u;
      return true;
    }
  }

  return false;
}

bool kuhn(){
  allocation.resize(10);
  matchA.assign(300,-1);
  matchB.assign(10,-1);

  bool flag = true;
  int matched = 0;

  while(flag){
    flag = false;
    visB.assign(10,false);

    for(int i=0;i<300;i++){
      if(matchA[i] != -1)
        continue;
      if(dfs(i)){
        matched++;
        flag = true;
      }
    }
  }

  if(matched < qtd_applications)
    return false; 

  for(int i=0;i<10;i++)
    if(matchB[i] == -1)
      allocation[i] = '_';
    else
      allocation[i] = matchB[i]%27 + 'A';

  return true;
}

int main(){
  fastio;

  bool flag = true;
  
  while(true){
    string line;
    flag = false;
    qtd_applications = 0;
    for(int i=0;i<300;i++)
      adj[i].clear();
      
    while(getline(cin,line)){
      if(sz(line) == 0)
        break;

      stringstream ss(line);
      string app;
      string computers;
      ss >> app >> computers;
      char application = app[0];
      int qtd_app = app[1] - '0';
      qtd_applications += qtd_app;

      for(int i=0;i<sz(computers)-1;i++){
        int cur_computer = computers[i] - '0';
        for(int j=0;j<qtd_app;j++)
          adj[application - 'A' + j * 27].pb(cur_computer);
      }

      flag = true;
    }
    if(flag == false)
      break;
    if(!kuhn())
      cout << "!" << endl;
    else
      cout << allocation << endl;
  }
 
  

  return 0;
}