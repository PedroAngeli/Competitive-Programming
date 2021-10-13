#include <bits/stdc++.h>

using namespace std;

int main(){

  int n,s;

  while(cin >> n >> s){

    int d=1,b=1,e=2,c=2;
    int sum = 1;
    int x = n/2, y = n/2;
    int mov = 0;

    while(sum < s){
      if(mov % 4 == 0){
        int tam = min(d,s-sum);
        sum += tam;
        x += tam;
        d += 2;
      }
      
      if(mov % 4 == 1){
        int tam = min(b,s-sum);
        sum += tam;
        y += tam;
        b += 2;
      }

      if(mov % 4 == 2){
        int tam = min(e,s-sum);
        sum += tam;
        x -= tam;
        e += 2;
      }

      if(mov % 4 == 3){
        int tam = min(c,s-sum);
        sum += tam;
        y -= tam;
        c += 2;
      }

      // cout << sum << " " << y << " " << x << endl;

      mov++;
    }

  cout << y << " " <<  x << endl;
  }

  return 0;
}