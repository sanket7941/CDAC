/*
to read file
*/
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char  *argv[]) {

  int src,dst;
  int cnt;
  char buff[512],str[512];

  src = open(argv[1],O_RDONLY);//read file
  // to print the file on terminal

  while ((cnt= read(src,buff,sizeof(buff)))>0)
   {
    write(1,buff,cnt);
    }
// --------------------------------------------------------------

  dst = open(argv[1],O_WRONLY | O_TRUNC | O_CREAT, 0644);//file to stor data

      cnt=read(0,str,16);
      write(dst,str,cnt);
    return 0;

    // ----------------------------------------------------
    // L-seek
}
