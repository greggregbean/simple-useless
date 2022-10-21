#include "uselessSetup.h"

void run_process (int time_sleep, const char* object_name) {
    printf("Time sleep = %d. \n", time_sleep);
    sleep(time_sleep);

    pid_t process_id = fork();
    
    //For Debugging:
    int child_status;
    wait(&child_status);

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
    int fd = open("file.txt", O_RDONLY);
    if(fd == -1) printf("Failed to open file! \n");

    char buf[MAXBUFSIZE] = {'\0'};
    read(fd, buf, MAXBUFSIZE);    
    printf("All buf:\n%s\n\n", buf);
    int iter = 0;

    int time_sleep = 0;
    char object_name[MAXNAMESIZE] = {'\0'};

    while(buf[iter] != '\0') {
        time_sleep = read_num(&iter, buf);
        space_skip(&iter, buf);
        strcpy(object_name, read_name(&iter, buf));
        space_skip(&iter, buf);
        
        run_process(time_sleep, object_name);
        printf("\n");
    }

    if(close(fd) == -1) printf("Failed to close file! \n");

    return 0;
}
