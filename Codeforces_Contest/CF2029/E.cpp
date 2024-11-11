#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];
int t[N];

signed main(){
    for(int i=2;i<N;i++){
        if(!t[i]){
            for(int j=i+i;j<N;j+=i)t[j]=1;
        }
    }
    cin>>T;
    while(T--){
        cin>>n;
        int v=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!t[a[i]]){
                if(v==0)v=a[i];
                else if(v!=a[i])v=-1;
            }
        }
        if(v==-1)printf("-1\n");
        else if(v==0)printf("2\n");
        else{
            int tag=1;
            for(int i=1;i<=n;i++)if(a[i]){
                for(int j=2;j*j<=a[i];j++)if(a[i]%j==0){
                    if(a[i]/j<v){
                        a[i]-=j;
                        if(a[i]/2<v)tag=0;
                    }
                    break;
                }
                if(tag==0)break;
            }
            if(tag)printf("%d\n",v);
            else printf("-1\n");
        }
    }
    return 0;
}


