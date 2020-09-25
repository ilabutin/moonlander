#include QMK_KEYBOARD_H
#include "version.h"
#include "lang_shift/code.c"
#include "combo/code.c"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  CLR_1,
  CLR_2,
  CLR_3,

  // TODO
  // // All of these modificators on 0 layer
  // MY_CTRL,
  // MY_ALT,
  // MY_WIN,
  // MY_SHAL, // Shift+Alt
  // MY_CTAL, // Ctrl+Alt
  // MY_CTSH, // Ctrl+Shift
  // MY_MCAS, // Ctrl+Alt+Shift

  // Russian specific keys
  RU_3DOT, // Three dots
  RU_CMSP, // Comma Space
  RU_SDOT, // Space + Dot + AutoShift

  // English specific keys
  EN_3DOT, // Three dots
  EN_CMSP, // Comma Space
  EN_SDOT, // Space + Dot + AutoShift

  KG_NEXT,

  I3_CR,

  MY_SCRN,

  CT_SHF,

  CT_A_C,
  CT_A_V,
  CT_A_X,

  KC_SPHY, // Space + Hyphen + Space
};

#define MY_layout( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,           \
    k53, \
    k50, k51, k52, \
    \
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k91, k92, k93, k94, k95, k96, \
    ka2, ka3, ka4, ka5, ka6, \
    kb3,\
    kb4, kb5, kb6 \
) \
LAYOUT_moonlander( \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6 \
)

// Shift keys
#define SH_F11 S(KC_F11)
#define SH_PSCR S(KC_PSCR)
#define SH_TAB S(KC_TAB)

// Ctrl+Shift keys
#define CS_TAB LCTL(S(KC_TAB))
#define CS_T LCTL(S(KC_T))
#define CS_K LCTL(S(KC_K))
#define TASK LCTL(S(KC_ESC))

// Alt keys
#define AL_TAB LALT(KC_TAB)
#define AL_TTAB M(0)
#define AL_D LALT(KC_D)
#define AL_PSCR LALT(KC_PSCR)
#define AL_F6 LALT(KC_F6) // Alt+Tab between same windows
#define AL_ESC LALT(KC_ESC) // Alt+Tab with instant preview
#define AL_F10 LALT(KC_F10) // Maximize window
#define AL_F4 LALT(KC_F4) // Close window

// Gui keys
#define WN_E LGUI(KC_E)
#define WN_D LGUI(KC_D)
#define WN_1 LGUI(KC_1) // Telegram
#define WN_2 LGUI(KC_2) // Yabrowser
#define WN_3 LGUI(KC_3) // Console
#define WN_4 LGUI(KC_4) // Nautilus
#define WN_5 LGUI(KC_5) // CLion
#define WN_6 LGUI(KC_6) // Sublime
#define WN_7 LGUI(KC_7) // Firefox
#define WN_8 LGUI(KC_8) // Git ahead
#define WN_RGHT LGUI(KC_RGHT) // Window to right half
#define WN_LEFT LGUI(KC_LEFT) // Window to left half
#define WS_RGHT LGUI(S(KC_RGHT)) // Window to right display
#define WS_LEFT LGUI(S(KC_LEFT)) // Window to left

// Ctrl keys
#define CT_LEFT LCTL(KC_LEFT)
#define CT_UP LCTL(KC_UP)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_RGHT LCTL(KC_RGHT)
#define CT_ENT LCTL(KC_ENT)
#define CT_DEL LCTL(KC_DEL)
#define CT_BSPC LCTL(KC_BSPC)
#define CT_TAB LCTL(KC_TAB)
#define CT_SLSH LCTL(KC_SLSH)
#define CT_1 LCTL(KC_1)
#define CT_2 LCTL(KC_2)
#define CT_3 LCTL(KC_3)
#define CT_4 LCTL(KC_4)
#define CT_5 LCTL(KC_5)
#define CT_Z LCTL(KC_Z)
#define CT_T LCTL(KC_T)
#define CT_W LCTL(KC_W)
#define CT_J LCTL(KC_J)
#define CT_D LCTL(KC_D)
#define CT_S LCTL(KC_S)
#define CT_F LCTL(KC_F)
#define CT_A LCTL(KC_A)
#define CT_S LCTL(KC_S)
#define CT_D LCTL(KC_D)

