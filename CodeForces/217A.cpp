#include <bits/stdc++.h>
 
 
using namespace std;
 
bool mat[1005][1005];
vector <int> adj[105];
vector < pair <int,int> > pares;
 
bool visitado[105];
 
void dfs(int v){
    
    visitado[v] = true;
    
    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(!visitado[u]){
            dfs(u);
        }
    }
}
 
int main(){
 
    int n;
    scanf("%d",&n);
 
    while(n--){
        int x,y;
        scanf("%d %d",&x,&y);
        pares.push_back({x,y});
    }
 
    for(int i=0;i<pares.size();i++){
        int x = pares[i].first;
        int y = pares[i].second;
 
        for(int j=i+1;j<pares.size();j++){
            
                int x2 = pares[j].first;
                int y2 = pares[j].second;
 
                if(x == x2){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
 
                if(y == y2){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        
    }
 
    int resp = -1;
      
    for(int i=1;i<=pares.size();i++){
        if(!visitado[i]){
            resp++;
            dfs(i);
        }
    }
 
    printf("%d\n",resp);
    
    return 0;
}
