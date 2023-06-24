// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int MB=1<<24;
struct FastIO{
    char ib[MB+100],*p,*q;
    char ob[MB+100],*r,stk[128];
    int tp;
    FastIO(){p=q=ib,r=ob,tp=0;}
    ~FastIO(){fwrite(ob,1,r-ob,stdout);}
    char read_char(){
        if(p==q){
            p=ib,q=ib+fread(ib,1,MB,stdin);
            if(p==q)return 0;
        }
        return *p++;
    }
    template<typename T>
    void read_int(T& x){
        char c=read_char(),l=0;
        for(x=0;!isdigit(c);c=read_char())l=c;
        for(;isdigit(c);c=read_char())x=x*10-'0'+c;
        if(l=='-')x=-x;
    }
    
    void write_char(char c){
        if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
        *r++=c;
    }
    template<typename T>
    void write_int(T x){
        if(x<0)write_char('-'),x=-x;
        do stk[++tp]=x%10+'0';
        while(x/=10);
        while(tp)write_char(stk[tp--]);
    }
}IO;

const int N=1.01e6,M=65535;
int T,min_N,max_N,m,ans[N],num[N];
double A,B,C,D;

inline int rd(){
    int x=rand()%8192,y=rand()%8192;
    return x*8192+y;
}

struct node{
    int id,val;
    node(int id=0,int val=0):id(id),val(val){}
    bool operator < (const node &_)const{return val<_.val;}
}p[N];

inline int Round(double val){
    return (val>0.0)?(val+0.5):(val-0.5); 
}

struct HashMap{
	int hd[M+1],nx[N],cnt;int val[N];
	inline void Ins(int x){val[++cnt]=x,nx[cnt]=hd[x&M],hd[x&M]=cnt;}
	inline bool Find(int x){for(int i=hd[x&M];i;i=nx[i])if(val[i]==x)return 1;return 0;}
	inline void Clear(){if(cnt*4>M)memset(hd,0,sizeof(hd)),cnt=0;else while(cnt)hd[val[cnt--]&M]=0;}
}H;

signed main(){
    iF("pic.in");
    oF("pic.out");
    
    srand(time(0));
    char c=0;
    T=read();
    cin>>A>>B>>C>>D;
    min_N=read(),max_N=read(),m=read();
    for(int i=1;i<=T;i++){
        p[i].id=i;
        for(int j=1,hs;j<=m;j++){
            while(c<97||c>122)c=IO.read_char();
            hs=0;
            while(97<=c&&c<=122){
                hs=hs*27+c-96;
                c=IO.read_char();
            }
            if(H.Find(hs))++p[i].val;
            else{
                H.Ins(hs);
                if(m==500)++ans[i];
            }
        }
        if(i<T)H.Clear();
    }
    sort(p+1,p+T+1);
    double B=double(max_N-min_N)/double(T);
    for(int i=1;i<=T;i++){
        if(m!=500)ans[p[i].id]=Round(1.0*max_N-B*(-0.5+i));
    }
    for(int i=1;i<=T;i++){
        _wri(ans[i]);
    }
    return 0;
}

