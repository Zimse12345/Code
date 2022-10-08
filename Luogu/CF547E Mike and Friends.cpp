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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,len[N],ch[N][26],fail[N],tot,dfn[N],sz[N],Time,qt,tr[N],ans[N*3],Pos[N];
char s[N];
vector<char> str[N];
vector<int> g[N];
queue<int> Q;

struct query{
    int x,y,id;
    query(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
    bool operator < (const query& A)const{return x<A.x;}
}qu[N*5];

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void add(int x){for(;x<N;ub(x))++tr[x];return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

void dfs(int u){
    dfn[u]=++Time,sz[u]=1;
    for(unsigned i=0;i<g[u].size();i++)dfs(g[u][i]),sz[u]+=sz[g[u][i]];
    return;
}

signed main(){
	n=read(),q=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        len[i]=strlen(s);
        int pos=0;
        for(int j=0;j<len[i];j++){
            str[i].push_back(s[j]-'a');
            if(!ch[pos][s[j]-'a'])ch[pos][s[j]-'a']=++tot;
            pos=ch[pos][s[j]-'a'];
        }
        Pos[i]=pos;
    }
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<26;i++){
            if(ch[u][i]){
                if(u)fail[ch[u][i]]=ch[fail[u]][i];
                Q.push(ch[u][i]);
            }
            else ch[u][i]=ch[fail[u]][i];
        }
    }
    for(int i=1;i<=tot;i++)g[fail[i]].push_back(i);
    dfs(0);
    for(int i=1,l,r,k;i<=q;i++){
        l=read(),r=read(),k=read();
        qu[++qt]=query(l-1,k,-i);
        qu[++qt]=query(r,k,i);
    }
    sort(qu+1,qu+qt+1);
    for(int i=1,j=1;i<=qt;i++){
        while(j<=qu[i].x){
            int pos=0;
            for(int k=0;k<len[j];k++){
                pos=ch[pos][str[j][k]];
                add(dfn[pos]);
            }
            ++j;
        }
        int p=Pos[qu[i].y],v=sum(dfn[p]+sz[p]-1)-sum(dfn[p]-1);
        if(qu[i].id>0)ans[qu[i].id]+=v;
        else ans[-qu[i].id]-=v;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
