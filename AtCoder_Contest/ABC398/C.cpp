#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N];
map<int,int> mp;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]=i;
    sort(a+1,a+n+1);
    a[0]=a[n+1]=-1;
    for(int i=n;i>=1;i--){
        if(a[i]!=a[i+1]&&a[i]!=a[i-1]){
            printf("%d\n",mp[a[i]]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}


