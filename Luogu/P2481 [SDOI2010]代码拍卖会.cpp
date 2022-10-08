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

const int N=1e3+7,Mod=999911659,INF=1e9+7;
int n,p,t[N],T[N][N],f[N][N][20],ans;
int st[N],tot,pre[N];
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}

inline int g(int x,int y){
	if(x==0)return 1;
	if(y==0)return 0;
	y=(x+y-1)%Mod;
	int res=y;
	for(int i=y-1;i>=y-x+1;i--)res=(res*i)%Mod;
	for(int i=1;i<=x;i++)res=(res*inv(i))%Mod;
	return res;
}


signed main(){
	n=read(),p=read();
	int x=0;
	for(int i=1;i<=n;i++){
		x=(x*10+1)%p;
		if(pre[x]){
			int len=i-pre[x],rm=n-i+1,k=rm/len;
			for(int j=pre[x];j<=tot;j++)t[st[j]]+=k;
			for(int j=pre[x];j<pre[x]+rm%len;j++)t[st[j]]++;
			x=st[pre[x]+(rm%len-1+len)%len];
			break;
		}
		else st[++tot]=x,pre[x]=tot,++t[x];
	}
	for(int i=0;i<p;i++)for(int j=0;j<10;j++)T[i][j]=g(j,t[i]);
	for(int i=0;i<10;i++)f[0][0][i]=T[0][i];
	for(int i=1;i<p;i++){
		for(int a=0;a<p;a++){
			for(int j=0;j<10;j++)if(f[i-1][a][j]!=0){
				for(int k=0;k+j<10;k++){
					(f[i][(a+i*k)%p][j+k]+=f[i-1][a][j]*T[i][k])%=Mod;
				}
			}
		}
	}
	for(int i=0;i<9;i++)(ans+=f[p-1][(p-x)%p][i])%=Mod;
	printf("%lld\n",ans);
	return 0;
}

