#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int vet[5];
bool can;

void solve(int i,int cur){
  if(i == 5){
    if(cur == 23)
      can = true;
    return;
  }

  solve(i+1,cur+vet[i]);

  solve(i+1,cur-vet[i]);

  solve(i+1,cur*vet[i]);
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> vet[0] >> vet[1] >> vet[2] >> vet[3] >> vet[4] && vet[0]){
    can = false;

    sort(vet,vet+5);
    solve(1,vet[0]);


    while(next_permutation(vet,vet+5)){
      solve(1,vet[0]);
    }

    if(can)
      cout << "Possible" << endl;
    else
      cout << "Impossible" << endl;
  }
  
  return 0;
}