#include <bits/stdc++.h>
using namespace std;

class Points{
    public :
    int x;
    int y;

    Points(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{

    vector<Points> vect;
    
    vect.push_back({2, 2});
    vect.push_back({4, 4});
    vect.push_back({5, 6});
    int min_d = INT_MAX;
    int d = 0;
    int i_min = 0, j_min = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            d = (pow((vect[j].x - vect[i].x), 2) + pow((vect[j].y - vect[i].y), 2)) ;
            
            if(d < min_d)
            {
                min_d = d;
                i_min = i;
                j_min = j;
            }
        }
    }
    
    cout << d << endl;
    cout << i_min << endl;
    cout << j_min << endl;
    
    return 0;
}
