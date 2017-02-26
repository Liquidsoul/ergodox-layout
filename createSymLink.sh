#!/usr/bin/env sh

# LAYOUT_LOCATION : the folder relative to the cwd where the symlink should be placed
# LAYOUT_NAME : the name to give to the symlink
# LAYOUT_FOLDER_NAME : the name of the folder in the cwd where the layout is located (where the symlink should point to)

function createSymLink {
    local layoutLocation=$1
    local layoutName=$2
    local layoutFolderName=$3

	local relative_path=`echo "$layoutLocation" | sed 's#[^/]*#..#g'`
    echo "$relative_path"
    ln -s "$relative_path/$layoutFolderName" "$layoutName"
}

function testLinkExistanceAndCreateItIfNecessary {
    local layoutLocation=$1
    local layoutName=$2
    local layoutFolderName=$3

    pushd "$layoutLocation" > /dev/null
    if [ ! -e "$layoutName" ]
    then
        echo "No '$layoutName' exists in '$layoutLocation', creating the symlink..."
        createSymLink $layoutLocation $layoutName $layoutFolderName
    else
        echo "'$layoutName' exists in '$layoutLocation'"
    fi
    popd > /dev/null
}

testLinkExistanceAndCreateItIfNecessary ${LAYOUT_LOCATION:?} ${LAYOUT_NAME:?} ${LAYOUT_FOLDER_NAME:?}
