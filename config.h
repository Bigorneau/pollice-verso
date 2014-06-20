#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct config_s {
	int height;
	int width;
	int verbose;
};

struct config_s * get_config();
int sanitize_config(struct config_s * config);
#endif
