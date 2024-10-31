#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const char *str) {
    const void *buf = (const void *)str;
    size_t count = strlen(str);
    int rez1 = write( 1, buf, count );
    if( rez1 < 0 )
    {
        errno = -rez1;
        return -1;
    }

    int rez2 = write( 1, "\n", 1 );
    if( rez2 < 0 )
    {
        errno = -rez2;
        return -1;
    }
    return 0;
}