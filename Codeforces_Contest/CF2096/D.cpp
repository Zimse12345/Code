#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,x[N],y[N];
map<int,int> m1,m2;

signed main(){
    cin>>T;
    while(T--){
        m1.clear(),m2.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
            m1[x[i]]++;
            m2[x[i]+y[i]]++;
        }
        int x=0,y=0;
        for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++){
            if((it->second)&1){
                x=(it->first);
                break;
            }
        }
        for(map<int,int>::iterator it=m2.begin();it!=m2.end();it++){
            if((it->second)&1){
                y=(it->first)-x;
                break;
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}


