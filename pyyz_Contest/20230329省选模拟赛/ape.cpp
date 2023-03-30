#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}

const int N=1024;

int n,q,u[N],v[N],w[N][N],f[N][N][4];

inline void _max(int &x,int y){
	if(y>x)x=y;
	return;
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++)u[i]=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)w[i][j]=read();
	}
	while(q--){
		int a=read(),b=read(),c=read(),d=read(),ans=0;
		for(int i=a;i<=b;i++){
			for(int j=c;j<=d;j++){
				for(int t=0;t<4;t++)f[i][j][t]=-1000000000;
			}
		}
		for(int i=a;i<=b;i++){
			for(int j=c;j<=d;j++){
				for(int t=0;t<4;t++){
					if(t==3)_max(f[i][j][t],w[i][j]-u[i]-v[j]);
					if((t&1)&&j<d){
						_max(f[i][j+1][3],f[i][j][t]+w[i][j+1]-v[j+1]);
						_max(f[i][j+1][1],f[i][j][t]);
					}
					if((t&2)&&i<b){
						_max(f[i+1][j][3],f[i][j][t]+w[i+1][j]-u[i+1]);
						_max(f[i+1][j][2],f[i][j][t]);
					}
					_max(ans,f[i][j][t]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
