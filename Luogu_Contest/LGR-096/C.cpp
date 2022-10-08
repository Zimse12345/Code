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

const int N=2e4+7,Mod=998244353,INF=1e9+7;
int n,p1[N],p2[N],p3[N],p4[N],p5[N],t;
char s[N];

int main(){
	n=read();
	scanf("%s",s+1);
	while(1){
		int L=0,R=n+1;
		for(int i=1;i<=n;i++)if(s[i]==s[i-1]){L=i;break;}
		for(int i=n;i>=1;i--)if(s[i]==s[i+1]){R=i;break;}
		if(L==0||R==n+1)break;
		if(L-1==R){
			char c=s[L]+1;
			if(c=='D')c='A';
			if(L!=n&&s[L+1]==c)++c;
			if(c=='D')c='A';
			++t;
			p1[t]=p2[t]=L,p3[t]=p4[t]=p5[t]=c;
			break;
		}
		char d[3]={'D','D','D'},c1=s[L],c2=s[R],c3='A';
		++c1,++c2;
		if(c1=='D')c1='A';
		if(c2=='D')c2='A';
		if(c2==c1)++c2;
		if(c2=='D')c2='A';
		if(c1=='A'||c2=='A'){
			c3='B';
			if(c1=='B'||c2=='B')c3='C';
		}
		//printf("(%d %d %c%c%c)\n",L,R,c1,c2,c3);
		if(s[L]!=s[R]){
			d[s[L]-'A']=c1,d[s[R]-'A']=c2;
			if(d[0]=='D')d[0]=c3;
			else if(d[1]=='D')d[1]=c3;
			else if(d[2]=='D')d[2]=c3;
		}
		else{
			d[s[L]-'A']=c1;
			if(d[0]=='D')d[0]=c2;
			else if(d[1]=='D')d[1]=c2;
			else if(d[2]=='D')d[2]=c2;
			if(d[0]=='D')d[0]=c3;
			else if(d[1]=='D')d[1]=c3;
			else if(d[2]=='D')d[2]=c3;
		}
		for(int i=L;i<=R;i++)s[i]=d[s[i]-'A'];
		++t;
		p1[t]=L,p2[t]=R,p3[t]=d[0],p4[t]=d[1],p5[t]=d[2];
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)printf("%d %d %c%c%c\n",p1[i],p2[i],p3[i],p4[i],p5[i]);
	return 0;
}
