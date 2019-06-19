#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, br, timee; //��� �������� ������� time, ����� ���� �� ������� ��������, �� ������������ � �� �� ������ ������� ���������� �� time ��� ���������� � ����� ��� (� ������ timee)
vector<vector<int> >a;
vector<bool>used;
vector<int>t, f;

void dfs(int v, int p){                 //���� � �������
    used[v]=1;                          //��������� ����� ���� �������
    f[v]=timee;                          //�������� �������� �� ������ f (������� �� ������� ��� �����)
    t[v]=timee;                          //�������� �������� �� ������ t
    timee++;                             //����������� ������ �� ����� �� ���� ��� �����
    for(int i=0; i<a[v].size(); i++){   //��������� �����
        int h=a[v][i];                  //�������� �� h ������ �� ����������
        if(h==p)continue;               //��� �������� � ��������� ��������, ������������ ��� ���������� ��������
        if(used[h]==1){                 //��� ����������� � �������
            f[v]=min(f[v], t[h]);       //������������ f[v]
        }
        else {                          //��� �� �
            dfs(h, v);                  //������ ���
            f[v]=min(f[v], f[h]);       //������������ f[v]
            if(f[h]>t[v]) br++;         //IS_BRIDGE (v, h)
        }
    }
}

int main ()
{
    cin>>n>>m;
    a.resize(n+1);
    used.resize(n+1);
    t.resize(n+1);
    f.resize(n+1);
    int x, y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, -1);
    cout<<br<<endl;


    return 0;
}
