#ifndef CLI_CMD_DUMP_H
#define CLI_CMD_DUMP_H

struct cli_cmd_dump_arg {
	int pid;

	// Whether to dump readable memory addresses.
	int read;

	// Whether to dump writable memory addresses.
	int write;

	// Whether to dump executable memory addresses.
	int execute;

	// Whether to dump program code.
	int program_code;
};

int cli_cmd_dump(struct cli_cmd_dump_arg *arg);

#endif /* CLI_CMD_DUMP_H */
