#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int T,n,m,a[N*N];
char s[N][N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
        }
        int l=1,r=m,u=1,d=n,ans=0;
        while(l<r&&u<d){
            int t=0;
            for(int i=l;i<r;i++)a[t++]=s[u][i]-'0';
            for(int i=u;i<d;i++)a[t++]=s[i][r]-'0';
            for(int i=r;i>l;i--)a[t++]=s[d][i]-'0';
            for(int i=d;i>u;i--)a[t++]=s[i][l]-'0';
            for(int i=0;i<t;i++){
                if(a[i]==1&&a[(i+1)%t]==5&&a[(i+2)%t]==4&&a[(i+3)%t]==3)++ans;
            }
            ++l,--r,++u,--d; 
        }
        printf("%d\n",ans);
    }
    return 0;
}


