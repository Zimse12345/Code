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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int T,n;
char c,s[N];

int main(){
	T=read();
	while(T--){
    	n=read();
    	cin>>c;
    	scanf("%s",s+1);
    	int tag=0,sd=0;
    	for(int i=1;i<=n;i++)if(s[i]==c)tag++;
    	if(tag==n){
    		printf("0\n");
    		continue;
		}
		if(s[n]==c){
			printf("1\n%d\n",n);
			continue;
		}
		
		for(int i=2;i<=n;i++){
			int cnt=0;
			for(int j=i;j<=n;j+=i)if(s[j]!=c)cnt=1;
			if(!cnt){
				sd=1;
				printf("1\n%d\n",i);
				break;
			}
		}
		if(sd==1)continue;
		printf("2\n%d %d\n",n-1,n);
	}
	return 0;
}
