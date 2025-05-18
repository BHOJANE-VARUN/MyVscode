#include <iostream>
using namespace std;

int i = 0;
string input;

int E();
int Edash();
int T();
int Tdash();
int F();

int E()
{
    if (T())
    {
        if (Edash())
            return 1;
    }
    return 0;
}

int Edash()
{
    if (input[i] == '+')
    {
        i++;
        if (T())
        {
            if (Edash())
                return 1;
        }
        return 0;
    }
    else
    {
        return 1; // epsilon
    }
}

int T()
{
    if (F())
    {
        if (Tdash())
            return 1;
    }
    return 0;
}

int Tdash()
{
    if (input[i] == '*')
    {
        i++;
        if (F())
        {
            if (Tdash())
                return 1;
        }
        return 0;
    }
    else
    {
        return 1; // epsilon
    }
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return 1;
            }
        }
        return 0;
    }
    else
    {
        // Match 'id' manually without substr()
        if (input[i] == 'i' && input[i + 1] == 'd')
        {
            i += 2;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cout << "Enter input string ending with $: ";
    cin >> input;
    i = 0;

    if (E() && input[i] == '$')
    {
        cout << "Parsing successful!" << endl;
    }
    else
    {
        cout << "Parsing failed!" << endl;
    }

    return 0;
}
