
// FD means "For Debugging"

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXBUFSIZE 1000
#define MAXNAMESIZE 20

void run_process (int time_sleep, const char* object_name) {
    printf("Time sleep = %d. \n", time_sleep);
    sleep(time_sleep);

    pid_t process_id = fork();
    
    //FD:
    //int child_status;
    //wait(&child_status);

    if(process_id < 0) printf("Failed to create child procces! \n");

    else if(process_id > 0) {
        printf("Parent proccess. PID = %d. Just go back to the loop. \n", getpid());
    }

    else {
        printf("Child proccess. PID = %d. \n", getpid());

        char src_obj_name[MAXNAMESIZE] = "./";
        strcat(src_obj_name, object_name);
        printf("Source object name: \"%s\". \n", src_obj_name);

        int res_of_run = execl(src_obj_name, src_obj_name, NULL);
        if(res_of_run == -1) printf("Failed to run %s! \n", src_obj_name);  

        exit(0);
    }
}


int main() {
    FILE* fp = fopen("file.txt", "r");

    int time_sleep = 0;
    char object_name[MAXNAMESIZE] = {'\0'};

    int res = fscanf(fp, "%d", &time_sleep);

    while(res != EOF) {
        fscanf(fp, "%s", object_name);
        run_process(time_sleep, object_name);
        res = fscanf(fp, "%d", &time_sleep);
        printf("\n");
    }

    fclose(fp);
}