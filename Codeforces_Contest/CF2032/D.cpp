#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],p[N],stk[N],l,r;

bool query(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int res;
    cin>>res;
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int se=0;
        l=1,r=0;
        for(int i=2;i<n;i++){
            if(!query(1,i)){
                se=i,p[se]=1;
                break;
            }
        }
        for(int i=2;i<se;i++)stk[++r]=i,p[i]=0;
        stk[++r]=se;
        for(int i=se+1;i<n;i++){
            while(stk[l]<p[i-1])++l;
            while(l<r&&query(stk[l],i))++l;
            p[i]=stk[l],++l;
            stk[++r]=i;
        }
        printf("! ");
        for(int i=1;i<n;i++)printf("%d ",p[i]);
        printf("\n");
        fflush(stdout);
    }
    return 0;
}


