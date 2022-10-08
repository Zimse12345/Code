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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],fa[N];

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),fa[v]=u;
	for(int i=1,op,u,k;i<=m;i++){
		op=read();
		if(op==1){
			u=read();
			int p=fa[u];
			while(p){
				if(gcd(a[u],a[p])>1)break;
				p=fa[p];
			}
			if(p==0)p=-1;
			printf("%d\n",p);
		}
		else u=read(),k=read(),a[u]=k;
	}
	return 0;
}
