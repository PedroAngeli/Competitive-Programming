#include <bits/stdc++.h>
using namespace std;
  
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
        if (node->r) query(i-1, x, node->r);
        else ans += 1 << i, query(i-1, x, node->l);
    }
    else {
        if (node->l) query(i-1, x, node->l);
        else ans += (1 << i), query(i-1, x, node->r);
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
 

int main (){
	ios_base::sync_with_stdio (0);
	cin.tie (0);

	int n;
  cin >> n;
  vector <int> a(n);
  map<int, int> mp;

  for(int i=0;i<n;i++)
    cin >> a[i];
  
  Trie *root = create_node();

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    mp[x]++;
    insert(31,x,root);
  }

  for(int i=0;i<n;i++){
    ans = 0;
    query(31,a[i],root);
    int x = ans ^ a[i];
    mp[x]--;
    if(mp[x] == 0)
      remove(31,x,root);
    cout << ans << " ";
  }

  cout << endl;

	return 0;
}