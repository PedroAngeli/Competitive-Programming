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

int solCnt;
    int x,y;

bool can(int r,int c,vector <int>&row){
  for(int i=1;i<c;i++){
    if(r == row[i] || (r+c == row[i]+i) || (r-c == row[i]-i))
      return false;
  }
  return true;
}

void solve(int col, vector <int>&row){
  if(col == 9 && row[y] == x){
    cout.width(2);
    cout << ++solCnt << "      ";
    for(int i=1;i<=8;i++){
      if(i == 8)
        cout << row[i] << endl;
      else
        cout << row[i] << " ";
    }
    return;
  }
 
  for(int i=1;i<=8;i++){
    if(can(i,col,row)){
      row[col] = i;
      solve(col+1,row);
    }
  }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    solCnt = 0;
    cin >> x >> y;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
    vector <int> row(9,0);
    row[y] = x;
    solve(1,row);
    if(t)
      cout << endl;
  }

  return 0;
}