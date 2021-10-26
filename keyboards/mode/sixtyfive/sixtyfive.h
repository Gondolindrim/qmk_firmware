#pragma once

#include "quantum.h"

#if defined(KEYBOARD_mode_sixtyfive_m65hi_alpha)
  #include "m65hi_alpha.h"
#elif defined(KEYBOARD_mode_sixtyfive_m65hi_prealpha)
  #include "m65hi_prealpha.h"
#elif defined(KEYBOARD_mode_sixtyfive_m65ha_alpha)
  #include "m65ha_alpha.h"
#elif defined(KEYBOARD_mode_sixtyfive_m65ha_prealpha)
  #include "m65ha_prealpha.h"
#endif // Mode65 solderable "S" and hotswap "H" revisions