#define CT_X LCTL(KC_X)
#define CT_C LCTL(KC_C)
#define CT_V LCTL(KC_V)

// Audio keys
#define AU_MUTE KC_AUDIO_MUTE
#define AU_VOLU KC_AUDIO_VOL_UP
#define AU_VOLD KC_AUDIO_VOL_DOWN
#define AU_NEXT KC_MEDIA_NEXT_TRACK
#define AU_PREV KC_MEDIA_PREV_TRACK
#define AU_PLAY KC_MEDIA_PLAY_PAUSE

#define RGB_LYR TOGGLE_LAYER_COLOR

#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_DOWN KC_MS_DOWN
#define MS_UP KC_MS_UP

// Chords
// Left Index
#define CMB_CTC CMB_000
#define CMB_CTV CMB_001
// Left Thumb
#define CMB_SHF CMB_002
#define CMB_BSP CMB_003
#define CMB_ENT CMB_004
#define CMB_CTL CMB_005
// Left Left Thumb
#define CMB_LY4 CMB_006
#define CMB_LY5 CMB_007
// Right Thumb
#define CMB_LAN CMB_008
#define CMB_DOT CMB_009
#define CMB_SPC CMB_010
#define CMB_ALT CMB_011
// Right Right Thumb
#define CMB_COM CMB_012
#define CMB_SLH CMB_013
// Right Index
#define CMB_CTS CMB_014
#define CMB_TAB CMB_015

// Russian keys
// Left Index
// No
// Left Thumb
#define CMS_SHF CMB_016
// Left Left Thumb
// No
// Right Thumb
#define CMS_DOT CMB_017
#define CMS_SPC CMB_018
// Right Right Thumb
#define CMS_COM CMB_019
#define CMS_SLH CMB_020
// Right Index
// No

