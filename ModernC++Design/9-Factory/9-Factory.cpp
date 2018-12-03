// 9-Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*0- So what is the motivation for using factories in the first place.
	 Well we do get situations where the logic involved in actually creating the object before you even start
	 using it becomes a bit too complicated a bit too convoluted and unfortunately there are lots of limitations
	 in terms of the API that you're given for creating an object because for example the constructor is
	 not particularly descriptive.
	 - For example you cannot change the name of a constructor because the name is mandated by the containing
	 type.
	 So the name of the constructor is the name of the type you're in.
	 - You also do not have the ability to have overloads of the constructor with the same sets of arguments
	 of the same type.
	 Just giving them different names and that's again an additional problem that you might have to resolve
	 somehow suddenly in the case of a constructor you cannot have two constructors which both take an int.
	 That's simply not possible.
	 - Now if you do decide to go for the other approach like for example start taking optional parameters
	 so that you get to kind of specify defaults and customization options inside a single constructor.
	 This turns into a really messy kind of scenario and kind of optional parameter hell where you get massive
	 constructors full of these optional parameters and nobody can quite figure out which parameters absolutely
	 must be specified them which can be left as defaults and whether the defaults are internally consistent
	 with one another.

	 So it all gets messy and that's why we use the factory design pattern.

	 So the idea is that if we are talking about individual kind of single statements for object creation
	 then we can outsource them to factories.

	 Now this is where the difference between the factories and the builder pattern comes in because the
	 builder is where you construct an object in steps you make several different calls , you might be using 
	 a fluent interface it's a complicated process.

	 In the case of a factory it's more of a process which has lots of different varieties like for example
	 suppose you making a bank account you can set it up as a checking account or as a credit account.
	 You can have all sorts of different overdraft options and you don't want to stick it into a single constructor
	 but you still have this paradigm of a construct like coal.

	 And that is where you can put for example this functionality into a separate function and that's what's
	 called the factory method design pattern.

	 Or you can make a separate class which takes care of the construction of particular objects and that
	 is the factory pattern.
	 But I would say that's the key pattern here is the factory.
	 And finally you can also create hierarchies of factories corresponding to the hierarchies of objects
	 that you have somewhere.
	 So you have hierarchies of factories creating hierarchies of objects and that is the much more rarely
	 used abstract factory design pattern.

	 So the factory design pattern is all about having some sort of component which is responsible solely
	 for the wholesale and not piecewise creation of objects so piecewise creation is something that's left
	 to the builder.
	 But the factory tries to make the entire object in a single call basically.
	 */

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
}

