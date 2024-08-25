#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,fa[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=2;i<=n;i++){
            int p=1;
            while(1){
                printf("? %d %d\n",p,i);
                fflush(stdout);
                int mid;
                cin>>mid;
                if(mid==p){
                    fa[i]=p;
                    break;
                }
                else p=mid;
            }
        }
        printf("! ");
        for(int i=2;i<=n;i++)printf("%d %d ",fa[i],i);
        printf("\n");
        fflush(stdout);
    }
    return 0;
}


