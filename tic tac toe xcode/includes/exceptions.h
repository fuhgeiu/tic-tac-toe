#ifndef exceptions_h
#define exceptions_h

#include <stdexcept>

namespace c_exception {

namespace runtime {

class acess_nullptr : public std::runtime_error {

public:

    acess_nullptr(const char* Message) : std::runtime_error (Message) {}

    const char *additonal_info() const { return "attempting to derefernce a nullptr, critical error"; }
};







} // end N runtime

} // end N c_exception




#endif /* exceptions_h */
