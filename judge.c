#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include "check_data.c"
#include "check_test.c"

int main()
{
    int pid, user, problem, users_amount, problems_amount;
    char *user_number = NULL;
    char *problem_number = NULL;
    char *text = NULL;
    user_number = (char*)malloc(sizeof(char) * 6);
    user_number[0] = 'u';
    user_number[1] = 's';
    user_number[2] = 'e';
    user_number[3] = 'r';
    user_number[4] = '0';
    user_number[5] = '0';
    problem_number = (char*)malloc(sizeof(char) * 4);
    problem_number[0] = '0';
    problem_number[1] = '0';
    problem_number[2] = '.';
    problem_number[3] = 'c';
    check_data();
    check_test();
    freopen("data/info.txt", "r", stdin);
    scanf("%d", &users_amount);
    for(user = 1; user <= users_amount; user++)
    {
        user_number[4] = user / 10 + '0';
        user_number[5] = user + '0';
        scanf("%s%s%s", text, text, text);
        problem = 1;
//      for(problem = 1; problem <= problems_amount; problem++)
        while(strcmp(text, "}"))
        {
            pid = fork();
            if(!pid)
            {
                problem_number[1] = problem + '0';
                execlp("./judge_unit", "./judge_unit", user_number, problem_number, NULL);
                printf("error\n");
                return 0;
            }
            wait(NULL);
            problem++;
            scanf("%s", text);
        }
    }
    return 0;
}
