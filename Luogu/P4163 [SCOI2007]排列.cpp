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
int T,d,n,f[4000][2000],tot[N];
char s[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),d=read();
		for(int i=0;i<10;i++)tot[i]=0;
		for(int i=1;i<=n;i++)++tot[s[i]-'0'];
		
		for(int i=0;i<(1<<n);i++)for(int j=0;j<d;j++)f[i][j]=0;
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<d;j++)if(f[i][j]){
				for(int k=1;k<=n;k++)if(!(i&(1<<(k-1)))){
					int t=i|(1<<(k-1));
					f[t][(j*10+s[k]-'0')%d]+=f[i][j];
				}
			}
		}
		int p=1;
		for(int i=0;i<10;i++){
			while(tot[i]>1)p*=tot[i],--tot[i];
		}
		printf("%lld\n",f[(1<<n)-1][0]/p);
	}
	return 0;
}

