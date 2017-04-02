#!/usr/bin/env sh

# BUILD_FOLDER : where the build command should be run
# LAYOUT_NAME : the name of the layout
# KEYBOARD : the name of the keybaord to build
# SUBPROJECT : the name of the subproject

readonly LAYOUT_NAME=$1
readonly KEYBOARD=$2
readonly SUBPROJECT=$3

function build {
    local target=${1:-}
    local master=${2:-left}
    make ${KEYBOARD:?}-${SUBPROJECT:?}-${LAYOUT_NAME:?}-${target} master=${master}
}

function flashEZ {
    echo "Flashing ez..."
    echo "Plug the keyboard in reset mode. Press enter key to continue"
    read x
    teensy_loader_cli -mmcu=atmega32u4 -w ${KEYBOARD}_${SUBPROJECT}_${LAYOUT_NAME}.hex
}

function flashInfinity {
    echo "Flashing infinity..."
    echo "Plug the Left hand in reset mode. Press enter key to continue"
    read x
    build dfu-util left
    echo "Plug the right hand in reset mode. Press enter key to continue"
    read x
    build dfu-util right
}

function flash {
    echo "Flash keyboard? (y/N)"
    read x
    if [[ "$x" == "y" ]]; then
        case ${SUBPROJECT} in
            "ez")
                flashEZ
                ;;
            "infinity")
                flashInfinity
                ;;
            *)
                echo "No implemented flashing method for subproject ${SUBPROJECT}"
                ;;
        esac
    fi
}

pushd ${BUILD_FOLDER:?} > /dev/null
build && flash
popd > /dev/null
