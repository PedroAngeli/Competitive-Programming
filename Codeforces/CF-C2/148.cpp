#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,a,b;
  cin >> n >> a >> b;
  int ans[n] = {0};

  if(b){
    int sum = 0;
    for(int i=0;i<=b;i++){
      ans[i] = sum+1;
      sum += ans[i];
    }
    
    for(int i=b+1,c=0;c<a;c++,i++)
      ans[i] = ans[i-1] + 1;
  
  }else{
    if(a && a > n-2){
      cout << -1 << endl;
      return 0;
    }

    ans[0] = 1;
    ans[1] = 1;

    for(int i=2,c=0;c<a;i++,c++){
      ans[i] = ans[i-1]+1;
    }
  }

  for(int i=0;i<n;i++){
    if(ans[i] == 0)
      ans[i] = 1;
    cout << ans[i] << " ";
  }

  cout << endl; 
  

  return 0;
}