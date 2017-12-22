#include <iostream>
#define MAXV 20
#define MAXE 20
#define INFINITY 65535
using namespace std;

typedef int p[MAXE][MAXE];
typedef int d[MAXV][MAXV];
typedef struct {
    int vexnum;
    int edgenum;
    int vex[MAXV];
    int edge[MAXE][MAXE];
}Graph;



int Input_Graph(Graph &m,p &P,d &D){
    cout<<"Input Vex and Edge number:"<<endl;
    int x,y,z;
    cin>>m.vexnum>>m.edgenum;
    for(int i = 0;i<m.vexnum;i++){
        for(int j = 0;j<m.vexnum;j++){
            P[i][j] = j;
            if(i==j)
                D[i][j] = 0;
            else
                D[i][j] = INFINITY;
        }
    }
    for(int i = 0;i<m.edgenum;i++){
        cin>>x>>y>>z;
        D[x][y] = z;
    }
}



int main() {
    Graph m;
    p P;
    d D;
    Input_Graph(m,P,D);
    return 0;
}