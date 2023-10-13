#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List<int> a(5);

    for (int i = 1; i < 7; i++)
        a.Push(i);

    a.Print();
    a.Extract();
    a.Extract();
    cout << endl;

    a.Print();
    cout << endl;

    return 0;
}