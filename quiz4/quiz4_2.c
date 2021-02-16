void child(int *fd, char **cmd){

    dup2(fd[1],STDOUT_FILENO);
    dup2(fd[1], STDERR_FILENO);

    if( execvp( cmd[0] , &cmd[0] ) <0 )
    {
        printf("ERROR\n"); //na ginei me fprintf
    }
    
    //close(fd[1]);
    //return;
}