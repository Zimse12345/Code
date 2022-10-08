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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=100+7,Mod=998244353,INF=1e9+7;
int T,n,t[N][N],q[N],c;
char s[N],p[4]={'X','+','-','='};

signed main(){
	T=read();
	while(T--){
		n=read(),c=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)if(s[i]=='2')q[++c]=i;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			if(i==j)t[i][j]=0;
			else t[i][j]=3;
		}
		for(int i=1;i<c;i++)t[q[i]][q[i+1]]=1,t[q[i+1]][q[i]]=2;
		t[q[c]][q[1]]=1,t[q[1]][q[c]]=2;
		
		if(c==1||c==2)printf("No\n");
		else{
			printf("Yes\n");
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					printf("%c",p[t[i][j]]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
