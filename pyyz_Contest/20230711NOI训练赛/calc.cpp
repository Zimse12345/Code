// Author:Zimse  Data:2023-07-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
#define int long long
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

const int N=1.01e7;
const int i2=499122177,i6=166374059;
int l,r,k,ans,AA,B,C;
int prime[N/5],tot,pr[N*2],mu[N*2],sumk2[N],suf[N],S2[N];
int sumk[N*2];
map<int,int> mp;
set<int> st;

inline int updiv(int x,int y){
    return x/y+(x%y?1:0);
}

inline int sum(int x){
    x%=Mod;
    return x*(x+1)%Mod*i2%Mod;
}

inline int sum2(int x){
    x%=Mod;
    return x*(x+1)%Mod*(x*2+1)%Mod*i6%Mod;
}

inline int Sumk(int m){
    m%=Mod;
    if(m<N*2)return sumk[m];
    if(mp[m])return mp[m];
    set<int>::iterator it=st.lower_bound(m);
    if(*it-m<=k/16){
        int res=mp[*it];//++C;//printf("(%lld %lld)",*it,m);
        for(int i=*it;i>m;i--)_mod(res,-fpow(i,k-1));//++AA;
//        for(int i=m+1;i<=*it;i++)_mod(res,fpow(i,k-1)),++AA;
        st.insert(m),mp[m]=res;
        return res;
    }
    --it;
    if(m-*it<=k/16){
        int res=mp[*it];//++C;
        for(int i=*it+1;i<=m;i++)_mod(res,fpow(i,k-1));//++AA;
//        for(int i=m;i>*it;i--)_mod(res,fpow(i,k-1)),++AA;
        st.insert(m),mp[m]=res;
        return res;
    }//++B;
//    m%=Mod;
//    if(mp[m])return mp[m];
    __int128 res=0;
//    int s2=1;
//    for(int j=2;j<=k+1;j++){
////        (s1*=((m-j)%Mod))%=Mod;
//        (s2*=(1-j))%=Mod;
//    }
//    pre[0]=1;
    suf[k+2]=1;
//    for(int i=1;i<=k+1;i++)pre[i]=(m-i)*pre[i-1]%Mod;
    for(int i=k+1;i>=1;i--)suf[i]=(m-i)*suf[i+1]%Mod;
    for(int i=1,pre=1;i<=k+1;i++){
        res+=pre*suf[i+1]%Mod*S2[i];
        (pre*=(m-i))%=Mod;
    }
//    for(int i=1;i<=k+1;i++){
//        int S1=1,S2=1;
//        for(int j=1;j<=k+1;j++)if(i^j){
//            (S1*=((m-j)%Mod))%=Mod;
//            (S2*=(i-j))%=Mod;
//        }
//        if(S1!=s1||S2!=s2)printf("i=%lld %lld %lld %lld %lld\n",i,S1,s1,S2,s2);
        
//        s1=(s1*((m-i)%Mod)%Mod*inv((m-i-1)%Mod))%Mod;
//        s2=(s2*i%Mod*inv(i-k-1))%Mod;
//    }
//    for(int i=1;i<=k+1;i++){
//        int s1=sumk[i],s2=1;
//        for(int j=1;j<=k+1;j++)if(i^j){
//            (s1*=(m-j))%=Mod;
//            (s2*=(i-j))%=Mod;
//        }
//        _mod(res,s1*inv(s2));
//    }
    res%=Mod;
    mp[m]=res;
    st.insert(m);
    return res;
}

inline int Calc(int n){
    int sum=0;
    for(int i=1,j;i*i<=n;){
        j=n/(n/i/i);
        j=sqrtl((long double)(j));
        _mod(sum,Sumk(n/i/i)*(sumk2[j]-sumk2[i-1]));
        i=j+1;
    }
//    for(int i=1;i*i<=n;i++)if(mu[i]!=0){
//        int m=n/i/i;
//        _mod(sum,Sumk(m)*fpow(i,2*(k-1))%Mod*mu[i]);
//    }
    return sum;
}

