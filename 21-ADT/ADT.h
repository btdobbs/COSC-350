//Abstract Data Type (ADT)
//how does one interact with a concept
//no implementation (this is where the algorithms and data are defined)
//.h files in c++

class Number{
public:
    Number operator +(Number n);
    Number operator -(Number n);
    Number operator /(Number n);
    Number operator *(Number n);
    Number operator <(Number n);
    Number operator >(Number n);
    Number operator =(Number n);
    Number operator ==(Number n);
    Number successor();
    Number predecessor();
};

