#include <bits/stdc++.h>

using namespace std;

const int nax = 2*1e5 + 5;
double vet[nax];
int n;

double f(double x){
  double mx = 0;
  double mn = 0; 
  double temp[n];
  double sum = 0;
  double ans = -1e10;

  for(int i=0;i<n;i++)
    temp[i] = vet[i]-x;

  for(int i=0;i<n;i++){
    sum += temp[i];
    ans = max(ans, max(sum - mn,mx - sum));
    mx = max(mx,sum);
    mn = min(mn,sum);
  }


  return ans;
}

int main(){

  cin >> n;

  for(int i=0;i<n;i++)  
    cin >> vet[i];

  double l = -10000;
  double r = 10000;

  for(int i=0;i<=100;i++){
    double m1 = l + (r-l)/3;
    double m2 = r - (r-l)/3;

    double f1 = f(m1);
    double f2 = f(m2);

    if(f1 > f2){
      l = m1;
    }else{
      r = m2;
    }
  }

  double ans = f(l);

  // cout << l << endl;

  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}