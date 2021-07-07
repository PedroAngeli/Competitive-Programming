#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

int n;
bool same(vector <string> v1,vector <string> v2){
    for(int i=0;i<n;i++)
      if(v1[i] != v2[i])
        return false;
    return true;
}

vector <string> rotate90(vector <string> v){
  vector <string> ret(n,string(n,'.'));

  int l = n-1;
  for(int i=0;i<n;i++){
    int k = 0;
    for(int j=0;j<n;j++){
      ret[k][l] = v[i][j];
      k++;
    }
    l--;
  }

  return ret;
}

vector <string> rotate180(vector <string> v){
  return rotate90(rotate90(v));
}

vector <string> rotate270(vector <string> v){
  return rotate90(rotate90(rotate90(v)));
}

vector <string> vertical(vector<string> v){
  vector <string> ret(n,string(n,'.'));

  int k = n-1;
  for(int i=0;i<n;i++){
    int l = 0;
    for(int j=0;j<n;j++){
      ret[k][l] = v[i][j];
      l++;
    }
    k--;
  }

  return ret;
}

int main(){
  fastio;

  int ncase = 1;

  while(cin >> n){
    cout << "Pattern " << ncase++ << " was ";
    vector <string> original(n);
    vector <string> transformed(n);

    for(int i=0;i<n;i++)
      cin >> original[i] >> transformed[i];
    
    if(same(original,transformed)){
      cout << "preserved." << endl;
    }else if(same(rotate90(original),transformed)){
      cout << "rotated 90 degrees." << endl;
    }else if(same(rotate180(original),transformed)){
      cout << "rotated 180 degrees." << endl;
    }else if(same(rotate270(original),transformed)){
      cout << "rotated 270 degrees." << endl;
    }else if(same(vertical(original),transformed)){
      cout << "reflected vertically." << endl;
    }else if(same(rotate90(vertical(original)),transformed)){
      cout << "reflected vertically and rotated 90 degrees." << endl;
    }else if(same(rotate180(vertical(original)),transformed)){
      cout << "reflected vertically and rotated 180 degrees." << endl;
    }else if(same(rotate270(vertical(original)),transformed)){
      cout << "reflected vertically and rotated 270 degrees." << endl;
    }else{
      cout << "improperly transformed." << endl;
    }
  }
  return 0;
}