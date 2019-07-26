#include <cstdio>

using namespace std;

#define MAXN 100000

int pai[MAXN];
int dist[MAXN];
int altura[MAXN];

long long int resp;

void solve(int u, int v, bool flag)
{
	if (u == v)
		return;

	if (flag)
	{
		resp += dist[u];
		solve(pai[u], v, false);
	}
	else
	{
		resp += dist[v];
		solve(u, pai[v], true);
	}

}

int sobe(int u, int alt)
{
	if (altura[u] == alt)
		return u;

	resp += dist[u];

	return sobe(pai[u], alt);
}

int main()
{
	int n;

	while (scanf("%d", &n) == 1 && n)
	{
		int p, d;

		pai[0] = 0;
		altura[0] = 0;
		dist[0] = 0;

		for (int i = 1; i < n; i++)
		{
			scanf("%d %d", &p, &d);
			pai[i] = p;
			dist[i] = d;
			altura[i] = altura[p] + 1;
		}

		int q;

		scanf("%d", &q);

		for (int i = 0; i < q; i++)
		{
			int u, v;
			resp = 0;
			scanf("%d %d", &u, &v);

			if (altura[u] == altura[v])
				solve(u, v, true);
			else
			{
				int a;

				if (altura[u] > altura[v])
				{
					a = sobe(u, altura[v]);
					solve(a, v, true);
				}
				else
				{
					a = sobe(v, altura[u]);
					solve(u, a, true);
				}
			}

			if(i == q-1) printf("%lld\n", resp);
			else printf("%lld ", resp);
		}
	}
	return 0;
}

