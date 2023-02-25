#include <stdio.h>

void log_int(int x)
{
    printf("LOG: %i \n", x);
}

void log_flt(float x)
{
    printf("LOG: %f \n", x);
}

void log_str(const char* x)
{
    printf("LOG: %s \n", x);
}

#if DEV_DEBUG == 1
#define LOG(X) _Generic((X), \
                int: log_int,  \
                float: log_flt, \
                default: log_str  \
              )(X)
#else
#define LOG(x)
#endif
