# Having a file like this allows you to override Makefile definitions
# for your own particular keymap

export LAYOUT_LOCATION=qmk_firmware/keyboards/ergodox/keymaps
export LAYOUT_NAME=liquidsoul
export LAYOUT_FOLDER_NAME=layout
export BUILD_FOLDER=qmk_firmware
export KEYBOARD=ergodox

all: ez infinity

ez: layout prerequisites
	./buildLayout.sh ${LAYOUT_NAME} ${KEYBOARD} $@

infinity: layout prerequisites
	./buildLayout.sh ${LAYOUT_NAME} ${KEYBOARD} $@

layout:
	./copyLayout.sh

prerequisites:
	brew bundle --no-upgrade

clean:
	rm -rf ${BUILD_FOLDER}/.build

.PHONY: all ez infinity layout clean
