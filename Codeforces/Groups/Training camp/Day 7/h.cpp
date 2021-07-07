#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  long long n;
  cin >> n;

  vector <pair <long long,int > > factors;
  long long div = 2;
  while(div*div <= n){
      int cnt = 0;
      while(n%div==0){
        n/=div;
        cnt++;
      }
      if(cnt)
        factors.push_back({div,cnt});
      div++;
  }
    if(n != 1)
      factors.push_back({n,1});

  if(factors.size() == 0){
    cout << "NO" << endl;
  }else if(factors.size() == 1){
    cout << "YES" << endl;
  }else{
    int cnt = 0;
    for(auto p:factors)
      if(p.second % 2 == 1)
        cnt++;
    if(cnt <= 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
 
 
  
  return 0;
}