#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    n/=2;
    if(n % 2 == 1)
      cout << "NO" << endl;
    else{
      cout << "YES" << endl;

      n *= 2;
      vector <int> ans;
      set <int> s;
      int sum = 0;
      for(int i=2;i<=n;i++)
        if(i%2 == 0)
        ans.push_back(i),sum+=i;

        int cnt =0;
      int sum2 = 0;
      for(int i=1;i<=n;i++){
        if(i%2==1){
        ans.push_back(i);
        cnt++;
        sum2+=i;
        }

        if(cnt == n/2 - 1)
          break;
      }
        

      ans.push_back(sum-sum2);

      for(int i=0;i<n;i++)
        cout << ans[i] << " ";

      cout << endl;

      
    }
  }
  

  return 0;
}