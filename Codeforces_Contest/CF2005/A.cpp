#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=(n+4)/5;i++)printf("a");
        for(int i=1;i<=(n+3)/5;i++)printf("e");
        for(int i=1;i<=(n+2)/5;i++)printf("i");
        for(int i=1;i<=(n+1)/5;i++)printf("o");
        for(int i=1;i<=(n+0)/5;i++)printf("u");
        printf("\n");
    }
    return 0;
}


