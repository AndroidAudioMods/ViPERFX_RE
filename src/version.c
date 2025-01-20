#include "version_note.h"

const lib_ver_note_t so_ver __attribute__ ((section (".note.lib.ver")))
      __attribute__ ((visibility ("default"))) = {
  100,
  0,
  0,
  "lib.ver.1.0.0.libv4a_skel.so:1.0.0",
};
