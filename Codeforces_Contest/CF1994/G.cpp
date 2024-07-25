#include <bits/stdc++.h>
using namespace std;

const int N=2.01e6;
int T,n,k;
char s[N],a[N],ans[N];

vector<int> v[N],f[N],p[N],px[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            scanf("%s",a+1);
            v[i].resize(0);
            for(int j=1;j<=k;j++)v[i].push_back(a[j]-'0');
        }
        f[0].resize(n*2+1);
        f[0][0]=1;
        for(int i=1;i<=k;i++){
            f[i].resize(n*2+1);
            p[i].resize(n*2+1);
            px[i].resize(n*2+1);
            for(int j=0;j<=n*2;j++)f[i][j]=0;
            int cnt=0;
            for(int j=1;j<=n;j++)if(v[j][i-1]==1)++cnt;
            for(int j=0;j<=n*2;j++)if(f[i-1][j]){
                int _j=j*2+s[i]-'0';
                if(_j>n*2)continue;
                if(cnt<=_j)f[i][_j-cnt]=1,p[i][_j-cnt]=0,px[i][_j-cnt]=j;
                if(n-cnt<=_j)f[i][_j-(n-cnt)]=1,p[i][_j-(n-cnt)]=1,px[i][_j-(n-cnt)]=j;
            }
        }
        if(!f[k][0])printf("-1\n");
        else{
            int x=0;
            for(int i=k;i>=1;i--){
                ans[i]=p[i][x]+'0';
                x=px[i][x];
            }
            for(int i=1;i<=k;i++)printf("%c",ans[i]);
            printf("\n");
        }
    }
    return 0;
}



