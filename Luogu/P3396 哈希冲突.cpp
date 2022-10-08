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

const int N=2e5+7,Mod=1000000007,INF=1e9+7;
int n,m,a[N],tot[400][400];
char op;

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=1;j<=300;j++)tot[j][i%j]+=a[i];
	}
	for(int i=1,x,y,ans;i<=m;i++){
		do{op=getchar();}while(op!='A'&&op!='C');
		x=read(),y=read();
		if(op=='A'){
			ans=0;
			if(x>300)for(int i=y;i<=n;i+=x)ans+=a[i];
			else ans=tot[x][y];
			printf("%lld\n",ans);
		}
		else{
			for(int j=1;j<=300;j++)tot[j][x%j]+=y-a[x];
			a[x]=y;
		}
	}
	return 0;
}
