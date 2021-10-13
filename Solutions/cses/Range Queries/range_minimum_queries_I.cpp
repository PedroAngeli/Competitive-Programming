#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
  private: 
    vector <int> st;
    vector <int> original_vet;
    int sz;
    int left(int i){ return i*2 + 1;}
    int right(int i) {return i*2 + 2;}

    void build(int l,int r,int pos){ 
      if(l == r){ 
        st[pos] = l;
        return;
      }

      int m = (l+r)/2;

      build(l,m,left(pos));  
      build(m+1,r,right(pos)); 

      int f1 = st[left(pos)];
      int f2 = st[right(pos)];

      st[pos] = original_vet[f1] <= original_vet[f2] ? f1 : f2;
    }

    int rmq(int ql, int qr, int l, int r, int pos){
      if(ql <= l && qr >= r){ 
        return st[pos];
      }

      if(ql > r || l > qr){ 
        return -1; 
      }

      int m = (l+r)/2;

      int f1 = rmq(ql,qr,l,m,left(pos));  
      int f2 = rmq(ql,qr,m+1,r,right(pos)); 

      
      if(f1 == -1) return f2;  
      if(f2 == -1) return f1;

      
      return original_vet[f1] <= original_vet[f2] ? f1 : f2;
    }

    void update(int l,int r,int pos, int index, int delta){ 
      
      if(index < l || index > r){ 
        return;
      }

      if(l == r){ 
        original_vet[l] += delta;
        return;
      }

      int mid = (l+r)/2;

      update(l,mid,left(pos),index, delta); 
      update(mid+1,r,right(pos),index, delta); 

      int f1 = st[left(pos)];
      int f2 = st[right(pos)];

      st[pos] = original_vet[f1] <= original_vet[f2] ? f1 : f2;
    }

  public:
    SegmentTree(vector<int> &A){ 
      original_vet = A;
      sz = A.size();

      st.assign(4*sz,0);

      build(0,sz-1,0);
    }

    int rmq(int ql,int qr){
      return rmq(ql,qr,0,sz-1,0);
    }

    void update(int index, int delta){
      update(0,sz-1,0,index,delta);
    }
};

int main(){

  int n,q;

  cin >> n >> q;

  vector <int> vet(n);

  for(int i=0;i<n;i++){
    cin >> vet[i];
  }

  SegmentTree *st = new SegmentTree(vet);

  while(q--){
    int a,b;
    cin >> a >> b;
    cout << vet[st->rmq(a-1,b-1)] << endl;
  }

  return 0;
}