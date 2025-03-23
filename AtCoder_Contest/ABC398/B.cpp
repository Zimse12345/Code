#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int t[N];

signed main(){
    for(int i=1,x=0;i<=7;i++){
        cin>>x;
        ++t[x];
    }
    int x=0,y=0;
    for(int i=1;i<=13;i++){
        if(t[i]>=3){
            if(!x)x=1;
            else y=1;
        }
        else if(t[i]>=2){
            y=1;
        }
    }
    if(x&&y)printf("Yes\n");
    else printf("No\n");
    return 0;
}