// Shifted index keys
#define CMB_CAC CMB_021
#define CMB_CAV CMB_022

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //---------------------------------------------------------------------------
  [0] = MY_layout(
    // LEFT HALF
    KC_ESC,  EN_AMPR, EN_LBRC, EN_RBRC, EN_PLUS, EN_EQL,  EN_GRV,
    KC_TAB,  EN_SCLN, EN_LCBR, EN_RCBR, EN_P,    EN_Y,    CMB_CTC,
    MO(4),   EN_A,    EN_O,    EN_E,    EN_U,    EN_I,    CMB_CTV,
    MO(5),   EN_QUOT, EN_Q,    EN_J,    EN_K,    EN_X,
    CT_J,    XXXXXXX, CT_SLSH, CMB_LY5, CMB_LY4,
    CMB_CTL, // LEFT RED THUMB KEY
    CMB_SHF, CMB_BSP, CMB_ENT, // LEFT THUMB KEYS

    // RIGHT HALF
    CT_D,    EN_ASTR, EN_EXCL, EN_RPRN, EN_LPRN, EN_QUES, CT_Z,
    CMB_CTS, EN_F,    EN_G,    EN_C,    EN_R,    EN_L,    EN_BSLS,
    CMB_TAB, EN_D,    EN_H,    EN_T,    EN_N,    EN_S,    EN_MINS,
             EN_B,    EN_M,    EN_W,    EN_V,    EN_Z,    EN_HASH,
                      CMB_COM, CMB_SLH, KG_NEXT, TG(6),   CT_J,
                      CMB_ALT, // RIGHT RED THUMB KEY
                      CMB_LAN, CMB_DOT, CMB_SPC // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [1] = MY_layout(
    // LEFT HALF
    _______, EN_7,    EN_5,    EN_3,    EN_1,    EN_9,    EN_DLR,
    _______, EN_COLN, EN_LT,   EN_GT,   EN_S_P,  EN_S_Y,  CMB_CAC,
    _______, EN_S_A,  EN_S_O,  EN_S_E,  EN_S_U,  EN_S_I,  CMB_CAV,
    _______, EN_DQUO, EN_S_Q,  EN_S_J,  EN_S_K,  EN_S_X, 
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    EN_TILD, EN_0,    EN_2,    EN_4,    EN_6,    EN_8,    EN_PERC,
    _______, EN_S_F,  EN_S_G,  EN_S_C,  EN_S_R,  EN_S_L,  EN_PIPE,
    _______, EN_S_D,  EN_S_H,  EN_S_T,  EN_S_N,  EN_S_S,  EN_AT,
             EN_S_B,  EN_S_M,  EN_S_W,  EN_S_V,  EN_S_Z,  EN_CIRC,
                      EN_COMM, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [2] = MY_layout(
    // LEFT HALF
    _______, RU_PLUS, RU_MINS, RU_SCLN, RU_DQUO, RU_COLN, _______,
    _______, RU_J,    RU_TS,   RU_U,    RU_JE,   RU_F,    CMB_CTC,
    _______, RU_K,    RU_M,    RU_V,    RU_A,    RU_P,    CMB_CTV,
    _______, RU_JA,   RU_CH,   RU_S,    RU_I,    RU_Y,
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    CMS_SHF, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, RU_ASTR, RU_EXCL, RU_RPRN, RU_LPRN, RU_QUES, CT_Z,
    _______, RU_SC,   RU_G,    RU_T,    RU_N,    RU_Z,    RU_HD,
    _______, RU_R,    RU_O,    RU_L,    RU_D,    RU_ZH,   RU_E,
             RU_SH,   RU_SF,   RU_B,    RU_JU,   RU_H,    RU_JO,
                      CMS_COM, CMS_SLH, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______, CMS_DOT, CMS_SPC // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [3] = MY_layout(
    // LEFT HALF
    _______, RU_7,    RU_5,    RU_3,    RU_1,    RU_9,    _______,
    _______, RU_S_J,  RU_S_TS, RU_S_U,  RU_S_JE, RU_S_F,  CMB_CAC,
    _______, RU_S_K,  RU_S_M,  RU_S_V,  RU_S_A,  RU_S_P,  CMB_CAV,
    _______, RU_S_JA, RU_S_CH, RU_S_S,  RU_S_I,  RU_S_Y,
    _______, _______, _______, _______, _______,
    _______, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    _______, RU_0,    RU_2,    RU_4,    RU_6,    RU_8,    KC_PERC,
    _______, RU_S_SC, RU_S_G,  RU_S_T,  RU_S_N,  RU_S_Z,  RU_S_HD,
    _______, RU_S_R,  RU_S_O,  RU_S_L,  RU_S_D,  RU_S_ZH, RU_S_E,
             RU_S_SH, RU_S_SF, RU_S_B,  RU_S_JU, RU_S_H,  RU_S_JO,
                      RU_COMM, _______, _______, _______, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______,  _______,  _______ // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [4] = MY_layout(
    // LEFT HALF
    TG(4),   KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   CT_X,
    AU_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WN_D,    CT_C,
    _______, AU_VOLU, AU_NEXT, CS_TAB,  CT_TAB,  AL_TAB,  CT_V,
    XXXXXXX, AU_VOLD, AU_PREV, CT_1,    CT_2,    AL_TTAB,
    LA_SYNC, _______, _______, WN_E,    AU_PLAY,
    TASK, // LEFT RED THUMB KEY
    _______, _______, _______, // LEFT THUMB KEYS

    // RIGHT HALF
    KC_PAUS, KC_F10,  KC_F2,   KC_F4,   KC_F6,   KC_F8,   KC_F11,
    KC_INS,  CT_DEL,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_F12,
    CT_BSPC, CS_K,    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_PSCR,
             CT_ENT,  CT_LEFT, CT_UP,   CT_DOWN, CT_RGHT, AL_PSCR,
                      _______, LA_CAPS, LA_ALSH, LA_CTSH, LA_WISP,
                      _______, // RIGHT RED THUMB KEY
                      _______, _______, _______ // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [5] = MY_layout(
    // LEFT HALF
    TG(5),   CT_1,    CT_2,    CT_3,    CT_4,     CT_5,     CT_X,
    KC_F5,   KC_F6,   CS_T,    CT_T,    CT_W,     CT_J,     CT_C,
    KC_BTN2, KC_BTN1, KC_BTN3, CS_TAB,  CT_TAB,   CT_D,     CT_V,
    _______, CT_S,    KC_ENT,  KC_UP,   KC_DOWN,  CT_F,
    XXXXXXX, _______, CLR_1,   CLR_2,   CLR_3,  
    RGB_MOD, // LEFT RED THUMB KEY
    RGB_VAD, RGB_VAI, RGB_LYR, // LEFT THUMB KEYS

    // RIGHT HALF
    AU_TOG,  RGB_SLD, RGB_HUD, RGB_HUI, RGB_TOG, _______, RESET,
    MU_TOG,  WN_6,    WN_1,    WN_2,    WN_3,    WN_4,    WN_5,
    MU_MOD,  WN_7,    AL_ESC,  AL_F6,   AL_F10,  _______, AL_F4,
             WN_8,    WN_LEFT, WN_RGHT, WS_LEFT, WS_RGHT, _______,
             MS_LEFT,  MS_UP,  MS_DOWN, MS_RGHT, _______,
                      _______, // RIGHT RED THUMB KEY
                      _______,  KC_MS_BTN2,  KC_MS_BTN1 // RIGHT THUMB KEYS
  ),

  //---------------------------------------------------------------------------
  [6] = MY_layout(
    // LEFT HALF
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_8,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
    XXXXXXX, XXXXXXX, TG(6),   KC_PERC, RU_CMSP,
    XXXXXXX, // LEFT RED THUMB KEY
    KC_SPC,  KC_LALT, KC_ENT, // LEFT THUMB KEYS

    // RIGHT HALF
    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UNDS,
                      KC_LEFT, KC_UP,   KC_DOWN, TG(6),   XXXXXXX,
                      XXXXXXX, // RIGHT RED THUMB KEY
                      XXXXXXX, XXXXXXX, XXXXXXX // RIGHT THUMB KEYS
    ),

  //---------------------------------------------------------------------------
  [7] = MY_layout(
    // LEFT HALF
    _______,  LGUI(KC_6),  LGUI(KC_5),  LGUI(KC_4),  LGUI(KC_3),  LGUI(KC_2),  LGUI(KC_1),
    LGUI(LCTL(KC_SPACE)),  LGUI(KC_F4),  LGUI(KC_F3),  LGUI(KC_F2),  LGUI(KC_F1),  LGUI(S(KC_Q)),  LGUI(KC_A),
    LGUI(LCTL(KC_LEFT)),  LGUI(KC_LEFT),  LGUI(KC_DOWN),  LGUI(KC_UP),  LGUI(KC_RIGHT),  LGUI(LCTL(KC_RIGHT)), LGUI(KC_I),
    LGUI(LALT(KC_LEFT)),  LGUI(KC_F8),  LGUI(KC_F7),  LGUI(KC_F6),  LGUI(KC_F5),  LGUI(LALT(KC_RIGHT)),
    _______,    _______,  _______,  _______,  _______,
    _______, // LEFT RED THUMB KEY
    _______,  _______,  _______, // LEFT THUMB KEYS

    // RIGHT HALF
    LGUI(S(KC_1)),    LGUI(S(KC_2)),  LGUI(S(KC_3)),  LGUI(S(KC_4)),  LGUI(S(KC_5)),  LGUI(S(KC_6)),  _______,
    LGUI(KC_F), LGUI(KC_R),  KC_LEFT,  KC_UP,  KC_DOWN,  KC_RIGHT,  LGUI(KC_SPACE),
    I3_CR,      LGUI(KC_D),  LGUI(S(KC_LEFT)),  LGUI(S(KC_UP)),    LGUI(S(KC_DOWN)),  LGUI(S(KC_RIGHT)),  LGUI(KC_G),
                LGUI(KC_H),  LGUI(KC_V),  LGUI(KC_E),  LGUI(KC_W),  LGUI(KC_S),  LGUI(KC_N),
                          _______,  _______,  _______,  _______,  _______,
                          _______, // RIGHT RED THUMB KEY
                          _______,  _______,  _______ // RIGHT THUMB KEYS
  ),
};

