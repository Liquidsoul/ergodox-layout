# Having a file like this allows you to override Makefile definitions
# for your own particular keymap

# LAYOUT_LOCATION=qmk_firmware/keyboards/ergodox/keymaps
# LAYOUT_NAME=liquidsoul
export LAYOUT_LOCATION=qmk_firmware/keyboards/ergodox/keymaps
export LAYOUT_NAME=liquidsoul
export LAYOUT_FOLDER_NAME=layout
export BUILD_FOLDER=qmk_firmware

all:
	./createSymLink.sh
	./buildLayout.sh
