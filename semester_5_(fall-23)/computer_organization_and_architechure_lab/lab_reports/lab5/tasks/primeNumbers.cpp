#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    int numHalf = num / 2;
    for (int i = 2; i <= numHalf; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main()
{

    int first, second;
    first = second = -1;
    int num = 3;

    for (int i = num - 1; i >= 2; i--)
    {
        if (isPrime(i))
        {
            if (first == -1)
                first = i;
            else if (second == -1)
                second = i;
            else
                break;
        }
    }

    first != -1 && second != -1 ? cout << "The largest two prime numbers lower than " << num << " are: " << first << " and " << second << endl : cout << "There are not enough prime numbers lower than " << num << " to find two." << endl;

    return 0;
}