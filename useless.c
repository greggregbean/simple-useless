#include "uselessSetup.h"

void run_process (clock_t start, int time_sleep, const char* object_name) {
    pid_t process_id = fork();
    
    //For Debugging:
    //int child_status;
    //wait(&child_status);

    if(process_id < 0) printf("Failed to create child procces! \n");

    else if(process_id > 0) {
        printf("Parent proccess. PID = %d. Just go back to the loop. \n", getpid());
    }

    else {
        printf("Child proccess. PID = %d. \n", getpid());

        clock_t current = clock();

        int spent_time = (current - start)/CLOCKS_PER_SEC;

        sleep(time_sleep - spent_time);

        int res_of_run = execl(object_name, object_name, NULL);
        if(res_of_run == -1) printf("Failed to run %s! \n", object_name);  

        exit(0);
    }
}


int main() {
    clock_t start = clock();

    int fd = open("file.txt", O_RDONLY);
    if(fd == -1) {
        printf("Failed to open file! \n");
        exit(-1); 
    }

    char buf[MAXBUFSIZE] = {'\0'};
    read(fd, buf, MAXBUFSIZE);  
    if(close(fd) == -1) printf("Failed to close file! \n");

    printf("All buf:\n%s\n\n", buf);
    int iter = 0;

    int time_sleep = 0;
    char object_name[MAXNAMESIZE] = {'\0'};

    while(buf[iter] != '\0') {
        time_sleep = read_num(&iter, buf);
        space_skip(&iter, buf);
        strcpy(object_name, read_name(&iter, buf));
        space_skip(&iter, buf);
        
        run_process(start, time_sleep, object_name);
        printf("\n");
    }

    return 0;
}
