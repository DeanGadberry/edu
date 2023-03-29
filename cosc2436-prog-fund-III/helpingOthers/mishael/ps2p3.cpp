//
//
// Deal with your spaces problem
// see comments for details
//
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int evaluatePostfix(string exp)
{
	stack<int> st;

    for (int count = 0; count < exp.size(); count++)
    {
    // What are the various cases that need to be checked?
        // how are you going to deal with spaces?
        // how are you going to deal with multiple-digit integers
        if (isdigit(exp[count]))
        {
        std::cout<<"is digit (if statement)"<<std::endl; // to test when this runs
            st.push(exp[count] - '0');
            cout << "After push operation: " << exp[count] << endl;
        }

        else
        {
        std::cout<<"is not digit (else statement)"<<std::endl; // to test when this runs
            // core dumps when this is encountered.
            // you need to deal with spaces. 
            int val1 = st.top();
            st.pop(); // try removing this line, and see what happens
                      // why? 
                      // this deletes the 1 digit which you loaded  
                      // when you called st.push();
            int val2 = st.top();
            st.pop(); // try removing htis line, and see what happens
                      // why?
                      // this tries to delete something from the stack
                      // but, the digit is already gone
                      // segmentation fault - core dumps.
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
