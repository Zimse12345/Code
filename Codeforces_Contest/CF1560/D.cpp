#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define int long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,s[N],la,t[N],lb,ans,f[N][N];

int w(){
	int L=la,R=lb,d=0;
	while(1){
		while(L>=1&&s[L]!=t[R])--L,++d;
		if(L>=1&&s[L]==t[R])--L,--R;
		if(L==0||R==0)break;
	}
	return d+L+R;
}

signed main(){
	T=read();
	while(T--){
		n=read(),la=lb=0,ans=INF;
		while(n)s[++la]=n%10,n/=10;
		t[++lb]=1;
		ans=min(ans,w());
		for(int k=1;k<=65;k++){
			t[lb+1]=0;
			for(int i=1;i<=lb;i++)t[i]*=2;
			for(int i=1;i<=lb;i++)t[i+1]+=t[i]/10,t[i]%=10;
			if(t[lb+1])++lb;
			ans=min(ans,w());
		}
		printf("%lld\n",ans);
	}
	return 0;
}
