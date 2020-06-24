#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool equal(int s[], int newSet[],int n){
  
  for(int i=0;i<n;i++){
    if(s[i] != newSet[i])
      return false;
  }
    
  return true;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  
  while(t--){
    int n;
    cin >> n;
    int s[n];
    for(int i=0;i<n;i++){
      cin >> s[i];
    }
    sort(s,s+n);
    int ans = -1;

    for(int i=1;i<1024;i++){
      int newSet[n];
      for(int j=0;j<n;j++)
        newSet[j] = s[j] ^ i;
      sort(newSet,newSet+n);
      if(equal(s,newSet,n)){
        ans = i;
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}