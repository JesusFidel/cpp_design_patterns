// 0IntroductionToModernCppDesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Key Concepts

/*Curiously Recurring Template Pattern*/
/*Essentially, the idea is simple: an inheritor passes itself as a
template argument to its base class:
struct Foo : SomeBase<Foo>
 {
 ...
 }
why one would ever do that? Well,
one reason is to be able to access a typed this pointer inside a base class
implementation.

*/

int main()
{
    return 0;
}

