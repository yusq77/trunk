#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>


char * Getip (char *interface)
{
    register int fd, intrface;
    struct ifreq buf[16];
    struct ifconf ifc;

    if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        return NULL;
    }

    ifc.ifc_len = sizeof (buf);
    ifc.ifc_buf = (caddr_t) buf;
    if (ioctl (fd, SIOCGIFCONF, (char *) &ifc) < 0)
    {
        return NULL;
    }

    intrface = ifc.ifc_len / sizeof (struct ifreq);
    while (intrface-- > 0)
    {
        //printf ("net device %s : ", buf[intrface].ifr_name);
        if (strcmp (buf[intrface].ifr_name, interface))
            continue;

        if ((ioctl (fd, SIOCGIFFLAGS, (char *) &buf[intrface])) < 0)
        {
            close (fd);
            return NULL;
        }

        if (!(ioctl (fd, SIOCGIFADDR, (char *) &buf[intrface])))
        {
            close (fd);
            return
                inet_ntoa (((struct sockaddr_in *) (&buf[intrface].ifr_addr))->sin_addr);
        }
        close (fd);
        return NULL;
    }
    close (fd);
    return NULL;
}

int main(int argc,char *argv[])
{
    printf("%s\n", Getip("eth1"));
    printf("%s\n", Getip("eth2"));
    printf("%s\n", Getip("eth3"));
    printf("%s\n", Getip("lo"));

/*
  int i=2;
  assert(i==3);
  printf("i=%d \n",i);
  */
  return 0;
}
