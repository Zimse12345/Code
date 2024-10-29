#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=1e9;
int T,n;
int Mx,ans,sum,cnt;

struct node{
    int val,pos;
    node(int val=0,int pos=0):val(val),pos(pos){}
    bool operator < (const node& _)const{return val<_.val;}
}a[N];

struct line{
    int l,r,p0,p1;
    line(int l=0,int r=0,int p0=0,int p1=0):l(l),r(r),p0(p0),p1(p1){}
    bool operator < (const line& _)const{return l<_.l;}
};
set<line> s;

inline void upt(line t,int v){
    if((t.r-t.l+1)%2==0&&(t.p0==1||t.p1==1))cnt+=v;
    if((t.r-t.l+1)%2==1&&t.p0==1)cnt+=v;
    sum+=(t.r-t.l+2)/2*v;
    return;
}

inline line merge(line x,line y){
    line z=line(x.l,y.r,x.p0,x.p1);
    if((x.r-x.l+1)%2==0)z.p0|=y.p0,z.p1|=y.p1;
    else z.p0|=y.p1,z.p1|=y.p0;
    return z;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].val;
            a[i].pos=i;
        }
        sort(a+1,a+n+1);
        s.clear();
        s.insert(line(-inf,-inf));
        s.insert(line(inf,inf));
        Mx=a[n].val,ans=0,sum=0,cnt=0;
        for(int i=n;i>=1;i--){
            int p=a[i].pos;
            line t=line(p,p,0,0);
            if(a[i].val==Mx)t.p0=1;
            set<line>::iterator L=s.lower_bound(t);
            set<line>::iterator R=L;
            --L;
            if((L->r)+1<p&&p+1<(R->l)){
                upt(t,1);
                s.insert(t);
            }
            else if((L->r)+1==p&&p+1<(R->l)){
                line _t=*L;
                s.erase(L);
                upt(_t,-1);
                t=merge(_t,t);
                upt(t,1);
                s.insert(t);
            }
            else if((L->r)+1<p&&p+1==(R->l)){
                line _t=*R;
                s.erase(R);
                upt(_t,-1);
                t=merge(t,_t);
                upt(t,1);
                s.insert(t);
            }
            else{
                line lt=*L,rt=*R;
                s.erase(lt),s.erase(rt);
                upt(lt,-1),upt(rt,-1);
                t=merge(merge(lt,t),rt);
                upt(t,1);
                s.insert(t);
            }
            ans=max(ans,Mx+a[i].val+sum-(cnt?0:1));
        }
        printf("%d\n",ans);
    }
    return 0;
}


