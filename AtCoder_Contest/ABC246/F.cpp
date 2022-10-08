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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,L,a[N],ans;
char s[N];

inline int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

signed main(){
	n=read(),L=read();
	for(int i=0;i<n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int j=1;j<=len;j++)a[i]|=(1<<(s[j]-'a'));
	}
	for(int i=1;i<(1<<n);i++){
		int b=(1<<26)-1,sig=-1;
		for(int j=0;j<n;j++)if(i&(1<<j)){
			b&=a[j];
			sig=-sig;
		}
		int cnt=0;
		for(int j=0;j<26;j++)if(b&(1<<j))++cnt;
		ans=(ans+sig*qp(cnt,L))%Mod;
	}
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

