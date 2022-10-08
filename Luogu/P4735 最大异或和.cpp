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
#define Lid (ch[id][0])
#define Rid (ch[id][1])

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,rt[N],v[N*32],ch[N*32][2],a[N],tot,ct;
char op;

void add(int x){
	x^=a[ct],a[++ct]=x;
	int id=++tot,_id=rt[ct-1];
	rt[ct]=id,v[id]=v[_id]+1;
	for(int j=30;j>=0;j--){
		if(x&(1<<j))Lid=ch[_id][0],Rid=++tot,id=Rid,_id=ch[_id][1];
		else Rid=ch[_id][1],Lid=++tot,id=Lid,_id=ch[_id][0];
		v[id]=v[_id]+1;
	}
	return;
}

signed main(){
	n=read(),m=read();
	add(0);
	for(int i=1;i<=n;i++)add(read());
	for(int i=1,l,r,x;i<=m;i++){
		do{op=getchar();}while(op!='A'&&op!='Q');
		if(op=='A')add(read());
		else{
			l=read(),r=read(),x=read()^a[ct];
			int id=rt[r],_id=rt[l-1],ans=0;
			for(int j=30;j>=0;j--){
				if(x&(1<<j)){
					if(v[Lid]-v[ch[_id][0]])ans+=(1<<j),id=Lid,_id=ch[_id][0];
					else id=Rid,_id=ch[_id][1];
				}
				else{
					if(v[Rid]-v[ch[_id][1]])ans+=(1<<j),id=Rid,_id=ch[_id][1];
					else id=Lid,_id=ch[_id][0];
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