signed main(){
    iF("calc.in");
    oF("calc.out");
    
    st.insert(INF),st.insert(-INF);
    mu[1]=pr[1]=1;
    for(int i=2;i<N*2;i++){
        if(!pr[i])prime[++tot]=i,pr[i]=i,mu[i]=-1;
        for(int j=1;j<=tot&&prime[j]*i<N*2;j++){
            pr[prime[j]*i]=prime[j],mu[prime[j]*i]=-mu[i];
            if(pr[i]==prime[j]){
                mu[prime[j]*i]=0;
                break;
            }
        }
    }
    l=read(),r=read(),k=read();
    S2[1]=1;
    for(int i=2;i<=k+1;i++){
//        (s1*=((m-j)%Mod))%=Mod;
        (S2[1]*=(1-i))%=Mod;
    }
    for(int i=1;i<=k+1;i++)S2[i+1]=(S2[i]*i%Mod*inv(i-k-1))%Mod;
    for(int i=1;i<N*2;i++){
        if(pr[i]==i)sumk[i]=fpow(i,k-1);
        else sumk[i]=sumk[i/pr[i]]*sumk[pr[i]]%Mod;
        if(i<N){
            if(pr[i]==i)sumk2[i]=fpow(i,2*(k-1));
            else sumk2[i]=sumk2[i/pr[i]]*sumk2[pr[i]]%Mod;
        }
    }
    for(int i=1;i<N*2;i++)_mod(sumk[i],sumk[i-1]);
    for(int i=1;i<N;i++)sumk2[i]=(sumk2[i-1]+mu[i]*sumk2[i])%Mod;
//    sumk2[i]=(sumk2[i-1]+mu[i]*fpow(i,2*(k-1)))%Mod;//printf("!\n");
    for(int i=1;i<=k+1;i++)S2[i]=inv(S2[i])*sumk[i]%Mod;
    for(int vl=1,vr,prev=0;vl<=r;){
//        ++A;if(A%100==0)_wri(A);
        int x=updiv(l,vl);
        int L=sqrtl((long double)(x));
        while(L*L<x)++L;
        x=r/vl;
        int R=sqrtl((long double)(x));
        while((R+1)*(R+1)<=x)++R;
        vr=r;
        _min(vr,r/R/R);
        if(L>1)_min(vr,(l-1)/((L-1)*(L-1)));
        
        int s=(sum(R)-sum(L-1)+Mod)%Mod,s2=(sum2(R)-sum2(L-1)+Mod)%Mod;
        // for(int i=L;i<=R;i++){
        //     _mod(s,i),_mod(s2,i*i);
        // }
        int sv=Calc(vr);
        swap(sv,prev),sv=prev-sv;//printf("%lld %lld %lld %lld [%lld,%lld]\n",vl,vr,s,sv,L,R);
//        int sv=Calc(vr)-Calc(vl-1);
        // for(int i=vl;i<=vr;i++)_mod(sv,fpow(i,k-1)*mu[i]*mu[i]);
        // printf("(%lld,%lld)  [%lld,%lld] %lld %lld smu=%lld\n",vl,vr,L,R,s,s2,smu);
        _mod(ans,sv*s%Mod*s%Mod*fpow(s2,k-2)%Mod);
        
        vl=vr+1;
    }
    // for(int v=1;v<=r;v++)if(mu[v]!=0){
    //     int s=0,s2=0;
    //     for(int i=1;v*i*i<=r;i++){
    //         if(l<=v*i*i)_mod(s,i),_mod(s2,i*i);
    //     }
    //     printf("[%lld %lld %lld]\n",v,l,r);
    //     // _mod(ans,fpow(v,k-1)*s%Mod*s%Mod*fpow(s2,k-2));
    // }
    _mod(ans,Mod);
    _wri(ans);
//    int pre=-INF,sa=0,sb=0;
//    for(set<int>::iterator it=st.begin();it!=st.end();it++){
//        if(*it-pre<k/4)sa+=(*it-pre)*30;
//        else sb+=k;
//        pre=*it;
//    }
//    printf("sa=%lld\nsb=%lld\nA=%lld\nB=%lld\nC=%lld\n",sa,sb,AA,B,C);
//    printf("A=%lld B=%lld C=%lld\n",A,B,C);
//    _wri(A);
    return 0;
}


