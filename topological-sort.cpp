#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
vector<vector<int> >a;
vector<int> indegree;
queue<int> topological;

void topologicalSort(){                                         //алгоритъм за топологично сортиране
    queue<int> q;                                               //опашка на текущо занулените върхове.
    for(int i=1; i<=n; i++){                                    //ако връх няма насочени към него ребра, то го добавяме в опашката
        if(indegree[i]==0)q.push(i);
    }

    while(!q.empty()){                                          //докато опашката не е празна
        int v=q.front();                                        //взимаме следващия връх
        q.pop();
        topological.push(v);                                    //добавяме го в топологичната подредба
        for(int i=0; i<a[v].size(); i++){                       //обхождаме съседите му
            indegree[a[v][i]]--;                                //премахваме свързващите ребра
            if(indegree[a[v][i]]==0)                            //ако намерим занулен съсед, го добавяме в опашкатая
                q.push(a[v][i]);
        }
    }
}


int main()
{
    cin>>n>>m;
    a.resize(n+1);
    indegree.resize(n+1);
    int x, y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        a[x].push_back(y);
        indegree[y]++;
    }
    topologicalSort();
    while(!topological.empty()){
        cout<<topological.front()<<" ";
        topological.pop();
    }
    cout<<endl;

    return 0;
}


/*
Алгоритъмът за топологично сортиране е модификация на алгоритмите за обхождане на ориентиран граф,
при който целта е постигане на такава линейна подредба на върховете, че всички ребра да са насочени отляво надясно.
Идеята е на всяко ниво на обхождане да се търсят такива върхове, че към тях да няма насочени ребра от недобавени в подредбата върхове.
Приложенията му са в търсене на подредба между зависими един от друг обекти.
*/
