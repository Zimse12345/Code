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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N][N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int t[2]={0,0};
				++t[s[i][j]-'0'];
				++t[s[j][n-i+1]-'0'];
				++t[s[n-i+1][n-j+1]-'0'];
				++t[s[n-j+1][i]-'0'];
//				printf("(%d %d %d %d)\n",i,j,t[0],t[1]);
				if(t[0]==0)continue;
				if(t[0]==1){
					ans+=1;
					s[i][j]=s[j][n-i+1]=s[n-i+1][n-j+1]=s[n-j+1][i]=0;
				}
				if(t[0]==2){
					ans+=2;
					s[i][j]=s[j][n-i+1]=s[n-i+1][n-j+1]=s[n-j+1][i]=0;
				}
				if(t[0]==3){
					ans+=1;
					s[i][j]=s[j][n-i+1]=s[n-i+1][n-j+1]=s[n-j+1][i]=1;
				}
				if(t[0]==4)continue;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

