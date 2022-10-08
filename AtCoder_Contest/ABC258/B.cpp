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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
char s[N][N],ans[N],ss[N];
int n;

void qwq(){
	for(int i=0;i<n;i++){
		if(ss[i]>ans[i]){
			for(int j=0;j<n;j++)ans[j]=ss[j];
			return;
		}
		if(ss[i]<ans[i])return;
	}
	return;
}

const int dx[8]={0,1,1,1,0,-1,-1,-1},dy[8]={1,1,0,-1,-1,-1,0,1};

signed main(){
	n=read();
	for(int i=0;i<n;i++)scanf("%s",s[i]),ans[i]=0;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int w=0;w<8;w++){
				int X=x,Y=y;
				for(int t=0;t<n;t++){
					ss[t]=s[X][Y];
					X=(X+dx[w]+n)%n;
					Y=(Y+dy[w]+n)%n;
				}
				qwq();
			}
		}
	}
	for(int i=0;i<n;i++)printf("%c",ans[i]);
	printf("\n");
	return 0;
}

