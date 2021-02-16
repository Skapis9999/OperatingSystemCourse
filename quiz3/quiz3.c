int execvpWithTimeout( int timeout, char **cmd ){
    
    int returnVal = 0;
    int pid, status; /* process identifier */
    pid = fork();
    
    if ( pid < 0 ) { 
        //printf("Cannot fork!!'\n");
        exit(0);
    }
    if ( pid == 0 )
    { /* Child process */ 
        sleep(timeout);
        //returnVal = 2;
        /*kill(pid1, 9);*/
        exit(2);
    }
    else{
        /* Parent process value of pid variable is child's pid */
        int pid2; /* process identifier */
        pid2 = fork();
        if ( pid2 < 0 ) { 
            //printf("Cannot fork!!'\n");
            exit(0);
        }
        if ( pid2 == 0 )
        { /* Child process */
            execvp(cmd[0], &cmd[1]); //This will run "cmd" as if it were a command
            exit(1);
        }
        else
        { /* Parent process value of pid variable is child's pid */
            int i = wait(&status);
            if(i==pid2){
                kill(pid, 9);       //sigkill is 9
                if(status==0){
                    returnVal = 0;
                    return returnVal;
                }
                else{
                    returnVal = 1;
                    return returnVal;
                }
            }
            
            else{
                kill(pid2, 9);
                returnVal = 2;
                return returnVal;
            }
        }
    }
  return returnVal;
}
    
