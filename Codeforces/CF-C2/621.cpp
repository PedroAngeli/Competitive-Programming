#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int n,p;
  cin >> n >> p;
  vector <pair<long long,long long> > s(n);

  for(int i=0;i<n;i++)
    cin >> s[i].first >> s[i].second;

  double sum = 0;

  for(int i=0;i<n;i++){
    long long l1 = s[i].first;
    long long r1 = s[i].second;
    long long l2 = s[(i+1)%n].first;
    long long r2 = s[(i+1)%n].second;
    long long q1 = r1/p - (l1-1)/p;
    long long q2 = r2/p - (l2-1)/p;
    long long tam = (r1-l1+1)*(r2-l2+1);
    sum += (double)(((q1* (r2-l2+1)) + (q2 * (r1-l1+1)) - q1*q2))/tam * 2000.00;  
  }

  cout << fixed << setprecision(15) << sum << endl;

  return 0;
}