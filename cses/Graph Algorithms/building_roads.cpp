#include <bits/stdc++.h>

using namespace std;

int n,m;
const int nax = 1e5 + 5;
int pai[nax];
int comp;

int find(int x){
  if(pai[x]==x) return x;
	return pai[x]=find(pai[x]); 
}

void Union(int x,int y){
  pai[find(x)]=find(y);
}

void initUnionFind(){
  for(int i=1;i<=n;i++){
    pai[i] = i;
  }
}

int main(){

  cin >> n >> m;
  comp = n;

  initUnionFind();

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    if(find(a) != find(b)){
      Union(a,b);
      comp--;
    }
  }

  cout << comp-1 << endl;
  set <int> pais;

  for(int i=1;i<=n;i++){
    pais.insert(find(i));
  }

  set <int> :: iterator it;
  set <int> :: iterator it2;
  it2 = pais.begin();
  it2++;

  for(it = pais.begin();it2!=pais.end();it++,it2++){
    cout << *it << " " << *it2 << endl;
  }

  return 0;
}