#pragma once

#ifndef CUSTOM_SAFE_RANGE
  #error "You must specify variable CUSTOM_SAFE_RANGE for custom hotkeys keycodes."
#endif

enum custom_hotkeys_keycodes {
  CUSTOM_HOTKEYS_START = CUSTOM_SAFE_RANGE,

  MY_HOME,
  MY_END,
  MY_SCRN,
  MY_DEL,
  CT_LEFT,
  CT_RGHT,
  CT_BSPC,
  CT_ENT,
  MY_ALT,
  MY_CTRL,
  MY_APP1,
  MY_APP2,
  MY_APP3,
  MY_APP4,
  MY_APP5,
  MY_APP6,
  MY_APP7,
  MY_APP8,
  MY_APP9,

  CUSTOM_HOTKEYS_NEW_SAFE_RANGE,
  #undef CUSTOM_SAFE_RANGE
  #define CUSTOM_SAFE_RANGE CUSTOM_HOTKEYS_NEW_SAFE_RANGE
};

// Мои языко-символьные клавиши
bool process_my_hotkeys(uint16_t keycode, keyrecord_t *record) {
  #define REG(X) register_code(X);
  #define UNREG(X) unregister_code(X);
  #define PRESS(X) REG(X); UNREG(X);
  #define WITH(X, Y) REG(X); Y; UNREG(X);
  #define CTRL KC_LCTRL
  #define ALT KC_LALT
  #define WIN KC_LGUI
  #define SHIFT KC_LSHIFT
  #define OPTION KC_LOPT
  #define COMMAND KC_LCMD

  uint16_t CTRL_OR_COMMAND = system_current == SYSTEM_MACOS ? COMMAND : CTRL;
  uint16_t CTRL_OR_OPTION = system_current == SYSTEM_MACOS ? OPTION : CTRL;  
  
  switch (keycode) {
    case MY_SCRN:
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_LINUX: {
            WITH(CTRL, { WITH(SHIFT, { PRESS(KC_PSCR); }); });
            break;
          }
          case SYSTEM_WINDOWS: {
            WITH(CTRL, { WITH(SHIFT, { PRESS(KC_PSCR); }); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(SHIFT, { WITH(COMMAND, { PRESS(KC_2); }); });
            break;
          }
        }
      }
      return false;
      break;
    case MY_APP1:
    case MY_APP2:
    case MY_APP3:
    case MY_APP4:
    case MY_APP5:
    case MY_APP6:
    case MY_APP7:
    case MY_APP8:
    case MY_APP9:
      if (record->event.pressed) {
        switch (system_current) {
          case SYSTEM_WINDOWS: {
            WITH(WIN, { PRESS(KC_1 + (keycode - MY_APP1)); });
            break;
          }
          case SYSTEM_LINUX: {
            WITH(WIN, { PRESS(KC_1 + (keycode - MY_APP1)); });
            break;
          }
          case SYSTEM_MACOS: {
            WITH(CTRL, { WITH(COMMAND, { PRESS(KC_1 + (keycode - MY_APP1)); }); });
            break;
          }
        }
      }
      return false;
      break;
    case MY_HOME: {
      if (system_current == SYSTEM_MACOS) {
        if (record->event.pressed) {
          REG(COMMAND);
          REG(KC_LEFT);
        } else {
          UNREG(KC_LEFT);
          UNREG(COMMAND);
        }
      } else {
        if (record->event.pressed) {
          REG(KC_HOME);
        } else {
          UNREG(KC_HOME);
        }
      }
      return false;
    }
    case MY_ALT: {
      if (system_current == SYSTEM_MACOS) {
        if (record->event.pressed) {
          REG(COMMAND);
        } else {
          UNREG(COMMAND);
        }
      } else {
        if (record->event.pressed) {
          REG(KC_LALT);
        } else {
          UNREG(KC_LALT);
        }
      }
      return false;
    }
    case MY_CTRL: {
      if (system_current == SYSTEM_MACOS) {
        if (record->event.pressed) {
          REG(COMMAND);
        } else {
          UNREG(COMMAND);
        }
      } else {
        if (record->event.pressed) {
          REG(KC_LCTL);
        } else {
          UNREG(KC_LCTL);
        }
      }
      return false;
    }
    case MY_END: {
      if (system_current == SYSTEM_MACOS) {
        if (record->event.pressed) {
          REG(COMMAND);
          REG(KC_RGHT);
        } else {
          UNREG(KC_RGHT);
          UNREG(COMMAND);
        }
      } else {
        if (record->event.pressed) {
          REG(KC_END);
        } else {
          UNREG(KC_END);
        }
      }
      return false;
    }
  }
  
  #define CASE_CTRL_OR_COMMAND(CASE, TO_PRESS) \
    case CASE: {\
      if (record->event.pressed) { \
        REG(CTRL_OR_COMMAND); \
        REG(TO_PRESS); \
      } else { \
        UNREG(TO_PRESS); \
        UNREG(CTRL_OR_COMMAND); \
      } \
      return false; \
    }
  
  #define CASE_CTRL_OR_OPTION(CASE, TO_PRESS) \
    case CASE: {\
      if (record->event.pressed) { \
        REG(CTRL_OR_OPTION); \
        REG(TO_PRESS); \
      } else { \
        UNREG(TO_PRESS); \
        UNREG(CTRL_OR_OPTION); \
      } \
      return false; \
    }
  
  switch (keycode) {
    CASE_CTRL_OR_COMMAND(CT_ENT, KC_ENT)
    CASE_CTRL_OR_OPTION(CT_LEFT, KC_LEFT)
    CASE_CTRL_OR_OPTION(CT_RGHT, KC_RGHT)
    CASE_CTRL_OR_OPTION(CT_BSPC, KC_BSPC)
  }

  #undef REG
  #undef UNREG
  #undef PRESS
  #undef WITH
  #undef CTRL
  #undef ALT
  #undef WIN
  #undef SHIFT
  #undef OPTION
  #undef COMMAND
  
  return true;
}