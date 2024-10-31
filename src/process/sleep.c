#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>


unsigned int sleep(unsigned int seconds) {
    struct timespec req = { seconds, 0 };
    struct timespec rem = { 0, 0 };
    
    while (nanosleep(&req, &rem) == -1 && rem.tv_sec > 0) {
        req = rem;
    }
    return (unsigned int)rem.tv_sec;
}
