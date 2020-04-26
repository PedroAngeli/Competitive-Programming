#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e5 + 5;
int parent[nax];
int qtd[nax];
int r[nax];

int Find(int x){
  if(parent[x] == x)
    return x;

  return parent[x] = Find(parent[x]);
}

int Union(int x,int y){
  x = Find(x);
  y = Find(y);

  if(x != y){
    if(r[x] < r[y]){
      parent[x] = y;
      qtd[y]+=qtd[x];
      return qtd[y];
    }else if(r[x] > r[y]){
      parent[y] = x;
      qtd[x]+=qtd[y];
      return qtd[x];
    }else{
      parent[x] = y;
      r[y]++;
      qtd[y] += qtd[x];
      return qtd[y];
    }
  }

  return qtd[x];
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    for(int i=0;i<nax;i++){
       parent[i] = i;
       qtd[i] = 1;
       r[i] = 0;
    }

    map <string,int> person;
    int x = 0;

    while(n--){
      string s1, s2;
      cin >> s1 >> s2;
      if(!person.count(s1))
        person[s1] = x++;

      if(!person.count(s2))
        person[s2] = x++;

      cout << Union(person[s1],person[s2]) << endl;
    }

  }

  return 0;
}