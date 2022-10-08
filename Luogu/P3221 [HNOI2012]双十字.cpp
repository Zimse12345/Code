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

const int N=2e6+7,Mod=1e9+9,INF=1e9+7;
int n,m,c,a[N],L1[N],R1[N],tr[N][5],inv2,ans;
inline int id(int x,int y){return (x-1)*m+y;}

inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void add(int x,int t,int p){x++;for(;x<N;ub(x))(tr[x][p]+=t)%=Mod;}
inline int qsum(int x,int p){x++;int res=0;for(;x;db(x))(res+=tr[x][p])%=Mod;return res;}

signed main(){
	n=read(),m=read(),inv2=inv(2);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[id(i,j)]=1;
	c=read();
	for(int i=1,x,y;i<=c;i++)x=read(),y=read(),a[id(x,y)]=0;
	for(int i=1;i<=n;i++){
		L1[id(i,1)]=a[id(i,1)];
		R1[id(i,m)]=a[id(i,m)];
		for(int j=2;j<=m;j++)if(a[id(i,j)])L1[id(i,j)]=L1[id(i,j-1)]+1;
		for(int j=m-1;j>=1;j--)if(a[id(i,j)])R1[id(i,j)]=R1[id(i,j+1)]+1;
	}
	for(int j=2;j<m;j++){
		for(int l=1,r;l<=n;){
			if(!a[id(l,j)]){++l;continue;}
			r=l;while(r<n&&a[id(r+1,j)])++r;
			for(int i=l+1;i<r;i++){
				int ki=min(L1[id(i,j)],R1[id(i,j)])-1;
				int ktt=qsum(ki,0),kt2t=qsum(ki,1),kt=qsum(ki,2),kt2=qsum(ki,3);
				int sum=((ki-inv2)*ktt%Mod-kt2t*inv2%Mod-(ki-inv2)*kt%Mod*l%Mod+kt2*l%Mod*inv2%Mod)%Mod*(r-i)%Mod;
				sum=(sum+(ki-1)*ki%Mod*inv2%Mod*(qsum(2e6,4)-qsum(ki,4))%Mod*(r-i))%Mod;
				ans=(ans+sum)%Mod;
				ki=min(L1[id(i-1,j)],R1[id(i-1,j)])-1;
				add(ki,ki*(i-1),0),add(ki,ki*ki%Mod*(i-1),1),add(ki,ki,2),add(ki,ki*ki,3),add(ki,i-1-l,4);
			}
			for(int i=l;i<r-1;i++){
				int ki=min(L1[id(i,j)],R1[id(i,j)])-1;
				add(ki,-ki*i,0),add(ki,-(ki*ki%Mod*i),1),add(ki,-ki,2),add(ki,-(ki*ki),3),add(ki,-(i-l),4);
			}
			l=r+1;
		}
	}
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

