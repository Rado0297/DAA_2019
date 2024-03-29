#include<iostream>
#include<vector>
#include <queue>
#define INF 32000
using namespace std;
vector < vector< pair<int, int> > > graph;
int n, m, x, y, z;
void dijkstra(int s){
    vector<int> d(n+1, INF);                                             //����� �� ����������� �� ��������� �� ��� ��� �� s �� ������ ��������
    d[s]=0;                                                             //����������� ���������� �� ��������� ���� ������ � 0
    priority_queue <pair<int, int> > q;                                 //������������� �� ������ q, ����� ��������� ��������� � ������������ �� ���. ���-������� ���������� � ���-����
    q.push(make_pair(s, 0));                                            //������� ��������� ����, � ���������� 0, �� �� ������� �����������
    while(!q.empty()){                                                  //������ �������� �� � ������
        pair<int, int> top = q.top();                                   //��������� ������� ������
        q.pop();                                                        //� �������������� ���� ���� �� ������
        for(int i=0; i<graph[top.first].size(); i++){                   //��������� �������� �� ������� ����
            int cur_vert=graph[top.first][i].first;                     //��������� ������ �� ������� ����� �
            int cur_dist = graph[top.first][i].second;                  //��������� ������������ �� ����
            if(d[cur_vert]>d[top.first]+cur_dist){                      //��� ����������� ���������� �� ������ � ��-������ �� ����������� ���������� �� �����, ����� ��� �������� �� ����� �� �������� + ������������ �� ���� �� ������, ����� �����������
                d[cur_vert]=d[top.first]+cur_dist;                      //��� �������� ��� ��������� ���. ��������� �� ��
                q.push(make_pair(cur_vert, d[top.first]+cur_dist));     // � �������� � �������� ����� ���� � ����� ��������� ��� �� ����
            }
        }
    }

    if(d[n]==INF) cout<<-1<<endl;
    else cout<<d[n]<<endl;
}

int main()
{
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0; i<m; i++){
        cin>>x>>y>>z;
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }
    dijkstra(1);


    return 0;
}
