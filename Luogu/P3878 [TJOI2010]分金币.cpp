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

const int N=1e2+7,Mod=998244353,INF=1e12+7;
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int cnt=25,sum1=0,sum2=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i<=n/2)sum1+=a[i];
			else sum2+=a[i];
		}
		int ans=abs(sum1-sum2);
		if(n>2)while(cnt--){
			double beginT=5000,endT=1e-9,changeT=0.91;
			for(double t=beginT;t>=endT;t*=changeT){
				int x=rand()%(n/2)+1,y=rand()%(n-n/2)+n/2+1;
				sum1+=a[y]-a[x],sum2+=a[x]-a[y];
				swap(a[x],a[y]);
				if(abs(sum1-sum2)<ans)ans=abs(sum1-sum2);
				else if(exp((ans-abs(sum1-sum2))/t)<(double(rand())/RAND_MAX)){
					sum1+=a[y]-a[x],sum2+=a[x]-a[y];
					swap(a[x],a[y]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

