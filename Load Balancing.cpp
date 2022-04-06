#include <cstdio>
#include <algorithm>
using namespace std;
 
int main()
{
    const int maxn = 100005;
    int a[maxn];
    int n;
    int sum = 0;
    int low, high;
    int jwb1 = 0, jwb2 = 0;
    scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        
        if(sum%n!=0)
        {
            low=sum/n;
            high=low+1;
        }
        else
        {
            low=high=sum/n;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]<low) jwb1+=low-a[i];
            if(a[i]>high) jwb2+=a[i]-high;
        }   
        printf("%d\n",max(jwb1, jwb2));
    
    return 0;
}