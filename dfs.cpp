#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >a;
int n, m;
bool used[128];

void dfs(int v){                            //��������� DFS
    used[v]=1;                              //����������� ������� ���� �� �������
    cout<<v<<" ";
    for(int i=0; i<a[v].size(); i++){       //��������� ������ ������� �� ���������� V
        if(used[a[v][i]]==0)                //��� ������� ���� �� � �������
            dfs(a[v][i]);                   //�������� �������� �� DFS � i-��� ���� �� ���������� V
    }
}

int main ()
{
    cin>>n>>m;
    a.resize(n+1);                          //�������� ������� A �� ��� N+1 ����������
    int v, u;
    for(int i=0; i<m; i++){                 //������� �� �������
        cin>>v>>u;                          //��������� ���� V � ���� U, ����� ����� ��� �����
        a[v].push_back(u);                  //�������� � ���������� V ���� U
        a[u].push_back(v);                  //�������� � ���������� U ���� V (��� ������������ ����)
    }

    cin>>v;                                 //��������� ������� ���� V �� �����������
    dfs(v);                                 //�������� DFS � ������� ���� V

    return 0;
}

/*
DFS (Depth-First-Search) � ��������� �� ��������� �� ���� � ���������. �.�. ���������� ����������� �� ���� ���� � ������ ����� ��������� ����� �
���� �� �������� �� ������ �� ����� (�� ����, ����� ���� ���������� ������). ���������� �� ������� �� ������ ��������� ���� � ���������.
������������ �� �� �� �������� �� ����� � ���� � ������ �� ������� (�����, ��������� ��������� ����������).
*/
