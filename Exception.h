#include <exception>

namespace mtm
{
    class Exception: public std::exception
    {
        public:
            class IllegalArgument{public: const char * what() const noexcept; };
            class IllegalCell{public: const char * what() const noexcept; };
            class CellEmpty{public: const char * what() const noexcept; };
            class MoveTooFar{public: const char * what() const noexcept; };
            class CellOccupied{public: const char * what() const noexcept; };
            class OutOfRange{public: const char * what() const noexcept; };
            class OutOfAmmo{public: const char * what() const noexcept; };
            class IllegalTarget{public: const char * what() const noexcept; };
    };
}