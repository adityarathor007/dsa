#include <iostream>
using namespace std;

bool isPrime(int n,int i)
{

    // corner cases
    if (n == 0 || n == 1 || n<0)
    {
        return false;
    }

    // Checking Prime
    if (n == i)
        return true;

    // base cases
    if (n % i == 0)
    {
        return false;
    }
    i++;
    return isPrime(n,i);
}

int CeilSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;

    // Starting from 1, try all numbers until
    // i*i is greater than or equal to x.
    int i = 1, result = 1;
    while (result < x)
    {
        i++;
        result = i * i;
    }
    return i;
}

bool checkPerfectSquare(int x){
    // Base cases
    if (x == 0 || x == 1)
        return true;

    // Starting from 1, try all numbers until
    // i*i is greater than or equal to x.
    int i = 1, result = 1;
    while (result <= x)
    {
        i++;
        result = i * i;
        if(result==x){
            return true;
        }
    }
    return false;
}


int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--){
        int a = 0;
        int counter = 0;
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            n -= 4;
            counter += 1;
        }

        // cout<<"the value of n based on cond "<<n<<endl;
        int sqrt = CeilSqrt(n);
        // cout << "the sqrt is " << sqrt << endl;

        // if a is 2;
        
        if (counter == 1)
        {
            for (int i = 3; i < sqrt; i++)
            {
                int temp = n;
                // cout<<"entered the for loop"<<endl;
                if (isPrime(i, 2))
                {
                    counter += 1;
                    temp -= (i * i);
                    // cout<< "the value of n is"<<temp<<endl;
                    // cout << "the value of sqrt n is: " << CeilSqrt(temp) << endl;
                    if (checkPerfectSquare(temp) and isPrime(CeilSqrt(temp),2))
                    {
                        counter += 1;
                        break;
                    }
                }
                
                counter = 1;
            }

            if (counter == 3)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        // else
    }

    return 0;
}
