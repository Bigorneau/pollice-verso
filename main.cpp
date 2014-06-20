#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "config.h"
#include "game.h"

static struct option opts[] = {
	{"width", required_argument, 0, 'W'},
	{"height", required_argument, 0, 'H'},
	{"verbose", no_argument, 0, 'v'},
	{"yolo", optional_argument, 0, 'y'},
	{0, 0, 0, 0}
};

void print_usage(char * bin)
{
	int i;
	printf("usage: %s", bin);
	for (i = 0; i < (sizeof(opts)/sizeof(opts[0]) -1); i++) {
		switch (opts[i].has_arg) {
		case required_argument:
			printf(" [--%s %s]", opts[i].name, opts[i].name);
			break;
		case optional_argument:
			printf(" [--%s [%s]]", opts[i].name, opts[i].name);
			break;
		case no_argument:
			printf(" [--%s]", opts[i].name);
			break;
		}
	}
	printf("\n");
}

void parse_opts(int argc, char **argv)
{
	int index, opt;
	struct config_s *config = get_config();
	while ((opt = getopt_long(argc, argv, "hvH:W:", opts, &index)) != -1) {
		switch (opt) {
		case 'v':
			config->verbose = 1;
			break;
		case 'H':
			config->height = atoi(optarg);
			break;
		case 'W':
			config->width = atoi(optarg);
			break;
		case '?':
			printf("? : '%s'\n", optarg);
			break;
		case 'h':
		default:
			print_usage(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	sanitize_config(config);
}

int main(int argc, char **argv)
{
	struct config_s * config = get_config();
	parse_opts(argc, argv);
	Game game;
	game.run();
	return 0;
}
