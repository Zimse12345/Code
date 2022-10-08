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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n;
int t[N];
char s[N];

char query1(int x){
	printf("? 1 %d\n",x);
	fflush(stdout);
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	return c;
}

int query2(int x,int y){
	printf("? 2 %d %d\n",x,y);
	fflush(stdout);
	return read();
}

signed main(){
	n=read();
	s[1]=query1(1);
	int d=1;
	for(int i=2;i<=n;i++){
		int p=query2(1,i);
		if(p!=d){
			s[i]=query1(i);
			++d;
		}
		else{
			int L=1,R=d-1,w=d;
			while(L<=R){
				int M=(L+R)/2,J=i,k=0;
				for(int I='a';I<='z';I++)t[I]=0;
				for(int j=i-1;j;j--){
					if(!t[s[j]])t[s[j]]=1,++k;
					if(k==M){J=j;break;}
				}
				int q=query2(J,i);
				if(q==M)w=M,R=M-1;
				else L=M+1;
			}
			for(int I='a';I<='z';I++)t[I]=0;
			for(int j=i-1;j;j--){
				if(!t[s[j]])t[s[j]]=1,--w;
				if(!w){s[i]=s[j];break;}
			}
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%c",s[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}

