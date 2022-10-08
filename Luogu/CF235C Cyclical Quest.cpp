#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353,SZ=26;
char s[N],q[N];
int n,m,tot,pre,vis[N];
vector<int> ch[N];

struct node{
    int len,link,to[SZ],cnt;
}t[N];

void ins(int c){
    int id=++tot,p=pre;
    t[id].len=t[pre].len+1,t[id].cnt=1;
    while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
    if(p==-1)t[id].link=0;
    else{
        int q=t[p].to[c];
        if(t[q].len==t[p].len+1)t[id].link=q;
        else{
            int cp=++tot;t[cp]=t[q],t[cp].len=t[p].len+1,t[cp].cnt=0;
            while(t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
            t[q].link=t[id].link=cp;
        }
    }
    pre=id;
    return;
}

void dfs(int id){
    for(unsigned i=0;i<ch[id].size();i++)dfs(ch[id][i]),t[id].cnt+=t[ch[id][i]].cnt;
    return;
}

signed main(){
    t[0].link=-1;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)ins(s[i]-'a');
    for(int i=1;i<=tot;i++)ch[t[i].link].push_back(i);
    dfs(0);
    m=read();
    for(int I=1;I<=m;I++){
        scanf("%s",q+1);
        int len=strlen(q+1),pos=0,l=0;
        ll ans=0;
        for(int i=1;i<=len;i++){
            q[i]-='a';
            while(pos!=-1&&!t[pos].to[q[i]])pos=t[pos].link;
            if(pos==-1)l=0,pos=0;
            else l=min(l,t[pos].len),pos=t[pos].to[q[i]],++l;
        }
        if(l==len&&vis[pos]<I)vis[pos]=I,ans+=t[pos].cnt;
        for(int i=1;i<=len;i++){
            if(l==len){
                if(l-1<=t[t[pos].link].len)pos=t[pos].link;
                --l;
            }
            while(pos!=-1&&!t[pos].to[q[i]])pos=t[pos].link;
            if(pos==-1)l=0,pos=0;
            else l=min(l,t[pos].len),pos=t[pos].to[q[i]],++l;
            if(l==len&&vis[pos]<I)vis[pos]=I,ans+=t[pos].cnt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
