#include <iostream>
#include <string>
#include <stack>

using namespace std;

//REFERENCE https://www.geeksforgeeks.org/evaluation-of-postfix-expression/#

int evaluatePostfix()
{
    string exp;
    cout << "Enter a postfix expression: ";
    getline(cin, exp);

    stack<int> st;
    cout << "Stack Contents: " << endl;

    for (int count = 0; count < exp.size(); ++count)
    {
        if (isdigit(exp[count]))
        {
            st.push(exp[count] - '0');
            cout << "After push operation: " << exp[count] << endl;

        }

        else if (exp[count] == '+' || exp[count] == '-' || exp[count] == '*' || exp[count] == '/')
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (exp[count])
            {
            case '+':
                st.push(val1 + val2);
                cout << "After + operation: " << val2 + val1 << endl;
                break;

            case '-':
                st.push(val2 - val1);
                cout << "After - operation: " << val2 - val1 << endl;
                break;

            case '*':
                st.push(val2 * val1);
                cout << "After * operation: " << val2 * val1 << endl;
                break;

            case '/':
                st.push(val2 / val1);
                cout << "After / operation: " << val2 / val1 << endl;
                break;

            }

        }

    }
    cout << "Final Value: "
        //return st.top();
    << st.top() //change to cout
    <<endl;
        st.pop();
 return 0; //return 0;
};


int main()
{
    char user_input = 'y';
    do
    {
        evaluatePostfix();
        cout<<"run:";
        cin>>user_input;
    } while (user_input == 'y' || user_input == 'Y');
    return 0;
}
