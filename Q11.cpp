#include <bits/stdc++.h>
using namespace std;
vector<string> production = {"E+E", "E-E", "E*E", "E/E", "(E)", "a", "b", "c"};
string input;
stack<string> parse_tree;

bool getReduced()
{
    int len = input.size();
    bool ok = false;
    for (int i = 0; i < len; i++)
    {
        for (auto prod : production)
        {
            int ind = i;
            bool ok = true;
            for (char ch : prod)
            {
                if (ch != input[ind])
                {
                    ok = false;
                    break;
                }
                ind++;
            }
            if (ok)
            {
                // production match
                input.erase(i, prod.size());
                input.insert(i, "E");
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> input;
    input += '$';
    while (input.size() > 2)
    {
        parse_tree.push(input);
        bool ok = getReduced();
        if (ok)
            continue;
        cout << "Invalid String." << endl;
        return 0;
    }
    // cout << input << " : last situation." << endl;
    parse_tree.push(input);
    while (!parse_tree.empty())
    {
        string str = parse_tree.top();
        str.pop_back();
        cout << str << endl;
        parse_tree.pop();
    }
    return 0;
}