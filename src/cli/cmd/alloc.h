#ifndef CLI_CMD_ALLOC_H
#define CLI_CMD_ALLOC_H

#include <stdlib.h>

struct cli_cmd_alloc_arg {
	int pid;

	// Requested size.
	size_t size;

	// Read permission.
	int read;

	// Write permission.
	int write;

	// Execute permission.
	int execute;
};

int cli_cmd_alloc(struct cli_cmd_alloc_arg *arg);

#endif /* CLI_CMD_ALLOC_H */
