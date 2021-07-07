#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

vector <pair <char,int> > adj[26];
const int INF = 1e9 + 7;

int dist[26][26];


void solve(char c){
  dist[c-'a'][c-'a'] = 0;
  set <pair <int,char> > pq;
  pq.insert({0,c});

  while(!pq.empty()){
    auto it = pq.begin();
    char u = it->second;
    pq.erase(it);
    for(auto p : adj[u-'a']){
      char v = p.first;
      int w = p.second;
      if(dist[c-'a'][v-'a'] > dist[c-'a'][u-'a'] + w){
        dist[c-'a'][v-'a'] = dist[c-'a'][u-'a'] + w;
        pq.insert({dist[c-'a'][v-'a'],v});
      }
    }
  }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  string s1,s2;
  cin >> s1 >> s2;
  
  int n = s1.size();
  int m = s2.size();

  if(n != m){
    cout << -1 << endl;
    return 0;
  }


  string ans;
  ans.resize(n);

  int t;
  cin >> t;

  while(t--){
    char c1,c2;
    int w;
    cin >> c1 >> c2 >> w;
    adj[c1-'a'].push_back({c2,w});
  }

  for(int i=0;i<26;i++)
    for(int j=0;j<26;j++)
      dist[i][j] = INF;

  for(int i=0;i<26;i++){
    solve(i+'a');
  }

  int mn = 0;

  for(int i=0;i<n;i++){
    if(s1[i] == s2[i]){
      ans[i]=s1[i];
      continue;
    }

    char chosen = '\0';

    int cost = INF;

    for(int j=0;j<26;j++){
      if(cost > dist[s1[i]-'a'][j]+dist[s2[i]-'a'][j]){
        chosen = j+'a';
        cost = dist[s1[i]-'a'][j]+dist[s2[i]-'a'][j];
      }
    }
    
    ans[i] = chosen;

    if(cost >= INF){
      cout << -1 << endl;
      return 0;
    }

    mn += cost;  
  }

  cout << mn << endl;
  cout << ans << endl;
    
  return 0;
}