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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,ans[N];
char s[N];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
    ans[n]=-1,ans[n-1]=n-1;
	for(int i=n-2;i>=1;i--){
		if(s[i]>s[i+2])ans[i]=i,printf("*");
		else if(s[i]==s[i+2]){
			int j=i+2;
			while(j<=n&&s[j]==s[j-2])++j;
			if(s[j]>s[j-2])ans[i]=i;
			else ans[i]=ans[i+1];
		}
		else ans[i]=ans[i+1];
		printf("(%d %d)\n",i,ans[i]);
	}
	for(int i=1;i<=n;i++){printf("[%d]",n);
		if(ans[i]!=-1)printf("%d ",n-i-1);
		else printf("%d ",n-i+1);
		int tot=0,R=i;
		for(int j=i;j<=n;j++){
			if(tot>=5)break;
			if(j!=ans[i]&&j!=ans[i]+1){
				printf("%c",s[j]);
				++tot;
			}
			R=j;
		}
		printf("...");
		tot=0;
		for(int j=n;j>R;j--){
			if(tot>=2)break;
			if(j!=ans[i]&&j!=ans[i+1]){
				printf("%c",s[j]);
				++tot;
			}
		}
		printf("\n");
	}
	return 0;
}
