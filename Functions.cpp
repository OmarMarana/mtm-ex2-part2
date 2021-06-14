#include "Functions.h"

namespace mtm
{
    namespace math
    {
        int abs(int a)
        {
            return a >= 0 ? a : -a;
        }
        
        int ceil(float num)
        {
            int inum = (int)num;

            if (num == (float)inum)
            {
                return inum;
            }

            return inum + 1;
        }
    }
}