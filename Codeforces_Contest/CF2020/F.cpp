#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,f[N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)if(n%i==0)f[i]=1;
    for(int i=1;i<=10;i++){
        for(int v=n;v>=1;v--){
            for(int j=1;j<v;j++)if(v%j==0)f[v]+=f[j];
        }
        printf("i=%d f=%d\n",i,f[n]);
    }
    return 0;
}


