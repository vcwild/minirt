#include "../includes/minishell.h"

int main()
{
	int pid;
	int status;
	pid_t id;
	bool died;

	pid = fork();

	kill(pid, SIGTERM);

	died = false;
	for (int loop; !died && loop < 5 /*For example */; ++loop)
	{

		sleep(1);
		if (waitpid(pid, &status, WNOHANG) == pid) died = true;
	}

	if (!died) kill(pid, SIGKILL);

}
