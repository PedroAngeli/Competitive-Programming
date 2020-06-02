#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,q;
  cin >> n >> q;
  queue <int> Q[n+1];
  queue <pair <int,int> > m;
  bool checked[q+1] = {false};
  int moment = 1;
  int ans = 0;

  for(int i=1;i<=q;i++){
    int op,x,t;
    cin >> op;

    if(op == 1){
      ans++;
      cin >> x;
      Q[x].push(moment);
      m.push({moment,x});
      moment++;
    }
    if(op == 2){
     cin >> x;
     ans -= Q[x].size();
     while(!Q[x].empty()){
       checked[Q[x].front()] = true;
       Q[x].pop();
     }
    }
    if(op == 3){
      cin >> t;
      while(!m.empty()){
        int time = m.front().first;
        if(time > t)
          break;
        int x = m.front().second;
        m.pop();
        if(!checked[time]){
          ans--;
          checked[time] = true;
          Q[x].pop();
        }
      }
    }


    cout << ans << endl;

  }
  
  

  return 0;
}