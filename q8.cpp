#include <iostream>
using namespace std ;
# pragma pack ( push , 4)
typedef struct MyStruct_ {
char Field1 ; // 
short Field2 ; //
int Field3 ; //
} MyStruct ;
# pragma pack ( pop )
int main ( void ){
cout << " SIZE : " << sizeof ( MyStruct ) << endl ;
cout << " SIZE : " << sizeof ( char ) << endl ;
cout << " SIZE : " << sizeof ( short ) << endl ;
cout << " SIZE : " << sizeof ( int ) << endl ;
return 0;
}