#include <bits/stdc++.h>

using namespace std;

class FenwickTree{
  private:
    vector <long long> ft;
  public:
    FenwickTree(int n){ 
      ft.assign(n+1,0); 
    }

    long long rsq(int i){ 
      long long sum = 0;

      while(i > 0){
        sum += ft[i];
        i -= (i & -i);
      }

      return sum;
    }

    long long rsq(int i,int j){ 
      return rsq(j) - rsq(i-1);
    }

    void update(int i,int v){ 
      int n = ft.size() - 1;

      while(i <= n){
        ft[i] += v;
        i += (i & -i);
      }
    }
};

int main(){

    int n,q;
    cin >> n >> q;

    FenwickTree *ft = new FenwickTree(n);

    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      ft->update(i+1,x);
    }

    while(q--){
      int v;
      cin >> v;

      if(v==1){
        int i,k;
        cin >> i >> k;
        ft->update(i,k-ft->rsq(i,i));
      }else{
        int a,b;
        cin >> a >> b;
        cout << ft->rsq(a,b) << endl;
      }
    }
   
    
  return 0;
}