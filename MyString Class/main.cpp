#include <iostream>
#include "Mystring.h"
using namespace std;

int main() {
    // just some sample test cases --
    cout<<"\n=====TEST-1=====\n"<<endl;
    Mystring obj1;
    obj1.display();

    Mystring obj2 {"Hello"};
    obj1 = obj2;
    obj2.display();

    obj2 = Mystring {"NewWorld"};
    obj2.display();

    obj2 = "GreatWorld";
    obj2.display();

    cout<<"\n=====TETS-2=====\n"<<endl;

    cout<<boolalpha;

    cout<<(obj1 == obj2)<<endl;  // false

    obj2 = obj1;
    cout<<(obj1 == obj2)<<endl;  // true
    cout<<("CheckObject" == obj2);

    cout<<"\n=====TETS-3=====\n"<<endl;

    cout<<(obj1 != obj2)<<endl;

    obj1 = "UniqueWorld";
    cout<<(obj1 != obj2)<<endl;
    cout<<("My_World" != obj2)<<endl;

    cout<<"\n=====TETS-4=====\n"<<endl;

    cout<<(obj1 > obj2)<<endl;
    cout<<(obj1 < obj2)<<endl;

    cout<<"\n=====TETS-5=====\n"<<endl;

    obj1.display();
    obj2.display();

    (obj1 + obj2).display();
    obj1.display();

    obj1 = obj1 + obj2 + "THIS IS TEST";
    obj1.display();
    obj2.display();

    cout<<"\n=====TETS-6=====\n"<<endl;

    obj1 = "Hello";
    obj2 = "World";

    obj1 += obj2 + "TEST CONCATENATION";

    obj1.display();
    obj2.display();

    cout<<"\n=====TETS-7=====\n"<<endl;

    obj1.display();
    obj2.display();

    obj2 = -obj1;

    obj1.display();
    obj2.display();

    cout<<"\n=====TETS-8=====\n"<<endl;

    obj1 = "Hello";
    obj2 = "World";

    (obj1 * 5).display();
    (obj2 * 0).display();

    obj1.display();
    obj2.display();

    cout<<"\n=====TETS-9=====\n"<<endl;

    obj1 *= 5;
    obj1.display();

    cout<<"\n=====TETS-10=====\n"<<endl;

    cout << obj1 << endl;
    cout << obj2 << endl;

    cout << obj1 << obj2 << endl;

    cout << "Enter string-1 & string-2 respectively: ";
    cin >> obj1 >> obj2;
    cout << obj1 << " " << obj2 << endl;
    return 0;
}
