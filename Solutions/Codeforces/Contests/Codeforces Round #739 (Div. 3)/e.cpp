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

  int T;
  cin >> T;
  while(T--){
    string t;
    cin >> t;
    stack <char> p;
    set <char> S;
    vector <int> freq(26, 0);
    for(int i=t.size()-1;i>=0;i--){
      if(S.count(t[i]) == 0){
        S.insert(t[i]);
        p.push(t[i]);
      }
      freq[t[i]-'a']++;
    }
      
    string ord_rem;
    while(!p.empty())
      ord_rem.push_back(p.top()), p.pop();
    
    bool can = true;

    int pref_len = 0;
    for(int i=0;i<ord_rem.size();i++){
      if(freq[ord_rem[i]-'a']%(i+1) != 0){
        can = false;
        break;
      }
      pref_len += (freq[ord_rem[i]-'a']/(i+1));
    }
    if(!can){
      cout << -1 << endl;
      continue;
    }

    string s = t.substr(0, pref_len);
    vector <int> freq_s(26, 0);
    for(char c:s)
      freq_s[c-'a']++;
    string check_t = s;
    for(int i=0;i<ord_rem.size();i++){
      freq_s[ord_rem[i]-'a'] = 0;
      for(char c:s)
        if(freq_s[c-'a'] > 0)
          check_t += c;
    }
    if(check_t == t){
      cout << s << " " << ord_rem << endl;
    }else
      cout << -1 << endl;
  }

  return 0;
}