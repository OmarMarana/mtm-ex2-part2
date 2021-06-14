#include <exception>

namespace mtm
{
    class Exception: public std::exception
    {
        public:
            class IllegalArgument{ const char * what() const noexcept; };
            class IllegalCell{ const char * what() const noexcept; };
            class CellEmpty{ const char * what() const noexcept; };
            class MoveTooFar{ const char * what() const noexcept; };
            class CellOccupied{ const char * what() const noexcept; };
            class OutOfRange{ const char * what() const noexcept; };
            class OutOfAmmo{ const char * what() const noexcept; };
            class IllegalTarget{ const char * what() const noexcept; };
    };
}