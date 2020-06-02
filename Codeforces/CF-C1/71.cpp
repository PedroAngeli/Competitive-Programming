#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  set <int> div;


  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      if(i > 2)
      div.insert(i);
      if(n / i > 2)
        div.insert(n/i);
    }
  }

  for(auto it = div.begin();it != div.end();it++){
    int x = *it;
    int esp = n/x;
      
    for(int i=0;i<n;i++){
      int j = i;
      int cnt = 0;
      while(vet[j%n] == 1 && cnt < x){
        j+=esp;
        cnt++;
      }

      if(cnt == x){
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}