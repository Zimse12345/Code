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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e7+7,INF=1e9+7;
int n,k,P,s[N],vis[N],ans;

inline int ldl(int x,int k=P-2){int res=1;while(k){if(k&1ll)res=(res*x)%P;x=(x*x)%P,k/=2;}return res;}

void dfs(int x,int v){
	if(x==n){
		(ans+=ldl(v,k))%=P;
	}
	else{
		for(int i=1;i<=n;i++)if(!vis[i]){
			vis[i]=1,s[x+1]=i;
			if(i>1&&s[x]<s[x-1]&&s[x]<s[x+1])dfs(x+1,v+1);
			else dfs(x+1,v);
			vis[i]=0;
		}
	}
	return;
}

signed main(){
	n=read(),k=read(),P=read();
	if(k==1){
		ans=ldl(3)*(n-2)%P;
		printf("%lld\n",ans);
	}
	else{
		dfs(0,0);
		for(int i=1;i<=n;i++)(ans*=ldl(i))%=P;
		printf("%lld\n",ans);
	}
	return 0;
}

