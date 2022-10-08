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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,ans[N],tot,rt[N],pre,pos[N],k[N],kk[N];
char s[N];
vector< vector<char> > str;
vector<char> _s;

struct query{
    int l,r,id;
    query(int l=0,int r=0,int id=0):l(l),r(r),id(id){};
}q[N],_q[N];

struct node{
    int len,link,to[2];
}t[N*16];

void sol(int L,int R,int ql,int qr){
    if(L>R||ql>qr)return;
    else if(L==R){
        for(int i=ql;i<=qr;i++)ans[q[i].id]=str[L].size();
    }
    else{
        int M=L;
        double mid=(L+R)/2.0,val=abs(M-mid)*abs(M-mid)*0.15+double(str[M].size());
        for(int i=L+1;i<=R;i++){
            double _val=abs(i-mid)*abs(i-mid)*0.15+double(str[i].size());
            if(_val<val)val=_val,M=i;
        }
        int A=0,B=0,T=ql-1;
        for(int i=ql;i<=qr;i++)if(q[i].r<M)_q[++T]=q[i];
        A=T;
        for(int i=ql;i<=qr;i++)if(q[i].l>M)_q[++T]=q[i];
        B=T;
        for(int i=ql;i<=qr;i++)if(q[i].l<=M&&q[i].r>=M)_q[++T]=q[i];
        for(int i=ql;i<=qr;i++)q[i]=_q[i];
        sol(L,M-1,ql,A),sol(M+1,R,A+1,B);
        for(int i=L;i<=R;i++)pos[i]=rt[i];
        for(int i=0;i<str[M].size();i++){
            for(int j=L;j<=R;j++){
                int x=str[M][i];
                while(pos[j]!=-1&&!t[pos[j]].to[x])pos[j]=t[pos[j]].link;
                if(pos[j]==-1)pos[j]=rt[j],k[j]=0;
                else k[j]=min(k[j],t[pos[j]].len)+1,pos[j]=t[pos[j]].to[x];
            }
            kk[M]=i+1;
            for(int i=M-1;i>=L;i--)kk[i]=min(kk[i+1],k[i]);
            for(int i=M+1;i<=R;i++)kk[i]=min(kk[i-1],k[i]);
            for(int i=B+1;i<=qr;i++)ans[q[i].id]=max(ans[q[i].id],min(kk[q[i].l],kk[q[i].r]));
        }
    }
    return;
}

void add(int c,int Rt){
    int id=++tot,p=pre;
    t[id].len=t[p].len+1;
    while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
    if(p==-1)t[id].link=Rt;
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

signed main(){
    n=read(),m=read();
    str.push_back(_s);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        int len=strlen(s+1);
        _s.resize(0);
        rt[i]=++tot;
        t[rt[i]].link=-1,pre=rt[i];
        for(int j=1;j<=len;j++){
            _s.push_back(s[j]-'0');
            add(s[j]-'0',rt[i]);
        }
        str.push_back(_s);
    }
    for(int i=1,l,r;i<=m;i++){
        l=read(),r=read();
        q[i]=query(l,r,i);
    }
    sol(1,n,1,m);
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}
