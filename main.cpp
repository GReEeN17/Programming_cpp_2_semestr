#include <iostream>
#include "pass_by_reference.h"
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    swap_values_ref(a, b);
    cout << a << " " << b;
    return 0;
}
