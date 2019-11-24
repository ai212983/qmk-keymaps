#!/bin/sh
rsync -avz ./{config.h,keymap.c,rules.mk} $QMK_FIRMWARE/keyboards/planck/keymaps/ai212983/ 
cd $QMK_FIRMWARE 
make planck/ez:ai212983
wally-cli $QMK_FIRMWARE/planck_ez_ai212093.bin
