#include <bits/stdc++.h>

using namespace std;


int main(){

  int h,m;

  while(cin >> h >> m){
    printf("%02d:%02d\n",h/30,(m*60)/360);
  }

  return 0;
}