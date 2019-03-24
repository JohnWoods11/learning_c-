#include "exercise_14.h"


void countCharClassifications(string &filename)
{
    ifstream ifst(filename);
    int space = 0, alpha = 0, digit = 0, xdigit = 0, upper = 0, lower = 0, alnum = 0, cntrl = 0, punct = 0, print = 0, graph = 0;
    for (char character; ifst.get(character); )
    {
        if (isspace(character))
        {
            space++;
        }
        if (isalpha(character))
        {
            alpha++;
        }
        if (isdigit(character))
        {
            digit++;
        }
        if (isxdigit(character))
        {
            xdigit++;
        }
        if (isupper(character))
        {
            upper++;
        }
        if (islower(character))
        {
            lower++;
        }
        if (isalnum(character))
        {
            alnum++;
        }
        if (iscntrl(character))
        {
            cntrl++;
        }
        if (ispunct(character))
        {
            punct++;
        }
        if (isprint(character))
        {
            print++;
        }
        if (isgraph(character))
        {
            graph++;
        }
        s += character;
    }
    cout 
    << "Spaces\t\t\t" << setw(10) << space << endl 
    << "Letters\t\t\t" << setw(10) << alpha << endl 
    << "Decimal digits\t\t" << setw(10) << digit << endl
    << "Hexadecimal digits\t" << setw(10) << xdigit << endl 
    << "Uppercase characters\t" << setw(10) << upper << endl 
    << "Lowercase characters\t" << setw(10) << lower << endl 
    << "Alphanumerics\t\t" << setw(10) << alpha << endl
    << "Control characters\t" << setw(10) << cntrl << endl
    << "Punctuation characters\t" << setw(10) << punct << endl
    << "Printable characters\t" << setw(10) << print << endl
    << "Graph characters\t" << setw(10) << graph << endl;
}