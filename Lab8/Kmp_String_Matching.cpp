#include <bits/stdc++.h>
using namespace std;

void string_matcher(string text, string pattern, vector<int> pi)
{
    int n = text.length();
    int m = pattern.length();
    int q = 0;
    for(int i = 1; i < n; i++)
    {
        while(q > 0 && pattern[q + 1] != text[i])
        {
            q = pi[q];
        }
        if(pattern[q + 1] == text[i])
        {
            q++;
        }
        if(q == m)
        {
            cout << " String occurs with shift " << (i - m) << endl;
            q= pi[q];
        }
    }
    
}
int main()
{
    string pattern, text;
    cin >> text;
    cin >> pattern;
    
    int cnt = 0;
    vector<int> pi(20, 0);
    int k = 0;
    for(int q = 2; q <= pattern.size()-1; q++) {
        bool t = (pattern[k+1] != pattern[q]);
        cnt ++;
        while(k > 0 && t) {
            k = pi[k];
            t = (pattern[k+1] != pattern[q]);
            cnt ++;
        }
        if(!t) k++;
        pi[q] = k;
    }
    
    string_matcher(text, pattern, pi);
    
    return 0;
}
