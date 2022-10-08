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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,f[N],P;

signed main(){
	n=read(),P=read();
	f[1]=1;
	int sum=1;
	for(int i=2;i<=n;i++){
		f[i]=sum;
		int y=0,k=0;
		
		if(i<=30){
			for(int z=2;z<=i;z++)f[i]=(f[i]+f[i/z])%P;
			sum=(sum+f[i])%P;
			continue;
		}
		
		for(int z=2;z*z<=i;z++)f[i]=(f[i]+f[i/z])%P,y=max(z,y);
		k=i/y,++y;
		while(y<=i&&i/y==k)f[i]=(f[i]+f[k])%P,++y;
		--k;
		for(int z=k;z>=1;z--){
			int R=i/z,L=i/(z+1)+1;
			f[i]=(f[i]+f[z]*(R-L+1))%P;
		}
		
		sum=(sum+f[i])%P;
	}
	printf("%lld\n",f[n]);
	return 0;
}