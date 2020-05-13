#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int vet[n];
    for(int i=0;i<n;i++)
      cin >> vet[i];

    int mov = 0;
    int a = 0;
    int b = 0;

    int l = 0;
    int r = n-1;
    int lastr = 0;
    int lastl = 0;

    while(l <= r){
      int curl = 0;
      while(l <= r && curl <= lastr)
        curl += vet[l++];

        a += curl;
        mov++;
  
      lastl = curl;

      if(l > r)
        break;

      int curr = 0;

      while(r >= l && curr <= lastl)
        curr += vet[r--];

        b+=curr;
        mov++;
      
      lastr = curr;
    }

    cout << mov << " " << a << " " << b << endl;
  }
    
  return 0;
}