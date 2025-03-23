#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,k,ans[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        int t=0;
        if(n<m)swap(m,n),t=1;
        for(int i=1;i<=n;i++)ans[i]=0;
        if(k>n){
            printf("-1\n");
            continue;
        }
        while(m>0){
            for(int i=k;i<=n;i++){
                if(!m)break;
                ++ans[i],--m;
            }
        }
        if(ans[n-1]==0&&k!=n){
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            printf("%d",0^t);
            for(int j=1;j<=ans[i];j++)printf("%d",1^t);
        }
        printf("\n");
    }
    return 0;
}


