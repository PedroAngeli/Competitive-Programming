#include <bits/stdc++.h>

using namespace std;

const int nax = 1e6;

class SegmentTree{
  private:
    vector <int> st;
    vector <int> original_vet;
    int sz;
    int left(int i){ return i*2 + 1;}
    int right(int i) {return i*2 + 2;}

    bool build(int l, int r, int pos){ //op == 1 -> or, op == 0 -> xor
      if(l == r){
        st[pos] = original_vet[l];
        return true;
      }

      int m = (l+r)/2;

      bool op = build(l,m,left(pos));
      build(m+1,r,right(pos));
      
      int f1 = st[left(pos)];
      int f2 = st[right(pos)];

      if(op){
        st[pos] = f1 | f2;
        return false; 
      }else{
        st[pos] = f1 ^ f2; 
        return true;
      }
    }

    int update(int l,int r,int pos, int index, int num){ //op == 2 -> xor
      if(index < l || index > r){ 
        return -1;
      }

      if(l == r){ 
        original_vet[l] = num;
        st[pos] = num;
        return 1;
      }

      int m = (l+r)/2;

      int op1 = update(l,m,left(pos),index,num);
      int op2 = update(m+1,r,right(pos),index,num);

      int f1 = st[left(pos)];
      int f2 = st[right(pos)];

      if(op1 == -1){
        if(op2 == 1){
          st[pos] = f1 | f2;
          return 2;
        }else{
          st[pos] = f1 ^ f2;
          return 1;
        }
      }else{
        if(op1 == 1){
          st[pos] = f1 | f2;
          return 2;
        }else{
          st[pos] = f1 ^ f2;
          return 1;
        }
      }
    }
  public:
    SegmentTree(vector <int> &A){
      original_vet = A;
      sz = A.size();

      st.assign(4*sz,0);

      build(0,sz-1,0);
    }

    int query(){
     return st[0];
    }

    void update(int index, int num){
      update(0,sz-1,0,index,num);
    }
};

int main(){

  int n, m;

  cin >> n >> m;

  int tam = pow(2,n);

  vector <int> vet(tam);

  for(int i=0;i<tam;i++){
    cin >> vet[i];
  }

  SegmentTree *st = new SegmentTree(vet);
  
  for(int i=0;i<m;i++){
    int p,b;
    cin >> p >> b;
    st->update(p-1,b);
    cout << st->query() << endl;
  }


  return 0;
}