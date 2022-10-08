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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=1e9+7;
int n,a[N],pre[N][N],suf[N][N],ans;

signed main(){
	n=read();
	pre[0][0]=suf[n+1][0]=1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)for(int j=0;j<256;j++)pre[i][j]=(pre[i-1][j]+pre[i-1][j^a[i]])%Mod;
	for(int i=n;i>=1;i--)for(int j=0;j<256;j++)suf[i][j]=(suf[i+1][j]+suf[i+1][j^a[i]])%Mod;
	for(int i=1;i<=n;i++){
		for(int x=0;x<256;x++){
			for(int y=0;y<256;y++)if(pre[i-1][x]&&suf[i+1][y]){
				if(pre[i-1][x]>0){
					int v=x^y;
					if((v^a[i])==0||v>a[i])ans=(ans+1ll*pre[i-1][x]*suf[i+1][y])%Mod;
				}
			}
		} 
	}
	printf("%d\n",ans);
	return 0;
}

