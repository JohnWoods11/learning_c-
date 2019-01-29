/*
Simple calculator

Implements a basic calculator.
Takes input from cin and outputs to cout.

The grammar for input is:

Calculation:
	quit
	print
	statement

Statement:
	declaration
	expression

Declaration:
	"#" name "=" expression

Expression
	term
	expression "+" term
	expression "-" term

Term:
	primary
	term "*" exponent
	term "/" exponent


Primary:
	number
	"(" expression ")" 
	- primary
	+primary
	sqrt(primary)
	pow(primary,primary)

number
	floating-point-literal


Input comes from cin through the Token_stream called ts.
*/

#include "../stdlibfacilities.h"


//Token for holding input (constructors for operator, number and name tokens)
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }											
	Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string name) :kind(ch), name(name) { }
};

//Token stream for look ahead functionality
class Token_stream {
	bool full;																		
	Token buffer;																
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 's';
const char power = 'p';

//Parse input into Token
Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '#':
		return Token(let);
	case '.': 
    case '0': case '1': case '2': case '3': case '4': 
    case '5': case '6': case '7': case '8': case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;				
			cin.unget();	
			if (s == "quit") return Token(quit);
			if (s == "sqrt") return Token(square_root);
			if (s == "pow") return Token(power);
			return Token(name, s);														
		}
		error("Bad token");
	}
}

//Ignore input up to char c
void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

//Struct for handling declared variables
struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names = {Variable("k",1000)};	

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;									
	error("get: undefined name " + s);
}

void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name " + s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

//Following parsing functions parse according to grammar
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}	
	case '-':																						//accept negative values
		return - primary();
	case '+':
		return + primary();
	case number:
		return t.value;
	case name:																						//accept declared variables
		return get_value(t.name);
	case square_root:
	{
		double expression = primary();
		if (expression < 0)
		{
			error("square root of negative number");
		}															// adding square root and power here have gone against the books advice 
		return sqrt(expression);									// on how big a function should be (fit on a sceen). However due to the way
	}																// the code is written if you want the operation as a prefix it must be in
	case power:														// primary?? Would it be good practice to make square_root and power into a  
	{																// function executed when their tokens are caught in the case. If i were 
		t = ts.get();												// to do that does it set presedence for doing the same with parentheses?
		if (t.kind != '(')
		{
			error("'(' expected");
		}
		double x = primary();
		t = ts.get();
		if (t.kind != ',')
		{
			error("',' expected");
		}
		int i;
		try
		{
			i = narrow_cast<int, double>(primary());
		}
		catch(const std::exception& e)
		{
			throw invalid_argument("Error: expected an interger!");
		}
		
		t = ts.get();													// % however i could not find this technique. I found the technique whereby 
		if (t.kind != ')')											// we used fmod to give float functionality and this would just involve using
		{															// powf(x,i). I'm not sure if the book meant use the technique we used for 
			error("')' expected");									// factorials in the previous chapter so i used that and just assigned i to int.
		}
		return pow(x,i);
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Declare a variable
double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name + " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " + name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

//Is user declaring or calculating
double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

//Ignore input until after a specific input
void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		while (t.kind != print and t.kind != quit)										//evaluates all declarations and expressions before
		{	
			ts.unget(t);																			//the print command
			cout << result << statement() << endl;	
			t = ts.get();
		}
		ts.unget(t);
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();																//Clear erroneous input ready for next task
	}
}

int main()

	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}