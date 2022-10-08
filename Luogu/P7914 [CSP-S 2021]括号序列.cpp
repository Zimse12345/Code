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

const int N=500+7,Mod=1e9+7,INF=1e9+7;
int n,k,vis[N][N],f[N][N],g[N][N],q[N][N],p[N][N];
char s[N];

void dp(int l,int r){
	if(vis[l][r]++)return;
	int tag=1;
	for(int i=l;i<=r;i++)if(!(s[i]=='*'||s[i]=='?')){tag=0;break;}
	if(r-l+1<=k&&l<=r)g[l][r]=tag;
	
	if(l>r)f[l][r]=1;
	else if(l==r)f[l][r]=0;
	else if(l+1==r){
		if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?'))f[l][r]=1;
	}
	else if(l+1<r){
		for(int i=l;i<=r-2;i++){
			if((s[i]=='*'||s[i]=='?')&&i-l+1<=k)dp(i+1,r),q[l][r]+=f[i+1][r];
			else break;
		}
		for(int i=r;i>=l+2;i--){
			if((s[i]=='*'||s[i]=='?')&&r-i+1<=k){
				dp(l,i-1),p[l][r]+=f[l][i-1];
			}
			else break;
		}
		for(int i=l+1;i<=r;i++){
			dp(l+1,i-1),dp(i+1,r);
			if((s[l]=='('||s[l]=='?')&&(s[i]==')'||s[i]=='?')){
				f[l][r]+=(f[l+1][i-1]+g[l+1][i-1]+q[l+1][i-1]+p[l+1][i-1])%Mod*
				(q[i+1][r]+f[i+1][r])%Mod;
			}
		}
	}
	f[l][r]%=Mod,q[l][r]%=Mod,p[l][r]%=Mod;
	return;
}

signed main(){
	n=read(),k=read();
	scanf("%s",s+1);
	dp(1,n);
	printf("%lld\n",f[1][n]);
	return 0;
}
