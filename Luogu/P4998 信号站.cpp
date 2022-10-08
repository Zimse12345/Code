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

const int N=1e6+7,INF=1e9+7,M=1e6+1;
int n,k,a[N],sl[N],sr[N],ans,b[N*2];

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1),a[n+1]=INF;
	for(int i=1;i<=n;i++)sl[i]=sl[i-1]+a[i];
	for(int i=n;i>=1;i--)sr[i]=sr[i+1]+a[i];
	for(int p=-M,f=1;p<=M;p++){
		while(a[f]<p)++f;
		b[p+M]=p*(f-1)-sl[f-1]+sr[f]-p*(n-f+1);
	}
	sort(b,b+M*2+1);
	for(int i=0;i<k;i++)ans+=b[i];
	printf("%lld\n",ans);
	return 0;
}

