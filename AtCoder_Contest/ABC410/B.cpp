#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,q,a[N];

signed main(){
    cin>>n>>q;
    a[0]=1e9;
    while(q--){
        int x=0;
        cin>>x;
        if(x){
            ++a[x];
            printf("%d ",x);
        }
        else{
            int p=0;
            for(int i=1;i<=n;i++)if(a[i]<a[p])p=i;
            ++a[p];
            printf("%d ",p);
        }
    }
    return 0;
}


