#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const int nax = 1e5+5;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int n,m;
  cin >> n >> m;
  vector <int> v;
  
  int mx = 1e9;

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    v.push_back(x);
  }

  v.push_back(mx);

  vector <int> h;

  for(int i=0;i<m;i++){
    int x1,x2,y;
    cin >> x1 >> x2 >> y;
    if(x1 == 1)
      h.push_back(x2);
  }

  sort(h.begin(),h.end());
  sort(v.begin(),v.end());

  
  int ans = INT_MAX;
  int j = 0;
  int len = h.size();

  for(int i=0;i<v.size();i++){
    while(j < len && h[j] < v[i])
      j++;
    ans = min(ans,len-j+i);
  }

  cout << ans << endl;
  
  
  return 0;
}