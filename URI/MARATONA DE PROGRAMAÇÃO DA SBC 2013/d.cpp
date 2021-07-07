#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

vi goal;

vi dobrar(vi vet,int i,int n){

  vi newVet(max(i+1,n-i-1));

  int j = i;
  int k = i+1;
  int m = newVet.size()-1;

  while(j >= 0 && k < n){
    newVet[m] = vet[j] + vet[k];
    m--;
    j--;
    k++;
  }

  while(j >= 0)
    newVet[m] = vet[j],j--,m--;
  
  while(k < n)
    newVet[m] = vet[k],k++,m--;

  return newVet;
}

bool equal(vi a,vi b){
  for(int i=0;i<a.size();i++)
    if(a[i] != b[i])
      return false;

  return true;
}

bool solve(vi cur){
  int n = cur.size();
  int m = goal.size();

  if(n < m)
    return false;

  if(n == m){
    bool a = equal(cur,goal);
    reverse(all(cur));
    bool b = equal(cur,goal);

    return a || b;
  }

  bool ret = false;

  for(int i=0;i<n-1;i++){
    ret = (ret || solve(dobrar(cur,i,n)));
    if(ret)
      break;  
  }

  return ret;
}

int main(){
  fastio;

  int n;
  while(cin >> n){
    vi maq(n);
    for(int i=0;i<n;i++)
      cin >> maq[i];
    int m;
    cin >> m;
    goal.resize(m);
    for(int i=0;i<m;i++)
      cin >> goal[i];

    bool can = solve(maq);

    if(can)
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }

  return 0;
}