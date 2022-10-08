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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,L,R,s=1e6,f[N][2],p,ans;

int main(){
	n=read();
	L=R=s;
	for(int i=1,a,b;i<=n;i++){
		a=read(),b=read();
		p^=1;
		for(int j=L-abs(a);j<=R+abs(a);j++)f[j][p]=-INF;
		for(int j=L;j<=R;j++)f[j][p]=f[j][p^1];
		for(int j=L;j<=R;j++){
			f[j+a][p]=max(f[j+a][p],f[j][p^1]+b);
		}
		if(a>0)R+=a;
		else L+=a;
	}
	for(int i=1e6;i<=R;i++)if(f[i][p]>=0)ans=max(ans,i+f[i][p]-s);
	printf("%d\n",ans);
	return 0;
}

