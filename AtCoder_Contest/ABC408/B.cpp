#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1;i<=n;i++)if(a[i]!=a[i-1])++sum;
    printf("%d\n",sum);
    for(int i=1;i<=n;i++)if(a[i]!=a[i-1])printf("%d ",a[i]);
    return 0;
}


