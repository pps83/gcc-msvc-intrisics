#include <stdint.h>
#include <emmintrin.h>
#ifdef _MSC_VER
#include <intrin.h>
#endif

#if !defined(_MSC_VER) && defined(__GNUC__)
static inline unsigned char _BitScanForward(unsigned long* ret, unsigned long x)
{
    *ret = __builtin_ctz(x);
    return x != 0;
}

static inline unsigned char _BitScanReverse(unsigned long* ret, unsigned long x)
{
    *ret = 31 - __builtin_clz(x);
    return x != 0;
}
#endif
