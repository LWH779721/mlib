#include <unistd.h>
#include <sys/reboot.h>

int sync_reboot()
{
    sync();
    return reboot(RB_AUTOBOOT);
}