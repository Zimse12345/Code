// Author: Zimse,Wrhaco
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define inv fpow

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;
mt19937 randint(chrono::system_clock::now().time_since_epoch().count());

struct Tile{
    int suit; //Character:1,Dot:2,Bamboo:3,Honor:4
    int rank;
    bool is_RedDora;
    Tile(int suit=0,int rank=0,bool is_RedDora=false):suit(suit),rank(rank),is_RedDora(is_RedDora){};
    bool operator < (const Tile &_)const{
        if(suit==_.suit){
            if(rank==_.rank)return is_RedDora<_.is_RedDora;
            return rank<_.rank;
        }
        return suit<_.suit;
    }
    bool operator == (const Tile &_)const{
        return suit==_.suit&&rank==_.rank&&is_RedDora==_.is_RedDora;
    }
    void show(){
        putchar('0'+rank);
        if(suit==1)putchar('m');
        if(suit==2)putchar('p');
        if(suit==3)putchar('s');
        if(suit==4)putchar('c');
        return;
    }
};

struct Furo{
    Tile tile;
    int type; //Pong:1,Exposed kong:2,Concealed kong:3
    Furo(Tile tile=Tile(),int type=0):tile(tile),type(type){}
};

struct Opt{
    int type;
    //Nothing:0
    //Draw:1,Discard:2
    //Pong:3,Exposed kong:4,Concealed kong:5
    //North:6,Richi:7
    //Win:point
    Tile tile;
    int from,to;
    bool is_predraw;
    Opt(int type=0,Tile tile=Tile(),int from=0,int to=0,bool is_predraw=false):
    type(type),tile(tile),from(from),to(to),is_predraw(is_predraw){}
};

namespace wrhaco{
    int CheckWin(vector<Tile> tile,vector<Furo> furo,Tile _tile,int NorthCnt,int DoraCnt,bool is_Riichi,int PrevailingWind,int DealerWind,vector<Opt> record){
        sort(tile.begin(),tile.end());
        if(tile[0].suit==tile[tile.size()-1].suit&&tile[0].suit==_tile.suit)return 48000;
        return 0;
    }
}

struct Player{
    vector<Tile> tile;
    vector<Tile> river;
    vector<Furo> furo;
    int NorthCnt;
    bool is_Riichi,is_FlowSlam;
    int PrevailingWind,DealerWind; // East:0,South:1,West:2
    int Score,Id;
    vector<Opt> *record;

    void InitRound(int prevailingWind,int dealerWind,vector<Opt> *_record){
        tile.resize(0);
        river.resize(0);
        furo.resize(0);
        NorthCnt=0;
        DealerWind=dealerWind,PrevailingWind=prevailingWind;
        is_Riichi=false,is_FlowSlam=true;
        record=_record;
        return;
    }

    void InitPlayer(int id=0){
        Score=35000,Id=id;
        return;
    }

    void Show(){
        printf("Id:%d  ",Id);
        sort(tile.begin(),tile.end());
        for(unsigned i=0;i<tile.size();i++)tile[i].show(),putchar(' ');
        printf(" furo: ");
        for(unsigned i=0;i<furo.size();i++){
            int cnt=3;
            if(furo[i].type>1)cnt=4;
            while(cnt--)furo[i].tile.show();
            putchar(' ');
        }
        putchar('\n');
        return;
    }

    int CheckWin(Tile _tile){
        return wrhaco::CheckWin(tile,furo,_tile,NorthCnt,0,is_Riichi,PrevailingWind,DealerWind,*record);
    }

    void Delcard(Tile _tile){
        int sz=tile.size();
        vector<Tile> tmp;
        for(int i=0;i<sz;i++){
            if(tile[i]==_tile)_tile.suit=0;
            else tmp.push_back(tile[i]);
        }
        swap(tmp,tile);
        return;
    }

    Tile Discard(){
        sort(tile.begin(),tile.end());
        int sz=tile.size(),p=0;
        if(tile[0].suit>1)p=sz-1;
        Tile t=tile[p];
        Delcard(t);
        return t;
    }

    Opt Draw(Tile _tile){
        int pt=CheckWin(_tile);
        if(pt)return Opt(pt,Tile(),Id,Id);
        tile.push_back(_tile);
        for(unsigned i=0;i<tile.size();i++){
            if(tile[i].suit==4&&tile[i].rank==4){
                Delcard(tile[i]);
                return Opt(6,Tile(4,4),Id,-1);
            }
        }
        sort(tile.begin(),tile.end());
        Tile t=Discard();
        return Opt(2,t,Id,-1,t==_tile);
    }

    Opt CheckTile(Tile _tile,int from){
        int pt=CheckWin(_tile);
        if(pt)return Opt(pt,Tile(),from,Id);
        int sz=tile.size(),p=0;
        for(int i=0;i<sz;i++){
            if(tile[i].suit==_tile.suit&&tile[i].rank==_tile.rank)++p;
        }
        if(p==4)return Opt(4,_tile,from,Id);
        if(p==3)return Opt(3,_tile,from,Id);
        return Opt();
    }

    void deal(Tile _tile){
        tile.push_back(_tile);
        return;
    }

    Opt Pong(Tile _tile){
        int sz=tile.size(),p=3;
        vector<Tile> tmp;
        for(int i=0;i<sz;i++){
            if(p>0&&tile[i].suit==_tile.suit&&tile[i].rank==_tile.rank)--p;
            else tmp.push_back(tile[i]);
        }
        swap(tmp,tile);
        furo.push_back(Furo(_tile,1));
        return Opt(2,Discard(),Id,-1);
    }

