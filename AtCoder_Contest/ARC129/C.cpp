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

const int N=1e6+7,Mod=998244353,INF=1e12+7;
int n,m,s,a[N],q[N],t;
double ans;

signed main(){
	n=read(),m=read(),s=read();
	double S=s;
	for(int i=1;i<=n;i++)a[i]=read();
	int u=n;
	while(u>0){
		int v=0;
		double sum=0,ar=0,Sum=0;
		for(int i=u;i>=1;i--){
			sum+=a[i];
			if(sum/double(u-i+1)>=ar)ar=sum/double(u-i+1),v=i,Sum=sum;
		}
		if(S/double(u-v+1)<=double(m)){
			ans+=S/double(u-v+1)*Sum;
			break;
		}
		ans+=double(m)*Sum;
		S-=double(m)*double(u-v+1);
		u=v-1;
	}
	printf("%.8f\n",ans);
	return 0;
}
