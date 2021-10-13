#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n,r,avg;

  cin >> n >> r >> avg;
  
  vector <pair <long long,long long> > grades(n);
  long long sum = 0;

  for(int i=0;i<n;i++){
    cin >> grades[i].second >> grades[i].first;
    sum += grades[i].second;
  }

  long long x = n*avg - sum;

  sort(grades.begin(),grades.end());

  long long ans = 0;

  for(int i=0;i<n && x > 0;i++){
      long long b = grades[i].first;
      long long a = grades[i].second;

      ans += min(r-a,x)*b;
      x = x - min(r-a,x);
  }
  

  cout << ans << endl;



  return 0;
}