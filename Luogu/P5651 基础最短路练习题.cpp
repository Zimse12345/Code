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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,Q,fa[N],w[N];

int F(int x){
    if(fa[x]==x)return x;
    int ff=F(fa[x]);w[x]^=w[fa[x]],fa[x]=ff;
    return ff;
}

int main(){
	n=read(),m=read(),Q=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    while(m--){
        int u=read(),v=read(),c=read();
        int A=F(u),B=F(v);
        if(A!=B)fa[B]=A,w[B]=w[u]^w[v]^c;
    }
    while(Q--){
        int u=read(),v=read();
        F(u),F(v);
        printf("%d\n",w[u]^w[v]);
    }
	return 0;
}