#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

const int nax = 1e7+1;
vi mobius;
vi primes;
bitset <nax> is_prime;

int main(){
  fastio;

	mobius.resize(nax);
	is_prime.set();
	mobius[1] = 1;
	for(int i = 2;i<nax;i++){
		if(is_prime[i]){
			primes.pb(i);
			mobius[i] = -1;
		}
		for(int j=0;j<sz(primes) && 1LL*i*primes[j] < nax;j++){
			is_prime[i * primes[j]] = 0;
			if(i % primes[j] == 0){
				mobius[i * primes[j]] = 0;
				break;
			}else{
				mobius[i * primes[j]] = mobius[i] * mobius[primes[j]];
			}
		}
	}

	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	ll ans = 0;
	
	for (int i=1; i<=min(b, d); i++)
		ans += mobius[i]*(b/i)*(d/i);
	
	for (int i=1; i<=min(a-1, d); i++)
		ans -= mobius[i]*((a-1)/i)*(d/i);
	
	for (int i=1; i<=min(b, c-1); i++)
		ans -= mobius[i]*(b/i)*((c-1)/i);
	
	for (int i=1; i<=min(a-1, c-1); i++)
		ans += mobius[i]*((a-1)/i)*((c-1)/i);
	
		
	cout << ans << endl;
  return 0;
}