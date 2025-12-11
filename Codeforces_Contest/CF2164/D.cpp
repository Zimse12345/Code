#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,kmax,k,p[N],x[N];
char s[N],t[N];
vector<int> ans[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>kmax;
        k=0;
        
        scanf("%s",s+1);
        scanf("%s",t+1);
        for(int i=0;i<=kmax;i++){
            ans[i].resize(n+2);
        }
        for(int i=1;i<=n;i++)ans[0][i]=i;
        int tag=0;
        p[n+1]=n;
        for(int i=n;i>=1;i--){
            p[i]=min(i,p[i+1]);
            while(p[i]>0&&i-p[i]<kmax&&s[p[i]]!=t[i])--p[i];
            if(s[p[i]]!=t[i]){
                tag=1;
                break;
            }
            x[i]=i;
        }
        if(tag){
            printf("-1\n");
            continue;
        }
        
        while(1){
            tag=0;
            for(int i=1;i<=n;i++)if(ans[k][i]!=p[i])tag=1;
            if(!tag)break;
            ++k;
            if(k>kmax)break;
            for(int i=1;i<=n;i++){
                ans[k][i]=ans[k-1][i];
                if(ans[k][i]>p[i])ans[k][i]=ans[k-1][i-1];
            }
        }
        if(k>kmax){
            printf("-1\n");
            continue;
        }
        printf("%d\n",k);
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++)printf("%c",s[ans[i][j]]);
            printf("\n");
        }
    }
    return 0;
}


