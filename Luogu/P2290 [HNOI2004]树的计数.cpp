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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e6+7,Mod=998244353,INF=1e15;
int n,d[N],prime[N],pr[N],t,tot[N],ans=1;

void add(int s){
	for(int i=2,x;i<=s;i++){
		x=i;
		while(x>1)++tot[pr[x]],x/=pr[x];
	}
	return;
}

signed main(){
	for(int i=2;i<N;i++){
		if(pr[i]==0)pr[i]=i,prime[++t]=i;
		for(int j=1;j<=t&&i*prime[j]<N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	n=read();
	if(n==1){
		n=read();
		if(n==0)printf("1\n");
		else printf("0\n");
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		d[i]=read()-1;
		if(d[i]<0)return !printf("0\n");
		add(d[i]),sum+=d[i];
	}
	for(int i=2;i<N;i++)tot[i]=-tot[i];
	add(n-2);
	for(int i=2;i<N;i++)for(int j=1;j<=tot[i];j++)ans*=i;
	if(sum!=n-2)ans=0;
	printf("%lld\n",ans);
	return 0;
}
