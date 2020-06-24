#include <bits/stdc++.h>

using namespace std;


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int ncase = 0;

  while(cin >> n){
    if(ncase)
      cout << endl;
    ncase++;
    int in = 0;
    int seg = 0;
    double r = (2*n-1)/2.0;

    for(int i=n;i>=-n;i--){
      if(i == 0)
        continue;
      for(int j=-n;j<=n;j++){
        if(j == 0)
          continue;
        bool upper = false;
        bool lower = false;

        if((double)(i*i + j*j) <= r*r){
          upper = true;
        }
        double x,y;

        if(i > 0){
          x = i-1;
          if(j < 0)
            y = j+1;
          else
            y = j-1;  
        }else{
          x = i+1;
          if(j < 0)
            y = j+1;
          else
            y = j-1; 
        }

        if(x*x + y*y <= r*r){
          lower = true;
        }


        if(upper && lower)
        in++;
        else if(lower || upper)
          seg++;
      }
      
    }

    cout << "In the case n = " << n << ", " << seg << " cells contain segments of the circle." << endl;
    cout << "There are " << in << " cells completely contained in the circle." << endl;
  }
 

  return 0;
}