#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int sum,limit;
  cin >> sum >> limit;

  vector <pair <int,int> > last;
  int pos = 0;

  for(int i=1;i<=limit;i++)
    last.push_back({i & (-i),i}), pos += (i & (-i));


  if(pos < sum){
    cout << -1 << endl;
  }else{
    sort(last.begin(),last.end());
    reverse(last.begin(),last.end());
    
    int n = last.size();
    vector <int> ans;

    for(int i=0;i<n;i++){
      int num = last[i].second;
      int bit = last[i].first;

      if(sum - bit >= 0){
        ans.push_back(num);
        sum -= bit;
      }
    }

    int m = ans.size();
    cout << m << endl;
    for(int i=0;i<m;i++)
      cout << ans[i] << " ";
    cout << endl;
  }
  
  

  return 0;
}