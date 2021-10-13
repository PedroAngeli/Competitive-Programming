#include <bits/stdc++.h>


using namespace std;

const int nax = 1e3 + 5;
bool lamp[nax];
vector <int> interruptor[nax];

int main(){

  int N,M;

  cin >> N >> M;

  int L;
  
  cin >> L;

  while(L--){
    int l;
    cin >> l;
    lamp[l] = true;
  }

  for(int i=0;i<N;i++){
    int k;
    cin >> k;

    for(int j=0;j<k;j++){
      int num;
      cin >> num;
      interruptor[i].push_back(num);
    }
  }

  bool apagou = false;
  int ans = 0;

  for(int k=0;k<2*N;k++){

    ans++;
    for(int i=0;i<interruptor[k%N].size();i++){
      lamp[interruptor[k%N][i]] = !lamp[interruptor[k%N][i]];
    }

    bool end = true;

    for(int i=1;i<=M;i++){
      if(lamp[i]){
        end = false;
        break;
      }
    }

    if(end){
      apagou = true;
      break;
    }

  }

  if(apagou){
    cout << ans << endl;
  }else{
    cout << "-1" << endl;
  }

  return 0;
}