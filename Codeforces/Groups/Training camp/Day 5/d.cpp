#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int h,m;
  scanf("%d:%d",&h,&m);

  h %= 12;

  double hour = 30*h + 0.5*m;
  double minute = m*6;


  printf("%.9lf %.9lf\n",hour,minute);
    
  return 0;
}