
#include "hellolib/hello.h"
#include <fmt/format.h>


void hello() {
    #ifdef NDEBUG
    const std::string build_type = "Release";
    #else 
    const std::string build_type = "Debug";
    #endif
    
    fmt::print("Hello, {} {}!", build_type, "world"); 
}
