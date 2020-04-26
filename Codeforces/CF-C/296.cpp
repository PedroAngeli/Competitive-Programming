#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e5 + 5;
int op_starting_at[nax];
int op_number_of_uses[nax];
long long a[nax];
long long array_change_starting_at[nax];
long long amount_to_add[nax];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k;
  cin >> n >> m >> k;

  for(int i=1;i<=n;i++)
    cin >> a[i];

  vector <pair<pair<int,int>,long long> > operations(m+1);

  for(int i=1;i<=m;i++){
    cin >> operations[i].first.first >> operations[i].first.second >> operations[i].second;
  }

  for(int i=0;i<k;i++){
    int l,r;
    cin >> l >> r;
    op_starting_at[l]++;
    op_starting_at[r+1]--;
  }

  op_number_of_uses[1] = op_starting_at[1];

  for(int i=2;i<=m;i++){
    op_number_of_uses[i] = op_starting_at[i] +  op_number_of_uses[i-1];
  }

  for(int i=1;i<=m;i++){
    int l = operations[i].first.first;
    int r = operations[i].first.second;
    long long d = operations[i].second;

    array_change_starting_at[l] += d*op_number_of_uses[i];
    array_change_starting_at[r+1] -= d*op_number_of_uses[i];
  }

  amount_to_add[1] = array_change_starting_at[1];

  for(int i=2;i<=n;i++)
    amount_to_add[i] = array_change_starting_at[i] + amount_to_add[i-1];

  for(int i=1;i<=n;i++)
    cout << a[i] + amount_to_add[i] << " ";

  cout << endl;

  return 0;
}