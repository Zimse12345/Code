#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,m,mp[N],pos[N],tag[N],_tag[N],nx[N],pre[N],suf[N][5],ans,M;
int c[N],ex[N][5];
char s[N];

signed main(){
    cin>>n>>m;
    M=n+5;
    for(int i=1,x=0;i<=n;i++){
        cin>>x;
        mp[x+M]=1;
    }
    scanf("%s",s+1);
    for(int i=1;i<=m;i++){
        pos[i]=pos[i-1],pre[i]=pre[i-1];
        if(s[i]=='L')--pos[i];
        if(s[i]=='R')++pos[i];
        if(s[i]=='F'&&mp[pos[i]+M]){
            if(!tag[pos[i]+M])++pre[i];
            ++tag[pos[i]+M];
        }
    }
    for(int i=-M;i<=M;i++)_tag[i+M]=tag[i+M];
    for(int d=-2;d<=2;d++)if(d!=0){
        for(int i=-M;i<=M;i++)tag[i+M]=_tag[i+M],c[i+M]=nx[i+M]=0;
        for(int i=m;i>=1;i--){
            suf[i][d+2]+=suf[i+1][d+2];
            if(s[i]=='F'&&mp[pos[i]+d+M]){
                if(!tag[pos[i]+d+M]&&!nx[pos[i]+d+M])++suf[i][d+2];
                ++nx[pos[i]+d+M];
            }
            if(s[i]=='F'){
                --tag[pos[i]+M];
                if(!tag[pos[i]+M]&&nx[pos[i]+M])++suf[i][d+2];
            }
            if(s[i]=='L'&&d==1&&!tag[pos[i]+d+M]&&!nx[pos[i]+d+M])++ex[i][d+2];
            if(s[i]=='R'&&d==-1&&!tag[pos[i]+d+M]&&!nx[pos[i]+d+M])++ex[i][d+2];
        }
    }
    ans=pre[m];
    for(int i=1;i<=m;i++){
        if(s[i]=='L')ans=max(ans,pre[i]+max(suf[i][3]+ex[i][3],suf[i][4]+ex[i][4]));
        if(s[i]=='R')ans=max(ans,pre[i]+max(suf[i][0]+ex[i][0],suf[i][1]+ex[i][1]));
        if(s[i]=='F')ans=max(ans,pre[i-1]+max(suf[i][1],suf[i][3]));
    }
    printf("%lld\n",ans);
    return 0;
}


