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
            if(i==j)
                m.edge[i][j] = 0;
            else
                m.edge[i][j] = INFINITY;
        }
    }
    for(int i = 0;i<m.edgenum;i++){
        cout<<"Input x to y ,weight :";
        cin>>x>>y>>z;
        m.edge[x][y] = z;
    }
    for(int i = 0; i < m.vexnum; i++)
    {
        for(int j = i; j < m.vexnum; j++)
        {
            m.edge[j][i] = m.edge[i][j];
        }
    }
    return 0;
}

int Floyd_warshall(Graph &m,p &P,d &D){
    int i,j,k;
    for(i = 0;i<m.vexnum;i++){
        for(j =0;j<m.vexnum;j++){
            D[i][j] = m.edge[i][j];
            P[i][j]=j;
        }
    }
    for(k=0;k<m.vexnum;k++){
        for(i=0;i<m.vexnum;i++){
            for(j=0;j<m.vexnum;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=P[i][k];
                }
            }
        }
    }

}




int main() {
    Graph m;
    p P;
    d D;
    Input_Graph(m,P,D);
    Floyd_warshall(m,P,D);
    int temp;
    for(int i =0;i<m.vexnum;i++){
        for(int j=i+1;j<m.vexnum;j++){
            cout<<i<<" to "<<j<<":";
            cout<<"Distance : "<<D[i][j];
            cout<<" Path "<<i<<' ';
            temp = P[i][j];
            while (temp != j)
            {
                cout << "- " << temp << " ";
                temp = P[temp][j];
            }
            cout << "- " << j << endl;
        }
    }
    return 0;
}