#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,s;
  cin >> n >> s;

  int ans[n];

  for(int i=0;i<n-1;i++)
    ans[i] = 1;
  ans[n-1] = s - (n-1);

  int l1 = n-1;
  int l2 = s - l1;
  
  bool exists = false;
  int val = 0;

  if(l1+1 < l2){
    exists = true;
    val = l2-1;
  }


  if(exists){
    cout << "YES" << endl;
    for(int i=0;i<n;i++)
      cout << ans[i] << " ";
      cout << endl;
      cout << val << endl;
  }else
    cout << "NO" << endl;

  return 0;
}