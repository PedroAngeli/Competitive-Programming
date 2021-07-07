#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main(){

  int t;
   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
 

    while(t--){
      int n;
      cin >> n;

      vector <long long> a(n);
      vector <long long> b(n);

      for(long long i=0;i<n;i++)
        cin >> a[i] >> b[i];


      vector <pair <long long, long long> > temp;
      long long sum = 0;

      for(long long i=0;i<n;i++){
        if(i == 0)
          temp.push_back({a[i],max(0LL,a[i]-b[n-1])});
        else
          temp.push_back({a[i],max(0LL,a[i]-b[i-1])});
        
        sum += temp[i].second;
      }

      long long ans = INF;

      
      for(long long i=0;i<n;i++){
        ans = min(ans, sum - temp[i].second + temp[i].first);
      }

      cout << ans << "\n";
    }
  return 0;
}