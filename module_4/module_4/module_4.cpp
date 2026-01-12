#include <iostream>
#include <windows.h>

int main(void) {
    
    // проверяем и выводим тип операционной системы и ее разрядность

    std::cout << "Type and version system: " << std::endl;

#if defined(__MSDOS__)
    puts("DOS 16 bit");
#elif defined(_WIN16)
    puts("Windows 16 bit");
#elif defined(_WIN64)
    puts("Windows 64 bit");
#elif defined(_WIN32) 
    puts("Windows 32 bit");
#elif defined(__APPLE__) && defined(__MACH__)
    puts("Mac OS");
#elif defined(__unix__) || defined(__linux__)
    puts("Linux 32 bit");
#elif defined(__LP64__) || defined(__amd64)
    puts("Linux 64 bit");
#else
    puts("Undefined system");
#endif

    // проверяем  и выводим информацию о типе компилятора

    std::cout << "Type compiler" << std::endl;

#ifdef __BORLANDC__
    puts("Borland");
#elif defined(__clang__)
    puts("Clang compiler");
#elif defined(__VECTORC__)
    puts("Codeplay VectorC");
#elif defined(__DMC__)
    puts("Digital Mars");
#elif defined(__INTEL_COMPILER)
    puts("Intel legacy Classic");
#elif defined(__INTEL_LLVM_COMPILER)
    puts("Intel LLVM based");
#elif defined(__SYMANTECC__)
    puts("Symantec");
#elif defined(__WATCOMC__)
    puts("Watcom");
#elif defined(__GNUC__)
    puts("GCC compiler");
#elif defined(_MSC_VER)
    puts("Microsoft");
#else
    puts("Undefined compiler");
#endif

    return 0;

}
