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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,dx[4]={1,0,-1,1},dy[4]={0,1,1,1};
char s[N][N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int d=0;d<4;d++){
				int tag=0;
				for(int k=0;k<6;k++){
					int x=i+dx[d]*k,y=j+dy[d]*k;
					if(1<=x&&x<=n&&1<=y&&y<=n){
						if(s[x][y]=='.')++tag;
					}
					else tag=3;
				}
				if(tag<=2){
					printf("Yes\n");
					return 0;
				}
			}
		}
	}
	printf("No\n");
	return 0;
}

