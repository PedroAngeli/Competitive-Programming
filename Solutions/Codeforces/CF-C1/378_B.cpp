#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string ans1;
  string ans2;
  ans1.assign(n,'0');
  ans2.assign(n,'0');

  int k  = n/2;

  for(int i=0;i<k;i++)
    ans1[i] = ans2[i] = '1';

  vector <pair <int, pair<int,int> > > vet;

  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    vet.push_back({a,{i,1}});
    vet.push_back({b,{i,2}});
  }

  sort(vet.begin(),vet.end());

  for(int i=0;i<n;i++){
    int semifinal = vet[i].second.second;
    int idx = vet[i].second.first;

    if(semifinal == 1)
      ans1[idx] = '1';
    else
      ans2[idx] = '1';
  }

  cout << ans1 << endl << ans2 << endl;
  

  return 0;
}