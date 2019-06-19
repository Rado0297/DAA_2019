/*  ������� ����:  ����� �� ������ �������� � ���� ����� �.
����� � ���-�������� �������� ��������? ��� �� ��? */
#include<iostream>
#include<utility>
#include<vector>
#define INF 99999
using namespace std;
int n, m, s[1024], maxValue=-1, index;
pair<int, int> a[1024];
vector<vector <bool> > used;

int main ()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i].first>>a[i].second;
        //��������� �� ������� � ���������� �� ����������

    used.resize(m+1);
    used[0].resize(n+1);

    for(int i=1; i<=m; i++){         //�� ����� ���� �����
        used[i].resize(n+1);  //��������������� �� ����� ������
        for(int j=0; j<n; j++){        //�� ������ ��������
            int price=a[j].first, value=a[j].second;
            if(i>=price && s[i-price]+value>s[i] && used[i-price][j]==0){
            //��� ������� �� ��������� ��������, ����� ����������� �
            //��������� ������� �� � ��������� �� ����
                s[i]=s[i-price]+value;//������������ ����������
                used[i]=used[i-price];//����������� ��� �������� ��� ���������� �� ��������� �� ���������� �����
                used[i][j]=1;//����������� ������� ������� �� ���������
            }
        }
        if(s[i]>maxValue){
            maxValue=s[i]; //����������� ��� � ������������ ��������
            index=i;  //� �������
        }
    }
    cout<<"Max value = "<<maxValue<<endl;
    for(int i=0; i<n; i++)if(used[index][i]==1)cout<<i+1<<endl; //�������� ��������� �� ����������, ���������� �� ������

    return 0;
}

/*������:
8 70
30 5
15 3
50 9
10 1
20 2
40 7
5 1
65 12
�����: 13*/
