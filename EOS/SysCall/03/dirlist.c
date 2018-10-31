#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

// ./02_dirlist <dirpath>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *de;
	// check cmd line args
	if(argc != 2)
	{
		fprintf(stderr, "syntax: %s <dir path>\n", argv[0]);
		_exit(1);
	}
	// open dir
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		perror("opendir() failed");
		_exit(2);
	}
	// get next dirent & print it
	while( (de = readdir(dp)) != NULL)
	{
		printf("%lu\t%s\n", de->d_ino, de->d_name);
	} // repeat until all entries are done

	// close dir
	closedir(dp);
	return 0;
}
