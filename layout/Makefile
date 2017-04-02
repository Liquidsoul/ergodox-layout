# Having a file like this allows you to override Makefile definitions
# for your own particular keymap

SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
COMMAND_ENABLE   = no  # Commands for debug and configuration

ifeq (${SUBPROJECT},infinity)
	VISUALIZER_ENABLE = yes
endif

ifeq (${VISUALIZER_ENABLE}, yes)
	OPT_DEFS += -DVISUALIZER_ENABLED
endif

GIT_REV = $(shell git rev-parse --short HEAD 2>/dev/null)
OPT_DEFS += -DGIT_REV=\"$(GIT_REV)\"

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
