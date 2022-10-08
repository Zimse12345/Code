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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,w,h,x_1,y_1,x_2,y_2;

signed main(){
	T=read();
	while(T--){
		w=read(),h=read(),x_1=read(),y_1=read(),x_2=read(),y_2=read();
		int x=max(x_1,x_2)-min(x_1,x_2),y=max(y_1,y_2)-min(y_1,y_2);
		int u=read(),v=read();
		if(!((max(u,x)<=w&&y+v<=h)||(x+u<=w&&max(y,v)<=h))){
			printf("-1\n");
			continue;
		}
		
		int ans=1e16,res;
		if(y+v<=h){
			res=max(0ll,v-y_1);
			ans=min(ans,res);
			res=max(0ll,y_2-h+v);
			ans=min(ans,res);
		}
		if(x+u<=w){
			res=max(0ll,u-x_1);
			ans=min(ans,res);
			res=max(0ll,x_2-w+u);
			ans=min(ans,res);
		}
		double p=ans;
		printf("%.7f\n",p);
	}
	return 0;
}
