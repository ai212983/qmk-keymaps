#!/bin/sh

source properties.sh

echo "\n = Building layout '$TARGET_LAYOUT', firmware folder '$QMK_FIRMWARE'\n"
rsync -avh $1/{config.h,keymap.c,rules.mk} $QMK_FIRMWARE/keyboards/$TARGET_KEYBOARD/keymaps/ai212983/
rsync -avh --delete common/ $QMK_FIRMWARE/users/$QMK_USER/
cd $QMK_FIRMWARE 
make git-submodule
rm -rf $QMK_FIRMWARE/${TARGET_LAYOUT}_${QMK_USER}.bin
echo "\nMaking layout ${MAKE_PREFIX}:${QMK_USER}"
make $MAKE_PREFIX:$QMK_USER
cd ..
