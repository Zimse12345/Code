#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,a,b,c,d; 

signed main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        int ans=0;
        for(int i=-200;i<=200;i++){
            int s=0;
            if(a+b==i)++s;
            if(b+i==c)++s;
            if(i+c==d)++s;
            ans=max(ans,s);
        }
        printf("%d\n",ans);
    }
    return 0;
}


