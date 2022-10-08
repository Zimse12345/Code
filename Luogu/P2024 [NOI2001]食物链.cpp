#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std; 

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();
return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=0x3f3f3f3f;
int n,k,fa[N],ans,vis[N];

int f(int x){
	if(x!=fa[x])fa[x]=f(fa[x]);
	return fa[x];
}

void lk(int ty,int x,int y){
	if(ty==1)fa[f(x)]=f(y),fa[f(x+n)]=f(y+n),fa[f(x+n*2)]=f(y+n*2);
	else fa[f(x)]=f(y+n),fa[f(x+n)]=f(y+n*2),fa[f(x+n*2)]=f(y);
	return;
}

int main(){
	n=read(),k=read();
	
	for(int i=1;i<=3*n;i++)fa[i]=i;
	while(k--){
		int ty=read(),x=read(),y=read();
		if(x>n||y>n||(x==y&&ty==2)){
			++ans;
			continue;
		}
		
		if(ty==1){
			if(f(x)==f(y+n)||f(x+n)==f(y))++ans;
			else lk(ty,x,y);
		}
		if(ty==2){
			if(f(x)==f(y)||f(x+n)==f(y))++ans;
			else lk(ty,x,y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
