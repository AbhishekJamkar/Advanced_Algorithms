#include <bits/stdc++.h>
using namespace std;


vector<char> findReachable(char symbol, map<char, vector<string>> productions)
{
    stack<char> st;
    map<char, bool> visited;
    vector<char> reachable;
    st.push(symbol);
    visited[symbol] = true;
   
    while(!st.empty())
    {
        char top = st.top();
        st.pop();
       
        for(auto prod : productions[top])
        {
            for(auto c : prod)
            {
                if(c >= 65 && c <= 90 && !visited[c])
                {
                    visited[c] = true;
                    st.push(c);
                }
            }
        }
    }
    for(auto it : visited)
    {
        if(it.second)
        {
            reachable.push_back(it.first);
        }
    }
    return reachable;
}


bool canTerminate(char symbol, map<char, vector<string>> productions)
{  
    bool foundNt = false;
    int count = 0;
    stack<char> st;
    st.push(symbol);
    map<char, bool> visited;
    visited[symbol] = true;


    while(!st.empty())
    {
        char top = st.top();
        st.pop();  
        int count = 0;


        for(auto prod : productions[top])
        {
            count = 0;
            for(auto c : prod)
            {
                if(c >= 65 && c <= 90)
                {
                    if(visited[c])
                    {
                        continue;
                    }
                    else
                    {
                        st.push(c);
                        visited[c] = true;
                        break;
                    }
                }
                else if(c == '^')
                {
                    return true;
                }
                else
                {
                    count++;
                }
            }
            if(count == prod.length())
            {
                return true;
            }
        }
    }


    return false;
}


int main()
{
    map<char, vector<string>> productions;
    char non_terminal, start_symbol;
    string temp;
    int n, no_of_pr;
    cout << "Enter number of non terminals : ";
    cin >> n;
    vector<string> tempProductions;
    vector<char> nonTerminals;


    for (int i = 0; i < n; i++)
    {
        tempProductions.clear();
        cout << "Enter non terminal : ";
        cin >> non_terminal;
        nonTerminals.push_back(non_terminal);


        if (i == 0)
        {
            start_symbol = non_terminal;
        }
        cout << "Enter number of productions for " << non_terminal << " : ";
       
        cin >> no_of_pr;
        for (int j = 0; j < no_of_pr; j++)
        {
            cout << non_terminal << " -> ";
            cin >> temp;
            tempProductions.push_back(temp);
        }
        productions.insert({non_terminal, tempProductions});
    }


    for (auto it : productions)
    {
        for (auto it2 : it.second)
        {
            cout << it.first << " -> " << it2 << endl;
        }
    }


    vector<char> reachable = findReachable(start_symbol, productions);


    //Above I have found unreachable non terminals
    //Removing those which productions are not able to terminate


    vector<char> terminating;


    for(auto it : reachable)
    {
        if(canTerminate(it, productions))
        {
            terminating.push_back(it);
        }
    }


    vector<bool> toKeep(26, false);


    for(auto it : terminating)
    {
        toKeep[it - 'A'] = true;
    }


    map<char, vector<string>> validProductions;
    bool isValid = true;
    vector<string> tempVect;


    for(auto it : terminating)
    {
        tempVect.clear();
        for(auto it2 : productions[it])
        {
            isValid = true;
            for(auto it3 : it2)
            {
                if(it3 >= 65 && it3 <= 90 && !toKeep[it3 - 'A'])
                {
                    isValid = false;
                    break;
                }
            }
            if(isValid)
            {
                tempVect.push_back(it2);
            }
        }
        validProductions.insert({it, tempVect});
    }
   
    if(validProductions.size())
    {
        cout << "Production rules after removal of useless variables : " << endl;
        for (auto it : validProductions)
        {
            for (auto it2 : it.second)
            {
                cout << it.first << " -> " << it2 << endl;
            }
        }
    }
    else
    {
        cout << "All are useless variables" << endl;
    }
}
