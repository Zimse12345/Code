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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
char s[N],t[N];
int bd[N];
int n,k,ans;

signed main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1),k=read();
	for(int i=2;i<=n;i++){
		int j=bd[i-1];
		while(j&&s[j+1]!=s[i])j=bd[j];
		if(s[j+1]==s[i])++j;
		bd[i]=j;
	}
	int len=strlen(t+1);
	int _n=n,xx=0,xxx=0;
	for(int I=1;I<=k;I++){
		int x=bd[n];
		while(x*2>=n)x=bd[x];
		int t=0;
		for(int j=x+1;j<=n-x;j++){
			++t,s[n+t]=s[j];
		}
		while(t--){
			++n;
			int j=bd[n-1];
			while(j&&s[j+1]!=s[n])j=bd[j];
			if(s[j+1]==s[n])++j;
			bd[n]=j;
		}
		printf("%d  +%d(%d)\n",n,n-_n,x+n);
		for(int i=1;i<=n;i++){
			printf("%c",s[i]);
			if(i==_n)printf(" | ");
		}
		printf("\n");
		if(I==1)xx=n-_n;
		if(I==2){
			xxx=n-_n;
			if(len==1){
				
			}
		}
		_n=n;
	}
	for(int i=1;i+len-1<=n;i++){
		int tag=1;
		for(int j=1;j<=len;j++)if(s[i+j-1]^t[j]){tag=0;break;}
		ans+=tag;
	}
	printf("%d\n",ans);
	return 0;
}

