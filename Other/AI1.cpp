// Author:Zimse  Data:2024-03-
#include <bits/stdc++.h>
#define pc putchar
#define inv fpow
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const double eps=0.0000001;

double testFunc1(double x){
    if(x<0)x=0;
    if(x>1)x=1;
    return x;
}

double Tanh(double x){
    return tanh(x);
}

double testFunc2(double x){
    if(x<=0)return 0;
    return 1;
}

function<double(double)> TestFunction[2]={testFunc1,testFunc2};

unsigned R_seed;
unsigned Get_random(){
    R_seed=(R_seed+1151)%4096;
    return (R_seed+rand()%4096)%4096;
}

double Random_double(double L,double R){
    return L+(R-L)*(double(Get_random())/4097.0);
}

double Random_unsigned(unsigned L,unsigned R){
    return L+Get_random()%(R-L+1);
}

bool Random_P(double p){
    return p*4096.0>double(Get_random());
}

struct AI{
    unsigned N,Time;

    struct InNode{
        unsigned func;
        vector<unsigned> act;
        double sta;
        InNode(unsigned _func=0,double _sta=0):func(_func),sta(_sta){}
        void Input(double x){
            sta=TestFunction[func](x);
            return;
        }

        void Random_grow(){
            int x=(rand()&3);
            if(x==0)func=Random_unsigned(0,1);
            else if(x==1)sta=Random_double(0,1);
            else if(x==2)sta+=Random_double(-0.1,0.1);
            else{

            }
            return;
        }
    };

    struct OutNode{
        unsigned n,dest_id,dest_pos;
        double A,B;
        bool outlimit;
        double L,R;
        vector<unsigned> pos;
        vector<double> weight;

        void Random_grow(){
            int x=(rand()&7);
            if(x==0)A+=Random_double(-0.1,0.1);
            else if(x==1)B+=Random_double(-0.1,0.1);
            else if(x==2)L+=Random_double(-0.1,0.1);
            else if(x==3)R+=Random_double(-0.1,0.1);
            else if(x==4&&!weight.empty()){
                x=Random_unsigned(0,weight.size()-1);
                weight[x]+=Random_double(-0.1,0.1);
            }
            else{

            }
            return;
        }
    };

    struct Cell{
        vector<InNode> innode;
        vector<OutNode> outnode;

        void Input(unsigned pos,double x){
            innode[pos].Input(x);
            return;
        }
        
        double Output(unsigned pos){
            double sum=0;
            for(unsigned i=0;i<outnode[pos].n;i++)
                sum+=innode[outnode[pos].pos[i]].sta*outnode[pos].weight[i];
            return sum*outnode[pos].A+outnode[pos].B;
        }
    };
    vector<Cell> cell;

    void Init(){
        N=Time=0;
        cell.resize(0);
        return;
    }

    InNode Random_innode(unsigned Size,double p){
        InNode c;
        c.sta=0;
        if((rand()&3)==0)c.sta=Random_double(0,1);
        for(unsigned j=0;j<Size;j++){
            if(Random_P(p))c.act.push_back(j);
        }
        if(Random_P(0.4))c.func=1;
        return c;
    }

    OutNode Random_outnode(unsigned Size,double p){
        OutNode c;
        c.n=0;
        for(unsigned j=0;j<Size;j++){
            if(Random_P(p)){
                c.pos.push_back(j);
                c.weight.push_back(Random_double(-1,1));
                c.n++;
            }
        }
        c.A=Random_double(-2,2);
        c.B=Random_double(-1,1);
        c.outlimit=true;
        c.L=Random_double(-0.2,0.2);
        c.R=Random_double(0.8,1.2);
        c.dest_id=Random_unsigned(0,N-1);
        c.dest_pos=Random_unsigned(0,Size-1);
        return c;
    }

    Cell Random_cell(unsigned Size=4,double p1=0.2,double p2=0.4){
        Cell c;
        c.innode.resize(Size);
        c.outnode.resize(Size);
        for(unsigned i=0;i<Size;i++){
            c.innode[i]=Random_innode(Size,p1);
            c.outnode[i]=Random_outnode(Size,p2);
        }
        return c;
    }

    void Random_Init(unsigned Size){
        Init();
        N=Size;
        cell.resize(N);
        for(unsigned i=0;i<N;i++)cell[i]=Random_cell();
        return;
    }

