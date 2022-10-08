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

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=1e9+7,INF=1e9+7;
int T,n,a[N],pos[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=0;i<n;i++)a[i]=read(),pos[a[i]]=i;
		int l=pos[0],r=pos[0],ans=1;
		for(int i=1;i<n;i++){
			if(l<pos[i]&&pos[i]<r)ans=(ans*(r-l+1-i))%Mod;
			l=min(l,pos[i]),r=max(r,pos[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

