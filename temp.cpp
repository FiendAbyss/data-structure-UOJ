#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printHeap(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n"
         << endl;
}

int main()
{
    vector<int> min = {05, 56, 20, 23, 40, 38, 29, 61, 35, 76, 28, 100};

    // ½¨Á¢Ð¡¶¥¶Ñ
    make_heap(min.begin(), min.end(), less<int>());
    printHeap(min); 

    
    sort_heap(min.begin(), min.end(), less<int>()); 
    printHeap(min);
    

    return 0;
}