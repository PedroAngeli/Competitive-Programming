#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n,a,b;

  while(cin >> n >> a >> b && n){
    unordered_map <int,int> cnt;
    long long deads = 0;
    long long cur = 0;

    while(true){
      cnt[cur]++;

      if(cnt[cur] == 2)
        deads++;
        
      if(cnt[cur] == 3)
        break;

      cur = (((a*cur)%n)*cur + b)%n;
    }


    cout << n - deads << endl;
  }
  
  
  return 0;
}