#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int a[n];

  for(int i=0;i<n;i++)
    cin >> a[i];

  int ans[n] = {0};

  for(int i=0;i<31;i++){
    int cnt = 0;
    for(int j=0;j<n;j++){
      if(a[j] & (1 << i))
        cnt++;
    }
    if(cnt % 2 == 0){
      for(int j=0;j<n;j++)
        ans[j] += (a[j] & (1 << i));
    }else{
      for(int j=0;j<n;j++){
        if((a[j] & (1 << i)) == 0)
          ans[j] += (1 << i);
      }
        
    }
  }

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
  cout << endl;
 
  return 0;
}