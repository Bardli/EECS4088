#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main (void)
{
int LOOP=5;
 int i=0,f=0;
    f=open("/sys/class/gpio/export",O_RDWR);
    write(f,"60",2);
    close(f);
 // set direction out
 f=open("/sys/class/gpio/gpio60/direction",O_RDWR);
 write(f,"out",3);
 close(f);
 f=open("/sys/class/gpio/gpio60/value",O_WRONLY);
// Note - correct i = LOOP, make it i less than or equal to LOOP
 for(i=1;i=LOOP;i++)
 {
  // LED On
  write(f,"1",1);
  sleep(1);
  // LED off;
  write(f,"0",1);
  sleep(1);
 }
 close(f);

 printf("\nLED Blink Program is terminated !!!");
} // end of main