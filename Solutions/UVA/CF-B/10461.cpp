#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
int v,e;
const int maxv = 505;
int t[maxv];
vector <int> adj1[maxv];
vector <int> adj2[maxv];
bool visitado[maxv];

int bfs1(int u){
   memset(visitado,false,sizeof visitado);
   queue <int> q;
   int ans = 0;
   visitado[u] = true;

   q.push(u);

   while(!q.empty()){
     int v = q.front();
     q.pop();

     for(int w : adj1[v]){
       if(!visitado[w]){
         ans += t[w];
         q.push(w);
         visitado[w] = true;
       }
     }
   }

   return ans;
}

int bfs2(int u){
   memset(visitado,false,sizeof visitado);
   queue <int> q;
   int ans = 0;
   visitado[u] = true;
   q.push(u);

   while(!q.empty()){
     int v = q.front();
     q.pop();

     for(int w : adj2[v]){
       if(!visitado[w]){
         q.push(w);
         visitado[w] = true;
       }
     }
   }

   for(int i=1;i<=v;i++)
    if(!visitado[i])
      ans += t[i];

   return ans;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ncase = 1;

  while(cin >> v >> e){
    if(v == 0)
      break;

    cout << "Case #" << ncase++ << ":" << endl;

    for(int i=1;i<=v;i++){
      cin >> t[i];
      adj1[i].clear();
      adj2[i].clear();
    }

    for(int i=0;i<e;i++){
      int a,b;
      cin >> a >> b;
      adj1[a].push_back(b);
      adj2[b].push_back(a);
    }

    int q;
    cin >> q;

    while(q--){
      int x;
      cin >> x;

      int minx = bfs1(x);
      int maxx = bfs2(x);

      cout << maxx - minx << endl;

      
    }

    cout << endl;

  }

  
  
  return 0;
}