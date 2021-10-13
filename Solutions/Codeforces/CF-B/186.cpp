#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool cmp(pair <double,int> p1,pair <double,int> p2){
  return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,t1,t2,k;

  cin >> n >> t1 >> t2 >> k;

  vector <pair <double,int> > ans;

  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    double f = a*t1*(1-((double)k/100)) + b*t2;
    double s = b*t1*(1-((double)k/100)) + a*t2;
  
    double best = max(f,s);
    ans.push_back({best,i});
  }


  sort(ans.begin(),ans.end(),cmp);

  for(int i=0;i<n;i++)
    cout << ans[i].second + 1 << " " << fixed << setprecision(2) << ans[i].first << endl;
  
  return 0;
}