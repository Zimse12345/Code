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
int T,n,k;
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		scanf("%s",s+1);
		int l=0,r=0,ans=0;
		for(int i=1;i<=n;i++)if(s[i]=='1'){
			if(!l)l=i;
			r=i;
			ans+=11;
		}
		int s=ans;
		if(r&&n-r<=k)ans=min(ans,s-10);
		if(l&&l-1<=k)ans=min(ans,s-1);
		if(l&&r&&l!=r&&(n-r)+(l-1)<=k)ans=min(ans,s-11);
		printf("%d\n",ans);
	}
	return 0;
}

