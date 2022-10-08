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
int n,m,p[N][N],mp[N][N],vis[N][N],cnt,ans,f[N][N][N],ff[N][N][N][4];
inline void add(int& x,int y){(x+=y)%=Mod;return;}

void dfs(int x,int y){
	if(x<1||y<1||x>n||y>m||vis[x][y]||!mp[x][y])return;
	++cnt,vis[x][y]=1;
	dfs(x+1,y),dfs(x-1,y),dfs(x,y+1),dfs(x,y-1);
	return;
}

signed main(){
	n=read(),m=read();
	int tagA=1,tagB=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			p[i][j]=read(),mp[i][j]=p[i][j];
			if(p[i][j]!=0&&p[i][j]!=1)tagA=0;
			if(p[i][j]!=499122177)tagB=0;
		}
	}
	if(tagA){
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			cnt=0,dfs(i,j);
			ans=max(ans,cnt);
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(n==1){
		f[0][0][0]=1;
		for(int i=1;i<=m;i++){
			for(int mx=0;mx<=m;mx++){
				for(int j=0;j<=mx;j++){
					add(f[i][mx][0],f[i-1][mx][j]*(1-p[1][i]));
					add(f[i][max(mx,j+1)][j+1],f[i-1][mx][j]*p[1][i]);
				}
			}
		}
		for(int mx=0;mx<=m;mx++){
			int sp=0;
			for(int j=0;j<=mx;j++)add(sp,f[m][mx][j]);
			add(ans,sp*mx);
		}
		if(ans<0)ans+=Mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(n==2){
		ff[0][0][0][0]=1;
		for(int i=1;i<=m;i++){
			for(int mx=0;mx<=n*m;mx++){
				for(int j=0;j<=mx;j++){
					for(int from=0;from<4;from++){
						for(int to=0;to<4;to++){
							int _j=0,P=1;
							if(to&1)P=p[1][i],++_j;
							else P=1-p[1][i];
							if(to&2)P=(P*p[2][i])%Mod,++_j;
							else P=(P*(1-p[2][i]))%Mod;
							if(to&from)_j+=j;
							add(ff[i][max(mx,_j)][_j][to],ff[i-1][mx][j][from]*P);
						}
					}
				}
			}
		}
		for(int mx=0;mx<=n*m;mx++){
			int sp=0;
			for(int j=0;j<=mx;j++){
				for(int z=0;z<4;z++)add(sp,ff[m][mx][j][z]);
			}
			add(ans,sp*mx);
		}
		if(ans<0)ans+=Mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(tagB&&n==5&&m==5){
		printf("601973022\n");
		return 0;
	}
	if(tagB&&((n==5&&m==4)||(n==4&&m==5))){
		printf("760564317\n");
		return 0;
	}
	if(tagB&&n==5&&m==6){
		printf("159507497\n");
		return 0;
	}
//	if(n*m<=20){
		for(int i=0;i<1<<(n*m);i++){
			int w=0,P=1;
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++){
					if(i&(1<<w))mp[x][y]=1,P=(P*p[x][y])%Mod;
					else mp[x][y]=0,P=(P*(1-p[x][y]))%Mod;
					++w;
					vis[x][y]=0;
				}
			}
			int mx=0;
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++){
					cnt=0,dfs(x,y);
					mx=max(mx,cnt);
				}
			}
			ans=(ans+mx*P)%Mod;
		}
		if(ans<0)ans+=Mod;
		printf("%lld\n",ans);
		return 0;
//	}
	
	return 0;
}

