#include "../apue.h"
#include "../myerr.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

void
daemonize(const char *cmd) {
	int i, fdo, fdl, fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;

	/* Clear file creation mask. */
	umask(0);

	/*
	* Get maximum number of file descriptors.
	*/
	if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
		err_quit("ss: can't get file limit", cmd);

	/*
	* Become a session leader to lose controlling TTY.
	*/
	if ((pid = fork()) < 0)
		err_quit("ss: can't fork", cmd);
	else if (pid != 0) { /* parent */
		exit(0);
	}
	setsid();
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
		err_quit("ss: can't ignore SIGHUP", cmd);
	if ((pid = fork()) < 0)
		err_quit("gs: can't fork", cmd);
	else if (pid != 0) /* parent */
		exit(0);

	/*
	* Change the current working directory to the root so
	* we won't prevent file systems from being unmounted.
	*/
	if (chdir("/") < 0)
		err_quit("ss: can't change directory to /", cmd);

	/*
	* Close all open file descriptors.
	*/
	if (rl.rlim_max == RLIM_INFINITY)
		rl.rlim_max = 1024;
	for (i = 0; i < rl.rlim_max; i++)
		close(i);

	/*
	* Attach file descriptors 0, 1, and 2 to /dev/null.
	*/
	fdo = open("/dev/null", O_RDWR);
	fd1 = dup(0);
	fd2 = dup(0);

	/*
	* Initialize the log file.
	*/
	openlog(cmd, LOG_CONS | LOG_PID, LOG_DAEMON);
	if (fdo != 0 || fd1 != 1 || fd2 != 2) {
		syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fdo, fd1, fd2);
		exit(1);

	}
}
