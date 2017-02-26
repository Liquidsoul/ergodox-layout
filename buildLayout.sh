#!/usr/bin/env sh

# BUILD_FOLDER : where the qmk build command should be run
# LAYOUT_NAME : the name of the layout

pushd ${BUILD_FOLDER:?} > /dev/null
make ergodox-ez-${LAYOUT_NAME:?}
popd > /dev/null
