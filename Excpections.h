#include <exception>

namespace mtm
{
    class Excpections: public std::exception
    {
        public:
            class IllegalCell{};
            class OutOfAmmo{};
            class OutOfRange{};
            class IllegalTarget{};

    };

    
}