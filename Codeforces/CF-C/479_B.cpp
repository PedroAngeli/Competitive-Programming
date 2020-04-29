#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;
  cin >> n >> k;

  vector <pair <int,int> > vet(n);

  for(int i=0;i<n;i++){
    cin >> vet[i].first;
    vet[i].second = i+1;
  }

  vector <pair <int,int> > ans(k);

  int op = 0;
  int dif = 1e9 + 7;

  sort(vet.begin(),vet.end());

  if(vet[n-1].first == vet[0].first){
    cout << 0 << " " << 0 << endl;
    return 0;
  }

  for(int i=0;i<k;i++){
    vet[0].first++;
    vet[n-1].first--;
    ans[i].first = vet[n-1].second;
    ans[i].second = vet[0].second;

    sort(vet.begin(),vet.end());

    if(dif > vet[n-1].first - vet[0].first){
      dif = vet[n-1].first - vet[0].first;
      op = i+1;
    }

  }

  cout << dif << " " << op << endl;

  for(int i=0;i<op;i++)
    cout << ans[i].first << " " << ans[i].second << endl;

  return 0;
}