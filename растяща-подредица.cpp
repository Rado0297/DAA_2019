#include<iostream>
using namespace std;
int n, a[128], dp[128], p[128], maxi;

void parent(int i){ //����� ���������� �� ��������
    if(p[i]==i){
        cout<<a[i]<<" ";
        return ;
    }cout<<a[i]<<" ";
    parent(p[i]);

}

int main ()
{
    cin>>n;
    for(int i=0; i<n; i++){cin>>a[i]; p[i]=i;}
    dp[0]=1;
    for(int i=1; i<n; i++){
        maxi=0;
        for(int j=0; j<i; j++){
            if(a[j]<a[i] && dp[j]>maxi){//��� ������� ��-����� ������� ��-���� � ��������, �� ����� ����� ��-����� ������� ������
                    maxi=dp[j];
                    p[i] = j;   //�������� ������� j ��� ��������
            }
        }
        dp[i]=maxi+1;
    }
    int sol=0, sol_position= 1;
    for(int i=0; i<n; i++){
        if(dp[i]>sol) {         //�� ���-������� ������� ���������
            sol = dp[i];
            sol_position = i;   //������� ������� �� ��������� ������� �� ���
        }

    }
    for(int i=0; i<n; i++)cout<<p[i]<<" "; cout<<endl;
    cout<<sol<<endl;
    parent(sol_position);       //�������� �����������
    cout<<endl;

    return 0;
}
