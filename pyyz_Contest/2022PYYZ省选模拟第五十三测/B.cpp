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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],m,val[N],f[N],sf[N],pre[N];
map<int,int> mp;

signed main(){
	freopen("divide4.in","r",stdin);
	f[0]=1,sf[0]=1;
	val[0]=-1;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	b[0]=-1;
	for(int i=1;i<=n;i++)if(b[i]!=b[i-1])val[++m]=b[i],mp[b[i]]=m;
	for(int i=1;i<=n;i++)a[i]=mp[a[i]];
	for(int i=1;i<=n;i++){
		int mex=0,pos=i-1,_mex;
		pre[a[i]]=i;
		for(int j=1;j<=m;j++){
			if(val[j]!=val[j-1]+1||!pre[j]){
				_mex=val[j-1]+1;
				(f[i]+=(_mex-mex)*sf[pos])%=Mod;
				break;
			}
			else{
				pos=min(pos,pre[j]-1);
				_mex=val[j]+1;
				(f[i]+=(_mex-mex)*sf[pos])%=Mod;
				mex=_mex;
			}
		}
		sf[i]=(sf[i-1]+f[i])%Mod; 
	}
	printf("%lld\n",f[n]);
	return 0;
}

