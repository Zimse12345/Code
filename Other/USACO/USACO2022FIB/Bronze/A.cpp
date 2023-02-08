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
int T,n,a[N],sum,mx,ans;

signed main(){
	T=read();
	while(T--){
		n=read(),sum=0,mx=0,ans=n-1;
		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i],mx=max(mx,a[i]);
		if(mx==0){
			printf("0\n");
			continue;
		}
		for(int i=mx;i<=sum;i++)if(sum%i==0){
			int tag=1,t=0,s=0;
			for(int j=1;j<=n;j++){
				s+=a[j];
				if(s==i)s=0,++t;
				if(s>i){tag=0;break;}
			}
			if(s)tag=0;
			if(tag)ans=min(ans,n-t);
		}
		printf("%d\n",ans);
	}
	return 0;
}

