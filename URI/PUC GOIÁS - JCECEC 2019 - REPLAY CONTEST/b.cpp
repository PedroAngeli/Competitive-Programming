#include <bits/stdc++.h>

using namespace std;

int xf,yf;

int dist(int x,int y){
  return ((x-xf)*(x-xf)) + ((y-yf)*(y-yf));
}

int main(){

  int n,i, k;

  cin >> n >> k >> xf >> yf;

  int x = 0 , y = 0;

  if(dist(x,y) > k*k){
      cout << "Trap " << 1 << "\n";
      return 0;
    }

  for(i=1;i<=n;i++){
    char inst;
    cin >> inst;

    if(inst == 'C')
      y++;
    if(inst == 'B')
      y--;
    if(inst == 'E')
      x--;
    if(inst == 'D')
      x++;

    if(dist(x,y) > k*k){
      cout << "Trap " << i << "\n";
      return 0;
    }
  }

  if(x != xf && y != yf){
      cout << "Trap " << n << "\n";
      return 0;
  }
   

  cout << "Sucesso\n";

  

  return 0;
}