    void update(int count){
        while(count--){
            unsigned id=rand()%N;
            if(rand()%8!=0){
                unsigned x=rand()%2;
                if(x==0&&!cell[id].innode.empty()){
                    unsigned y=Random_unsigned(0,cell[id].innode.size()-1);
                    cell[id].innode[y].Random_grow();
                }
                if(x==1&&!cell[id].outnode.empty()){
                    unsigned y=Random_unsigned(0,cell[id].outnode.size()-1);
                    cell[id].outnode[y].Random_grow();
                }
                continue;
            }
            if(rand()&1)cell[id].innode[rand()%cell[id].innode.size()]=Random_innode(4,0.2);
            else cell[id].outnode[rand()%cell[id].outnode.size()]=Random_outnode(4,0.4);
        }
        return;
    }

    struct data{
        unsigned Time;
        bool type;
        unsigned id,pos;
        double val;
        data(unsigned _Time,bool _type=false,unsigned _id=0,unsigned _pos=0,double _val=0):Time(_Time),type(_type),id(_id),pos(_pos),val(_val){}
        bool operator < (const data& _)const{return Time>_.Time;}
    };

    double Run(vector<double> _input,double Ans){
        // printf("Run--Start!\n");
        int T=0;
        priority_queue<data> Q;
        for(unsigned i=0;i<_input.size();i++){
            Q.push(data(i*2,false,0,0,_input[i]));
        }
        while(!Q.empty()){
            data s=Q.top();
            Q.pop();
            // printf("(T=%d time=%d %c %u %u %.2lf)\n",T,s.Time,s.type?'I':'O',s.id,s.pos,s.val);
            if(s.type==false){
                cell[s.id].Input(s.pos,s.val);
                // printf("(id=%u size=%u)",s.id,cell[s.id].innode[s.pos].act.size());
                for(auto i:cell[s.id].innode[s.pos].act)Q.push(data(s.Time+1,true,s.id,i,0));
            }
            if(s.type==true){
                double x=cell[s.id].Output(s.pos);
                if(cell[s.id].outnode[s.pos].outlimit&&(x<cell[s.id].outnode[s.pos].L||x>cell[s.id].outnode[s.pos].R))continue;
                if(s.id==1){
                    return max(0.0,1.0-fabs(x-Ans)*5.0);
                }
                // printf("(%u,%u) --(%.3lf)--> (%u,%u)\n",s.id,s.pos,x,cell[s.id].outnode[s.pos].dest_id,cell[s.id].outnode[s.pos].dest_pos);
                Q.push(data(s.Time+1,false,cell[s.id].outnode[s.pos].dest_id,cell[s.id].outnode[s.pos].dest_pos,x));
            }
            ++T;
            if(T>10)break;
        }
        return 0;
    }

    void Save(const char *str){
        FILE* file;
        file=fopen(str,"w");
        fprintf(file,"%u\n",N);
        for(unsigned i=0;i<N;i++){
            fprintf(file,"%llu ",cell[i].innode.size());
            for(auto c:cell[i].innode){
                fprintf(file,"%u %.3lf ",c.func,c.sta);
                fprintf(file,"%llu ",c.act.size());
                for(auto j:c.act)fprintf(file,"%u ",j);
            }
            fprintf(file,"%llu ",cell[i].outnode.size());
            for(auto c:cell[i].outnode){
                fprintf(file,"%.3lf %.3lf %u %u %u %.3lf %.3lf ",c.A,c.B,c.dest_id,c.dest_pos,c.outlimit?1:0,c.L,c.R);
                fprintf(file,"%u ",c.n);
                for(unsigned j=0;j<c.n;j++)fprintf(file,"%u %.3lf ",c.pos[j],c.weight[j]);
            }
            fprintf(file,"\n");
        }
        fclose(file);
        return;
    }

    void Load(const char *str){
        Init();
        FILE* file;
        file=fopen(str,"r");
        fscanf(file,"%u",&N);
        cell.resize(N);
        for(unsigned i=0;i<N;i++){
            unsigned Size,t;
            fscanf(file,"%u",&Size);
            cell[i].innode.resize(Size);
            for(unsigned j=0;j<Size;j++){
                InNode c;
                fscanf(file,"%u %lf",&c.func,&c.sta);
                fscanf(file,"%u",&t);
                c.act.resize(t);
                for(unsigned k=0;k<t;k++)fscanf(file,"%u",&c.act[k]);
                cell[i].innode[j]=c;
            }
            fscanf(file,"%u",&Size);
            cell[i].outnode.resize(Size);
            for(unsigned j=0;j<Size;j++){
                OutNode c;
                fscanf(file,"%lf %lf %u %u %u %lf %lf",&c.A,&c.B,&c.dest_id,&c.dest_pos,&t,&c.L,&c.R);
                c.outlimit=(t?1:0);
                fscanf(file,"%u",&c.n);
                c.pos.resize(c.n),c.weight.resize(c.n);
                for(unsigned k=0;k<c.n;k++)fscanf(file,"%u %lf",&c.pos[k],&c.weight[k]);
                cell[i].outnode[j]=c;
            }
        }
        fclose(file);
        return;
    }
};

