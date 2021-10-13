#include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int,int> a, pair <int,int> b){
  return a.second < b.second;
}

int main(){

  int n;
  cin >> n;

  vector < pair <int,int> > movies;

  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    movies.push_back({a,b});
  }

  sort(movies.begin(),movies.end(),cmp);
  pair <int,int> atual = movies[0];
  int resp = 1;

  for(int i=1;i<n;i++){
    if(movies[i].first >= atual.second){
      resp++;
      atual = movies[i];    
    }  
  }

  cout << resp << endl;



  return 0;
}