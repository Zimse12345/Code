#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],b[N];
map<int,int> mp;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!mp[a[i]])b[i]=-1;
        else b[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    printf("\n");
    return 0;
}


