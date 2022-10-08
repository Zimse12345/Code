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
int Len,n,t[N][26],c[26],trie[N][27],tot,Tag=1;
string s[N];
int p[N],pp[N];
vector<int> cnt[N];

void sol(int L,int R){
    if(L==R)return;
    for(int i=0;i<26;i++)c[i]=0;
    int tag=0;
    for(int i=L;i<=R;i++){
        int id=p[i];
        for(int j=0;j<26;j++){
            c[j]+=t[id][j];
            if(c[j]==R-L+1)tag=1;
        }
    }
    if(!tag){
        Tag=0;
        return;
    }
    for(int i=0;i<=tot;i++){
        for(int j=0;j<=26;j++)trie[i][j]=0;
        cnt[i].clear();
    }
    tot=0;
    for(int i=L;i<=R;i++){
        int id=p[i],pos=0;
        for(int j=0;j<Len;j++){
            int v=s[id][j]-'a';
            if(c[s[id][j]-'a']!=R-L+1)v=26;
            if(!trie[pos][v])trie[pos][v]=++tot;
            pos=trie[pos][v];
        }
        cnt[pos].push_back(id);
    }
    vector<int> q;
    q.push_back(L-1);
    int pos=L-1;
    for(int i=1;i<=tot;i++)if(cnt[i].size()){
        for(unsigned j=0;j<cnt[i].size();j++)pp[++pos]=cnt[i][j];
        q.push_back(pos);
    }
    for(int i=L;i<=R;i++)p[i]=pp[i];
    if(q.size()==2){
        Tag=0;
        return;
    }
    for(unsigned j=1;j<q.size();j++)sol(q[j-1]+1,q[j]);
    return;
}

signed main(){
    Len=read(),n=read();
    vector<int> q;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<Len;j++)t[i][s[i][j]-'a']=1;
        p[i]=i;
    }
    sol(1,n);
    if(Tag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
