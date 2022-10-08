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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e12+7;
int T,n,a[N],sum;

signed main(){
	T=read();
	while(T--){
		n=read(),sum=0;
		int ans=INF;
		for(int i=1;i<=n;i++)a[i]=read()%2,sum+=a[i];
		if((sum!=n/2)&&(sum!=(n+1)/2)){
			printf("-1\n");
			continue;
		}
		if(sum==n/2){
			int c=0,j=2;
			for(int i=1;i<=n;i++)if(a[i])c+=abs(i-j),j+=2;
			ans=min(ans,c);
		}
		if(sum==(n+1)/2){
			int c=0,j=1;
			for(int i=1;i<=n;i++)if(a[i])c+=abs(i-j),j+=2;
			ans=min(ans,c);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

