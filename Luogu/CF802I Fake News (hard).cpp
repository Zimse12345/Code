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
int T;
char s[N];
int n,m,tot,pre;
ll ans;
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
            while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
            t[q].link=t[id].link=cp;
        }
    }
    pre=id;
    return;
}

void dfs(int id){
    for(unsigned i=0;i<ch[id].size();i++)dfs(ch[id][i]),t[id].cnt+=t[ch[id][i]].cnt;
    if(id)ans+=1ll*t[id].cnt*t[id].cnt*(t[id].len-t[t[id].link].len);
    return;
}

signed main(){
    T=read();
    while(T--){
        for(int i=0;i<=tot;i++){
            for(int j=0;j<SZ;j++)t[i].to[j]=0;
            t[i].len=t[i].link=t[i].cnt=0;
            ch[i].resize(0);
        }
        ans=0,pre=tot=0,t[0].link=-1;
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++)ins(s[i]-'a');
        for(int i=1;i<=tot;i++)ch[t[i].link].push_back(i);
        dfs(0);
        printf("%lld\n",ans);
    }
    return 0;
}