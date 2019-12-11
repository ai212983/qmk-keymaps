#!/bin/sh

QMK_FIRMWARE=qmk_firmware
QMK_USER=ai212983
TARGET_LAYOUT=${1%/} # first argument without last slash

if [ $TARGET_LAYOUT = planck* ] ; then 
    TARGET_KEYBOARD=planck
    MAKE_PREFIX=planck/ez
    IMAGE_EXTENSION=bin
else 
    TARGET_KEYBOARD=$TARGET_LAYOUT
    MAKE_PREFIX=$TARGET_LAYOUT
    IMAGE_EXTENSION=hex
fi
