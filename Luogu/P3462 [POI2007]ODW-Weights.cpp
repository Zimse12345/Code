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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,w[N],a[N],s[N],t,p[N],ans;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=m;i++)a[i]=read();
	sort(a+1,a+m+1),a[0]=-1;
	for(int i=1;i<=m;i++){
		if(a[i]!=a[i-1])a[++t]=a[i],s[t]=1;
		else ++s[t];
	}
	for(int i=1;i<=n;i++){
		for(int j=t;j>=1;j--)p[j]+=w[i]/a[j],w[i]%=a[j];
	}
	for(int j=1;j<=t;j++){
		while(s[j]--){
			int tag=0;
			for(int i=j;i<=t;i++)if(p[i]>0){
				for(int k=i;k>j;k--)--p[k],p[k-1]+=2;
				tag=1,--p[j],++ans;
				break;
			}
			if(!tag)break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