const ComboWithKeycode combos[COMBO_COUNT] = {
  // Left Index
  CHORD(CT_C,    /* <- */ CMB_CTC),
  CHORD(CT_V,    /* <- */ CMB_CTV),
  CHORD(CT_X,    /* <- */ CMB_CTC, CMB_CTV),

  // Left Index + Thumb
  CHORD(CT_A_C,  /* <- */ CMB_SHF, CMB_CTC),
  CHORD(CT_A_V,  /* <- */ CMB_SHF, CMB_CTV),
  CHORD(CT_A_X,  /* <- */ CMB_SHF, CMB_CTC, CMB_CTV),

  // Left Thumb
  CHORD(SHF_1,   /* <- */ CMB_SHF),
  CHORD(KC_BSPC, /* <- */ CMB_BSP),
  CHORD(KC_ENT,  /* <- */ CMB_ENT),
  CHORD(KC_LCTL, /* <- */ CMB_CTL),
  CHORD(CT_A,    /* <- */ CMB_SHF, CMB_CTL),
  CHORD(SHF_1_O, /* <- */ CMB_SHF, CMB_BSP),
  CHORD(KC_DEL,  /* <- */ CMB_BSP, CMB_CTL),
  CHORD(CT_BSPC, /* <- */ CMB_BSP, CMB_ENT),
  CHORD(CT_SHF,  /* <- */ CMB_SHF, CMB_BSP, CMB_CTL),
  CHORD(MY_SCRN, /* <- */ CMB_BSP, CMB_ENT, CMB_CTL),

  // Left Left Thumb
  CHORD(MO(4),   /* <- */ CMB_LY4),
  CHORD(MO(5),   /* <- */ CMB_LY5),
  CHORD(MO(6),   /* <- */ CMB_LY4, CMB_LY5),

  // Right Thumb
  CHORD(LA_CHNG, /* <- */ CMB_LAN),
  CHORD(EN_DOT,  /* <- */ CMB_DOT),
  CHORD(KC_SPC,  /* <- */ CMB_SPC),
  CHORD(KC_LALT, /* <- */ CMB_ALT),
  CHORD(EN_SDOT, /* <- */ CMB_DOT, CMB_SPC),
  CHORD(LA_SYNC, /* <- */ CMB_LAN, CMB_DOT),
  CHORD(EN_UNDS, /* <- */ CMB_SPC, CMB_ALT),
  CHORD(EN_MINS, /* <- */ CMB_DOT, CMB_ALT),
  CHORD(KC_LGUI, /* <- */ CMB_SPC, CMB_DOT, CMB_ALT),
  CHORD(XXXXXXX, /* <- */ CMB_LAN, CMB_DOT, CMB_ALT),

  // Right Right Thumb
  CHORD(EN_CMSP, /* <- */ CMB_COM),
  CHORD(EN_SLSH, /* <- */ CMB_SLH),
  CHORD(XXXXXXX, /* <- */ CMB_COM, CMB_SLH),

  // Right Index
  CHORD(CT_S,    /* <- */ CMB_CTS),
  CHORD(XXXXXXX, /* <- */ CMB_TAB),
  CHORD(KC_SPHY, /* <- */ CMB_CTS, CMB_TAB),

  // Right Thumb + Left Thumb
  CHORD(EN_COMM, /* <- */ CMB_SHF, CMB_COM), // Костыль, потому что шифт является одновременно слоём, и одновременно они с запятой аккорды, поэтому нужно такая вещь для дополнительной подстраховки, ибо что-то там не работает...

  // -------------------------------------------------------------------------
  // Shifted index keys

  // Left Index
  CHORD(CT_A_C,  /* <- */ CMB_CAC),
  CHORD(CT_A_V,  /* <- */ CMB_CAV),
  CHORD(CT_A_X,  /* <- */ CMB_CAC, CMB_CAV),

  // -------------------------------------------------------------------------
  // Duplicate of chords for russian layer

  // Left Index + Thumb
  CHORD(CT_A_C,  /* <- */ CMS_SHF, CMB_CTC),
  CHORD(CT_A_V,  /* <- */ CMS_SHF, CMB_CTV),
  CHORD(CT_A_X,  /* <- */ CMS_SHF, CMB_CTC, CMB_CTV),

  // Left Thumb
  CHORD(SHF_3,   /* <- */ CMS_SHF),
  CHORD(CT_A,    /* <- */ CMS_SHF, CMB_CTL),
  CHORD(SHF_3_O, /* <- */ CMS_SHF, CMB_BSP),
  CHORD(CT_SHF,  /* <- */ CMS_SHF, CMB_BSP, CMB_CTL),

  // Right Thumb
  CHORD(RU_DOT,  /* <- */ CMS_DOT),
  CHORD(KC_SPC,  /* <- */ CMS_SPC),
  CHORD(RU_SDOT, /* <- */ CMS_DOT, CMS_SPC),
  CHORD(LA_SYNC, /* <- */ CMB_LAN, CMS_DOT),
  CHORD(RU_UNDS, /* <- */ CMS_SPC, CMB_ALT),
  CHORD(RU_MINS, /* <- */ CMS_DOT, CMB_ALT),
  CHORD(KC_LGUI, /* <- */ CMS_SPC, CMS_DOT, CMB_ALT),
  CHORD(XXXXXXX, /* <- */ CMB_LAN, CMS_DOT, CMB_ALT),

  // Right Right Thumb
  CHORD(RU_CMSP, /* <- */ CMS_COM),
  CHORD(RU_SLSH, /* <- */ CMS_SLH),
  CHORD(XXXXXXX, /* <- */ CMS_COM, CMS_SLH),

  // Right Thumb + Left Thumb
  CHORD(RU_COMM, /* <- */ CMS_SHF, CMS_COM),
};

