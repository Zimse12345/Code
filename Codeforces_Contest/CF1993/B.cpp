#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a,b,x[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        a=b=0;
        int mx=0,mxb=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(x[i]&1)++a,mx=max(mx,x[i]);
            else ++b,mxb=max(mxb,x[i]);
        }
        if(!a||!b)printf("0\n");
        else{
            sort(x+1,x+n+1);
            for(int i=1;i<=n;i++)if(x[i]%2==0){
                if(mx<x[i]){
                    ++b;
                    break;
                }
                mx=min(mx+x[i],1000000000);
            }
            printf("%d\n",b);
        }
    }
    return 0;
}


