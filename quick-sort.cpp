#include <iostream>
#define MAXN 1024
using namespace std;
int n, arr[225];

void quickSort(int left, int right){    //Quick sort ��������� � ������� (���) � ����� (�����) ������ (�����������)
    int p=arr[left];                    //������� �������� �� ���-������ �������
    int i=left, j=right;                //������� �� ����� � ����� ������
    while(i<=j){                        //������ ����� ������ � ��-����� �� ������, �.�. ������ �� �� �������
        while(arr[i]<p){                //�������� ���-������ ������� ��-����� �� ���-�����
            i++;
        }
        while(arr[j]>p){                //�������� ���-����� ������� ��-����� �� ���-������
            j--;
        }
        if(i<=j){                       //��� ��� ��� �� ��� ��������� ���������
            swap(arr[j], arr[i]);       //��������� ����� ��������
            i++; j--;
        }
    }
    if(left<j){                         //��� �� ��� ���������� ������ ������ �� ���-�����
        quickSort(left, j);             //��������� quick sort �� ���� �������
    }

    if(right>i){                        //����������
        quickSort(i, right);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];
    quickSort(0, n-1);                     //��������� Quick sort � ������� (���) ������ 0 � ����� (�����) ������ - ���������, �������� �������
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


