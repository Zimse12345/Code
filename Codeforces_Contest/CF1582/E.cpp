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

const int N=1e5+7,Mod=998244353,INF=1e16+7;
int T,n,a[N],s[N],f[N][500];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=0;i<500;i++)f[0][i]=0;
		f[0][0]=INF;
		for(int i=1;i<=n;i++)a[n-i+1]=read();
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<500;j++)f[i][j]=f[i-1][j];
			
			for(int j=1;(j*(j+1ll))/2ll<=i;j++){
				if(f[i-j][j-1]>s[i]-s[i-j])f[i][j]=max(f[i][j],s[i]-s[i-j]);//printf("(%d %d)\n",i,j);
			}
		}
		for(int i=499;i>=0;i--)if(f[n][i]>0){
			printf("%lld\n",i);
			break;
		}
	}
	return 0;
}
