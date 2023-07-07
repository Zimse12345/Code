#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,q,cnt,ans;
char s[N];
int l[N],r[N],p[N],cur,tag[N],a[N];
set<int> S;

void ck(int x){
    ans-=a[x],a[x]=0;
    if(tag[x]&&s[x]=='0')a[x]=1,ans++;
    return;
}

signed main(){
    cin>>n>>m>>q;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)if(s[i]=='1')++cnt;
    for(int i=1;i<=n+1;i++)S.insert(i);
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        while(1){
            set<int>::iterator it=S.lower_bound(l[i]);
            if(*it>r[i])break;
            p[++cur]=*it;
            if(cur<=cnt)tag[*it]=1;
            S.erase(it);
        }
    }
    for(int i=1;i<=n;i++)ck(i);
    while(q--){
        int x;
        cin>>x;
        if(s[x]=='0')++cnt,tag[p[cnt]]=1,ck(p[cnt]);
        else tag[p[cnt]]=0,ck(p[cnt]),--cnt;
        s[x]^=1;
        ck(x);
        printf("%d\n",ans);
    }
    return 0;
}


