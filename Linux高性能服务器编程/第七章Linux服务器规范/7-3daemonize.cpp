bool daemonize()
{
	//创建子进程， 关闭父进程。 这样可以使得程序在后台运行
    pid_t pid = fork();
    if ( pid < 0 )
    {
        return false;
    }
    else if ( pid > 0 )
    {
        exit( 0 );
    }
	//设置文件权限掩码， 当进程创建新文件时， 文件
	//权限是mode & 0777
    umask( 0 );

    pid_t sid = setsid();
    if ( sid < 0 )
    {
        return false;
    }
	//切换工作目录
    if ( ( chdir( "/" ) ) < 0 )
    {
        /* Log the failure */
        return false;
    }
	//关闭标准输入设备 标准输出设备 标准 错误输出设备
    close( STDIN_FILENO );
    close( STDOUT_FILENO );
    close( STDERR_FILENO );

    open( "/dev/null", O_RDONLY );
    open( "/dev/null", O_RDWR );
    open( "/dev/null", O_RDWR );
    return true;
}