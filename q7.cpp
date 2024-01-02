#include <iostream>
class Sample {
    private :
        int num1 ;
    public :
        Sample ( int num2 ) {
            num1 = num2 ;
        }
        void func1 () {
            Sample d (4) ;
        }
};
void func2 () {
    Sample c (3) ;
    c. func1 () ;
}
Sample b (2) ;
int main () {
Sample a (1) ;
func2 () ;
return 0;
}