// Модификаторы, которые одновременно переключают слой на 0
// TODO
/*
bool process_my_modifiers(uint16_t keycode, keyrecord_t *record) {
  static uint8_t my_old_lang = 0;
  #define PROCESS(_name, _register, _unregister) \
    case _name: { \
      if (record->event.pressed) { \
        my_old_lang = lang_should_be; \
        lang_activate_from_user(0); \
        default_layer_set(0); \
        _register; \
      } else { \
        lang_activate_from_user(my_old_lang); \
        _unregister; \
      } \
      return false; \
      } break;

  #define Rg(x) register_code(KC_L ## x)
  #define Un(x) unregister_code(KC_L ## x)

  switch (keycode) {
    PROCESS(MY_CTRL, Rg(CTRL), Un(CTRL));
    PROCESS(MY_ALT,  Rg(ALT),  Un(ALT));
    PROCESS(MY_WIN,  Rg(GUI),  Un(GUI));
    PROCESS(MY_CTAL, { Rg(CTRL);  Rg(ALT);   }, { Un(ALT);   Un(CTRL);  })
    PROCESS(MY_SHAL, { Rg(SHIFT); Rg(ALT);   }, { Un(ALT);   Un(SHIFT); })
    PROCESS(MY_CTSH, { Rg(CTRL);  Rg(SHIFT); }, { Un(SHIFT); Un(CTRL);  })
    PROCESS(MY_MCAS, { Rg(CTRL);  Rg(ALT); Rg(SHIFT); }, { Un(SHIFT); Un(ALT); Un(CTRL); })
  }

  return true;
}
*/

