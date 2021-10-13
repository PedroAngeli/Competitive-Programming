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

int cur_line;
ll reg[8];
bool find_exit;

ll val(string r){
  return reg[r[1] - '0'];
}

void mov(string rx, ll num){
  reg[rx[1] - '0'] = num;
}

void mov(string rx, string ry){
  reg[rx[1] - '0'] = val(ry);
}

void add(string rx, string ry, string rz){
  reg[rx[1] - '0'] = val(ry) + val(rz);
}

void sub(string rx, string ry, string rz){
  reg[rx[1] - '0'] = val(ry) - val(rz);
}

void mul(string rx, string ry, string rz){
  reg[rx[1] - '0'] = val(ry) * val(rz);
}

void div(string rx, string ry, string rz){
  reg[rx[1] - '0'] = val(ry) / val(rz);
}

void mod(string rx, string ry, string rz){
  reg[rx[1] - '0'] = (val(ry) + val(rz))%val(rz);
}



void process(string a){
  stringstream ss(a);
  string op, ry, rx, rz;
  ss >> op;

  transform(op.begin(), op.end(), op.begin(), ::toupper); 

  if(op == "MOV"){
    ss >> rx >> ry;
    try{
      ll num = stoi(ry);
      mov(rx, num);
    }catch(...){
      mov(rx, ry);
    }
  }

  if(op == "ADD"){
    ss >> rx >> ry >> rz;
    add(rx, ry, rz);
  }

  if(op == "SUB"){
    ss >> rx >> ry >> rz;
    sub(rx, ry, rz);
  }

  if(op == "MUL"){
    ss >> rx >> ry >> rz;
    mul(rx, ry, rz);
  }

  if(op == "DIV"){
    ss >> rx >> ry >> rz;
    div(rx, ry, rz);
  }

  if(op == "MOD"){
    ss >> rx >> ry >> rz;
    mod(rx, ry, rz);
  }

  if(op == "BEQ"){
    int endereco;
    ss >> rx >> ry >> endereco;
    if(val(rx) == val(ry)){
      cur_line = endereco;
      return;
    }
  }

  if(op == "BLT"){
    int endereco;
    ss >> rx >> ry >> endereco;
    if(val(rx) < val(ry)){
      cur_line = endereco;
      return;
    }
  }

  if(op == "JMP"){
    int endereco;
    ss >> endereco;
    cur_line = endereco;
    return;
  }

  if(op == "EXIT"){
    find_exit = true;
    return;
  }

  if(op == "PRINT"){
      ss >> rx;
      cout << val(rx) << endl;
  }

  cur_line++;  
}

int main(){
  fastio;

  int n;
  cin >> n;
  string l;
  getline(cin, l);

  vs lines(n);
  
  for(int i=0;i<n;i++) getline(cin, lines[i]);

  for(int i=0;i<1e5;i++){
    process(lines[cur_line]);
    if(find_exit) return 0;
  }
  
  cout << "laco infinito!" << endl;

  return 0;
}