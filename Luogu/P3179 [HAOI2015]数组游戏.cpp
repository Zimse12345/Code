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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,sq,w,val[N],tot,vis[N],sg[N],ans;

int SG(int x){
	if(x<sq)return sg[tot-x+1];
	if(n/x<sq)return sg[n/x];
	int L=1,R=tot,p=0;
	while(L<=R){
		int M=(L+R)>>1;
		if(x<=val[M])p=M,L=M+1;
		else R=M-1;
	}
	return sg[p];
}

signed main(){
	n=read(),q=read();
	sq=sqrt(n)-1;
	for(int l=1;l<=n;l=n/(n/l)+1)val[++tot]=n/l;
	for(int i=1,x;i<=tot;i++){
		vis[0]=i,x=0;
		for(int k=2;k*val[i]<=n;){
			int l=n/(k*val[i]),r;
			if(l!=1)r=n/(n/(l-1))+1;
			else r=l;
			int L=k,R=n/val[i]/r,rk=k;
			while(L<=R){
				int M=(L+R)>>1;
				if(n/(M*val[i])>=r)rk=M,L=M+1;
				else R=M-1;
			}
			int s=SG(k*val[i]);
			vis[s^x]=i;
			if((rk-k+1)&1)x^=s;
			k=rk+1;
		}
		while(vis[sg[i]]==i)++sg[i];
	}
	while(q--){
		w=read(),ans=0;
		while(w--)ans^=SG(read());
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

