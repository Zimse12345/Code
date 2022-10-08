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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=270000,M=60,Mod=998244353;
int n,a[N],f[N][M],ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),f[i][a[i]]=i,ans=max(ans,a[i]);
	for(int j=2;j<60;j++){
		for(int i=1;i<=n;i++){
			if(f[i][j-1]&&f[f[i][j-1]+1][j-1]){
				f[i][j]=f[f[i][j-1]+1][j-1],ans=max(ans,j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
