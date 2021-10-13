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

int n;
vi matrix;
int dp[11][11];
int parentheses[11][11];

int solve(int i,int j){

  if(i == j)
    return 0;
    
  int& state = dp[i][j];

  if(state != -1)
    return state;

  int mn = INT_MAX;
  int bestK = i;

  for(int k=i;k<j;k++){
    int val = solve(i,k) + solve(k+1,j) + matrix[i-1]*matrix[k]*matrix[j];
    if(val < mn){
      mn = val;
      bestK = k;
    }
  }
  parentheses[i][j] = bestK;
  return state = mn;
}

string findEq(int i,int j){
  if(i == j)
    return "A" + to_string(i);

  int k = parentheses[i][j];
  return "(" + findEq(i,k) + " x " + findEq(k+1,j) + ")"; 
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int ncase = 1;

  while(cin >> n && n){
    cout << "Case " << ncase++ << ": ";

    matrix.resize(n+1);
    memset(dp,-1,sizeof dp);
    memset(parentheses,-1,sizeof parentheses);

    for(int i=0;i<n;i++){
      cin >> matrix[i] >> matrix[i+1];
    }

    solve(1,n);
    string ans = findEq(1,n);

    cout << ans << endl;
  }

  return 0;
}