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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
int n,m,ans,L=1;
char s[N][N],c;
char t1[N][N];
vector<node> pos;

void myinit(){
	for(int i=1;i<=3;i++)t1[0][i]=t1[3][i]='-',t1[1][i]=t1[2][i]=' ';
	t1[0][0]=t1[0][4]=t1[3][0]=t1[3][4]='+';
	t1[1][0]=t1[2][0]=t1[1][4]=t1[2][4]='|';
	return;
}

signed main(){
	n=read(),m=read();
	myinit();
	
	for(int i=1;i<=n;i++){
		c=getchar();
		while(c!='+'&&c!='|'&&c!='.')c=getchar();
		s[i][1]=c;
		for(int j=2;j<=m;j++)s[i][j]=getchar();
	}
	while(1){
		pos.clear();
		int ttag=0;
		for(int i=1;i<=n;i++){
			for(int j=L;j<=m;j++){
//				printf("%c",s[i][j]);
				if(s[i][j]=='/')ttag=1;
			}
//			printf("\n");
		}
		if(!ttag)break;
		for(int i=1;i+3<=n;i++){
			for(int j=L;j+4<=m;j++){
				int tag=1;
				for(int a=0;a<4;a++){
					for(int b=0;b<5;b++)if(s[i+a][j+b]!=t1[a][b]){tag=0;break;}
					if(!tag)break;
				}
				for(int a=i;a<=n;a++)if(!((s[a][j]=='|'||s[a][j]=='+')&&(s[a][j+4]=='|'||s[a][j+4]=='+'))){tag=0;break;}
				if(!tag)continue;
				++ans,pos.push_back(node(i-2,j+2));
//				printf("(%d %d)\n",i,j);
			}
		}
		for(unsigned i=0;i<pos.size();i++){
			int x=pos[i].x,y=pos[i].y;
			if(x<1||y+4>m)continue;
			for(int a=0;a<4;a++)for(int b=0;b<5;b++)s[x+a][y+b]=t1[a][b];
			s[x+4][y]='.';
		}
		n-=2,L+=2;
		if(pos.empty())break;
	}
	printf("%d\n",ans);
	return 0;
}

