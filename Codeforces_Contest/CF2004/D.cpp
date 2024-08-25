#include <bits/stdc++.h>
using namespace std;

const int N=2.01e5;
int T,n,q,mp[256],a[N],pre[N][16],suf[N][16];
char s[8];

inline int _abs(int x){
    return x<0?-x:x;
}

signed main(){
    cin>>T;
    mp['B']=0,mp['R']=1,mp['G']=2,mp['Y']=3;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            a[i]=(1<<mp[(unsigned)s[0]])+(1<<mp[(unsigned)s[1]]);
            for(int j=0;j<16;j++){
                pre[i][j]=pre[i-1][j];
                if(a[i-1]==j)pre[i][j]=i-1;
            }
        }
        for(int i=0;i<16;i++)suf[n][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<16;j++){
                suf[i][j]=suf[i+1][j];
                if(a[i+1]==j)suf[i][j]=i+1;
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            if(a[x]&a[y]){
                printf("%d\n",_abs(x-y));
                continue;
            }
            int ans=1e9;
            for(int i=0;i<16;i++)if((i&a[x])>0&&i!=a[x]){
                if(pre[x][i])ans=min(ans,x-pre[x][i]+_abs(pre[x][i]-y));
                if(suf[x][i])ans=min(ans,suf[x][i]-x+_abs(suf[x][i]-y));
            }
            for(int i=0;i<16;i++)if((i&a[y])>0&&i!=a[y]){
                if(pre[y][i])ans=min(ans,y-pre[y][i]+_abs(pre[y][i]-x));
                if(suf[y][i])ans=min(ans,suf[y][i]-y+_abs(suf[y][i]-x));
            } 
            if(ans==1e9)ans=-1;
            printf("%d\n",ans);
        }
    }
    return 0;
}


