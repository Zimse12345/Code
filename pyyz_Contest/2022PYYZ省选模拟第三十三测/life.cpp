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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],f[N][2][2][2],_2[1000000],ans,inv2;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline void add(int& x,int y){x=(x+y)%Mod;return;}
inline int calc(int x,int y){return x?inv2:(y?0:1);}

signed main(){
	n=read();
	_2[0]=1,inv2=qp(2,Mod-2);
	for(int i=1;i<1000000;i++)_2[i]=(_2[i-1]*2)%Mod;
	for(int i=1;i<=n;i++)a[i]=read();
	int T=0; 
	f[T][0][0][0]=1;
	for(int pos=n;pos>=1;pos--){
		T^=1;
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				for(int z=0;z<2;z++){
					f[T][x][y][z]=0;
				}
			}
		}
		for(int cl=0;cl<2;cl++){
			if((cl^1)==a[pos])continue;
			int rm=n-pos;
			for(int x=0;x<2;x++){
				for(int y=0;y<2;y++){
					for(int z=0;z<2;z++){
						if(cl==0){
							add(f[T][x|1][y^1][z],_2[rm]*calc(z,0)%Mod*f[T^1][x][y][z]);
							add(f[T][x][y][z],_2[rm]*calc(z,1)%Mod*f[T^1][x][y][z]);
						}
						else{
							add(f[T][x][y^1][z|1],_2[rm]*calc(x,0)%Mod*f[T^1][x][y][z]);
							add(f[T][x][y][z],_2[rm]*calc(x,1)%Mod*f[T^1][x][y][z]);
						}
					}
				}
			}
		}
	}
	add(ans,f[T][0][1][0]+f[T][0][1][1]+f[T][1][1][0]+f[T][1][1][1]);
	printf("%lld\n",ans);
	return 0;
}

