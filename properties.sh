#!/bin/sh

QMK_FIRMWARE=qmk_firmware
QMK_USER=ai212983
TARGET_LAYOUT=${1%/} # first argument without last slash

if [ $TARGET_LAYOUT = planck* ] ; then 
    TARGET_KEYBOARD=planck
    MAKE_PREFIX=planck/ez
else 
    TARGET_KEYBOARD=$TARGET_LAYOUT
    MAKE_PREFIX=$TARGET_LAYOUT
fi
