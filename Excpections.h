#include <exception>

namespace mtm
{
    class Excpections: public std::exception
    {
        public:
            class ileegalCell1;
            class OutOfAmmo{};
    };

    
}