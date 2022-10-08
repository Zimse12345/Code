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

const int N=1e5+7,Mod=998244353,SZ=26;
int T,tot,pre,n,maxl[N],k[N];
char s[N];
vector<int> ch[N];

struct node{
    int len,link,to[SZ];
}t[N];

void add(int c){
    int id=++tot,p=pre;
    t[id].len=t[pre].len+1;
    while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
    if(p==-1)t[id].link=0;
    else{
        int q=t[p].to[c];
        if(t[q].len==t[p].len+1)t[id].link=q;
        else{
            int cp=++tot;t[cp]=t[q],t[cp].len=t[p].len+1;
            while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
            t[q].link=t[id].link=cp;
        }
    }
    pre=id;
    return;
}

void dfs(int p){
    for(unsigned i=0;i<ch[p].size();i++){
        dfs(ch[p][i]);
        k[p]=max(k[p],k[ch[p][i]]);
    }
    maxl[p]=min(maxl[p],k[p]);
    return;
}

signed main(){
    T=read();
    while(T--){
        for(int i=0;i<=tot;i++){
            t[i].len=t[i].link=0;
            for(int j=0;j<26;j++)t[i].to[j]=0;
            ch[i].resize(0);
        }
        t[0].link=-1,tot=0,pre=0;

        n=read();
        scanf("%s",s+1);
        int len=strlen(s+1);
        for(int i=1;i<=len;i++)add(s[i]-'a');
        for(int i=1;i<=tot;i++){
            maxl[i]=t[i].len,ch[t[i].link].push_back(i);
        }
        for(int i=2;i<=n;i++){
            scanf("%s",s+1);
            int p=0,len=strlen(s+1),l=0;
            for(int j=1;j<=len;j++){
                s[j]-='a';
                while(p!=-1&&!t[p].to[s[j]])p=t[p].link;
                if(p==-1)p=0,l=0;
                else l=min(l,t[p].len)+1,p=t[p].to[s[j]];
                k[p]=max(k[p],l);
            }
            dfs(0);
            for(int i=1;i<=tot;i++)k[i]=0;
        }
        int ans=0;
        for(int i=1;i<=tot;i++)ans=max(ans,maxl[i]);
        printf("%d\n",ans);
    }
    return 0;
}
