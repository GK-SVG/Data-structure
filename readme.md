Data structure
*What will be the output of the following program?
#include * 
enum xyz 
{
    a, b, c
}; 
int main()
{
    int x = a, y = b, z = c; 
    int &p = x, &q = y, &r = z; 
    p = z; 
    p = ++q;
    q = ++p;
    z = ++q + p++; 
    cout<< p << " " << q << " " << z;
    return 0; 
}
A.	2 3 6
B.	4 4 7
C.	4 5 8
D.	3 4 6

*Reply below your answer a b c or d 💬*
