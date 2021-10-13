#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
   int T;
   cin >> T;
  long double EPS = 1e-12;
   while(T--){
     long long h,c,t;
     cin >> h >> c >> t;
     long double even = (long double)(h+c)/2.0;
     long double distEven = fabs(even-t);
     long long num = t-h;
     long long den = h+c-2*t;

     if(den == 0){
       cout << 2 << endl;
       continue;
     }

     long long x = ceil((long double)num/den);
     long long y = x-1;

     long double distOdd = LDBL_MAX;
     long long qtdOdd;

     if(x >=0 && y >=0){
        distOdd = fabs((long double)(x*h + y*c)/(x+y) - (long double)t);
        qtdOdd = x+y;
     }

     long long x1 = x-1;
     long long y1 = x1-1;

     if(x1>=0 && y1>=0){
       long double tmp = fabs((long double)(x1*h + y1*c)/(x1+y1) - (long double)t);
       if(distOdd-tmp > EPS){
         distOdd = tmp;
         qtdOdd = x1 + y1;
       }
     }

     long long x2 = x+1;
     long long y2 = x2-1;

     if(x2>=0 && y2>=0){
       long double tmp = fabs((long double)(x2*h + y2*c)/(x2+y2) - (long double)t);
       if(distOdd-tmp > EPS){
         distOdd = tmp;
         qtdOdd = x2 + y2;
       }
     }

     if((distEven - distOdd) > EPS)
      cout << qtdOdd << endl;
     else
      cout << 2 << endl;
   } 

  return 0;
}