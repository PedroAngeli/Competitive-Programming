#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

struct Trie{
    Trie *l, *r;
};
Trie *create_node(){
    Trie *node = (Trie*)malloc(sizeof (Trie));
    node->l = NULL;
    node->r = NULL;
    return node;
}
void insert(int i, int n, Trie *node){
    if (i < 0 ) return ;
    int on = (1 << i) & n;
    if (!on){
        if (node->l == NULL) node->l = create_node();
        insert(i-1, n, node->l);
    }
    else {
        if (node->r == NULL) node->r = create_node();
        insert(i-1, n, node->r);
    }
}
int ans;
void query(int i, int x, Trie *node){
    if (i < 0) return ;
    int on = (1<<i) & x;
    if (on){
        if (node->l) ans += 1 << i, query(i-1, x, node->l);
        else query(i-1, x, node->r);
    }
    else {
        if (node->r) ans += 1 << i, query(i-1, x, node->r);
        else query(i-1, x, node->l);
    }
}

Trie* remove(int i, int x, Trie *node){
    if (node == NULL or i < 0) return NULL;
    if (node->l == NULL and node->r == NULL){
        return NULL;
    }
    int on = (1 << i) & x;
    if (!on){
        node->l = remove(i-1, x, node->l);
    }
    else node->r = remove(i-1, x, node->r);

    if (node->l == NULL and node->r == NULL)
      return NULL;
      
    return node;
}
void print(int i, Trie *node){
    if (i < 0 ) return ;
    if (node->l) print(i-1, node->l),
    cout << i << ": 0" << endl;
    if (node->r) print(i-1, node->r), cout << i << ": 1" << endl;
}
int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
    Trie *root = create_node();
    map<int, int> mp;
    insert(31, 0, root);
	while (tc--)
	{
		ll i, j, n, q;
		cin >> q;
        while (q--){
            char op;
            int x;
            cin >> op >> x;
            if (op == '+'){
                mp[x]++;
                insert(31, x, root);
            }
            else if (op == '?') {
                ans = 0;
                query(31, x, root);
                cout << ans << '\n';
            }
            else {
                
                if (mp[x] == 1){
                    root = remove(31, x, root);
                    mp[x] = 0;
                }
                else
                    mp[x]--;
                // print(31, root);
            }
        }
	}

	return 0;
}

