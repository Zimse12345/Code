#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,x;

signed main(){
    cin>>T;
    while(T--){
        cin>>x;
        int tag=1;
        for(int i=1;i<30;i++)if((x==(1<<i))||(x==(1<<i)-1))tag=0;
        if(tag){
            int y=x,a=0,b=0;
            for(int i=29;i>=0;i--){
                if(x&(1<<i)){
                    if(!a)a=1,y-=(1<<i);
                }
                else{
                    if((!b)&&a)b=1,y+=(1<<i);
                }
            }
            printf("%d\n",y);
        }
        else printf("-1\n");
    }
    return 0;
}


