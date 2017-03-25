#!/usr/bin/env sh

# BUILD_FOLDER : where the build command should be run
# LAYOUT_NAME : the name of the layout
# KEYBOARD : the name of the keybaord to build
# SUBPROJECT : the name of the subproject

readonly LAYOUT_NAME=$1
readonly KEYBOARD=$2
readonly SUBPROJECT=$3

pushd ${BUILD_FOLDER:?} > /dev/null
docker run -e keymap=${LAYOUT_NAME:?} -e subproject=${SUBPROJECT:?} -e keyboard=${KEYBOARD:?} --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
popd > /dev/null
