// Author:Zimse  Data:2024-04-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
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

double readf(){
    double x=0;
    char c=getchar();
    while(c<48||57<c)c=getchar();
    while(47<c&&c<58)x=x*10+(double(c)-48),c=getchar();
    if(c=='.'){
        c=getchar();
        double p=0.1;
        while(47<c&&c<58)x+=(double(c)-48)*p,p*=0.1,c=getchar();
    }
    return x;
}

unsigned R_seed;
unsigned Get_random(){
    R_seed=(R_seed+1151)%4096;
    return (R_seed+rand()%4096)%4096;
}

double Random_double(double L,double R){
    return L+(R-L)*(double(Get_random())/4097.0);
}

double Random_unsigned(unsigned L,unsigned R){
    return L+Get_random()%(R-L+1);
}

bool Random_P(double p){
    return p*4096.0>double(Get_random());
}

double testFunc1(double x){
    if(x<0)return 0;
    return x;
}

double testFunc2(double x){
    return tanh(x);
}

double testFunc3(double x){
    return x;
}

function<double(double)> TestFunction[3]={testFunc1,testFunc2,testFunc3};

const unsigned N=2,M=4;
struct AI{
    vector<double> val[N+1];
    vector<double> weight[N+1][M+1];
    vector<unsigned> func[N+1];
    
    void Init(){
        for(unsigned i=0;i<=N;i++){
            val[i].resize(M+1);
            func[i].resize(M+1);
            val[i][0]=1;
            for(unsigned j=0;j<=M;j++){
                weight[i][j].resize(M);
                func[i][j]=Random_unsigned(0,2);
                for(unsigned k=0;k<=M;k++)weight[i][j][k]=Random_double(-2,2);
            }
        }
        return;
    }

    void Update(int cnt=1){
        if(cnt<1)return;
        while(cnt--){
            unsigned x=Random_unsigned(1,N),y=Random_unsigned(0,M),z=Random_unsigned(0,M);
            if(rand()&1){
                func[x][y]=Random_unsigned(0,2);
            }
            else{
                if(rand()&1)weight[x][y][z]=Random_double(-2,2);
                else weight[x][y][z]+=Random_double(-0.2,0.2);
            }
        }
        return;
    }

    void Input(vector<double> x){
        for(unsigned i=1;i<=M;i++)val[0][i]=x[i%x.size()];
        return;
    }

    int Output(){
        int o=0;
        for(int i=1;i<=int(M);i++)if(val[N][i]>val[N][o])o=i;
        return o;
    }

    void Run(){
        for(unsigned i=1;i<=N;i++){
            for(unsigned j=1;j<=M;j++){
                val[i][j]=0;
                for(unsigned k=0;k<=M;k++)val[i][j]+=val[i-1][k]*weight[i][j][k];
                val[i][j]=TestFunction[func[i][j]](val[i][j]);
            }
        }
        return;
    }
};

double A[128],B[128];
int ans[128];
double Test(AI ai){
    double res=0;
    for(int i=1;i<=100;i++){
        AI cop=ai;
        vector<double> x;
        x.push_back(A[i]),x.push_back(B[i]);
        cop.Input(x);
        cop.Run();
        int o=cop.Output();
        // printf("[%d %d]\n",o,ans[i]);
        if(o==ans[i])res+=0.01;
    }
    return res;
}

signed main(){
    freopen("1.txt","r",stdin);
    for(int i=1;i<=100;i++){
        A[i]=readf(),B[i]=readf(),ans[i]=read();
        // printf("%.3lf %.3lf %d\n",A[i],B[i],ans[i]);
    }

    srand(time(0));
    AI ai,_ai;
    double max=0;
    for(int i=1;i<=5000;i++){
        ai.Init();
        double s=Test(ai);
        if(s>max)max=s,_ai=ai,printf("%.7lf\n",max);
    }
    printf("-------\n");
    for(int i=1;i<=5000;i++){
        ai=_ai;
        ai.Update(rand()%4);
        double s=Test(ai);
        if(s>max)max=s,_ai=ai,printf("%.7lf\n",max);
    }
    printf("%.7lf\n",max);
    return 0;
}

