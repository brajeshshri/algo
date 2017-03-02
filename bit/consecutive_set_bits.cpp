#include<bits/stdc++.h>
using namespace std;
 
// Returns true if n has increasing count of
// continuous-1 else false
bool findContinuous1(int n)
{
    const int bits = 8*sizeof(int);
 
    // store the bit-pattern of n into
    // bit bitset- bp
    string bp = bitset <bits>(n).to_string();
 
    // set prev_count = 0 and curr_count = 0.
    int prev_count = 0, curr_count = 0;
 
    int i = 0;
    while (i < bits)
    {
        if (bp[i] == '1')
        {
            // increment current count of continuous-1
            curr_count++;
            i++;
        }
 
        // traverse all continuous-0
        else if (bp[i-1] == '0')
        {
            i++;
            curr_count = 0;
            continue;
        }
 
        // check  prev_count and curr_count
        // on encounter of first zero after
        // continuous-1s
        else
        {
            if (curr_count < prev_count)
                return 0;
            i++;
            prev_count=curr_count;
            curr_count = 0;
        }
    }
 
    // check for last sequence of continuous-1
    if (prev_count > curr_count && (curr_count != 0))
        return 0;
 
    return 1;
}
 
// Driver code
int main()
{
    int n;
    cout <<"Enter a number: ";
    cin>>n;
    if (findContinuous1(n))
        cout << "Yes"<<endl;
    else
        cout << "No"<<endl;
 
    return 0;
}
