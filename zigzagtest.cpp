#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set <int> s;
int main()
{
    for (int i = 2; i <= 10; i += 2)
        s.insert(i);
    s.erase(9);
    for (auto it = s.cbegin(); it != s.cend(); it++)
    {
        int x = *it;
        printf("%d\n", x);
    }
    return 0;
}
