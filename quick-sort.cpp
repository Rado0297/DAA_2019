#include <iostream>
#define MAXN 1024
using namespace std;
int n, arr[225];

void quickSort(int left, int right){    //Quick sort алгоритъм с начален (ляв) и краен (десен) индекс (включително)
    int p=arr[left];                    //взимаме елемента на най-лявата позиция
    int i=left, j=right;                //взимаме си левия и десен индекс
    while(i<=j){                        //докато левия индекс е по-малък от десния, т.е. докато не ги срещнем
        while(arr[i]<p){                //намираме най-десния елемент по-малък от най-левия
            i++;
        }
        while(arr[j]>p){                //намираме най-левия елемент по-голям от най-десния
            j--;
        }
        if(i<=j){                       //ако все още не сме разминали индексите
            swap(arr[j], arr[i]);       //разменяме двата елемента
            i++; j--;
        }
    }
    if(left<j){                         //ако не сме приближили десния индекс до най-левия
        quickSort(left, j);             //прилагаме quick sort на този отрязък
    }

    if(right>i){                        //аналогично
        quickSort(i, right);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];
    quickSort(0, n-1);                     //извикваме Quick sort с начален (ляв) индекс 0 и краен (десен) индекс - последния, съдържащ елемент
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


