#include<iostream>
#include<cmath>
using namespace std;

class Quadratic
{
public:
 int a, b, c, s;
 Quadratic()
 {
  a = 0;
  b = 0;
  c = 0;
 }
 Quadratic operator+(Quadratic& d)
 {
  Quadratic c4;
  c4.a = this.a + d.a;
  c4.b = this.b + d.b;
  c4.c = this.c + d.c;
  return c4;
 }
 friend void operator<<(ostream& o, Quadratic& e)
 {
  o << e.a << "x^2" << "+" << e.b << "x" << "+" << e.c;
 }
 friend void operator>>(istream &i,Quadratic &q)
    {
        i>>q.a>>q.b>>q.c;
    }
};

int main()
{
 Quadratic c1, c2, c3;
 cout << "Initially polynomial is: ";
 cout << c1;
 cout << "\nEnter first polynomial: " << endl;
 cin >> c1;
 cout << "Enter second polynomial: " << endl;
 cin >> c2;
 c3 = c1 + c2;
 cout << "\nAddition of two polynomial: " << endl;
 cout << c3;
 return 0;
}
