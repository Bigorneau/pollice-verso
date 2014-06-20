#include <iostream>
#include "config.h"

using namespace std;

struct config_s * get_config()
{
	static struct config_s config;
	return &config;
}

int sanitize_config(struct config_s * config)
{
	if (!config->width || !config->height) {
		vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
		/* pick first video mode */
		if (modes.size() == 0)
			return -1;
		config->width = modes[0].width;
		config->height = modes[0].height;
	}
	return 0;
}
