#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector < stack<string> > piles;

bool match(string a, string b){
  return a[0] == b[0] || a[1] == b[1];
}

void solve(){
  bool canMove = true;

  while(canMove){
    canMove = false;

    int n = piles.size();

    for(int i=0;i<n;i++){
      if(i>=3 && match(piles[i-3].top(),piles[i].top())){
        piles[i-3].push(piles[i].top());
      }else if(i >= 1 && match(piles[i-1].top(),piles[i].top())){
        piles[i-1].push(piles[i].top());
      }else continue;
      piles[i].pop();
      if(piles[i].size() == 0)
        piles.erase(piles.begin() + i);
      
      canMove = true;
      break;
    }
  }

}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  while(true){
    piles.clear();
    bool eof = false;
    string s;
    for(int i=0;i<52;i++){
      cin >> s;
      if(s == "#"){
        eof = true;
        break;
      }
      stack <string> aux;
      aux.push(s);
      piles.push_back(aux);
      solve();
    }

     if(eof)
      break;

    int n = piles.size();
  if(n == 1)
    cout << n << " pile remaining: ";
  else
    cout << n << " piles remaining: ";

  for(int i=0;i<n;i++){
    int len = piles[i].size();

    if(i == n-1)
      cout << len << endl;
    else
      cout << len << " ";
  }

  }
  
  return 0;
}