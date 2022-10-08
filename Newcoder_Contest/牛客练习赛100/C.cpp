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
char s[N];

signed main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int a=0,b=0,c=0,sum=0;
	for(int i=1;i<=n;i++){
		s[i]-='0';
		if(s[i]%3==0&&s[i]!=0)++a;
		if(s[i]%3==1)++b;
		if(s[i]%3==2)++c;
		sum+=s[i];
	}
	sum%=3;
	if(sum==0){
		--a;
		if(a<0)printf("yukari\n");
		else{
			if(b==c&&a)printf("kou\n");
			else printf("yukari\n");
		}
	}
	else if(sum==1){
		--b;
		if(b<0)printf("yukari\n");
		else{
			if(b==c&&a)printf("kou\n");
			else printf("yukari\n");
		}
	}
	else{
		--c;
		if(c<0)printf("yukari\n");
		else{
			if(b==c&&a)printf("kou\n");
			else printf("yukari\n");
		}
	}
	return 0;
}

