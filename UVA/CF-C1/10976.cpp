#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int lcm(int a,int b){
  return (a*b)/__gcd(a,b);
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int k;

  while(cin >> k){
    vector <pair<int,int> > ans;
    for(int x=2*k;x>=1;x--){
      int m = lcm(x,k);
      int d1 = m/k;
      int d2 = m/x;

      if((d1-d2) > 0 && m % (d1-d2) == 0){
        int y = m/(d1-d2);
        ans.push_back({y,x});
      }
    }

    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());

    int n = ans.size();

    cout << n << endl;

    for(int i=0;i<n;i++){
      cout << "1/" << k << " = " << "1/" << ans[i].first << " + " << "1/" << ans[i].second << endl;
    }
  }

 
  
  return 0;
}