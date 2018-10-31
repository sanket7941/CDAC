/*
 *this code will work as similar to #cp  command
*/
#if 1
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc , char *argv[])
{
	int fs , fd , cnt;
	char buf[512];
// check cmd line args
	if(argc != 3)
	{
		fprintf(stderr ,"syntax : %s <src file> <dest file>\n",argv[0]);
		_exit(1);
	}
	// open src file for reading

	fs = open(argv[1],O_RDONLY);
	if(fs == -1)
	{
		perror("open() failed for src file");
		_exit(2);
	}

	// open dest file for writing
	fd = open(argv[2],O_WRONLY |O_TRUNC | O_CREAT, 0644);

	if(fd == -1)
	{
		perror("open() faild for dest file");
		close(fs);
		_exit(3);
	}

	// read from src file
	while( ( cnt = read(fs, buf ,sizeof(buf))) > 0 )
	{
	 // write into dest file
		write(fd ,buf ,cnt);
	}

	//  close dest file
		close(fd);
	//  close src file
		close(fs);

		printf("file copied sucsessfuly :)\n");
		return 0;
}
#endif
#if 0
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

//syntax: ./01_filecopy <src file> <dest file>

int main(int argc, char *argv[])
{
	int fs, fd, cnt;
	char buf[512];
	// check cmd line args
	if(argc != 3)
	{
		fprintf(stderr, "syntax: %s <src file> <dest file>\n", argv[0]);
		_exit(1);
	}
	// open src file for reading
	fs = open(argv[1], O_RDONLY);
	if(fs == -1)
	{
		perror("open() failed for src file");
		_exit(2);
	}
	// open dest file for writing
	fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if(fd == -1)
	{
		perror("open() failed for dest file");
		close(fs);
		_exit(3);
	}
	// read from src file
	while( (cnt = read(fs, buf, sizeof(buf))) > 0 )
	{
		// write into dest file
		write(fd, buf, cnt);
	} // repeat until end of src file
	// close dest file
	close(fd);
	// close src file
	close(fs);
	printf("file copied.\n");
	return 0;
}
#endif
