#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool stan(pair <int,int> p1, pair <int,int> p2){
  return (p1.first > p2.first && p1.second > p2.second) ||
  (p1.first < p2.first && p1.second < p2.second);
}

bool ollie(pair <int,int> p1, pair <int,int> p2){
  return (p1.first > p2.first && p1.second < p2.second) ||
  (p1.first < p2.first && p1.second > p2.second);
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  while(cin >> n && n){
    vector < pair <int,int> > p(n);

    for(int i=0;i<n;i++)
      cin >> p[i].first >> p[i].second;

    pair <int,int> cross = p[n/2];

    int s = 0;
    int o = 0;

    for(int i=0;i<n;i++){
      if(stan(p[i],cross))
        s++;
      if(ollie(p[i],cross))
        o++;
    }

    cout << s << " " << o << endl;
  }

  return 0;
}