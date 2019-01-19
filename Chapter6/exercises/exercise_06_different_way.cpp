#include "../stdlibfacilities.h"


string get_part()
{
    string input;
    cin >> input;                                                                           //collect word from string
    if (input == "swim" or input == "fly" or input == "rules")
        return "verb";                                                                      //word is verb
    else if (input == "birds" or input == "fish" or input == "C++")
        return "noun";                                                                      //word is noun
    else if (input == "and" or input == "or" or input == "but")
        return "conjunction";                                                               //word is conjunction
    else if (input == ".")
        return "end";                                                                       //termination character entered
    else
        return "invalid";                                                                   //Word is invalid
}
    


string noun_verb()
{
    string is_noun = get_part();                                                            //retrieve word: is_noun
    if (is_noun == "noun")                                                                  //is is_noun a noun?
    {
        string is_verb = get_part();                                                        //if is_noun was a noun retrieve word: is_verb
        if (is_verb == "verb")                                                              //is is_verb a verb?
        {
            return "sentence";                                                              //is_noun = noun and is_verb = verb                                                                                            
        }                                                                                   //return sentence
        else
        return is_verb;                                                                     //is_verb not a verb
    }                                                                                       //return its type
    else
    return is_noun;                                                                         //is_noun not a noun
}                                                                                           //return its type

bool sentence()
{
    string left_sentence = noun_verb();                                                     //check for noun verb pair
    if (left_sentence == "end")                                                             //if either is termination character return false
    return false;
    string next = get_part();                                                               //what is next word/characters type
    if (next == "conjunction")                                                          
    {
        if (sentence() == true and left_sentence == "sentence")                             //if conjunction are the words following
        return true;                                                                        //it a sentence
        else
        return false;
    }
    else if (next == "end")                                                                 //if termination character is called was a
    {                                                                                       //the previous input a sentence according to grammar
        if (left_sentence == "sentence")
        return true;
        else
        return false;
    }
    else                                                                                    //if it was neither a conjunction or termination 
    {                                                                                       //character the input failed the grammar check
    left_sentence = "false";                                                            
    while (true)                                                                        
    if (get_part() == "end")                                                                //cycle through the rest of the input until
    return false;                                                                           //termination character so input is empty for
    }                                                                                       //next grammar check
    
}

void grammar_check()
{
    if (sentence() == true)
    {
        cout << "OK." << endl;
    }
    else 
    {
        cout << "not OK." << endl;
    }
}

int main()
{
    cout << "Please enter the string that you would like to check against the grammar." << endl
    << "Terminate string with ' .' (a whitespace followed by a full stop)." << endl;
    while (true)
    {
        try
        {
            grammar_check();
        }
        catch (...)
        {
            cout << "MAJOR ERROR";
            return 1;
            break;
        }
    }
    return 0;
}