# Ergodox Layout

This is my custom layout for the Ergodox (EZ & Infinity).

First I forked the [qmk_firmware](https://github.com/qmk/qmk_firmware)
repository to add mine but I've decided to move to a dedicated
repository with a submodule to have only my history of changes.

One downside is that I had to create a build process using some "tweaks"
which may be too brittle in the long run because it uses the current
source layout of the firmware which may change.

## Building the layouts

First you need to have [homebrew](https://brew.sh) installed.
Then all you have to do is run:

    $ make
    
And the layouts should be compiled and the hex files will be in the
qmk_firmware folder.

If you want to build only the ez or the infinity layout, just run:

    $ make ez

or

    $ make infinity

## Some details

The current process uses docker to build the layouts. This simplifies a lot the
configuration of the building machine and the resolution of all dependencies.
One downside with that is during the development of the layout because there is
no incremental compilation. Meaning that everything will need to be recompiled
every time `make` is run.
