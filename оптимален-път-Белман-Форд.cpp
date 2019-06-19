#include<iostream>
#define inf 9999999999
#defone MAXN 128
using namespace std;
int n, m, dp[MAXN], a[MAXN][MAXN], v, u, w, s;

int main ()
{
    cin>>n>>m;                                  //��������� N-���� ������� � M-���� �����

    for(int i=1; i<=n; i++){                    //��������� ������ �������
        for(int j=1; j<=n; j++)                 //��������� ������ �������
            a[i][j]=inf;                        //�������� ��������� �������� INF
    }

    for(int i=0; i<m; i++){                     //������� �� �������
        cin>>v>>u>>w;                           //�������� ����� ����� ���� V � ���� U � ����� (�������) W
        a[v][u]=w;                              //�����������, �� ������� ����� V � U ���� W � ��������� �� ������� (���������� ����)
    }

    s=1;                                        //�������� ������� ���� S (� ������ - 1)
    for(int i=1; i<=n; i++){                    //��������� ������ �������
        dp[i]=a[s][i];                          //�������������� ��� �� ����� ���� ���� � ����� �� S �� ����
    }
    dp[s]=0;                                    //���-������� ��� �� ����� S �� ����� ���� � 0

    for(int k=0; k<n-2; k++)                    //��������� ������� ������ N-1 ����
        for(int i=1; i<=n; i++){                //��������� ������ �������
            for(int j=1; j<=n; j++){            //��������� ������ �������
                if(dp[i]>dp[j]+a[j][i])         //��� ������� �� ��������� ���� �� ����� j, ������� � ������� �� ������� �� j �� i � ��-����� �� �������������� ��� �� i
                    dp[i]=dp[j]+a[j][i];        //����������� �� i ����� �� j � ���� ����� i � j
            }
        }

    cout<<dp[n];                                //�������� ������ DP � ������� �������� ����

    return 0;
}

/*
����������� �� ������� ����� ���������� ��������� ���� � ������ ���-����� ��� ����� �������� ������� � ����� ���� (� ������ S � N).
 ���������� �� � �(N^3) ������ ����� ������� ������.
*/
