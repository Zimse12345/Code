#include <cstdio>
#include <algorithm>
#define int long long

using namespace std;

int a,b,P,Mod,tag;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9'){if(qrx*10+qrc-'0'>=Mod)tag=1;qrx=(qrx*10+qrc-'0')%Mod,qrc=getchar();
}return qrx*qry;}

int qp(int x,int k){
	if(k==0)return 1;
	int s=qp(x,k/2);s=(s*s)%P;
	if(k&1)s=(s*x)%P;
	return s;
}

int phi(int x){
	int res=1;
	
	
	for(int i=2;i*i<=x;i++)if(x%i==0){
		int c=1;
		while(x%i==0)c*=i,x/=i;
		c-=c/i;
		res*=c;
	}
	if(x>1)res*=x-1;
	return res;
}

signed main(){
	Mod=1e15,a=read(),P=read(),Mod=phi(P);
	int m=read()+Mod*tag;
	printf("%lld\n",qp(a,m));

	return 0;
}
