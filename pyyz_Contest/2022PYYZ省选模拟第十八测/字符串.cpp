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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,f[N][N],ans;
char t[N],s[N];

int dp(int l,int r){
	if(f[l][r])return f[l][r];
	if(r<l)return 1;
	for(int i=l+1;i<=r;i++){
		for(int k=1;k<=i-l;k++)if((i-l+1)%k==0){
			int tag=1;
			for(int j=l+k;j<=i;j++)if(s[j]!=s[j-k]){tag=0;break;}
			if(tag)f[l][r]+=dp(i+1,r)*dp(l,l+k-1)%Mod;
		}
	}
	f[l][r]+=dp(l+1,r);
	f[l][r]%=Mod;
	return f[l][r];
}

signed main(){
	scanf("%s",t+1);
	n=strlen(t+1);
	int c=0;
	for(int i=1;i<=n;i++)if(t[i]=='1')++c;
	for(int i=0;i<(1<<c);i++){
		int T=0;
		for(int j=1;j<=n;j++){
			s[j]='0';
			if(t[j]=='1'){if(i&(1<<T))s[j]='1';++T;}
		}
		for(int a=0;a<=n;a++)for(int b=0;b<=n;b++)f[a][b]=0;
		ans+=dp(1,n);
		ans%=Mod;
	}
	printf("%lld\n",(ans+Mod)%Mod);
	return 0;
}

