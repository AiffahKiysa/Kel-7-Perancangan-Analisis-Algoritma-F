#include <bits/stdc++.h>
using namespace std;

long getNumberOfWays(long N, vector<long> Coins)
{
	vector<long> ways(N + 1);
	ways[0] = 1;

	for(int i = 0; i < Coins.size(); i++)
	{
		
		for(int j = 0; j < ways.size(); j++)
		{
			if (Coins[i] <= j)
			{
				
				ways[j] += ways[(j - Coins[i])];
			}
		}
	}

	return ways[N];
}

void printArray(vector<long> coins)
{
	for(long i : coins)
		cout << i << "\n";
}

int main()
{
	vector<long> Coins;
    int num,n,goal;
    cin>>goal;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin >> num;
        Coins.push_back(num);
    }

	cout << "The Coins Array:" << endl;
	printArray(Coins);
	
	cout << "Solution:" << endl;
	cout << getNumberOfWays(goal, Coins) << endl;
}

