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
int n,d,a[N],f[N][20],t,ans;

signed main(){
	n=read(),d=read(),t=1<<n;
	for(int i=0;i<n;i++)a[i]=read();
	a[n]=INF,f[0][n]=1;
	for(int i=0;i<t;i++){
		for(int j=0;j<=n;j++)if(f[i][j]){
			for(int k=0;k<n;k++){
				if(((i&(1<<k))==0)&&abs(a[k]-a[j])>d)f[i|(1<<k)][k]+=f[i][j];
			}
		}
	}
	for(int j=0;j<n;j++)ans+=f[t-1][j];
	printf("%lld\n",ans);
	return 0;
}
