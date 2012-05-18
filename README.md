evdevhelper
===========

A helper program to output joypad info and to determine if a device really is a joypad

udev
----

Put the following inside ``/etc/udev/rules.d/10-udev.rules``:

``
KERNEL=="event[0-9]*" PROGRAM="path_to_joypad_is_joypad/joypad_is_joypad %k" GROUP="joypad" MODE="640"
``
