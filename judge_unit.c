#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>

int
main (int argc, char **argv)
{
    int prog_checker[2];
    int fd, i;
    int pid, pid1, pid2;
    char * test_number_dat = NULL;
    char * test_number_ans = NULL;
    char * problem = NULL;
    problem = (char*)malloc(sizeof(char) * 4);
    test_number_dat = (char*)malloc(sizeof(char) * 7);
    test_number_ans = (char*)malloc(sizeof(char) * 7);
    test_number_dat[0] = '0';
    test_number_dat[1] = '0';
    test_number_dat[2] = '0';
    test_number_dat[3] = '.';
    test_number_dat[4] = 'd';
    test_number_dat[5] = 'a';
    test_number_dat[6] = 't';
    test_number_ans[0] = '0';
    test_number_ans[1] = '0';
    test_number_ans[2] = '0';
    test_number_ans[3] = '.';
    test_number_ans[4] = 'a';
    test_number_ans[5] = 'n';
    test_number_ans[6] = 's';


    pid = fork();
    if (pid == 0)
    {
        execlp("gcc", "gcc", "-Wall", argv[1], "-o", "prog", NULL);
    }
    else
    {
        wait(NULL);
    }



    for(i = 1; i <= 2; i++)
    {
        pipe(prog_checker);
        pid1 = fork();
        if (pid1 == 0)
        {
            test_number_dat[2] = i + '0';
            fd = open(test_number_dat, O_CREAT);
            close(prog_checker[0]);
            dup2(fd, 0);
            close(fd);
            dup2(prog_checker[1], 1);
            close(prog_checker[1]);
            execlp("./prog", "./prog", NULL);
            return 0;
            exit(1);
        }
        pid2 = fork();
        if (pid2 == 0)
        {
            close(prog_checker[1]);
            dup2(prog_checker[0], 0);
            close(prog_checker[0]);
            test_number_ans[2] = i +'0';
            execlp("./checker", "./checker", test_number_ans, NULL);
            exit(1);
        }
        close(prog_checker[0]);
        close(prog_checker[1]);
        wait(NULL);
        wait(NULL);
    }

    return 0;
}
