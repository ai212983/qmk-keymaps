#!/bin/sh

source properties.sh

echo "\n = Building layout '$TARGET_LAYOUT', firmware folder '$QMK_FIRMWARE'\n"
rsync -avh $1/{config.h,keymap.c,rules.mk} $QMK_FIRMWARE/keyboards/planck/keymaps/ai212983/ 
rsync -avh --delete common/ $QMK_FIRMWARE/users/ai212983/
cd $QMK_FIRMWARE 
make git-submodule
make planck/ez:ai212983
cd ..
