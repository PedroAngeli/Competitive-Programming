#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int letters[n];

  int firstPos = -1;

  for(int i=0;i<n;i++){
    cin >> letters[i];
    if(letters[i] && firstPos == -1)
      firstPos = i;
  }

  if(firstPos == -1)
    cout << 0 << endl;
  else{
      int i = firstPos;
      int ans = 0;

      while(i < n){
        int cnt = 0;
        while(i < n && letters[i])
          i++,cnt++;
        ans += cnt+1;
  
        while(i < n && !letters[i])
          i++;
      }

    cout << ans-1 << endl;


    }

  

  
  return 0;
}