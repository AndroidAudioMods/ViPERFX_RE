# ViPERFX RE

This is a project aimed to reverse-engineer ViPERFX. The version of the shared library used is the armv7 version
taken from the ViPER4Android Magisk apk (2.5.0.4). It was then imported in Ghidra and analyzed.

There's a lot of code that doesn't quite make sense, and it's important to look at the bytecode if something seems strange.
Liberties may be taken to write equivalent code in a mor readable way.

# Contributing

Feel free to PR in a more "clean" version of various methods, or general project cleanup.
You may rename fields, but ideally this is left until all methods are cleaned.
