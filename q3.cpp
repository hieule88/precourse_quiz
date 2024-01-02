#include <iostream>

class Parent {
    public :
        int value ;
        Parent () { initialize () ; }
        virtual void initialize () { value = 1; }
};
class Children : public Parent {
    public :
        Children () : Parent () { initialize(); }
        void initialize () override { value = 5; }
};
int main () {
    Parent * ptr = new Children () ;
    std :: cout << ptr -> value << "\n ";
    delete ptr ;
    return 0;
}