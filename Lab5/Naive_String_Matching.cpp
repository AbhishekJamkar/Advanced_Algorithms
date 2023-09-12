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
    int shift = 0;
    vector<int> vect;
    
    for(int i = 0; i < n - m + 1; i++)
    {
        string textfind = text.substr(i, m);
        cout << "Comparing " << pattern << " with " << textfind << endl;
        shift++;
        
        if(textfind == pattern)
        {
            vect.push_back(i);
        }
    }
    
    for(auto it : vect)
    {
        cout << it << endl;
    }

    return 0;
}


// Enter text : 
// jim_saw_me_in_a_book_shop_book_shop
// Enter pattern : 
// book
// Comparing book with jim_
// Comparing book with im_s
// Comparing book with m_sa
// Comparing book with _saw
// Comparing book with saw_
// Comparing book with aw_m
// Comparing book with w_me
// Comparing book with _me_
// Comparing book with me_i
// Comparing book with e_in
// Comparing book with _in_
// Comparing book with in_a
// Comparing book with n_a_
// Comparing book with _a_b
// Comparing book with a_bo
// Comparing book with _boo
// Comparing book with book
// Comparing book with ook_
// Comparing book with ok_s
// Comparing book with k_sh
// Comparing book with _sho
// Comparing book with shop
// Comparing book with hop_
// Comparing book with op_b
// Comparing book with p_bo
// Comparing book with _boo
// Comparing book with book
// Comparing book with ook_
// Comparing book with ok_s
// Comparing book with k_sh
// Comparing book with _sho
// Comparing book with shop
// 16
// 26
