#include "lib/linux/proctal.h"
#include "lib/linux/ptrace.h"

void proctal_linux_init(struct proctal_linux *pl)
{
	proctal_init(&pl->p);

	pl->ptrace = 0;
	pl->mem = NULL;

	pl->address.started = 0;
	pl->address.curr = NULL;
	pl->address.maps = NULL;

	pl->region.finished = 0;
	pl->region.maps = NULL;
}

void proctal_linux_deinit(struct proctal_linux *pl)
{
	proctal_deinit(&pl->p);

	if (pl->mem) {
		fclose(pl->mem);
	}

	if (pl->ptrace) {
		pl->ptrace = 1;
		proctal_linux_ptrace_detach(pl);
	}

	if (pl->address.maps) {
		fclose(pl->address.maps);
		pl->address.maps = NULL;
	}

	if (pl->region.maps) {
		fclose(pl->region.maps);
		pl->region.maps = NULL;
	}
}

void proctal_linux_set_pid(struct proctal_linux *pl, pid_t pid)
{
	if (pl->mem) {
		fclose(pl->mem);
		pl->mem = NULL;
	}

	if (pl->ptrace) {
		pl->ptrace = 1;
		proctal_linux_ptrace_detach(pl);
	}

	pl->pid = pid;
}

pid_t proctal_linux_pid(struct proctal_linux *pl)
{
	return pl->pid;
}
