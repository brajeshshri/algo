#include<iostream>

using namespace std;


int main()
{

    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Input stream: "<<endl;
    int bdigit = 0, num = 0, rem = 0;
    while(1) {
        cin>>bdigit;

        if(bdigit == 1) {
            rem = (rem * 2 +1) % n;
        } else if (bdigit == 0) {
            rem = (rem * 2) % n;
        } else{
          break;
        }

        if (rem == 0) {
           cout << "yes";
        } else {
           cout << "no";
        }
    }
}
