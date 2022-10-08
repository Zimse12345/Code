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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,vis[N],f[N];
char s[N];
int type,k,tot,pre;
vector<int> ch[N];

struct node{
    int len,link,to[26],cnt;
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
            while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
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

void dfs2(int id){
    if(vis[id]++)return;
    f[id]=type?t[id].cnt:1;
    for(int i=0;i<26;i++)if(t[id].to[i]){
        dfs2(t[id].to[i]);
        f[id]+=f[t[id].to[i]];
    }
    return;
}

void findans(int id,int k){
    int c=type?t[id].cnt:1;
    if(k<=c)return;
    k-=c;
    for(int i=0;i<26;i++)if(t[id].to[i]){
        int v=t[id].to[i];
        if(k>f[v])k-=f[v];
        else{
            printf("%c",'a'+i);
            findans(v,k);
            return;
        }
    }
    printf("-1\n");
    return;
}

signed main(){
    t[0].link=-1;
    scanf("%s",s+1);
    n=strlen(s+1),type=read(),k=read();
    for(int i=1;i<=n;i++)ins(s[i]-'a');
    for(int i=1;i<=tot;i++)ch[t[i].link].push_back(i);
    dfs(0),t[0].cnt=1;
    dfs2(0);
    findans(0,k+1);
    printf("\n");
    return 0;
}
