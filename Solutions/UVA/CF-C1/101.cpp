#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector <vi> ans(n);
  vi curPile(n);
  for(int i=0;i<n;i++)
    ans[i].push_back(i),curPile[i]=i;

  string t1;

  while(cin >> t1){

    if(t1 == "quit")
      break;
    int a,b;
    string t2;
    cin >> a >> t2 >> b;

    if(curPile[a] == curPile[b])
      continue;
    
    if(t1 == "move"){
       while(ans[curPile[a]].back() != a){
         int curTop = ans[curPile[a]].back();
          ans[curTop].push_back(curTop);
          curPile[curTop] = curTop;
          ans[curPile[a]].pop_back();
      }
      ans[curPile[a]].pop_back();
      curPile[a] = curPile[b];
      if(t2 == "onto"){
        while(ans[curPile[b]].back() != b){
          int curTop = ans[curPile[b]].back();
          ans[curTop].push_back(curTop);
          curPile[curTop] = curTop;
          ans[curPile[b]].pop_back();
        }
      }
      ans[curPile[b]].push_back(a);
    }else{
        vi aux;
        while(ans[curPile[a]].back() != a){
            aux.push_back(ans[curPile[a]].back());
            ans[curPile[a]].pop_back();
        }
        aux.push_back(ans[curPile[a]].back());
        ans[curPile[a]].pop_back();

        if(t2 == "onto"){
          while(ans[curPile[b]].back() != b){
          int curTop = ans[curPile[b]].back();
          ans[curTop].push_back(curTop);
          curPile[curTop] = curTop;
          ans[curPile[b]].pop_back();
          }
        }
      while(aux.size() > 0){
        curPile[aux.back()] = curPile[b];
        ans[curPile[b]].push_back(aux.back());
        aux.pop_back();
      }
    }
  }
  
  for(int i=0;i<n;i++){
    cout << i << ":";
    for(int j=0;j<ans[i].size();j++)
      cout << " " << ans[i][j];
    cout << endl;
  }

  return 0;
}