#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;

  vector <pair <int,int> > vet(n);

  for(int i=0;i<n;i++) 
    cin >> vet[i].first >> vet[i].second;

  sort(vet.begin(),vet.end(),[&](auto p1,auto p2){
    return p1.second > p2.second || p1.second == p2.second && p1.first > p2.first;
  });

  int ans = 0;
  int cnt = 1;

  for(int i=0;i<n;i++){
    cnt--;
    ans += vet[i].first;
    cnt += vet[i].second;
    if(cnt == 0)
      break;
  }

  cout << ans << endl;



  
  return 0;
}