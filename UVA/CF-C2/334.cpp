#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int nc;
  int test = 1;

  while(cin >> nc && nc){
    vector <string> events(200);
    map <string,int> mp;
    vector <vector <bool> > pairs(200,vector <bool>(200,false));
    int v = 0;

    for(int i=0;i<nc;i++){
      int ne;
      cin >> ne;
      for(int j=0;j<ne;j++){
        string s;
        cin >> s;
        events[v] = s;
        mp[s] = v;

        if(j < ne-1)
          pairs[v][v+1] = true;
        v++;
      }
    }

    int nm;
    cin >> nm;
    while(nm--){
      string s1,s2;
      cin >> s1 >> s2;
      int u1 = mp[s1];
      int u2 = mp[s2];
      pairs[u1][u2] = true;
    }

    for(int k=0;k<v;k++)
      for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
          pairs[i][j] = pairs[i][j] || (pairs[i][k] && pairs[k][j]);

    int ans = 0;
    vector <pair <string,string> > vet;

    for(int i=0;i<v;i++)
      for(int j=i+1;j<v;j++)
        if(!pairs[i][j] && !pairs[j][i]){
          ans++;
          if(vet.size() < 2)
            vet.push_back({events[i],events[j]});
        }

      if(ans == 0){
        cout << "Case " << test++ << ", no concurrent events." << endl;
        continue;
      }

      cout << "Case " << test++ << ", " << ans << " concurrent events:" << endl;

      for(int i=0;i<min(ans,2);i++)
        cout << "(" << vet[i].first << "," << vet[i].second << ")" << " ";

      cout << endl;
  }

  return 0;
}