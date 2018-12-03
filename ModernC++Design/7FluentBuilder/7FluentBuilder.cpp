// 7FluentBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;



struct HtmlElement
{
	string _name, _text;
	vector <HtmlElement> _elements;

	const size_t indent_size = 2;

	HtmlElement() = default;

	HtmlElement(const string &name, const string &text) : _name(name), _text(text) {}

	string str(int indent = 0) const {
		ostringstream oss;
		string i(indent_size *indent, ' ');
		oss << i << "<" << _name << ">" << endl;

		if (_text.size() > 0) {
			oss << string(indent_size * (indent + 1), ' ') << _text << endl;
		}

		for (const auto& e : _elements) {
			oss << e.str(indent + 1);
		}

		oss << i << "</" << _name << ">" << endl;
		return oss.str();
	}

	/*4- Now another thing that you can do is you can give a hint to the consumer to the client that's actually
		 using your API that they should really be using the builder.
		 And here once again it's really up to you how to do this.
		 But for example what you could do is you could make a static function inside the HTMLElement because
		 that's actually the thing that we're building up you can make a static function called build which would
		 return and HTML builder.
		 So you would have a function called build which would take the route name because remember,
		 That's what the HTMLBuilder takes as a constructor argument.
		 And here you would return simply the HTMLBuilder with that argument so you would return root_name on this
		 provided to the constructor of a HtmlBuilderr and notice we don't have to put in the actual
		 name of the class we're returning here because it's inferred from this.*/
	//C++17
	/*static HtmlBuilder build(string root_name) {
		return { root_name };
	}*/
};


struct HtmlBuilder {
	HtmlElement _root;

	HtmlBuilder(string root_name) {
		_root._name = root_name;
	}
	//utility func
	/*1- Now to make a fluent interface you simply change the return type of a function from a void into either
		 a pointer or a reference to the type you're currently in.*/

	HtmlBuilder& add_child(string child_name, string child_text) {
		HtmlElement e{ child_name, child_text };
		_root._elements.emplace_back(e);
		return *this;
	}
	/* Print our HTML out after we are done working with it*/
	string str() const { return _root.str(); }

};

int main()
{

	
	/*auto text = "hello";
	string output;
	output += "<p>";
	output += text;
	output += "</p>";
	cout << output << endl;

	string words[] = { "hello", "world" };
	ostringstream oss;
	oss << "<ul>";

	for (auto w : words) {
		oss << " <li>" << w << "</li>";
	}
	oss << "</ul>";
	cout << oss.str() << endl;*/

	/*0- So one of the improvements that I want to add to our implementation of the builder is something called
		 a fluent interface so as you can see we've got two child coal's here one after another.
		 And what if I told you that you can actually do them like this sort of add child 1 and then add child
		 to another.
		 This is actually quite common in design patterns such as the builder and it's called a flu and interface.
     */

	
	HtmlBuilder builder{ "ul" };
	builder.add_child("li", "hello").add_child("li", "world");
	/*2- The end result of that call is a reference to a builder and you can take that reference and do another
	     call of ADD child on top of that and you can sort of continue this to infinity by doing more and more
		 calls.*/

	/*3- Now this is particularly convenient in builders because sometimes the builders you make they want to
		 kind of do several very similar things.
		 Or you might want to specify how the chain of build commands can be constructed then you can do this
		 using this kind of fluent interface.*/

	cout << builder.str() << endl;

	/*5- And as a result what you can do is you can do something like the following: auto builder
		 equals and then you can see a similar element.
		 Colin Colin build so you build the order list for example and then you can call at child on it however
		 many times you want.
		 So this is a valid way of actually putting many things into a single basket so to speak.
		 So at the same time you constructed from the elements you're building up and then you call and child
		 on the final kind of icing on the cake if you will is that it's possible to define an automatic conversion
		 operators so that when you instead of making a builder Let's suppose you actually want to get an HMO
		 element here and let's suppose you want to have an element called element or just L.M. in here as a
		 result of this build process.*/

	////C++17
	//auto builder2 = HtmlElement::build("ul").add_child("", "");



	return 0;
}
