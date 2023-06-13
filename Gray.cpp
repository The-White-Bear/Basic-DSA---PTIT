#include <bits/stdc++.h>
using namespace std;
vector<string> generateGray(int n)
{
    if (n <= 0)
        return {"0"};
    if (n == 1)
    {
        return {"0", "1"};
    }
    vector<string> recAns = generateGray(n - 1);
    vector<string> mainAns;
    for (int i = 0; i < recAns.size(); i++)
    {
        string s = recAns[i];
        mainAns.push_back("0" + s);
    }
    for (int i = recAns.size() - 1; i >= 0; i--)
    {
        string s = recAns[i];
        mainAns.push_back("1" + s);
    }
    return mainAns;
}
void generateGrayarr(int n)
{
    vector<string> arr;
    arr = generateGray(n);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
}
void gray_to_binary(string gray)
{
    string binary="";
    binary+=gray[0];
    for(int i=1;i<gray.length();i++)
    {
        if(gray[i]=='1')
        {
            if(binary[i-1]=='0')
            {
                binary=binary+"1";
            }
            if(binary[i-1]=='1')
            {
                binary=binary+"0";
            }
        }
        else
        {
            binary+=binary[i-1];
        }
    }
    cout <<binary<< endl;
}
string binary_to_gray(string binary)
{
    int n = binary.length();
    string gray = binary;

    for (int i = 1; i < n; i++)
    {
        if (binary[i] != binary[i - 1])
        {
            gray[i] = '1';
        }
        else
        {
            gray[i] = '0';
        }
    }

    return gray;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin>>s;
        gray_to_binary(s);
        
    }
}