// 8. Write a program which converts a word of C++ program to its equivalent token
// Sample input: 554 258.5 *
#include <bits/stdc++.h>
using namespace std;
int pointCount = 0;

char singleQuote = '\'';
char doubleQuote = '\"';

vector<string> keywords = {"true", "false", "or", "and", "for", "if", "else", "do", "while", "break", "continue", "int", "float", "double", "bool", "long", "unsigned", "char", "string", "void", "auto", "new", "switch", "namespace", "class", "const", "sizeof", "typedef", "xor", "delete", "nullptr"};

vector<string> arithmetic_operators = {"+", "-", "*", "/", "%"};
vector<string> inc_dec_operators = {"++", "--"};
vector<string> assignment_operators = {"=", "+=", "-=", "*=", "/=", "%="};
vector<string> relational_operators = {"==", "!=", ">", "<", ">=", "<="};
vector<string> logical_operators = {"&&", "||", "!"};
vector<string> bitwise_operators = {"&", "!", "^", "~", "<<", ">>"};

void sort_keywords_operators()
{
    sort(keywords.begin(), keywords.end());
    sort(arithmetic_operators.begin(), arithmetic_operators.end());
    sort(inc_dec_operators.begin(), inc_dec_operators.end());
    sort(assignment_operators.begin(), assignment_operators.end());
    sort(relational_operators.begin(), relational_operators.end());
    sort(logical_operators.begin(), logical_operators.end());
    sort(bitwise_operators.begin(), bitwise_operators.end());
}

string isConstant(string input)
{
    pointCount = 0;
    bool isConstant = false;

    if (input[0] == doubleQuote && input[input.size() - 1] == doubleQuote)
    {
        // cout << "Double Quotation Found !" << endl;
        return "String Constant (Double Quotation Found)";
    }
    else if (input[0] == singleQuote && input[input.size() - 1] == singleQuote && input.size() == 3)
    {
        // cout << "Single Quotation Found !" << endl;
        return "String Constant (Single Quotation Found)";
    }

    // Check if it is a number
    if (isdigit(input[0]))
    {
        isConstant = true;
        // Check if rest of the characters are number (and 1 point)
        for (int i = 1; i < input.size(); i++)
        {
            if (input[i] == '.')
            {
                pointCount++;
            }
            else if (!isdigit(input[i]))
            {
                isConstant = false;
                break;
            }
        }
        if (pointCount == 0 && isConstant)
            return "Integer";
        else if (pointCount == 1 && isConstant)
            return "Float";
    }
    return "xInvalidx";
}

bool isKeyword(string input)
{
    if (binary_search(keywords.begin(), keywords.end(), input))
        return true;
    else
        return false;
}

string isOperator(string input)
{
    if (binary_search(arithmetic_operators.begin(), arithmetic_operators.end(), input))
        return "Arithmetic Operator";
    else if (binary_search(inc_dec_operators.begin(), inc_dec_operators.end(), input))
        return "Increment-Decrement Operator";
    else if (binary_search(assignment_operators.begin(), assignment_operators.end(), input))
        return "Assignment Operator";
    else if (binary_search(relational_operators.begin(), relational_operators.end(), input))
        return "Relational Operator";
    else if (binary_search(logical_operators.begin(), logical_operators.end(), input))
        return "Logical Operator";
    else if (binary_search(bitwise_operators.begin(), bitwise_operators.end(), input))
        return "Bitwise Operator";
    else
        return "xInvalidx";
}

bool isIdentifier(string input)
{
    bool isIdentifier = false;

    if (isalpha(input[0]) || (input[0] == '_'))
    {
        isIdentifier = true;
        for (int i = 1; i < input.size(); i++)
        {
            if (!isalpha(input[i]) && !isdigit(input[i]) && input[i] != '_')
            {
                isIdentifier = false;
                break;
            }
        }
    }
    if (isIdentifier)
        return true;
    else
        return false;
}

vector<string> separateWords(string str)
{
    vector<string> words;
    string word = "";

    for (auto letter : str)
    {
        if (letter == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else

            word += letter;
    }
    words.push_back(word);
    return words;
}

int main()
{
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);

    sort_keywords_operators();

    string str;
    getline(cin, str);

    // Separate Words from a Long String and Save them to 'lexemes' vector
    vector<string> lexemes = separateWords(str);

    for (int i = 0; i < lexemes.size(); i++)
    {
        string input = lexemes[i];
        cout << "Scanned : " << input << endl;

        if (isConstant(input) != "xInvalidx")
        {
            cout << isConstant(input) << endl;
        }
        else if (isKeyword(input))
        {
            cout << "Keyword" << endl;
        }
        else if (isOperator(input) != "xInvalidx")
        {
            cout << isOperator(input) << endl;
        }

        else if (isIdentifier(input))
        {
            cout << "Identifier" << endl;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
}