#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  int k1;
  cin >> k1;
  vector <int> p1(k1);
  vector <int> p2(n-k1);
  vector <int> t1(k1);
  vector <int> t2(n-k1);

  for(int i=0;i<k1;i++)
    cin >> p1[i], t1[i] = p1[i];
  
  int k2;
  cin >> k2;

  for(int i=0;i<k2;i++)
    cin >> p2[i], t2[i] = p2[i];

  int ans = 0;
  int cnt = 0;

  while(cnt < 1e6){
    int x1 = t1[0];
    int x2 = t2[0];
    cnt++;

    if(x1 > x2){
      t1.push_back(x2);
      t1.push_back(x1);
    }else{
      t2.push_back(x1);
      t2.push_back(x2);
    }

    t1.erase(t1.begin());
    t2.erase(t2.begin());

    if(t1.size() == 0){
      ans = 2;
      break;
    }

    if(t2.size() == 0){
      ans = 1;
      break;
    }

  }

  if(cnt == 1e6)
    cout << -1 << endl;
  else
  cout << cnt << " " << ans << endl;

  return 0;
}