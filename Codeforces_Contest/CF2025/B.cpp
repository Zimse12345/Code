#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n[N],k[N],p2[N];

signed main(){
    p2[0]=1;
    for(int i=1;i<N;i++)p2[i]=p2[i-1]*2%1000000007;
    cin>>T;
    for(int i=1;i<=T;i++)cin>>n[i];
    for(int i=1;i<=T;i++){
        cin>>k[i];
        if(k[i]==n[i])printf("1\n");
        else printf("%d\n",p2[k[i]]);
    }
    return 0;
}


