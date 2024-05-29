#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *filename = "example.txt";
    struct stat fileStat;

    if (stat(filename, &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    printf("File Size: \t\t%ld bytes\n", fileStat.st_size);
    printf("Number of Links: \t%lu\n", fileStat.st_nlink);
    printf("File inode: \t\t%lu\n", fileStat.st_ino);
    printf("File Permissions: \t");
    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
    return 0;
}
