#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector <int> > matriz;
vector < vector <int> > SegTreeMin;
vector < vector <int> > SegTreeMax;
vector <int> node;
vector <int> st;
vector <int> linhaMin;

void buildMinimumNode(int p,int L,int R)
{
	if (L == R) st[p] = L;                                         
    	else 
	{                               
	      buildMinimumNode(2*p , L , (L + R) / 2);
	      buildMinimumNode(2*p + 1, (L + R) / 2 + 1, R);

	      int p1 = st[2*p], p2 = st[2*p + 1];
	      st[p] = (node[p1] <= node[p2]) ? p1 : p2;
	}
}

void buildMaximumNode(int p,int L,int R)
{
	if (L == R) st[p] = L;                                         
    	else 
	{                               
	      buildMaximumNode(2*p , L , (L + R) / 2);
	      buildMaximumNode(2*p + 1, (L + R) / 2 + 1, R);

	      int p1 = st[2*p], p2 = st[2*p + 1];
	      st[p] = (node[p1] >= node[p2]) ? p1 : p2;
	}
}

int RMinQ(int p, int L, int R, int i, int j,int x)
{
	if (i >  R || j <  L) return -1; 
	if (L >= i && R <= j) return SegTreeMin[x][p];   
	     
	int p1 = RMinQ(2*p , L , (L+R) / 2, i, j,x);
	int p2 = RMinQ(2*p + 1, (L+R) / 2 + 1, R  , i, j,x);

	if (p1 == -1) return p2;   
	if (p2 == -1) return p1;                               
	return (linhaMin[p1] <= linhaMin[p2]) ? p1 : p2; 
}

int RMaxQ(int p, int L, int R, int i, int j,int x)
{
	if (i >  R || j <  L) return -1; 
	if (L >= i && R <= j) return SegTreeMax[x][p];   
	     
	int p1 = RMaxQ(2*p , L , (L+R) / 2, i, j,x);
	int p2 = RMaxQ(2*p + 1, (L+R) / 2 + 1, R  , i, j,x);

	if (p1 == -1) return p2;   
	if (p2 == -1) return p1;                               
	return (linhaMin[p1] >= linhaMin[p2]) ? p1 : p2; 
}

int update_MINpoint(int p, int L, int R, int idx, int new_value,int x) 
{
    
    	int i = idx, j = idx;

	if (i > R || j < L) return SegTreeMin[x][p];

	if (L == i && R == j) 
	{
		matriz[x][i] = new_value; 
 		return SegTreeMin[x][p] = L; 
	}

	int p1, p2;
	p1 = update_MINpoint(2*p , L , (L + R) / 2, idx, new_value,x);
	p2 = update_MINpoint(2*p + 1, (L + R) / 2 + 1, R , idx, new_value,x);

   	return SegTreeMin[x][p] = (matriz[x][p1] <= matriz[x][p2]) ? p1 : p2;
}

int update_MAXpoint(int p, int L, int R, int idx, int new_value,int x) 
{
    
    	int i = idx, j = idx;

	if (i > R || j < L) return SegTreeMax[x][p];

	if (L == i && R == j) 
	{
		matriz[x][i] = new_value; 
 		return SegTreeMax[x][p] = L; 
	}

	int p1, p2;
	p1 = update_MAXpoint(2*p , L , (L + R) / 2, idx, new_value,x);
	p2 = update_MAXpoint(2*p + 1, (L + R) / 2 + 1, R , idx, new_value,x);

   	return SegTreeMax[x][p] = (matriz[x][p1] >= matriz[x][p2]) ? p1 : p2;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		node.clear();
		st.resize(4*n,0);

		for(int j=0;j<n;j++)
		{
			int temp;
			scanf("%d",&temp);
			node.push_back(temp);
		}

		matriz.push_back(node);

		buildMinimumNode(1,0,n-1);
		SegTreeMin.push_back(st);

		st.resize(4*n,0);

		buildMaximumNode(1,0,n-1);
		SegTreeMax.push_back(st);
	}

	int q;
	scanf("%d%*c",&q);

	for(int i=0;i<q;i++)
	{
		char op;
		int xl,xr,yl,yr;

		scanf("%c",&op);

		if(op == 'q')
		{
			vector <int> Min;
			vector <int> Max;
			int idx;

			scanf("%d %d %d %d%*c",&xl,&yl,&xr,&yr);

			for(int j = xl-1;j <= xr-1;j++)
			{
				linhaMin = matriz[j];

				idx = RMinQ(1,0,n-1,yl-1,yr-1,j);
				Min.push_back(matriz[j][idx]);

				idx = RMaxQ(1,0,n-1,yl-1,yr-1,j);
				Max.push_back(matriz[j][idx]);
			}

			sort(Min.begin(),Min.end());
			sort(Max.begin(),Max.end());

			printf("%d %d\n",Max[Max.size()-1],Min[0]);
		}
		else
		{
			int x,y,newvalue;
			scanf("%d %d %d%*c",&x,&y,&newvalue);

			linhaMin = matriz[x-1];
			update_MINpoint(1,0,n-1,y-1,newvalue,x-1);
			update_MAXpoint(1,0,n-1,y-1,newvalue,x-1);
		}
	}

}
