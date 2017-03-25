#!/usr/bin/env sh

# LAYOUT_LOCATION : the folder relative to the cwd where the symlink should be placed
# LAYOUT_NAME : the name to give to the symlink
# LAYOUT_FOLDER_NAME : the name of the folder in the cwd where the layout is located (where the symlink should point to)

function copyLayout {
    local layoutLocation=$1
    local layoutName=$2
    local layoutFolderName=$3

	local relative_path=`echo "$layoutLocation" | sed 's#[^/]*#..#g'`
    cp -r "$relative_path/$layoutFolderName" "$layoutName"
}

function replaceOrCopyLayoutToQMK {
    local layoutLocation=$1
    local layoutName=$2
    local layoutFolderName=$3

    pushd "$layoutLocation" > /dev/null
    if [ -e "$layoutName" ]
    then
        echo "'$layoutName' exists in '$layoutLocation', deleting it..."
        rm -rf "$layoutName"
    fi
    copyLayout $layoutLocation $layoutName $layoutFolderName
    popd > /dev/null
}

replaceOrCopyLayoutToQMK ${LAYOUT_LOCATION:?} ${LAYOUT_NAME:?} ${LAYOUT_FOLDER_NAME:?}
