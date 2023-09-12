#include <bits/stdc++.h>

using namespace std;

int main()
{
    string text;
    string pattern;
    cout << "Enter text : " << endl;
    getline(cin >> ws, text);
    cout << "Enter pattern : " << endl;
    cin >> pattern;
    int n = text.length();
    int m = pattern.length();
    int shift[26];
    vector<int> vect;
    
    for(int i = 0; i < 26; i++)
    {
        shift[i] = pattern.length();
    }
    
    for(int i = 0; i < m - 1; i++)
    {
        shift[pattern[i] - 'a'] = m - i - 1;
    }
   
    for(int i = 0; i < 26; i++)
    {
        cout << shift[i] << endl;
    }
    
    int j = 0, i = 0;
    
    while(j + m <= n)
    {
        if(pattern[m - 1] == text[j + m - 1])
        {
            i = m - 2;
            while(i >= 0 && pattern[i] == text[j + i])
            {
                i--;
                if(i == -1)
                {
                    vect.push_back(j);
                }
            }
        }
        if(shift[text[j + m - 1]] >= 26 || shift[text[j + m - 1]] < 0)
        {
            j += j + pattern.length();
        }
        j += j + shift[text[j + m - 1]];
    }
    
    for(auto it : vect)
    {
        cout << it << endl;
    }
    return 0;
}


