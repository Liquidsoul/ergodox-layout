# Ergodox Layout

This is my custom layout for the Ergodox EZ.

First I forked the [qmk_firmware](https://github.com/qmk/qmk_firmware)
repository to add mine but I've decided to move to a dedicated
repository with a subtree to have only my history of changes.

One downside is that I had to create a build process using some "tweaks"
which may be too brittle in the long run because it uses the current
source layout of the firmware which may change.

## Building the layout

All you have to do is run:

    $ make
    
And the layout should be compiled and the hex file will be in the
qmk_firmware folder.
