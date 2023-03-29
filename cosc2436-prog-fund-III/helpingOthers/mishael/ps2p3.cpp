#include <iostream>
#include <string>
#include <stack>

using namespace std;

int evaluatePostfix(string exp)
{
	stack<int> st;

    for (int count = 0; count < exp.size(); count++)
    {
        if (isdigit(exp[count]))
        {
            st.push(exp[count] - '0');
            cout << "After push operation: " << exp[count] << endl;
    
        }

        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[count])
            {
            case '+':
                st.push(val2 + val1);
                cout << "After + operation: " << val2 + val1 << endl;
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;

            }
        }
    }
    return st.top();
}


int main()
{
	string exp;
	cout << "Enter a postfix expression: ";
    getline(cin, exp);

    cout << evaluatePostfix(exp);
}
