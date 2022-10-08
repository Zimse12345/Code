#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

#define int long long

const int N=2048,B1=41,B2=43,Mod=998244353;
const double k1=1.2,k3=2,b=0.75;

int n,m;
double Len[N],Lave;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x==A.x?y<A.y:x<A.x;}
};

map<node,int> vis[N];
map<node,double> idf;
map<node,int> query;

signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(1){
			int h1=0,h2=0;
			while(c>='a'&&c<='z')h1=(h1*B1+c-'a')%Mod,h2=(h2*B2+c-'a')%Mod,c=getchar();
			vis[i][node(h1,h2)]++,Len[i]+=1;
			idf[node(h1,h2)]=1;
			while(c<'a'||c>'z'){
				if(c=='\n'||c=='\r'||c==EOF||c=='\0')break;
				c=getchar();
			}
			if(c=='\n'||c=='\r'||c==EOF||c=='\0')break;
		}
		Lave+=Len[i];
	}
	Lave/=double(n);
	for(map<node,double>::iterator it=idf.begin();it!=idf.end();it++){
		double df=0;
		for(int i=1;i<=n;i++)if(vis[i][it->first])df+=1;
		it->second=log(double(double(n)-df+0.5)/double(df+0.5));
	}
	while(m--){
		char c=getchar();
		while(c<'0'||c>'9')c=getchar();
		int id=0;
		while(c>='0'&&c<='9')id=id*10+c-'0',c=getchar();
		while(c<'a'||c>'z')c=getchar();
		query.clear();
		while(1){
			int h1=0,h2=0;
			while(c>='a'&&c<='z')h1=(h1*B1+c-'a')%Mod,h2=(h2*B2+c-'a')%Mod,c=getchar();
			query[node(h1,h2)]++;
			while(c<'a'||c>'z'){
				if(c=='\n'||c=='\r'||c==EOF||c=='\0')break;
				c=getchar();
			}
			if(c=='\n'||c=='\r'||c==EOF||c=='\0')break;
		}
		double K=k1*(1.0-b+b*(Len[id]/Lave));
		double RSV=0;
		for(map<node,int>::iterator it=query.begin();it!=query.end();it++){
			double tf=vis[id][it->first];
			double W1=(k1+1.0)*tf/(K+tf);
			double W2=(k3+1.0)*double(it->second)/(k3+double(it->second));
			RSV+=idf[it->first]*W1*W2*double(it->second);
		}
		printf("%.4lf\n",RSV);
	}
	return 0;
}

