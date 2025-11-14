#include <iostream>

using namespace std;

int add_integers (int a, int b)
{
    return ( a + b ); 
}
int main ( )
{
    int x = 0, y = 0; 
    
    while(1)
    {
        cout << "\nEnter two numbers : ";
        
        /* Reading multiple variables using chaining*/
        /* After using >>, a trailing newline remains in the buffer. 
         * If you then call std::getline, you may read an empty line. Consume it first:
         * std::cin >> n;
         * std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         * std::getline(std::cin, line); */
        cin >> x >> y; 
        
        cout << "sum of two numbers : "<< add_integers (x, y) << endl;
    }
 
    return 0;
}