double AI_Test(AI ai,int Count=100){
    double sum=0;
    for(int i=1;i<=Count;i++){
        int x=rand()%2,y=rand()%2;
        vector<double> _input;
        _input.push_back(x),_input.push_back(y);
        AI cop=ai;
        sum+=cop.Run(_input,x^y);
    }
    return sum/double(Count);
}

signed main(){
    srand(time(0));
    AI test;
    // test.N=2;
    // test.cell.resize(2);
    // test.cell[0].innode.resize(2);
    // test.cell[0].outnode.resize(2);
    // test.cell[1].innode.resize(2);
    // test.cell[1].outnode.resize(2);

    // test.cell[0].innode[0].act.push_back(0);

    // test.cell[0].outnode[0].n=1;
    // test.cell[0].outnode[0].outlimit=false;
    // test.cell[0].outnode[0].pos.push_back(0);
    // test.cell[0].outnode[0].weight.push_back(1);
    // test.cell[0].outnode[0].A=1;
    // test.cell[0].outnode[0].dest_id=0;
    // test.cell[0].outnode[0].dest_pos=1;

    // test.cell[0].innode[1].act.push_back(1);

    // test.cell[0].outnode[1].n=2;
    // test.cell[0].outnode[1].outlimit=false;
    // test.cell[0].outnode[1].pos.push_back(0);
    // test.cell[0].outnode[1].weight.push_back(1);
    // test.cell[0].outnode[1].pos.push_back(1);
    // test.cell[0].outnode[1].weight.push_back(1);
    // test.cell[0].outnode[1].A=1;
    // test.cell[0].outnode[1].B=-1;
    // test.cell[0].outnode[1].dest_id=1;
    // test.cell[0].outnode[1].dest_pos=0;

    // test.cell[1].innode[0].act.push_back(0);

    // test.cell[1].outnode[0].n=1;
    // test.cell[1].outnode[0].outlimit=false;
    // test.cell[1].outnode[0].pos.push_back(0);
    // test.cell[1].outnode[0].weight.push_back(1);
    // test.cell[1].outnode[0].A=1;
    // test.cell[1].outnode[0].dest_id=0;
    // test.cell[1].outnode[0].dest_pos=1;
    // test.Save("s.txt");
    // test.Load("s.txt");
    // test.Save("a.txt");
    // printf("%.7lf\n",AI_Test(test,1000));
    // test.Save("a.txt");
    // return 0;

    AI ai,maxAI;
    // ai.Random_Init(8);printf("*");return 0;
    double max=0;
    for(int i=1;i<=10000;i++){
        if(i%1000==0)printf("%d/%d\n",i,10000);
        ai.Random_Init(4);
        double score=AI_Test(ai);
        if(score>max)maxAI=ai,max=score;
    }
    printf("%.7lf\n",AI_Test(maxAI,10000));
    for(int i=1;i<=10000;i++){
        if(i%1000==0)printf("%d/%d\n",i,10000);
        ai=maxAI;//printf("A");
        ai.update(rand()%4+1);//printf("B");ai.Save("s.txt");
        double score=AI_Test(ai);//printf("C\n");
        if(score>max){
            maxAI=ai,max=score;
            maxAI.Save("s.txt");
        }
    }printf("end\n");
    // for(int i=1;i<=500;i++){
    //     ai=maxAI;
    //     ai.updata(1);
    //     double score=AI_Test(ai);
    //     if(score>max)maxAI=ai,max=score;
    // }
    printf("%.7lf\n",AI_Test(maxAI,10000));
    // vector<double> _input;
    // int n;
    // n=read();
    // _input.resize(n);
    // for(int i=0;i<n;i++){
    //     double x;
    //     scanf("%lf",&x);
    //     _input[i]=x;
    // }
    // ai.Run(_input);
    return 0;
}

