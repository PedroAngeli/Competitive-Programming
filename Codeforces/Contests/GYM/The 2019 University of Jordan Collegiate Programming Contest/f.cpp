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

const int nax = 3e4 + 5;
int x[nax], y[nax], a[nax], r[nax];

ld L[nax], R[nax];
const ld EPS = 1e-9;
const ld PI = acos(-1);
 
bool eq(ld x, ld y){ //x == y
  return fabs(x - y) < EPS;
}
 
bool lte(ld x,ld y){ //x <= y
  return x < y + EPS;
}
 
bool lt(ld x,ld y){ // x < y
  return x + EPS < y; 
}
 
bool gt(ld x,ld y){ //x > y
  return !lte(x, y);
}
 
bool gte(ld x, ld y){ //x >= y
  return !lt(x,y);
}
 
 
// -------------------------------
// Class to represent a graph 
class Graph { 
    // No. of vertices' 
    int V; 
  
    // Pointer to an array containing 
    // adjacency listsList 
    list<int>* adj; 
  
public: 
    // Constructor 
    Graph(int V); 
  
    // Function to add an edge to graph 
    void addEdge(int u, int v); 
  
    // prints a Topological Sort of 
    // the complete graph 
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
} 
  
// The function to do 
// Topological Sort. 
void Graph::topologicalSort() 
{ 
    // Create a vector to store 
    // indegrees of all 
    // vertices. Initialize all 
    // indegrees as 0. 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists 
    // to fill indegrees of 
    // vertices.  This step 
    // takes O(V+E) time 
    for (int u = 0; u < V; u++) { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); 
             itr != adj[u].end(); itr++) 
            in_degree[*itr]++; 
    } 
  
    // Create an queue and enqueue 
    // all vertices with indegree 0 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store 
    // result (A topological 
    // ordering of the vertices) 
    vector<int> top_order; 
  
    // One by one dequeue vertices 
    // from queue and enqueue 
    // adjacents if indegree of 
    // adjacent becomes 0 
    while (!q.empty()) { 
        // Extract front of queue 
        // (or perform dequeue) 
        // and add it to topological order 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        // Iterate through all its 
        // neighbouring nodes 
        // of dequeued node u and 
        // decrease their in-degree 
        // by 1 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); 
             itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, 
            // add it to queue 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) { 
        cout << "-1\n";
        return; 
    } 
  
    // Print topological order 
    for (int i = 0; i < top_order.size(); i++) 
        cout << top_order[i] + 1 << " "; 
    cout << '\n'; 
} 
// -------------------------------


int main(){
  fastio;

	int n;
	cin >> n;
	Graph G (n);
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i] >> a[i] >> r[i];
		L[i] = (a[i]-r[i]+360)%360;
		R[i] = (a[i]+r[i])%360;
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(i==j)continue;
			int dx=x[j]-x[i], dy=y[j]-y[i];
			double ang=atan2(dy,dx);
			if(ang<0)
				ang+=2*PI;
			ang*=180/PI;
			if(L[i] > R[i]){
				 if(gte(ang, L[i]) or gte(R[i], ang)) G.addEdge(i, j);
			}
			else if(gte(ang, L[i]) and gte(R[i], ang)) G.addEdge(i, j);
		}
	
  G.topologicalSort ();
  return 0;
}