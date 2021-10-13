#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long x;

  cin >> x;

  vector <int> ans;

  while(x > 0){
    int dig = x%10;
    x /= 10;

    if(9-dig != 0 && 9-dig < dig)
      ans.push_back(9-dig);
    else if(9-dig == 0 && x > 0)
      ans.push_back(9-dig);
    else
      ans.push_back(dig);
  }

  reverse(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++)
    cout << ans[i];

  cout << endl;
  return 0;
}