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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=1e9+7,INF=1e9+7;
int n,a[N],f[N][16][16][2][2][2][2],ans;
inline void add(int& x,int y){x=(x+y)%Mod;return;}
char s[N];

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	int t=n;
	while(a[t]==0)--t;
	--a[t];
	for(int i=t+1;i<=n;i++)a[i]=9;
	if(t==1&&a[t]==0){
		for(int i=1;i<n;i++)a[i]=a[i+1];
		--n;
	}
	f[0][0][0][1][0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<10;j++){
			for(int pp=0;pp<10;pp++){
				for(int p=0;p<10;p++){
					for(int fl=0;fl<2;fl++){
						for(int tag=0;tag<2;tag++){
							for(int a00=0;a00<2;a00++){
								for(int a0=0;a0<2;a0++){
									int _fl=fl,_tag=tag,_a00=a0,_a0=a0;
									if(fl&&j>a[i])continue;
									if(fl&&j<a[i])_fl=0;
									if((j==p||j==pp)&&(!(a0==0||(a00==0&&j!=p))))_tag=1;
									if(j>0)_a0=1;
									add(f[i][p][j][_fl][_tag][_a00][_a0],f[i-1][pp][p][fl][tag][a00][a0]);
								}
							}
						}
					}
				}
			}
		}
	}
	for(int pp=0;pp<10;pp++)for(int p=0;p<10;p++)for(int fl=0;fl<2;fl++)for(int a00=0;a00<2;a00++)add(ans,-f[n][pp][p][fl][1][a00][1]);
	for(int i=1;i<=n;i++)for(int j=0;j<10;j++)for(int k=0;k<10;k++)for(int fl=0;fl<2;fl++)for(int tag=0;tag<2;tag++)for(int a0=0;a0<2;a0++)for(int a00=0;a00<2;a00++)f[i][j][k][fl][tag][a00][a0]=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	for(int i=1;i<=n;i++){
		for(int j=0;j<10;j++){
			for(int pp=0;pp<10;pp++){
				for(int p=0;p<10;p++){
					for(int fl=0;fl<2;fl++){
						for(int tag=0;tag<2;tag++){
							for(int a00=0;a00<2;a00++){
								for(int a0=0;a0<2;a0++){
									int _fl=fl,_tag=tag,_a00=a0,_a0=a0;
									if(fl&&j>a[i])continue;
									if(fl&&j<a[i])_fl=0;
									if((j==p||j==pp)&&(!(a0==0||(a00==0&&j!=p))))_tag=1;
									if(j>0)_a0=1;
									add(f[i][p][j][_fl][_tag][_a00][_a0],f[i-1][pp][p][fl][tag][a00][a0]);
								}
							}
						}
					}
				}
			}
		}
	}
	for(int pp=0;pp<10;pp++)for(int p=0;p<10;p++)for(int fl=0;fl<2;fl++)for(int a00=0;a00<2;a00++)add(ans,f[n][pp][p][fl][1][a00][1]);
	printf("%d\n",ans);
	return 0;
}

