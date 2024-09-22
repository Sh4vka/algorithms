#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int position;
    cin >> position;
    vector <int> fib = {0, 1};
    while (fib.size() <= position)
    {
        fib.push_back(fib[(fib.size() - 1)] + fib[(fib.size() - 2)]);
    }
    cout << fib[position];
    return 0;
}