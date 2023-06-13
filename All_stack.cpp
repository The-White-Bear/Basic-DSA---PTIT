#include <bits/stdc++.h>
using namespace std;
bool is_Operator(string x)
{
    if (x == "+" || x == "-" || x == "*" || x == "/")
        return true;
    return false;
}
string pre_to_infix(vector<string> prefix)
{
    stack<string> infix;

    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        if (!is_Operator(prefix[i]))
        {
            infix.push(prefix[i]);
        }
        else
        {
            string op1 = infix.top();
            infix.pop();
            string op2 = infix.top();
            infix.pop();
            string tmp = op1 + op2 + prefix[i];
            infix.push(tmp);
        }
    }
    return infix.top();
}
long long tinh_hauto(vector<string> postfix)
{
    stack<int> st;
    for (int i = 0; i < postfix.size(); ++i)
    {

        if (!is_Operator(postfix[i]))
            st.push(stoi(postfix[i]));
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            if (postfix[i] == "+")
            {
                st.push(val2 + val1);
            }
            if (postfix[i] == "-")
            {
                st.push(val2 - val1);
            }
            if (postfix[i] == "*")
            {
                st.push(val2 * val1);
            }
            if (postfix[i] == "*")
            {
                st.push(val2 / val1);
            }
        }
    }
    return st.top();
}
int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    vector<string> postfix;
    while (ss >> word)
    {
        postfix.push_back(word);
    }
    int res = tinh_hauto(postfix);
    cout << res;
}