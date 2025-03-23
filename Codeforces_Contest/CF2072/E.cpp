#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,k,ans[N],n;

signed main(){
    cin>>T;
    while(T--){
        cin>>k;
        n=0;
        int v=0;
        while(k){
            ++v;
            int x=1;
            while((x+1)*x/2<=k)++x;
            k-=(x-1)*x/2;
            while(x--)ans[++n]=v;
        }
        printf("%d\n",n);
        for(int i=1;i<=n;i++)printf("%d %d\n",ans[i],i);
    }
    return 0;
}


