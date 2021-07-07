#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;
unordered_map <int, int> freq;

vector <int> inp;

bool solve (int l, int r)
{
	if (r - l <= 1) return true;
	int i;
  freq.clear();
	for (i = l; i < r; ++i)
		freq[inp[i]]++;
	vector <pair <int, int>> idx;
	for (i = l; i < r; ++i)
		if (freq[inp[i]] == 1)
			break;
	if (i >= r) return false;
	idx.push_back ({l, i});
	for (; i < r; ++i)
		if (freq[inp[i]] == 1)
			idx.push_back ({idx.back ().s + 1, i});
	idx.push_back ({idx.back ().s + 1, r});
	bool can = true;
	for (i = 0; i < idx.size (); ++i)
		can = can && solve (idx[i].f, idx[i].s);
	return can;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> n;
	inp.resize (n);
	trav (a, inp) cin >> a;
	if (solve (0, n)) cout << "Y\n";
	else cout << "N\n";

	return 0;
}

