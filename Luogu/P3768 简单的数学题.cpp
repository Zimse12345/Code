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

const int N=5e6+7,INF=1e9+7;
int n,P,ans,inv2,inv6;
int prime[N],t,pr[N],phi[N];
map<int,int> val;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%P;x=(x*x)%P,k/=2;}return res;}
inline int inv(int x){return qp(x,P-2);}
inline int calc(int x){x%=P;return x*x%P*(x+1)%P*(x+1)%P*inv2%P*inv2%P;}
inline int calc_2(int x){x%=P;return x*(x+1)%P*(x+x+1)%P*inv6%P;}

int f[N],s[N];
int S(int x){
	if(x<N)return s[x];
	if(val.count(x))return val[x];
	int res=calc(x);
	for(int l=2,r;l<=x;){
		r=x/(x/l);
		res=(res-(calc_2(r)-calc_2(l-1))*S(x/l))%P;
		l=r+1;
	}
	val[x]=res;
	return res;
}

signed main(){
	P=read(),n=read();
	phi[1]=1,inv2=inv(2),inv6=inv(6);
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++t]=i,pr[i]=i,phi[i]=(i-1)%P;
		for(int j=1;j<=t&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j],phi[prime[j]*i]=phi[i]*(prime[j]-1)%P;
			if(pr[i]==prime[j]){phi[prime[j]*i]=phi[i]*prime[j]%P;break;}
		}
	}
	for(int i=1;i<N;i++)f[i]=i*i%P*phi[i]%P,s[i]=(s[i-1]+f[i])%P;
	for(int l=1,r;l<=n;){
		r=n/(n/l);
		ans=(ans+calc(n/l)*(S(r)-S(l-1)))%P;
		l=r+1;
	}
	ans=(ans+P)%P;
	printf("%lld\n",ans);
	return 0;
}

