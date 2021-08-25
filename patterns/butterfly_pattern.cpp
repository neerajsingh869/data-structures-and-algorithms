#include<iostream>
using namespace std;
int main(){
    // Butterfly Pattern
    int n;
    cin>>n;
    int row = 2*n;
    int col = 2*n;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            if(i<=n){
                if (j >= i + 1 && j <= col - i)
                {
                    cout <<"  ";
                }
                else
                {
                    cout <<"* ";
                }
            }
            else{
                if (j >= col - i + 2  && j <= i - 1)
                {
                    cout <<"  ";
                }
                else
                {
                    cout <<"* ";
                }
            }
            
        }
        cout<<endl;
    }
}

// Another way of doing the same thing

// int main()
// {
//     int n;
//     cin >> n;
//     // printing patterns
//     for (int i = 1; i <= n; i++)
//     {
//         // for stars
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         // for spaces
//         for (int j = 1; j <= 2 * (n - i); j++)
//         {
//             cout << "  ";
//         }
//         // for stars
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     // reversing above pattern upside down
//     for (int i = n; i >= 1; i--)
//     {
//         // for stars
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         // for spaces
//         for (int j = 1; j <= 2 * (n - i); j++)
//         {
//             cout << "  ";
//         }
//         // for stars
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }