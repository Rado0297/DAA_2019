#include<iostream>
#include<utility>
#include<iomanip>
using namespace std;
int n, m, b;
pair<int, double>a[1024];
bool c[1024][1024];
double s[1024], maxi=-1;

int main ()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;                               //��������� �� ���������� - ������� ����� � ����
    }

    for(int i=1; i<=m; i++){                                        //�� ������ �������� ����� �� 1 �� M
        for(int j=0; j<n; j++){                                     //��������� ����������
            b=a[j].first;
            if(i>=b && s[i-b]+a[j].second>s[i] && c[i-b][j]==0){    //��� �������� �� �������� � ��-����� �� �����������, ���������� �� ��� �������� �� ������� ������ � ��������� �� � ���������
                s[i]=s[i-b]+a[j].second;                            //��������
                for(int h=0; h<n; h++)c[i][h]=c[i-b][h];            //� ����������� ��� �������� ��� ����������, �� �� ������� ������
                c[i][j]=1;                                          //����������� �������� ���� ���������
            }
        }
        if(s[i]>maxi)maxi=s[i];                                     //��� ������ � ��-������ �� ������������, � �������� �� ����������
    }
    cout<<maxi<<endl;                                               //�������� ������������ ����

    return 0;
}
