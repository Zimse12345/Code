#include <bits/stdc++.h>
using namespace std;

const int N=4.01e6,MX=4000000;
int T,n,a[N],m,mx[N*4],ans[N],tot;
set<int> S;

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

void update(int id,int L,int R,int x,int v){
    if(L==R)mx[id]=v;
    else{
        if(x<=M)update(Lid,L,M,x,v);
        else update(Rid,M+1,R,x,v);
        mx[id]=max(mx[Lid],mx[Rid]);
    }
    return;
}

void add(int x){
    set<int>::iterator it=S.lower_bound(x);
    int R=*it;
    --it;
    int L=*it;
    update(1,1,MX,L+1,x-L-1);
    update(1,1,MX,x+1,R-x-1);
    S.insert(x);
    return;
}

void era(int x){
    S.erase(x);
    set<int>::iterator it=S.lower_bound(x);
    int R=*it;
    --it;
    int L=*it;
    update(1,1,MX,x+1,0);
    update(1,1,MX,L+1,R-L-1);
    return;
}

int query(int id,int L,int R,int x){
    if(L==R)return L;
    if(mx[Lid]>=x)return query(Lid,L,M,x);
    return query(Rid,M+1,R,x);
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        S.insert(0),S.insert(MX+1);
        update(1,1,MX,1,MX);
        for(int i=1;i<=n;i++)cin>>a[i],add(a[i]);
        cin>>m;
        tot=0;
        while(m--){
            char op=getchar();
            while(op!='-'&&op!='+'&&op!='?')op=getchar();
            int x;
            cin>>x;
            if(op=='-')era(x);
            else if(op=='+')add(x);
            else ans[++tot]=query(1,1,MX,x);
        }
        for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
        printf("\n");
        while(1){
            set<int>::iterator it=S.begin();
            ++it;
            if(*it==MX+1)break;
            era(*it); 
        }
    }
    return 0;
}


