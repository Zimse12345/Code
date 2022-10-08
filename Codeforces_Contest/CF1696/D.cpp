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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],premin[N],premax[N],pos[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
		
		premin[0]=n;
		for(int i=1;i<=n;i++){
			premin[i]=min(premin[i-1],a[i]);
			premax[i]=max(premax[i-1],a[i]);
		}
		int t=0,p=pos[premax[n]],ans=0;
		while(p!=1){
			++ans,t^=1;
			if(t)p=premin[p];
			else p=premax[p];
			p=pos[p];
		}
		
		premin[n+1]=n,premax[n+1]=0;
		for(int i=n;i>=1;i--){
			premin[i]=min(premin[i+1],a[i]);
			premax[i]=max(premax[i+1],a[i]);
		}
		p=pos[premax[1]],t=0;
		while(p!=n){
			++ans,t^=1;
			if(t)p=premin[p];
			else p=premax[p];
			p=pos[p];
		}
		printf("%d\n",ans);
	}
	return 0;
}

