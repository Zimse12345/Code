#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define int long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while('0'<=qrc&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=1e9+7;
int n,S=1,a[N],b[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		b[i]=read();
		if(a[i]==1)S+=b[i];
	}
	double mx=S;
	int pos=0;
	for(int i=1;i<=n;i++)if(a[i]^1){
		double v=double(b[i]+S)/(double(a[i]));
		if(v>mx)mx=v,pos=i;
	}
	if(pos)S+=b[pos];
	S%=Mod;
	for(int i=1;i<=n;i++)if(i^pos)S=(S*a[i])%Mod;
	printf("%lld\n",S);
	return 0;
}

