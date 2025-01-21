#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,ans[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int L=1,R=n;
        for(int i=1,s=k-1;i<=n;i++){
            if(s>0)printf("%d ",R),--R,--s;
            else printf("%d ",L),++L,s=k-1;
        }
        printf("\n");
    }
    return 0;
}


