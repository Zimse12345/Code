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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m;
char a[N],s[N],b[N];

signed main(){
	T=read();
	while(T--){
		scanf("%s %s",a+1,s+1),n=strlen(a+1),m=strlen(s+1);
		int L=n,p=0,R=m,tag=1;
		while(1){
			if(a[L]<=s[R])b[++p]=s[R]-a[L]+'0',--R,--L;
			else if(R==1){tag=0;break;}
			else{
				int v=s[R]-'0'+(s[R-1]-'0')*10;
				int va=a[L]-'0';
				if(v-va>9||v-va<0){tag=0;break;}
				b[++p]=v-va+'0',R-=2,--L;
			}
			if(R<=0)break;
			if(L<=0){
				for(int i=R;i>=1;i--)b[++p]=s[i];
				break;
			}
		}
		if(tag==0||L)printf("-1\n");
		else{
			while(b[p]=='0')--p;
			for(int i=p;i>=1;i--)printf("%c",b[i]);
			printf("\n");
		}
	}
	return 0;
}

