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

const int N=4e6+7,Mod=998244353,INF=1e9+7;
stack<int>s;
int T,n,cnt,ans,x,y;
char str[N];

int main(){
	T=read();
	while(T--){
		while(s.size())s.pop();
		n=read(),ans=cnt=0;
		
		scanf("%s",str+1);
		for(int i=1;i<=n;i++){
			if(str[i]=='0'||str[i]=='1')s.push(str[i]-'0');
			else if(s.size()<2)while(s.size())s.pop();
			else{
				x=s.top(),s.pop(),y=s.top(),s.pop();
				if(str[i]=='|'){
					if(x==2&&y==2)++ans,s.push(2);
					else if((x==2&&y==1)||(x==1&&y==2))s.push(1);
					else if(x==2||y==2)++ans,s.push(2);
					else s.push(x|y);
				}
				else if(str[i]=='&'){
					if(x==2&&y==2)++ans,s.push(2);
					else if((x==2&&y==0)||(y==2&&x==0))s.push(0);
					else if(x==2||y==2)++ans,s.push(2);
					else s.push(x&y);
				}
				else{
					if(x+y==1||x==2||y==2)++ans,s.push(2);
					else s.push(x|y);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
