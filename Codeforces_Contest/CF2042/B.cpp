#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],t[N],c[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<=n;i++)t[i]=c[i]=0;
        for(int i=1;i<=n;i++)cin>>a[i],++t[a[i]];
        for(int i=1;i<=n;i++)if(t[i])++c[t[i]];
        int s=(c[1]+1)/2*2;
        for(int i=2;i<=n;i++)s+=c[i];
        printf("%d\n",s);
    }
    return 0;
}


