/*
    notes

    selective stream mover

    *key points

    * read the stream character by character and only moves what is allowed by condition
    * useing move semantics, stream data is only moved once cleared, no copying when processed
    * can define conditions, for data they want to get, bad data is never moved
    * can define, so user can recieve feedback
    * must define, where the data is to be moved to

    class condition - base class                                lines (30-38)
    1) virtual ~condition ()
    2) const virtual bool pass_condition (int) = 0
    3) virtual void output_range () = 0

    derived class
    1, range ()                                                 lines (40-58)
    constructors
    1, (int, int)           (upper bound, lower bound)          set a upper and lower bound
    2, (char, int)          (upper or lower bound, int)     set the bound to a lower or upper 'u' upper, 'l' lower
    ______________________________________________________________________________________________________________________
    BASE CLASS ::CONDITION
    1) virtual destructor to be called when heap allocated object derived from base class is deleted
    2) virtual method for determining whether data passed conditions, return bool      -pure virtual
    3) virtual method for printing range of the condition, no return     -pure virtual
    ______________________________________________________________________________________________________________________
    DERIVED ::RANGE
 */


#include <iostream>
#include "str.hpp"


namespace strm {


class condition {

public:
    
    virtual ~condition (){};                  // called after destructor for derived class called, if set to a base class pointer

    virtual const bool pass_condition (int) = 0;

    virtual void output_range () = 0;
};

class range : public condition {                                                   // class for range condition

    int lower_bound, upper_bound;
    char lower_upper_choice;

public:

    range (int upper, int lower){                               // constructor

        lower_bound = lower;
        upper_bound = upper;
        lower_upper_choice = 'n';
    }
    
    range (char lower_upper, int bound) {                        // constructor

        if (lower_upper == 'u') upper_bound = bound;
        if (lower_upper == 'l') lower_bound = bound;
        lower_upper_choice = lower_upper;
    }

    const bool pass_condition (int i) {

        if (lower_upper_choice == 'n') {

            if (i > lower_bound && i < upper_bound) return true;
            else return false;
        }

        if (lower_upper_choice == 'l') {

            if (i > lower_bound) return true;
            else return false;
        }

        if (lower_upper_choice == 'u') {

            if (i < upper_bound) return true;
            else return false;
        }
        return false;
    }

    void output_range ()  { std::cout << "upper bound" << upper_bound; std::cout << "lower bound" << lower_bound; }
};


class conditional {                                             // class for stream return

     condition *Condition;                                       // store condition for object

public:

    conditional (){};                                                     // constructor generic

    template <class Ccond>                                            // if pass in condition at object instantiation
    conditional (Ccond condition) {

        conditional::Condition = condition;
    }
    
    conditional (condition* C) {Condition = C;}
    
// method to get integars from stream and return using condition passed in constructor
int move (std::istream &universal_stream) {

    int integar;

        universal_stream >> integar;

        integar = (Condition->pass_condition(integar));

    return std::move(integar);
}


// method to get integars from stream and return using passed in condition object
int moveif (std::istream &by_stream, condition* Cotn) {

    int integar;

        by_stream >> integar;

        integar = (Cotn->pass_condition(integar));

    return std::move(integar);
}


// method to get characters from stream and return into object (usually string)
template <typename condition,typename C>
void moveif (std::istream &by_stream,condition Cotn, C object) {                        // in progress

    char character;
    // contianer to store stream data

    while (by_stream.get(character)) {

        // check if stream data meets condition
        // if meets condition than append it to the container
    }
    // return std::move(container)
}


char* getline (std::istream &stream,strstd::string string_container) {                  // in progress

//    char character;
    // string container to return
    auto *m_data = new char[1];

//    std::getchar();

    // while stream is not a null character

        // append string container with character from stream
//  return container
    return m_data;
}

};  // end class conditional




int get (std::istream &by_stream, condition* Condition) {           // to get int from stream, only return after condition is met

    int i;

    while (true) {

        by_stream >> i;
        if (Condition->pass_condition(i-1)) {return i;}
        else if (std::cin.fail()) {
            std::cout << "invalid data\n";  std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
        else break;
    }
    return i;
}

}   // end of namespace
