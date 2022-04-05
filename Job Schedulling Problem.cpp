#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
    int deadline;
    int profit;
};

bool comparison(Job a, Job b)
{
	if(a.profit == b.profit){
        return a.deadline < b.deadline;
	}            
            
    return a.profit > b.profit;
}

int JobScheduling(Job arr[], int n)
{
	sort(arr, arr+n, comparison);

	int hasil=0; 
	bool slot[n]; 

	for (int i=0; i<n; i++){
		slot[i] = false;
    }
	
	for (int i=0; i<n; i++)
	{
    	for (int j=min(n, arr[i].deadline)-1; j>=0; j--)
    	{
    		if (slot[j]==false)
    		{
    			hasil += arr[i].profit;
    			slot[j] = true;
    			break;
    		}
    	}
	}
    return hasil;
}

int main()
{
	int N;
	cin >> N;
	struct Job arr[N];
	for (int i=0; i<N; i++){
	    cin >> arr[i].deadline >> arr[i].profit;
	}

	cout << JobScheduling(arr, N) << endl;
	return 0;
}
