#!/bin/sh

source properties.sh

echo "\n = Building and flashing layout '$TARGET_LAYOUT', firmware folder '$QMK_FIRMWARE'\n"
./build.sh $TARGET_LAYOUT
./bin/wally-cli $QMK_FIRMWARE/${TARGET_LAYOUT}_ai212983.${IMAGE_EXTENSION}