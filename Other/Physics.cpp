// Author:Zimse  Data:2024-05-
#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
const double eps=1e-3;
double T;

struct vec{
    double x,y,z;
    vec(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
    vec operator + (const vec& _)const{
        return vec(x+_.x,y+_.y,z+_.z);
    }
    vec operator * (const vec& _)const{
        return vec(y*_.z-z*_.y,z*_.x-x*_.z,x*_.y-y*_.x);
    }
    vec operator * (const double& _)const{
        return vec(x*_,y*_,z*_);
    }
    vec operator / (const double& _)const{
        if(fabs(_)<eps)return vec();
        return vec(x/_,y/_,z/_);
    }
    void show(){
        printf(" [x=%.3lf y=%.3lf z=%.3lf] \n",x,y,z);
        return;
    }
};

vec Z(vec p,double t=T){
    return vec(0,0,1);
}

struct MagneticField{
    function<vec(vec,double)> c;
    MagneticField(function<vec(vec,double)> _c=Z):c(_c){}
};
vector<MagneticField> mf;

vec getB(vec p,double t=T){
    vec b;
    for(unsigned i=0;i<mf.size();i++)b=b+mf[i].c(p,t);
    return b;
}

struct particle{
    vec pos,v;
    double q,m;

    #define B getB(pos)
    vec F(void){return v*B*q;}
    vec a(void){return F()/m;}
    void Run(){
        pos=pos+v*eps;
        v=v+a()*eps;
        return;
    }
    #undef B
};

signed main(){
    mf.push_back(MagneticField());
    particle s;
    s.v=vec(1,0,0);
    s.m=1,s.q=1;
    while(T<=2){
        T+=eps;
        s.Run();
        printf("T=%.3lf (%.3lf %.3lf %.3lf)\n",T,s.pos.x,s.pos.y,s.pos.z);
    }
    return 0;
}

