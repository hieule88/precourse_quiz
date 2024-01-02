#include <iostream>
template < typename T >
void func ( T && param ) {
    std :: cout << " test 1!" << std :: endl ;
}
template < typename T >
void func ( T& param ) {
    std :: cout << " test 2!" << std :: endl ;
}
int main () {
    int x = 10;
    func (x) ;
    func (20) ;
    return 0;
}