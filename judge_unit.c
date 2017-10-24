#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int
main (void)
{
    int fd[2];
    int pid, pid1, pid2;
    pid = fork();
    if (pid == 0)
    {
        execlp("gcc", "gcc", "-Wall", "01.c", "-o", "01", NULL);
    }
    else
    {
        wait(NULL);
    }
    pipe(fd);
    pid1 = fork();
    if (pid1 == 0)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
        execlp("./01", "./01", NULL);
        _exit(1);
    }
    pid2 = fork();
    if (pid2 == 0)
    {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        execlp("./checker", "./checker", "fans.txt", NULL);
        _exit(1);
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
