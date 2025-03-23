#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,q,w[N],s[N],p[N][32];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>w[i];
            s[i]=s[i-1]^w[i];
            for(int j=0;j<30;j++)p[i][j]=p[i-1][j];
            for(int j=29;j>=0;j--)if(w[i]&(1<<j)){
                for(int k=j;k>=0;k--)p[i][k]=i;
                break;
            }
        }
        w[0]=(1<<30);
        while(q--){
            int x=0,pos=n;
            cin>>x;
            while(x){
                int t=29;
                while((x&(1<<t))==0)--t;
                int l=p[pos][t];
                x^=(s[pos]^s[l]);
                pos=l;
                if(x>=w[pos])x^=w[pos],--pos;
                else break;
            }
            printf("%d ",n-pos);
        }
    }
    return 0;
}


