#include <bits/stdc++.h>
using namespace std;
// int evaluateArithmeticExpression(string &expression)
// {
// 	st
// }
// string postfixtoprefix(string &str)
// {
// 	stack<char> sk;
// 	string ans;
// 	for(int i =0;i<str.length();i++)
// 	{
// 		if('0'<=str[i] && str[i]<='9')
// 		{
// 			ans += str[i];
// 		}
// 		else if(str[i]=='(')
// 		{
// 			sk.push(str[i]);
// 		}
// 		else if(str[i]==')')
// 		{
// 			while(sk.top()!='(')
// 			{
// 				ans+= sk.top();
// 				sk.pop();
// 			}
// 			sk.pop();
// 		}
// 		else{
// 			if(str[i]=='*' || str[i]=='/')
// 			{	if(sk.top()=='*' || sk.top()=='/')
// 			{
// 				ans += sk.top();
// 				sk.pop();
// 				sk.push(str[i]);
// 			}
// 			else
// 				sk.push(str[i]);
// 			}
// 			else{
// 				if((sk.top()=='*' || sk.top()=='/') )
// 				{
// 					while(!sk.empty() || sk.top()!='(')
// 					{
// 						ans += sk.top();
// 						sk.pop();
// 					}
// 					sk.push(str[i]);
// 				}
// 				else sk.push(str[i]);
// 			}
// 		}
// 	}
// 	return ans;
// }
// int evaluatePostfix(string &expr) {
//     string exp = postfixtoprefix(expr);
//     stack<int> sk;
//     for(int i =0;i<exp.length();i++)
//     {   if(ch!=' ')
//         {
//         if('0'<= ch && ch<= '9')
//         {
//             sk.push(ch);
//         }
//         else{
//             int ele1 = sk.top();
//             if(sk.top()>9)
//              ele1 = sk.top()-((int)'0');
//             sk.pop();
//             int ele2 = sk.top();
//             if(sk.top()>9)
//             ele2 = sk.top()-((int)'0');
//             sk.pop();
//             if(ch=='+')
//             {
//                 sk.push(ele1+ele2);
//             }
//             else if(ch=='-')
//             {
//                 sk.push(ele2-ele1);
//             }
//             else if(ch=='*')
//             {
//                 sk.push(ele1*ele2);
//             }
//             else{
//                 sk.push(ele2/ele1);
//             }
//         }}
//     }
//     return sk.top();
// }
void solve(stack<char> &opert, stack<int> &sk)
{
    char ch = opert.top();
    opert.pop();
    int ele1 = sk.top();
    sk.pop();
    int ele2 = sk.top();
    sk.pop();
    if (ch == '+')
    {
        sk.push(ele1 + ele2);
    }
    else if (ch == '-')
    {
        sk.push(ele2 - ele1);
    }
    else if (ch == '*')
    {
        sk.push(ele1 * ele2);
    }
    else
    {
        sk.push(ele2 / ele1);
    }
}
int evaluateArithmeticExpression(string &str) 
{
    stack<char> opert;
    stack<int> nums;
    	for(int i =0;i<str.length();i++)
	{
		if('0'<=str[i] && str[i]<='9')
		{	int num =0;
			while(('0'<=str[i] && str[i]<='9'))
			{
				num = num*10;
				num += (str[i]-'0');
				i++;
			}
			i--;
            nums.push(num);
		}
		else if(str[i]=='(')
		{
			opert.push(str[i]);
		}
		else if(str[i]==')')
		{
			while(opert.top()!='(')
			{
				solve(opert,nums);
			}
			opert.pop();
		}
		else{
			if(str[i]=='*' || str[i]=='/')
            {
                while ((!opert.empty()) && (opert.top()!='+' || opert.top()!='-') && opert.top()!='(')
                {
                    solve(opert,nums);
                }
                opert.push(str[i]);
            }
            else{
                while((!opert.empty()) && opert.top()!='(')
                {
                    solve(opert,nums);
                    opert.push(str[i]);
                }
                opert.push(str[i]);
            }
	}
	
}
if(!opert.empty()) cout<<opert.top();
  return nums.top();  
}
int main()
{
    string str = "(3*(5+2)*(10-7))";
    cout << evaluateArithmeticExpression(str);
}