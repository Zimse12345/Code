#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,ans[N];

inline int query(int l,int r){
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int res;
    cin>>res;
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int pos=0;
        for(int i=2;i<=n;i++){
            if(query(i-1,i)){
                pos=i;
                break;
            }
        }
        if(!pos){
            printf("! IMPOSSIBLE\n");
            fflush(stdout);
            continue;
        }
        int v=query(1,pos);
        for(int i=pos-1;i>=pos-v;i--)ans[i]=0;
        for(int i=1;i<pos-v;i++)ans[i]=1;
        ans[pos]=1;
        for(int i=pos+1;i<=n;i++){
            int vv=query(1,i);
            if(vv>v)ans[i]=1;
            else ans[i]=0;
            v=vv;
        }
        printf("! ");
        for(int i=1;i<=n;i++)printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}


