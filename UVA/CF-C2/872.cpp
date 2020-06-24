#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

vector <int> adj[26];
vector <string> ans;
int deg[26];
bool exist[26];
int v; 
bool cycle;

void allTopo(vector <int> &topo,vector <bool> &vis){
  bool can = false;

  for(int i=0;i<26;i++){
    if(exist[i] == true && deg[i] == 0 && vis[i] == false){
        for(int j=0;j<adj[i].size();j++)
         deg[adj[i][j]]--;

       topo.push_back(i);
       vis[i] = true;

       allTopo(topo,vis);

       vis[i] = false;
       topo.erase(topo.end()-1);
        for(int j=0;j<adj[i].size();j++)
          deg[adj[i][j]]++;

        can = true;
    }
  }

  if(topo.size() == v){
    int len = topo.size();
    cycle = false;
    string resp = "";
    for(int i=len-1;i>=0;i--){
      char cur = topo[i]+'A';
      resp += cur;
    }
    ans.push_back(resp);
  }
}

void solve(){
 vector <bool> vis(26);

  vector <int> topo;
  allTopo(topo,vis);
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t;
  scanf("%d%*c",&t);
  bool newLine = false;
  while(t--){
    if(newLine)
      printf("\n");
    newLine = true;
    ans.clear();
    v = 0;
    cycle = true;
    for(int i=0;i<26;i++)
      adj[i].clear(), exist[i] = false,deg[i] = 0;

    scanf("%*c");
    char variables[1000];
    scanf("%[^\n]%*c",variables);

    int vLen = strlen(variables);
    for(int i=0;i<vLen;i+=2){
      exist[variables[i]-'A'] = true;
      v++;
    }

    char constraints[1000];
    scanf("%[^\n]%*c",constraints);

    int cLen = strlen(constraints);

    for(int i=0;i<cLen;i+=4){
      adj[constraints[i+2] - 'A'].push_back(constraints[i]-'A');
      deg[constraints[i]-'A']++;
    }

    solve();

    if(cycle)
      printf("NO\n");
    else{
      sort(ans.begin(),ans.end());
      for(int i=0;i<ans.size();i++)
        for(int j=0;j<ans[i].size();j++){
          if(j == ans[i].size() - 1)
            printf("%c\n",ans[i][j]);
          else
            printf("%c ",ans[i][j]);
        }
    }
  }
  
  return 0;
}