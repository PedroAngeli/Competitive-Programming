#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int in[n];
  int out[n];
  int pos[n];

  for(int i=0;i<n;i++){
    cin >> in[i];
    pos[in[i]] = i;
  }

  for(int i=0;i<n;i++)
    cin >> out[i];

  int j = 0;
  int ans = 0;

  for(int i=0;i<n;i++){
    int cur = out[i];
    if(cur == in[j]){
      in[j] = 0;
      while(j < n && in[j] == 0)
        j++;
    }else{
      in[pos[cur]] = 0;
      ans++;
    }

    // for(int k=0;k<n;k++)
    //   cout << in[k] << " ";
    // cout << endl;
  }

  cout << ans << endl;

  
  return 0;
}