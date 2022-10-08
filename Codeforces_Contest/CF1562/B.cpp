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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];
char s[N];

int main(){
	T=read();
	while(T--){
		n=read();
		int y=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)a[i]=s[i]-'0';
		
		for(int i=1;i<=n;i++)if((a[i]%2==0&&a[i]>2)||a[i]==1||a[i]==9){
			printf("1\n%d\n",a[i]),y=1;
			break;
		}
		if(y)continue;
		
		for(int i=2;i<=n;i++)if(a[i]==2){
			printf("2\n%d%d\n",a[i-1],a[i]),y=1;
			break;
		}
		if(y)continue;
		
		for(int i=1;i<=n&&y==0;i++)for(int j=i+1;j<=n;j++){
			int v=a[i]*10+a[j];
			if(v%3==0||v%5==0||v%7==0||v%11==0||v%13==0){
				printf("2\n%d\n",v),y=1;
				break;
			}
		}
	}
	return 0;
}
