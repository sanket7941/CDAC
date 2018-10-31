#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

//syntax: ./01_filecopy <src file>

int main(int argc, char *argv[])
{
	int fs, cnt;
	char buf[512];
	// check cmd line args
	if(argc != 2)
	{
		fprintf(stderr, "syntax: %s <src file>\n", argv[0]);
		_exit(1);
	}
	// open src file for reading
	fs = open(argv[1], O_RDONLY);
	if(fs == -1)
	{
		perror("open() failed for src file");
		_exit(2);
	}
	// read from src file
	while( (cnt = read(fs, buf, sizeof(buf))) > 0 )
	{
		// write into dest(stdout) file
		write(1, buf, cnt);
	} // repeat until end of src file
	// close src file
	close(fs);
	return 0;
}
