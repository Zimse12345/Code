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
const __int128 T=10;
inline void write(__int128 x){if(x>=T)write(x/T);putchar('0'+x%T);return;}

const int N=4e7+7,M=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,ty,a[N],_p[M],_l[M],_r[M],P;
signed st[N],b[N],l,r;
__int128 ans;

signed main(){
	n=read(),ty=read();
	if(!ty)for(int i=1;i<=n;i++)a[i]=read();
	else{
		int X=read(),Y=read(),Z=read();
		b[1]=read(),b[2]=read(),m=read(),P=1<<30;
		for(int i=1;i<=m;i++)_p[i]=read(),_l[i]=read(),_r[i]=read();
		for(int i=3;i<=n;i++)b[i]=(X*b[i-1]+Y*b[i-2]+Z)%P;
		for(int i=1,j=1;i<=n;i++){
			while(_p[j]<i)++j;
			a[i]=(b[i]%(_r[j]-_l[j]+1))+_l[j];
		}
	}
	
	for(int i=1;i<=n;i++)a[i]=a[i-1]+a[i];
	st[1]=0,l=r=1;
	for(int i=1;i<=n;i++){
		while(l<r&&a[i]>=2*a[st[l+1]]-a[b[st[l+1]]])++l;
		b[i]=st[l];
		while(l<r&&2*a[i]-a[b[i]]<2*a[st[r]]-a[b[st[r]]])--r;
		st[++r]=i;
	}
	while(n){
		__int128 t=a[n]-a[b[n]];
		ans+=t*t,n=b[n];
	}
	write(ans),putchar(10);
	
	return 0;
}
