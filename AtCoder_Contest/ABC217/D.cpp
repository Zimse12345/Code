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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n;

struct Treap{
    int ch[N][2],val[N],dat[N],siz[N],cnt[N];
    int tot,root;

    int New(int v){
        val[++tot]=v,dat[tot]=rand();
        siz[tot]=cnt[tot]=1;
        return tot;
    }

    void pushup(int id){
        siz[id]=siz[ch[id][0]]+siz[ch[id][1]]+cnt[id];
        return;
    }

    void build(){
        root=New(0),ch[root][1]=New(n);
        pushup(root);
        return;
    }

    void rot(int &id,int d){
        int t=ch[id][d^1];
        ch[id][d^1]=ch[t][d],ch[t][d]=id,id=t;
        pushup(ch[id][d]),pushup(id);
        return;
    }

    void ins(int &id,int v){
        if(!id)id=New(v);
        else if(v==val[id])++cnt[id];
        else{
            int d=v<val[id]?0:1;
            ins(ch[id][d],v);
            if(dat[id]<dat[ch[id][d]])rot(id,d^1);
        }

        pushup(id);
        return;
    }

    void rem(int &id,int v){
        if(!id)return;

        if(v==val[id]){
            if(cnt[id]>1)--cnt[id];
            else if(ch[id][0]||ch[id][1]){
                if(!ch[id][1]||dat[ch[id][0]]>dat[ch[id][1]])rot(id,1),rem(ch[id][1],v);
                else rot(id,0),rem(ch[id][0],v);
            }
            else id=0;
        }
        else{
            int d=v<val[id]?0:1;
            rem(ch[id][d],v);
        }
        
        pushup(id);
        return;
    }

    int rk(int &id,int v){
        if(!id)return 0;
        if(v==val[id])return siz[ch[id][0]]+1;
        int res=v<val[id]?rk(ch[id][0],v):rk(ch[id][1],v);
        if(res==0)return 0;
        if(v>val[id])res+=siz[ch[id][0]]+cnt[id];
        return res;
    }

    int num(int &id,int rk){
        if(!id)return INF-1;
        if(rk<=siz[ch[id][0]])return num(ch[id][0],rk);
        if(rk<=siz[ch[id][0]]+cnt[id])return val[id];
        return num(ch[id][1],rk-siz[ch[id][0]]-cnt[id]);
    }

    int pre(int v){
        int id=root,pre=-INF;
        while(id){
            if(val[id]<v)pre=val[id],id=ch[id][1];
            else id=ch[id][0];
        }
        return pre;
    }

    int nxt(int v){
        int id=root,nxt=INF;
        while(id){
            if(val[id]>v)nxt=val[id],id=ch[id][0];
            else id=ch[id][1];
        }
        return nxt;
    }

    void insert(int v){
        ins(root,v);
        return;
    }

    void remove(int v){
        rem(root,v);
        return;
    }

    int rank(int v){
        return rk(root,v)-1;
    }

    int number(int rk){
        return num(root,rk+1);
    }
}a;

int main(){
	n=read(),T=read(),a.build();
	while(T--){
		int ty=read(),x=read();
		if(ty==1)a.insert(x);
		else printf("%d\n",a.nxt(x)-a.pre(x));
	}
	return 0;
}
