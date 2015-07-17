//입력
//6
//4 3 2 2 9 10
//
//출력
//3

#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int natural[20000] = {0, };

int getMaxIndex(int left, int right)
{
    int mid;
    
    if (left >= right)
        return natural[left];
    else {
        mid = (left + right) / 2;
        MAX(getMaxIndex(left, mid), getMaxIndex(mid + 1, right));
    }
    
    return -1;
}



int main()
{
    int num_data;
    int max_index;
    
    cin >> num_data;
    for(int i = 0; i < num_data; i++)
        cin >> natural[i];
        
    max_index = getMaxIndex(0, num_data - 1);
    cout << max_index << endl;
    
//    for(int i = 0; i < n; i++) {
//        if(i == idx);
//    }
}