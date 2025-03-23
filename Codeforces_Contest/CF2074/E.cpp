#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;

inline int query(int x,int y,int z){
    printf("? %d %d %d\n",x,y,z);
    fflush(stdout);
    int res=0;
    cin>>res;
    return res;
}

signed main(){
    cin>>T;
    srand(time(0));
    while(T--){
        cin>>n;
        int a=1,b=2,c=3;
        while(1){
            int res=query(a,b,c);
            if(res==0)break;
            int w=rand()%3;
            if(w==0)a=res;
            if(w==1)b=res;
            if(w==2)c=res;
        }
        printf("! %d %d %d\n",a,b,c);
        fflush(stdout);
    }
    return 0;
}


