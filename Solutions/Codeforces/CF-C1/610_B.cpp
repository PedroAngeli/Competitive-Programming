#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  long long vet[n];
  long long mn = INT_MAX;

  for(int i=0;i<n;i++)
    cin >> vet[i],mn = min(mn,vet[i]);

  long long dist = 0;
  long long lastPos = -1;
  
  for(int i=0;i<2*n;i++){
    if(vet[i%n] == mn){
      if(lastPos == -1)
        lastPos = i;
      else
        dist = max(dist, i-lastPos-1),lastPos = i;
    }
  }

  long long ans = (mn*n) + dist;

  cout << ans << endl;

  return 0;
}