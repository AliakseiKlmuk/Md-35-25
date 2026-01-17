#include <iostream>

int main()
{

    int a, b;
    std::cout << "enter a number a\n";
    std::cin >> a;
    std::cout << "enter a number b\n";
    std::cin >> b;
    std::cout << "change and enter operation\n";

    // std::cin.read();

         //a + b plus
         // a - b minus 
         // a * b Times
    std::cout << a + b << " " << a - b << " " << a * b;

    //a == b equal to
    if (a == b) { std::cout << true << std::endl; }
    else { std::cout << false << std::endl; }

    //a != b not equal to
    if (a != b) { std::cout << true << std::endl; }
    else { std::cout << false << std::endl; }

    //a > b more than
    if (a > b) { std::cout << true << std::endl; }
    else { std::cout << false << std::endl; }

    //a < b  less than
    if (a < b) { std::cout << true << std::endl; }
    else { std::cout << false << std::endl; }

    //a >= b greater than or equal to
    if (a <= b) { std::cout << true << std::endl; }
    else { std::cout << false << std::endl; }

    //a <= b less than or equal to
    if (a >= b) { std::cout << true << std::endl; }
    else { std::cout << false << std::endl; }

    //a & b AND
    int c = a & b;
    std::cout << c << std::endl;

    //a | b OR
    int d = a | b;
    std::cout << d << std::endl;

    //a ^ b XOR
    int e = a ^ b;
    std::cout << d << std::endl;

    //~a NOT
    int f = ~a;
    std::cout << f << std::endl;

    //a << 2
    int g = b << 2;
    std::cout << g << std::endl;

    //b >> 1
    int h = b >> 1;
    std::cout << h << std::endl;

}