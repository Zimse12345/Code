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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=512;
const int prime[8]={2,3,5,7,11,13,17,19};
int n,p,f[256][256],g[256][256],vis[N],ans;
unsigned z[N];

void add(int& x,int y){(x+=y)%=p;return;}
bool isp(int x){
	for(int i=2;i*i<=x;i++)if(!(x%i))return false;
	return true;
}

signed main(){
	n=read(),p=read();
	f[0][0]=1;
	for(int i=2;i<=n;i++){
		for(unsigned j=0;j<8;j++){
			if(!(i%prime[j]))z[i]|=(1<<j);
		}
	}
	for(int i=n;i>19;i--)if(isp(i)){
		for(int j=i;j<=n;j+=i){
			vis[j]=1;
			for(unsigned y=255;y<256;y--){
				for(unsigned x=255;x<256;x--){
					add(g[x|z[j]][y],f[x][y]+g[x][y]);
				}
			}
		}
		for(int x=0;x<256;x++){
			for(int y=0;y<256;y++)add(f[x][y],g[x][y]),add(f[y][x],g[x][y]),g[x][y]=0;
		}
	}
	for(int i=2;i<=n;i++)if(!vis[i]){
		for(unsigned x=255;x<256;x--){
			for(unsigned y=255;y<256;y--){
				add(f[x|z[i]][y],f[x][y]);
				add(f[x][y|z[i]],f[x][y]);
			}
		}
	}
	for(unsigned x=0;x<256;x++){
		for(unsigned y=0;y<256;y++)if(!(x&y))add(ans,f[x][y]);
	}
	printf("%lld\n",ans);
	return 0;
}

