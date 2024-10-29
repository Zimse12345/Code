#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=1000001;
int n,m,tag[N],f[N];
set<int> s;
vector<int> a[N],l[N],r[N];

signed main(){
    scanf("%d%d",&n,&m);
    int ans1=0,Tag=1;
    for(int i=1;i<=n;i++){
        a[i].resize(m+2);
        l[i].resize(m+2);
        r[i].resize(m+2);
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            l[i][j]=l[i][j-1];
            if(a[i][j]){
                if(a[i][j]<l[i][j])tag[i]=1;
                l[i][j]=a[i][j];
            }
        }
        for(int j=m;j>=1;j--){
            if(j==m)r[i][j]=inf;
            else r[i][j]=r[i][j+1];
            if(a[i][j])r[i][j]=a[i][j];
        }
        if(!tag[i])++ans1,Tag=0;
    }
    int ans=0,mx=0;
    s.insert(0);
    s.insert(inf);
    for(int j=1;j<=m;j++){
        int v=0;
        for(int i=1;i<=n;i++)if(a[i][j]){
            if(v==0)v=a[i][j];
            else if(v!=a[i][j]){
                v=-1;
                break;
            }
        }
        if(v==0){
            int L=0,R=inf;
            for(int i=1;i<=n;i++)if(tag[i]==0)L=max(L,l[i][j]),R=min(R,r[i][j]);
            if(L<=R)++ans;
        }
        if(v>0){
            if(Tag){
                ++ans;
                continue;
            }
            for(int i=1;i<=n;i++)if((tag[i]==0)&&(!(l[i][j]<=v&&v<=r[i][j]))){
                v=-1;
                break;
            }
            if(v>0){
                set<int>::iterator it=s.upper_bound(v);
                int p=*it;
                --it;
                f[v]=max(f[v],f[*it]+1);
                mx=max(mx,f[v]);
                if(f[v]>=f[p])s.erase(p);
                s.insert(v);
            }
        }
    }
    printf("%d %d\n",ans1,ans+mx);
    return 0;
}


