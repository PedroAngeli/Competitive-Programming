#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

map <char, int> matches;
string roman[4000];

int main(){
  fastio;
  matches['I'] = 1;
  matches['V'] = 2;
  matches['X'] = 2;
  matches['L'] = 2;
  matches['C'] = 2;
  matches['D'] = 3;
  matches['M'] = 4;

  roman[1] = "I";  
  roman[2] = "II";  
  roman[3] = "III";  
  roman[4] = "IV";  
  roman[5] = "V";  
  roman[6] = "VI";  
  roman[7] = "VII";  
  roman[8] = "VIII";  
  roman[9] = "IX";  
  roman[10] = "X";  
  roman[20] = "XX";  
  roman[30] = "XXX";  
  roman[40] = "XL";  
  roman[50] = "L";  
  roman[60] = "LX";  
  roman[70] = "LXX";  
  roman[80] = "LXXX";  
  roman[90] = "XC";  
  roman[100] = "C";  
  roman[200] = "CC";  
  roman[300] = "CCC";  
  roman[400] = "CD";  
  roman[500] = "D";  
  roman[600] = "DC";  
  roman[700] = "DCC";  
  roman[800] = "DCCC";  
  roman[900] = "CM";  
  roman[1000] = "M";  
  roman[2000] = "MM";  
  roman[3000] = "MMM";  
  
  int n;
  while(cin >> n){
    string number = to_string(n);
    string conversion = "";
    for(int i=0;i<sz(number);i++){
      int idx = (number[i] - '0')*pow(10, sz(number) - i - 1);
      conversion += roman[idx];
    }
    int ans =0 ;
    for(auto c:conversion)
      ans += matches[c];

    cout << ans << endl;
  }
  return 0;
}