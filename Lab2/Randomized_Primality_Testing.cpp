#include <bits/stdc++.h>
using namespace std;
int k = 100;
int liars = 0, witnesses = 0;

unsigned long long gcd_(unsigned long long a, unsigned long long b)
{
    if(a < b)
    {
        return gcd_(b, a);
    }
    else if(a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd_(b, a % b);
    }
}

unsigned long long power(unsigned long long a, unsigned long long n, unsigned long long p)
{
    unsigned long long res = 1;
    a = a % p;

    while(n > 0)
    {
        if(n & 1)
            res = (res * a) % p;
        
        n = n >> 1;
        a = (a * a) % p;
    }
    return res;
}
bool isPrime(unsigned long long n)
{
    if(n <= 1 || n <= 4)
        return false;
    if(n <= 3)
        return true;

    while(k > 0)
    {
        unsigned long long a = 2 + rand() % (n - 3);

        if(gcd_(n, a) != 1)
        {
            return false;
        }
        if(power(a, n - 1, n) != 1)
        {
            witnesses++;
            return false;
        }
        if(power(a, n - 1, n) == 1)
        {
            liars++;
        }
        
        cout << "w" << witnesses << endl;
        cout << "l" << liars << endl;

        k--;
    }
    return true;
}

void liarFinder(unsigned long long n)
{
    for(int a = 2; a <= n - 2; a++)
    {
        unsigned long long z = power(a, n - 1, n);
        if(z == 1)
        {
            liars++;
        }
        else
        {
            witnesses++;
        }
    }
    
    cout << "Liars " << liars << endl;
    cout << "Witnesses " << witnesses << endl;
    float probL = (liars) / float(n - 3);
    float probW = witnesses / float(n - 3);
    
    cout << probL << " " << probW << endl;
}
int main()
{
    unsigned long long n;
    cin >> n;

    if(isPrime(n))
    {
        cout << "Number is prime" << endl;
    }
    else
    {
        cout << "Number is composite" << endl;
    }

    liarFinder(n);
    
    return 0;
}
