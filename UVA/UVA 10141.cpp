#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct 
{
	string company;
	double d;
	int r;
}Proposal;

vector <Proposal> vet;


bool cmp(Proposal a, Proposal b)
{
	if(a.r > b.r) return 1;
	else if(a.r == b.r) return a.d < b.d;

	return 0;
}

int main()
{
	int n,p;
	string paunocu;
	int rpf = 1;
	
	while(scanf("%d %d",&n,&p) == 2 && n)
	{
		if(rpf > 1) printf("\n");
		scanf("%*c");
		for(int i=0;i<n;i++)
		{
			getline(cin, paunocu);
			//cout << paunocu << endl;
		}

		while(p--)
		{
			Proposal proposal;

			getline(cin, proposal.company);
			//cout << proposal.company << endl;

			//scanf("%*c");

			scanf("%lf %d",&proposal.d,&proposal.r);
			scanf("%*c");

			vet.push_back(proposal);

			int r = proposal.r;

			while(r--)
			{
				getline(cin, paunocu);
				//cout << paunocu << endl;
				//scanf("%*c");
			}
		}

		sort(vet.begin(),vet.end(),cmp);
		
		printf("RFP #%d\n",rpf);
		rpf++;

		cout << vet[0].company << "\n";

		vet.clear();
	}

	return 0;
}
