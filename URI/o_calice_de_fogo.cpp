#include <bits/stdc++.h>

using namespace std;

const long long maxprime = 1e7 + 5;
const long long mod = 1e9 + 7;
bitset <maxprime> is_prime;
vector <long long> primes;
vector <pair <long long,long long> > factors;

class SegmentTree{
  private:
    vector <long long> st;
    vector <long long> original_vet;
    long long sz;
    long long left(long long i){ return i*2 + 1;}
    long long right(long long i) {return i*2 + 2;}

    void build(long long l, long long r,long long pos){
    if(l==r){
      st[pos] = original_vet[l];
      return;
    }

    long long m = (l+r)/2;

    build(l,m,left(pos));
    build(m+1,r,right(pos));

    long long f1 = st[left(pos)];
    long long f2 = st[right(pos)];

    st[pos] = ((f1 % mod) * (f2 % mod)) % mod;
  }
  long long query(long long ql, long long qr,long long l,long long r, long long pos){
     if(ql <= l && qr >= r){ 
        return st[pos];
      }

      if(ql > r || l > qr){ 
        return -1; 
      }

      long long m = (l+r)/2;

      long long f1 = query(ql,qr,l,m,left(pos));
      long long f2 = query(ql,qr,m+1,r,right(pos));

      if(f1 == -1) return f2;  
      if(f2 == -1) return f1;

      return ((f1 % mod) * (f2 % mod)) % mod;
  }
  void update(long long l, long long r, long long pos, long long index,long long delta){
    
    if(index < l || index > r){ 
        return;
      }

    if(l == r){
        original_vet[l] += delta;
        st[pos] = original_vet[l];
    
        return;
      }

    long long mid = (l+r)/2;

    update(l,mid,left(pos),index, delta); 
    update(mid+1,r,right(pos),index, delta); 

    int f1 = st[left(pos)];
    int f2 = st[right(pos)];

    st[pos] = ((f1 % mod) * (f2 % mod)) % mod;
  }
  public:
    SegmentTree(vector <long long> &A){
      original_vet = A;
      sz = A.size();

      st.assign(4*sz,1);

      build(0,sz-1,0);
    }

    long long query(long long ql, long long qr){
      return query(ql,qr,0,sz-1,0);
    }

    void update(long long index, long long delta){
      update(0,sz-1,0,index,delta);
    }
};

void SieveOfEratosthenes(){
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;

  for(long long i = 2;i<=maxprime;i++){
    if(is_prime[i]){
      primes.push_back(i);
      for(long long j = i*i;j<=maxprime;j+=i){
        is_prime[j] = 0;
      }
    }
  }
}

void primeFactors(long long N){
  int idx = 0;
  long long pf = primes[idx];
  while(pf*pf <= N){
    long long qtd = 0;
    while(N%pf == 0){
      N /= pf;
      qtd++;
    }
    factors.push_back({pf,qtd});
    pf = primes[++idx];
  }

  if(N != 1){
    factors.push_back({N,1});
  }
}

int main(){

  SieveOfEratosthenes();
  
  long long N;

  scanf("%lld",&N);
  
  primeFactors(N);

  vector <long long> vet(primes.size(),1);

  for(int i=0;i<factors.size();i++){
     long long idx = lower_bound(primes.begin(),primes.end(),factors[i].first) - primes.begin();
    if(i == idx)
    vet[i] = factors[i].second + 1;
  }

  SegmentTree *st = new SegmentTree(vet);
  
  long long p;

  while(scanf("%lld",&p) == 1){

   long long idx = lower_bound(primes.begin(),primes.end(),p) - primes.begin();
   long long resp = st->query(0,idx-1);


  if(idx > 0)
   resp = st->query(0,idx-1);

   st->update(idx,1);

  if(idx == 0)
    cout << "1" << endl;
  else
   cout << resp << endl;
  }

  return 0;
}