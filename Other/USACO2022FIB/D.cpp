#include <cstdio>
#include <algorithm>

using namespace std;

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

const int N=2e3+7;
int n,a[N][N],t[N],d[N][N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(!t[i])d[a[i][j]][i]=1;
			if(a[i][j]==i)t[i]=j;
		}
	}
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]|=(d[i][k]&d[k][j]);
	for(int i=1,j;i<=n;i++){
		j=1;
		while(!(d[a[i][j]][i]&d[i][a[i][j]]))++j;
		printf("%d\n",a[i][j]);
	}
	return 0;
}

