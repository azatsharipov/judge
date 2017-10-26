#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>

int
main (int argc, char **argv)
{
    int prog_checker[2];
    int fd;
    int pid, pid1, pid2;
    char * text = NULL;
    char * test_number_dat = NULL;
    char * test_number_ans = NULL;
    test_number_dat = (char*)malloc(sizeof(char) * 7);
    test_number_ans = (char*)malloc(sizeof(char) * 7);

    test_number_dat[0] = 'd';
    test_number_dat[1] = 'a';
    test_number_dat[2] = 't';
    test_number_dat[3] = 'a';
    test_number_dat[4] = '/';
    test_number_dat[5] = '0';
    test_number_dat[6] = '0';
    test_number_dat[7] = '0';
    test_number_dat[8] = '.';
    test_number_dat[9] = 'd';
    test_number_dat[10] = 'a';
    test_number_dat[11] = 't';

    test_number_ans[0] = 'd';
    test_number_ans[1] = 'a';
    test_number_ans[2] = 't';
    test_number_ans[3] = 'a';
    test_number_ans[4] = '/';
    test_number_ans[5] = '0';
    test_number_ans[6] = '0';
    test_number_ans[7] = '0';
    test_number_ans[8] = '.';
    test_number_ans[9] = 'a';
    test_number_ans[10] = 'n';
    test_number_ans[11] = 's';



    pid = fork();
    if (pid == 0)
    {
        execlp("gcc", "gcc", "-Wall", argv[1], "-o", "var/prog", NULL);
    }
    else
    {
        wait(NULL);
    }

    freopen("test/info.txt", "r", stdin);
    scanf("%s", text);
    while(strcmp(text, argv[2]))
        scanf("%s", text);
    scanf("%s", text);
    scanf("%s", text);

    while(strcmp(text, "}"))
    {
        pipe(prog_checker);
        pid1 = fork();
        if (pid1 == 0)
        {
            test_number_dat[5] = text[0];
            test_number_dat[6] = text[1];
            test_number_dat[7] = text[2];
            fd = open(test_number_dat, O_CREAT);
            close(prog_checker[0]);
            dup2(fd, 0);
            close(fd);
            dup2(prog_checker[1], 1);
            close(prog_checker[1]);
            execlp("./var/prog", "./var/prog", NULL);
            return 0;
            exit(1);
        }
        pid2 = fork();
        if (pid2 == 0)
        {
            close(prog_checker[1]);
            dup2(prog_checker[0], 0);
            close(prog_checker[0]);
            test_number_ans[5] = text[0];
            test_number_ans[6] = text[1];
            test_number_ans[7] = text[2];
            execlp("./checker", "./checker", test_number_ans, NULL);
            exit(1);
        }
        close(prog_checker[0]);
        close(prog_checker[1]);
        wait(NULL);
        wait(NULL);
        printf("OK\n");
        scanf("%s", text);
    }

    return 0;
}
