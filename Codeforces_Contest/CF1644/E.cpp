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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7;
int T,n,q,dx[N],dy[N],ans;
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		q=strlen(s+1);
		dx[q+1]=dy[q+1]=ans=0;
		for(int i=q;i>=1;i--){
			dx[i]=dx[i+1],dy[i]=dy[i+1];
			if(s[i]=='R')++dx[i];
			else ++dy[i];
		}
		if(!dx[1]||!dy[1]){
			printf("%lld\n",n);
			continue;
		} 
		int x=1,y=1,p=0;
		for(int i=1;i<=q;i++){
			if(s[i]=='R')++x;
			else ++y;
			if(s[i]!=s[i+1]){
				if(s[i]=='R')dy[i]=dy[i+1];
				else dx[i]=dx[i+1];
				p=i;
				break;
			}
			++ans;
		}
		ans+=(n-x+1)*(n-y+1)-dx[p+1]*dy[p+1]+1;
		printf("%lld\n",ans);
	}
	return 0;
}

