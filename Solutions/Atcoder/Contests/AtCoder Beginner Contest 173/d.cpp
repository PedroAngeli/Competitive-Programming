#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector <long long> vet(n);
  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet.begin(),vet.end());
  reverse(vet.begin(),vet.end());

  long long ans = 0;

  int i = 0;
  int players = 1;

  if(players < n){
    ans = vet[i++];
    players++;
    while(true){
      if(players >= n)
        break;
      ans+=vet[i];
      players++;
      if(players >= n)
        break;
      ans+=vet[i];
      players++;
      i++;
    }
  }


  cout << ans << endl;
 
  return 0;
}