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

int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int n,a[N],ans=1;
double k,s,b[N],d;

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];
	s/=double(n);
	for(int i=1;i<=n;i++)b[i]=abs(a[i]-s),d+=b[i]*b[i];
	if(abs(d)<1e-9){
		printf("No answer!\n");
		return 0;
	}
	d/=n;
	ans=sqrt(k/d);
	int aans=ans;
	for(double i=max(1.0,aans-2.0);i<=aans+2.0;i+=1){
		if(abs(i*i*d-k)<abs(ans*ans*d-k))ans=i;
	}
	if(ans<1)ans=1;
	printf("%lld\n",ans);
	return 0;
}

