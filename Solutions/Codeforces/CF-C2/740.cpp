#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  vector <pair<int,int> > ran(m);
  for(int i=0;i<m;i++){
    cin >> ran[i].first >> ran[i].second;
  }

  sort(ran.begin(),ran.end(),[&](auto p1,auto p2){
    int d1 = p1.second-p1.first;
    int d2 = p2.second-p2.first;

    return (d1 > d2) || (d1 == d2 && p1.first < p2.first);
  });

  int cnt = ran[m-1].second - ran[m-1].first +1;
  cout << cnt << endl;
  int ans[n];

  int num = 0;
  for(int i=0;i<n;i++,num++)
    ans[i] = num%cnt;

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}