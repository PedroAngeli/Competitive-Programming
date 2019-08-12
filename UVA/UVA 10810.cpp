#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 500123

int vet[MAXN];
int aux[MAXN];
long long int count;

void Merge(int inicio,int fim)
{
	int j = (inicio+fim)/2 + 1;
	int k = 0;
	int meio = (inicio+fim)/2;
	int i=inicio;

	while(i<=meio && j<=fim)
	{
		if(vet[j] < vet[i])
		{
			aux[k++] = vet[j++];
			count+=(meio-i+1);
		}
		else aux[k++] = vet[i++];
	}
	
	while(i<=meio)
		aux[k++]=vet[i++];
	
	while(j<=fim)
		aux[k++] = vet[j++];

	
	for(int i = inicio;i<=fim;i++)
		vet[i] = aux[i-inicio];

}

void mergeSort(int inicio,int fim)
{
	if(inicio == fim) return;
	mergeSort(inicio,(inicio+fim)/2);
	mergeSort((inicio+fim)/2 + 1,fim);
	
	Merge(inicio,fim);
}
int main()
{

	int n;

	while(scanf("%d",&n) == 1 && n)
	{
		count = 0;
		int fim = n-1;
		int i = 0;

		while(n--)
			scanf("%d",&vet[i++]);

		mergeSort(0,fim);

		printf("%lld\n",count);
	}

}
