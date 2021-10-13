#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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


int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    string s;
    cin >> s;
    //2, 3, 5 e 7
    //1, 4, 6, 8, 9
    vector <int> freq(10, 0);
    for(int i=0;i<k;i++)
      freq[s[i] - '0']++;
    
    if(freq[1])
      cout << "1\n1" << endl;
    else if(freq[4])
      cout << "1\n4" << endl;
    else if(freq[6])
      cout << "1\n6" << endl;
    else if(freq[8])
      cout << "1\n8" << endl;
    else if(freq[9])
      cout << "1\n9" << endl;
    else{
      vector <string> p = {"22", "25", "27", "32", "33", "35",
                          "52", "55", "57", "72", "75", "77"};
      cout << 2 << endl;
      for(int i=0;i<p.size();i++){
        int p1 = 0;
        int p2 = 0;
        while(p1 < p.size() and p2 < k){
          if(s[p2] == p[i][p1])
            p1++;
          p2++;
        }

        if(p1 == 2){
          cout << p[i] << endl;
          break;
        }
      }
    }
  
  }
  
  return 0;
}