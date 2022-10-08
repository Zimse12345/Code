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
#define Lid ch[id][0]
#define Rid ch[id][1]
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=3e6+7,Mod=998244353,SZ=26;
int n,tot,pre,m,k[N],w[N],rt;
char s[N],q[N];
vector<int> g[N],G[N];
int ch[32000000][2],Rt[N],cnt;

struct node{
    int len,link,to[SZ];
}t[N];

void build(int L,int R,int& id,int x){
    if(!id)id=++cnt;
    if(L^R)x<=M?build(L,M,Lid,x):build(M+1,R,Rid,x);
    return;
}

void merge(int L,int R,int& id,int id1,int id2){
    if(!id1||!id2)id=id1^id2;
    else id=++cnt,merge(L,M,Lid,ch[id1][0],ch[id2][0]),merge(L,M,Rid,ch[id1][1],ch[id2][1]);
}

int findR(int L,int R,int id,int r){
    if(L>r||!id)return 0;
    if(L==R)return L;
    int x=findR(M+1,R,Rid,r);
    return x?x:findR(L,M,Lid,r);
}

void add(int c,int tag,int Root){
    int id=++tot,p=pre;
    t[id].len=t[pre].len+1;
    if(!Root)build(1,n,Rt[id],t[id].len);
    w[id]=tag;
    while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
    if(p==-1)t[id].link=Root;
    else{
        int q=t[p].to[c];
        if(t[q].len==t[p].len+1)t[id].link=q;
        else{
            int cp=++tot;t[cp]=t[q],t[cp].len=t[p].len+1;
            while(t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
            t[q].link=t[id].link=cp;
        }
    }
    pre=id;
    return;
}

void dfs(int id){
    for(unsigned i=0;i<g[id].size();i++){
        int v=g[id][i];
        dfs(v);
        w[id]=max(w[id],min(t[id].len,w[v]));
    }
    return;
}

void Init(int id){
    for(unsigned i=0;i<G[id].size();i++){
        int v=G[id][i],_Rt=0;
        Init(v);
        merge(1,n,_Rt,Rt[id],Rt[v]);
        Rt[id]=_Rt;
    }
    return;
}

signed main(){
    t[0].link=-1;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)add(s[i]-'a',0,0);
    for(int i=1;i<=tot;i++)G[t[i].link].push_back(i);
    Init(0);
    int pos=t[0].to[4];
    m=read();
    int TOT=tot;
    while(m--){
        scanf("%s",q+1);
        int L=read(),R=read();
        int len=strlen(q+1),p=0,l=0;
        for(int i=1;i<=len;i++){
            q[i]-='a';
            while(p!=-1){
                if(t[p].to[q[i]]){
                    int v=t[p].to[q[i]];
                    int pos=findR(1,n,Rt[v],R);
                    int mx=min(pos-L+1,t[v].len);
                    if(t[v].link==-1||mx>t[t[v].link].len)if(mx>0){
                        l=min(l+1,mx),p=v;
                        break;
                    }
                }
                p=t[p].link;
                l=min(l,t[p].len);
            }
            if(p==-1)p=0,l=0;
            k[i]=l;
        }
        ++tot,t[tot].link=-1,pre=tot,rt=tot;
        for(int i=1;i<=len;i++)add(q[i],k[i],rt);
        for(int i=TOT+2;i<=tot;i++)g[t[i].link].push_back(i);
        dfs(rt);
        ll ans=0;
        for(int i=rt+1;i<=tot;i++)ans+=t[i].len-max(w[i],t[t[i].link].len);
        printf("%lld\n",ans);

        for(int i=rt;i<=tot;i++){
            for(int j=0;j<SZ;j++)t[i].to[j]=0;
            t[i].len=t[i].link=w[i]=0,g[i].resize(0);
        }
        tot=TOT;
    }
    return 0;
}
