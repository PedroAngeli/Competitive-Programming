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

struct Date{
  int day, month, year;
};

int bi(int year){
  return (year%4 == 0 and year%100) or (year%400 == 0);
}

int table(int month, int year){
  if(month == 1) return 31;
  if(month == 2) return 28 + bi(year);
  if(month == 3) return 31;
  if(month == 4) return 30;
  if(month == 5) return 31;
  if(month == 6) return 30;
  if(month == 7) return 31;
  if(month == 8) return 31;
  if(month == 9) return 30;
  if(month == 10) return 31;
  if(month == 11) return 30;
  if(month == 12) return 31;
  return 0;
}

Date solve(int d){
  Date date;
  date.year = 2021;
  date.month = 1;
  date.day = 1;

  d -= 10;

  while(d){
    int days_of_year = 365;
    if(bi(date.year)) days_of_year++;
    if(days_of_year <= d){
      d -= days_of_year;
      date.year++;
    }else{
      int days_of_month = table(date.month, date.year);
      if(days_of_month <= d){
        d -= days_of_month;
        date.month++;
      }else{
        date.day = d;
        d = 0;
      }
    }
  }

  return date;
}

int main(){
  // fastio;

  int n;
  scanf("%d", &n);

  int dj = floorl((ld)11.9*365.25*n);
  int ds = floorl((ld)29.6*365.25*n);

  Date DJ = solve(dj);
  Date DS = solve(ds);

  printf("Dias terrestres para Jupiter = %d\n", dj);
  printf("Data terrestre para Jupiter: %d-%02d-%02d\n", DJ.year, DJ.month, DJ.day);
  printf("Dias terrestres para Saturno = %d\n", ds);
  printf("Data terrestre para Saturno: %d-%02d-%02d\n", DS.year, DS.month, DS.day);

  return 0;
}