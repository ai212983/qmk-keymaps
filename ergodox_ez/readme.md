# ErgoDox EZ Default Configuration
---------------

## Features wishlist

* Launchbar key
* NKRO enabled (do i really need it?)
* Plover/Steno layer
* Home/End keys
* hjkl-like arrows on NavigationLayer
* Delete on Backspace + Hyper or Delete on NavigationLayer?
* Toggle layer on press and hold, set layer on single press?
* Better `~` and backticks keys

* Disable incorrect sequences?
  * Shift + 9/0 for brackets `()`

### References

* superduper mode: https://github.com/qmk/qmk_firmware/blob/f8e4f7ea80a1e94a6e205f9bc790fc2f3a4a2ce3/keyboards/planck/keymaps/narze/keymap.c
* nice layer management https://github.com/qmk/qmk_firmware/tree/master/keyboards/planck/keymaps/dr_notsokind
* nice nav layer switch https://noahfrederick.com/log/the-planck-keyboard https://github.com/noah:frederick/qmk-keymaps


## Current Karabiner modifications

* Caps Lock to Escape on single press, Hyper on press and hold
* Command_R to escape if pressed alone, map to Hyper for Kinesis
* Command_L to Escape if pressed alone
* Better shifting: Parentheses on shift keys
* Better shifting: Shift rolls (`()` on both shifts?)
* Better shifting: End parenthesis on shift + space (`)` and `space`)

also see [Article about Space Cadet](http://stevelosh.com/blog/2012/10/a-modern-space-cadet/)

## Default modifier keys
Control, Option, Command, Shift

## Changelog

* Dec 2016:
  * Added LED keys
  * Refreshed layout graphic, comes from http://configure.ergodox-ez.com now.
* Sep 22, 2016:
  * Created a new key in layer 1 (bottom-corner key) that resets the EEPROM.
* Feb 2, 2016 (V1.1): 
  * Made the right-hand quote key double as Cmd/Win on hold. So you get ' when you tap it, " when you tap it with Shift, and Cmd or Win when you hold it. You can then use it as a modifier, or just press and hold it for a moment (and then let go) to send a single Cmd or Win keystroke (handy for opening the Start menu on Windows).

This is what we ship with out of the factory. :) The image says it all:

![Default](https://i.imgur.com/Be53jH7.png)
