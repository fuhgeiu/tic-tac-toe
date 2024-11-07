#ifndef exceptions_h
#define exceptions_h

#include <stdexcept>

namespace c_exception {

namespace runtime {


struct acess_nullptr : public std::runtime_error {

    acess_nullptr(const char* Message) : std::runtime_error (Message) {}

    const char *additional_info() const { return "attempting to derefernce a nullptr, critical error"; }
};

struct invalid_input_type : public std::runtime_error {
    
    invalid_input_type (const char* Message) : std::runtime_error (Message) {}
    
    const char *additional_info() const { return "wrong data type";}
};




} // end N runtime

} // end N c_exception




#endif /* exceptions_h */
