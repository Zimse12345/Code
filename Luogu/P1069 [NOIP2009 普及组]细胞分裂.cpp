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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m1,m2,p[N],c[N],t,ans=-1,min_t=INF;

signed main(){
	n=read(),m1=read(),m2=read();
	for(int i=2;i<=m1;i++)if(m1%i==0){
		p[++t]=i;
		while(m1%i==0)m1/=i,++c[t];
		c[t]*=m2;
	}
	
	for(int i=1,x;i<=n;i++){
		x=read();
		int res=0;
		for(int j=1;j<=t;j++){
			int cnt=0,y;
			while(x%p[j]==0)x/=p[j],++cnt;
			if(cnt==0){res=INF;break;}
			y=c[j]/cnt;
			if(c[j]%cnt)++y;
			res=max(res,y);
		}
		if(res<min_t)min_t=res,ans=i;
	}
	if(ans==-1)min_t=-1;
	printf("%d\n",min_t);
	return 0;
}

