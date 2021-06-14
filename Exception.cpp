#include "Exception.h"

namespace mtm
{
    const char* Exception::IllegalArgument::what() const noexcept
    {
        return "A game related error has occurred: IllegalArgument";
    }

    const char* Exception::IllegalCell::what() const noexcept
    {
        return "A game related error has occurred: IllegalCell";
    }

    const char* Exception::CellEmpty::what() const noexcept
    {
        return "A game related error has occurred: CellEmpty";
    }

    const char* Exception::MoveTooFar::what() const noexcept
    {
        return "A game related error has occurred: MoveTooFar";
    }

    const char* Exception::CellOccupied::what() const noexcept
    {
        return "A game related error has occurred: CellOccupied";
    }

    const char* Exception::OutOfRange::what() const noexcept
    {
        return "A game related error has occurred: OutOfRange";
    }

    const char* Exception::OutOfAmmo::what() const noexcept
    {
        return "A game related error has occurred: OutOfAmmo";
    }

    const char* Exception::IllegalTarget::what() const noexcept
    {
        return "A game related error has occurred: IllegalTarget";
    }
   
}