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

const int N=1e6+7,H1=41,H2=43,M1=998244353,M2=6662333;
int T,n,Lh[N],Rh[N];
int qp(int x,int k,int M){int res=1;while(k){if(k&1ll)res=(res*x)%M;x=(x*x)%M,k/=2;}return res;}
char s[N];

int Lhash(int l,int r){
	--l;
	return ((Lh[r]-Lh[l]*qp(H1,r-l,M1))%M1+M1)%M1;
}

int Rhash(int l,int r){
	++r;
	return ((Rh[l]-Rh[r]*qp(H1,r-l,M1))%M1+M1)%M1;
}

bool ck(int l,int r){
	int len=r-l+1,m=(l+r)>>1;
	if(len&1)return Lhash(l,m-1)==Rhash(m+1,r);
	return Lhash(l,m)==Rhash(m+1,r);
	return true;
}

signed main(){
	T=read();
	while(T--){
		int ans=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)s[i]-='a'-1;
		for(int i=1;i<=n;i++)Lh[i]=(Lh[i-1]*H1+s[i])%M1;
		Rh[n+1]=0;
		for(int i=n;i>=1;i--)Rh[i]=(Rh[i+1]*H1+s[i])%M1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(ck(i,j)&&ck(j+1,k)){
						ans=(ans+i*k)%1000000007;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

