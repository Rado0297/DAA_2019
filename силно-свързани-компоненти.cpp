#include <iostream>
#include<vector>
#define MAXN 128
using namespace std;
int N, M;
int A[MAXN][MAXN];
vector<bool> used;
int postnum[MAXN], count=0;

void DFS(int v){                                    //алгоритъм DFS
    used[v]=1;
    for(int j=1; j<=N; j++)
        if (used[j]==0 && A[v][j]==1)
            DFS(j);

    postnum[v]=count;
    count++;
}

void backDFS(int v){                                //алгоритъм DFS
    cout<<v<<" ";
    count++;
    used[v]=1;
    for (int j=1; j<=N; j++)
        if(used[j]==0 && A[j][v]==1)
            backDFS(j);
}

void strongComponents(){                            //намира силно свързаните компоненти в граф
    used.assign(N+1, 0);
    for(int i=0; i<N; i++)                          //алгоритъм за DFS върху целия граф
        if(used[i]==0)
            DFS(i);
    used.assign(N+1, 0);
    count=0;
    while(count<N-1){                               //докато не обиколим целия граф
        int max=-1, maxv=-1;
        for(int i=1; i<=N; i++)
            if(used[i]==0 && postnum[i]>max){       //намираме върха с най-голяма номерация
                max=postnum[i];
                maxv=i;
            }
        cout<<"{";
        backDFS(maxv);                              //от него започва силно свързана компонента
        cout<<"}"<<endl;
    }
}

int main()
{
    cin>>N>>M;
    int x, y;
    for(int i=0; i<M; i++){
        cin>>x>>y;
        A[x][y]=1;
    }

    strongComponents();

    return 0;
}