    void Exposedkong(Tile _tile){
        int sz=tile.size(),p=4;
        vector<Tile> tmp;
        for(int i=0;i<sz;i++){
            if(p>0&&tile[i].suit==_tile.suit&&tile[i].rank==_tile.rank)--p;
            else tmp.push_back(tile[i]);
        }
        swap(tmp,tile);
        furo.push_back(Furo(_tile,2));
        return;
    }

    void Concealedkong(Tile _tile){
        int sz=tile.size(),p=4;
        vector<Tile> tmp;
        for(int i=0;i<sz;i++){
            if(p>0&&tile[i].suit==_tile.suit&&tile[i].rank==_tile.rank)--p;
            else tmp.push_back(tile[i]);
        }
        swap(tmp,tile);
        furo.push_back(Furo(_tile,3));
        return;
    }
};

struct Game{
    vector<Opt> record;
    queue<Tile> Wall;

    void Deal(Player &p){
        while(p.tile.size()<13){
            p.deal(Wall.front());
            record.push_back(Opt(1,Wall.front(),-1,p.Id));
            Wall.pop();
        }
        sort(p.tile.begin(),p.tile.end());
        return;
    }

    queue<Tile> Shuffle(){
        while(!Wall.empty())Wall.pop();
        vector<Tile> _Wall;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=9;j++){
                if((i==1&&(j!=1&&j!=9))||i==4&&j>7)continue;
                _Wall.push_back(Tile(i,j,(i!=4&&j==5)?true:false));
                _Wall.push_back(Tile(i,j,false));
                _Wall.push_back(Tile(i,j,false));
                _Wall.push_back(Tile(i,j,false));
            }
        }
        shuffle(_Wall.begin(),_Wall.end(),randint);
        for(unsigned i=0;i<_Wall.size();i++)Wall.push(_Wall[i]);
        return Wall;
    }

    vector<int> StartRound(Player &A,Player &B,Player &C,int PrevailingWind){
        A.InitRound(PrevailingWind,0,&record);
        B.InitRound(PrevailingWind,1,&record);
        C.InitRound(PrevailingWind,2,&record);
        Shuffle();
        record.resize(0);
        vector<int> RoundResult(4);
        
        Deal(A),Deal(B),Deal(C);
        Player *p[3]={&A,&B,&C};
        int cur=0;
        Opt preopt=Opt();
        while(!Wall.empty()){
            Opt opt=Opt();
            if(!preopt.type){
                Tile tile=Wall.front();
                Wall.pop();
                record.push_back(Opt(1,tile,-1,p[cur]->Id));
                opt=p[cur]->Draw(tile);
            }
            else{
                if(preopt.type!=6)record.push_back(preopt);
                if(preopt.type==3)opt=p[cur]->Pong(preopt.tile);
                if(preopt.type==4){
                    p[cur]->Exposedkong(preopt.tile);
                    Tile tile=Wall.front();
                    Wall.pop();
                    record.push_back(Opt(1,tile,-1,p[cur]->Id));
                    opt=p[cur]->Draw(tile);
                }
                if(preopt.type==6){
                    ++p[cur]->NorthCnt;
                    Tile tile=Wall.front();
                    Wall.pop();
                    record.push_back(Opt(1,tile,-1,p[cur]->Id));
                    opt=p[cur]->Draw(tile);
                }
            }
            record.push_back(opt);
            if(opt.type>7){
                RoundResult[cur+1]+=opt.type;
                if(cur){
                    RoundResult[(cur+1)%3+1]-=opt.type/3;
                    RoundResult[(cur+2)%3+1]-=opt.type/3;
                    RoundResult[1]-=opt.type/3;
                }
                else{
                    RoundResult[(cur+1)%3+1]-=opt.type/2;
                    RoundResult[(cur+2)%3+1]-=opt.type/2;
                }
                break;
            }
            if(opt.type==6){
                preopt=opt;
                continue;
            }
            if(opt.type==2){
                Opt opt1=p[(cur+1)%3]->CheckTile(opt.tile,cur);
                Opt opt2=p[(cur+2)%3]->CheckTile(opt.tile,cur);
                if(opt1.type>7||opt2.type>7){
                    if(opt1.type>7){
                        RoundResult[cur+1]-=opt1.type;
                        RoundResult[(cur+1)%3+1]+=opt1.type;
                    }
                    if(opt2.type>7){
                        RoundResult[cur+1]-=opt2.type;
                        RoundResult[(cur+2)%3+1]+=opt2.type;
                    }
                    break;
                }
                else if(opt1.type==3||opt1.type==4){
                    preopt=opt1,cur=(cur+1)%3;
                    continue;
                }
                else if(opt2.type==3||opt2.type==4){
                    preopt=opt2,cur=(cur+2)%3;
                    continue;
                }
            }
            preopt=Opt(),cur=(cur+1)%3;
        }
        return RoundResult;
    }
    
    vector<int> StartContest(Player &A,Player &B,Player &C,int ContestType=0){
        A.InitPlayer(0),B.InitPlayer(1),C.InitPlayer(2);
        vector<int> res=StartRound(A,B,C,0);
        vector<int> ContestResult(4);
        ContestResult=res;
        return ContestResult;
    }
};

signed main(){
    ofile("log.txt");
    
    Game game;
    Player A,B,C;
    vector<int> res=game.StartContest(A,B,C);
    
    printf("Record:\n");
    for(unsigned i=0;i<game.record.size();i++){
        printf("type=%d ",game.record[i].type);
        game.record[i].tile.show();
        printf(" from=%d to=%d ",game.record[i].from,game.record[i].to);
        if(game.record[i].is_predraw)printf("is_predraw ");
        printf("\n");
    }
    printf("Result: ");
    for(int i=1;i<=3;i++)printf("%d ",res[i]);
    printf("\n");
    A.Show(),B.Show(),C.Show();
    return 0;
}

