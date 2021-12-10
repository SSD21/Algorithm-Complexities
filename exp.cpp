#include <math.h>
#include <iostream>
using namespace std;

int exponentation(int num)
{
    int temp = num;
    int count = 0;
    int firstLog = (int)floor(log(temp) / log(2));
    int firstPow = (int)pow(2, firstLog);

    cout << "log(" << temp << ") = " << firstLog << endl;
    cout << temp << " - 2^" << firstLog << " = " << temp - firstPow << endl;
    temp -= firstPow;
    while (temp > 0)
        
    {
        int l = (int)floor(log(temp) / log(2));
        int po = (int)pow(2, l);
        cout << "log(" << temp << ") = " << l << endl;
        cout << temp << " - 2^" << l << " = " << temp - po << endl;
        temp -= po;
        count++;
    }
    return count + firstLog;
}
string getOut(int pow)
{
    return "a^" + to_string(pow);
}
int methB(int num)
{
    int count = 0;
    while (num > 1)
    {
        bool isOdd = num % 2 == 1;
        count += (isOdd ? 2 : 1);
        num /= 2;
        cout << (isOdd ? "a * " : "") << getOut(num) << " * " << getOut(num) << endl;
    }

    return count;
}
int main()
{
    int input;
    cout << "Enter an input: ";
    cin >> input;
    cout << "Method A: " << endl;
    int ans = exponentation(input);
    cout << "The answer is " << ans << endl;
    cout << "Method B: " << endl;
    ans = methB(input);
    cout << "The answer is " << ans << endl;
    return 0;
}