// Мои языко-символьные клавиши
bool process_my_lang_keys(uint16_t keycode, keyrecord_t *record) {
  // Russian-specific codes
  switch (keycode) {
    case RU_3DOT:
      if (record->event.pressed) {
        lang_tap_key(RU_DOT);
        lang_tap_key(RU_DOT);
        lang_tap_key(RU_DOT);
      }    
      return false;
      break;
    case RU_CMSP:
      if (record->event.pressed) {
        lang_tap_key(RU_COMM);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      return false;
      break;
    case RU_SDOT:
      if (record->event.pressed) {
        lang_tap_key(RU_DOT);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        shift_once_use_to_next_key(3);
      }
      return false;
      break;
  }

  // English-specific codes
  switch (keycode) {
    case EN_3DOT:
      if (record->event.pressed) {
        lang_tap_key(EN_DOT);
        lang_tap_key(EN_DOT);
        lang_tap_key(EN_DOT);
      }    
      return false;
      break;
    case EN_CMSP:
      if (record->event.pressed) {
        lang_tap_key(EN_COMM);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      return false;
      break;
    case EN_SDOT:
      if (record->event.pressed) {
        lang_tap_key(EN_DOT);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        shift_once_use_to_next_key(1);
      }
      return false;
      break;
  }
  return true;
}

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define COLOR_ANY_FINGER { 120, 255, 255 }
#define COLOR_PINKY { 33, 255, 255 }
#define COLOR_ANNULAR { 146, 255, 255 }
#define COLOR_MIDDLE { 85, 255, 255 }
#define COLOR_INDEX { 224, 255, 255 }
#define COLOR_THUMB { 23, 255, 255 }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { COLOR_ANY_FINGER, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANY_FINGER, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANY_FINGER, COLOR_ANNULAR, COLOR_ANNULAR, COLOR_ANNULAR, COLOR_ANNULAR, COLOR_ANY_FINGER, COLOR_MIDDLE, COLOR_MIDDLE, COLOR_MIDDLE, COLOR_MIDDLE, COLOR_THUMB, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB, COLOR_THUMB, COLOR_THUMB, COLOR_THUMB, COLOR_ANY_FINGER, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANY_FINGER, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANY_FINGER, COLOR_ANNULAR, COLOR_ANNULAR, COLOR_ANNULAR, COLOR_ANNULAR, COLOR_ANY_FINGER, COLOR_MIDDLE, COLOR_MIDDLE, COLOR_MIDDLE, COLOR_MIDDLE, COLOR_THUMB, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB, COLOR_THUMB, COLOR_THUMB, COLOR_THUMB },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        //rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

uint8_t draw_layer = 0;
void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (draw_layer) {
    case 1:
      set_layer_color(0);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (combo_enabled && !combo_process(keycode, record)) {
    return false;
  }

  if (!process_my_lang_keys(keycode, record)) {
    return false;
  }

  if (!process_record_lang_shift(keycode, record)) {
    return false;
  }

  // TODO
  // if (!process_my_modifiers(keycode, record))
  //   return false;

  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case CLR_1:
      if (record->event.pressed) {
        if (draw_layer == 1) {
          draw_layer = 0;
        } else {
          draw_layer = 1;
        }
      }
      return false;
    case CLR_2:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case CLR_3:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case KG_NEXT:
      if (record->event.pressed) {
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        register_code(KC_LCTRL);
        register_code(KC_RGHT);
        unregister_code(KC_RGHT);
        unregister_code(KC_LCTRL);
      }    
      return false;
      break;
    case I3_CR:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSHIFT);

        register_code(KC_C);
        unregister_code(KC_C);

        register_code(KC_R);
        unregister_code(KC_R);

        unregister_code(KC_LSHIFT);
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case CT_SHF:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_LSHIFT);
      } else {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LCTRL);
      }
      return false;
    case MY_SCRN:
      if (record->event.pressed) {
        switch (lang_current_change) {
          case LANG_CHANGE_CAPS: {
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            register_code(KC_PSCR);
            unregister_code(KC_PSCR);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LCTRL);
          } break;
          case LANG_CHANGE_ALT_SHIFT:
          case LANG_CHANGE_CTRL_SHIFT: {
            register_code(KC_LGUI);
              register_code(KC_LSHIFT);
              register_code(KC_S);
            unregister_code(KC_S);
              unregister_code(KC_LSHIFT);
              unregister_code(KC_LGUI);
          } break;
          case LANG_CHANGE_WIN_SPACE: {
            // No screenshot, maybe it android
          } break;
        } 
      }
      return false;
      break;
    case CT_A_C:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_A);
        unregister_code(KC_A);
        register_code(KC_C);
        unregister_code(KC_C);
        unregister_code(KC_LCTRL);
      }
      return true;
    case CT_A_V:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_A);
        unregister_code(KC_A);
        register_code(KC_V);
        unregister_code(KC_V);
        unregister_code(KC_LCTRL);
      }
      return true;
    case CT_A_X:
      if (record->event.pressed) {
        register_code(KC_LCTRL);
        register_code(KC_A);
        unregister_code(KC_A);
        register_code(KC_X);
        unregister_code(KC_X);
        unregister_code(KC_LCTRL);
      }
      return true;
    case KC_SPHY:
      if (record->event.pressed) {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
        register_code(KC_MINS);
        unregister_code(KC_MINS);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      return false;
      break;
  }

  return true;
}

void user_timer(void) {
  combo_user_timer();
  shift_user_timer();
  shift_once_user_timer();
  lang_user_timer();
}

void matrix_scan_user(void) {
  user_timer();
}
