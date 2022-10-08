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
 
const int N=800,Mod=1e9+7;
int n,st[N],top,nxt[N],f[N][N][3][3],vis[N][N];
char s[N];
void add(int &x,int v){x=(x+v)%Mod;return;}
 
void dp(int l,int r){
	if(vis[l][r]++||l==r)return;
	if(l+1==r){f[l][r][0][1]=f[l][r][0][2]=f[l][r][1][0]=f[l][r][2][0]=1;return;}
	if(nxt[l]==r){
		dp(l+1,r-1);
		for(int lc=0;lc<3;lc++)for(int rc=0;rc<3;rc++){
			int x=f[l+1][r-1][lc][rc];
			if(lc!=1)add(f[l][r][1][0],x);
			if(lc!=2)add(f[l][r][2][0],x);
			if(rc!=1)add(f[l][r][0][1],x);
			if(rc!=2)add(f[l][r][0][1],x);
		}
	}
	else{
		int L1=l,R1=nxt[l],L2=nxt[l]+1,R2=r;
		dp(L1,R1),dp(L2,R2);
		for(int l1=0;l1<3;l1++)for(int r1=0;r1<3;r1++){
			for(int l2=0;l2<3;l2++)for(int r2=0;r2<3;r2++)if(r1==0||(r1!=l2)){
				int x=(f[L1][R1][l1][r1]*f[L2][R2][l2][r2])%Mod;
				add(f[l][r][l1][r2],x);
			}
		}
	}
	return;
}
 
signed main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='(')st[++top]=i;
		else nxt[st[top--]]=i;
	}
	dp(1,n);
	int ans=0;
	for(int lc=0;lc<3;lc++)for(int rc=0;rc<3;rc++)add(ans,f[1][n][lc][rc]);
	printf("%lld\n",ans);
	return 0;
}
