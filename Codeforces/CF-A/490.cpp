#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[4];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector <pair <int, int> > vet(n);
 

  for(int i=0;i<n;i++){
    cin >> vet[i].first;
    vet[i].second = i;
    cnt[vet[i].first]++;
  }

  sort(vet.begin(),vet.end());

  int teams = min(cnt[1],min(cnt[2],cnt[3]));

  cout << teams << endl;

  for(int k=0;k<teams;k++){
    int num = 1;
    for(int i=0;i<n;i++){
      if(vet[i].first == num){
        num++;
        vet[i].first = 0;
        cout << vet[i].second + 1 << " ";
      }
    }

    cout << endl;
  }
    

  
  
  return 0;
}