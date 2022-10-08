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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,k,a[N],sum,ans;

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
	if(sum<k)k=sum;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int p=a[i]-a[i-1],b=n-i+1ll;
		if(!p)continue;
		if(p*b<=k){
			k-=p*b;
			ans+=((a[i-1]+1ll+a[i])*p*b)/2ll;
		}
		else{
			int h=k/b;
			ans+=((a[i]-h+1ll+a[i])*h*b)/2ll;
			ans+=(k%b)*(a[i]-h);
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
