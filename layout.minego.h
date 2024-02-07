#include <linux/input-event-codes.h>

#define KBD_PIXEL_HEIGHT				250
#define KBD_PIXEL_LANDSCAPE_HEIGHT		250
#define KBD_KEY_BORDER					2

/* layout declarations */
enum layout_id {
	Compact = 0,
	Full,

	Index,
	NumLayouts,
};

static struct key keys_full[];
static struct key keys_compact[];
static struct key keys_index[];

// second parameter is the keymap name
// third parameter is the layout name
// last parameter indicates if it's an alphabetical/primary layout
static struct layout layouts[NumLayouts] = {
	[Compact]		= { keys_compact,	"latin",	"compact",	true	},
	[Full]			= { keys_full,		"latin",	"full",		true	},

	[Index]			= { keys_index,		"latin",	"index",	false	},
};

/* key layouts
 *
 * define keys like:
 *
 *  `{
 *     "label",
 *     "SHIFT_LABEL",
 *     1,
 *     [Code, Mod, Layout, EndRow, Last],
 *     [KEY_CODE, Modifier],
 *     [&layout]
 *  },`
 *
 * - label: normal label for key
 *
 * - shift_label: label for key in shifted (uppercase) layout
 *
 * - width: column width of key
 *
 * - type: what kind of action this key performs (emit keycode, toggle modifier,
 *   switch layout, or end the layout)
 *
 * - code: key scancode or modifier name (see
 *   `/usr/include/linux/input-event-codes.h` for scancode names, and
 *   `keyboard.h` for modifiers)
 *
 * - layout: layout to switch to when key is pressed
 *
 * Setting `.scheme = x` will change the colorscheme to one of the ones listed
 * in config.def.h or config.h
 */
static struct key keys_full[] = { // 14.5 keys wide per row
	{ "`",		"~",	1.0,	Code,		KEY_GRAVE								},
	{ "1",		"!",	1.0,	Code,		KEY_1									},
	{ "2",		"@",	1.0,	Code,		KEY_2									},
	{ "3",		"#",	1.0,	Code,		KEY_3									},
	{ "4",		"$",	1.0,	Code,		KEY_4									},
	{ "5",		"%",	1.0,	Code,		KEY_5									},
	{ "6",		"^",	1.0,	Code,		KEY_6									},
	{ "7",		"&",	1.0,	Code,		KEY_7									},
	{ "8",		"*",	1.0,	Code,		KEY_8									},
	{ "9",		"(",	1.0,	Code,		KEY_9									},
	{ "0",		")",	1.0,	Code,		KEY_0									},
	{ "-",		"_",	1.0,	Code,		KEY_MINUS								},
	{ "=",		"+",	1.0,	Code,		KEY_EQUAL								},
	{ "⌫",		"⌫",	1.5,	Code,		KEY_BACKSPACE,	.scheme = 1				},
	{ "",		"",		0.0,	EndRow												},

	{ "tab",	"tab",	1.5,	Code,		KEY_TAB,		.scheme = 1				},
	{ "q",		"Q",	1.0,	Code,		KEY_Q									},
	{ "w",		"W",	1.0,	Code,		KEY_W									},
	{ "e",		"E",	1.0,	Code,		KEY_E									},
	{ "r",		"R",	1.0,	Code,		KEY_R									},
	{ "t",		"T",	1.0,	Code,		KEY_T									},
	{ "y",		"Y",	1.0,	Code,		KEY_Y									},
	{ "u",		"U",	1.0,	Code,		KEY_U									},
	{ "i",		"I",	1.0,	Code,		KEY_I									},
	{ "o",		"O",	1.0,	Code,		KEY_O									},
	{ "p",		"P",	1.0,	Code,		KEY_P									},
	{ "[",		"{",	1.0,	Code,		KEY_LEFTBRACE							},
	{ "]",		"}",	1.0,	Code,		KEY_RIGHTBRACE							},
	{ "\\",		"|",	1.0,	Code,		KEY_BACKSLASH							},
	{ "",		"",		0.0,	EndRow												},

	{ "ctrl",	"ctrl",	1.75,	Mod,		Ctrl,			.scheme = 1				},
	{ "a",		"A",	1.0,	Code,		KEY_A									},
	{ "s",		"S",	1.0,	Code,		KEY_S									},
	{ "d",		"D",	1.0,	Code,		KEY_D									},
	{ "f",		"F",	1.0,	Code,		KEY_F									},
	{ "g",		"G",	1.0,	Code,		KEY_G									},
	{ "h",		"H",	1.0,	Code,		KEY_H									},
	{ "j",		"J",	1.0,	Code,		KEY_J									},
	{ "k",		"K",	1.0,	Code,		KEY_K									},
	{ "l",		"L",	1.0,	Code,		KEY_L									},
	{ ";",		":",	1.0,	Code,		KEY_SEMICOLON							},
	{ "'",		"\"",	1.0,	Code,		KEY_APOSTROPHE							},
	{ "enter",	"enter",1.75,	Code,		KEY_ENTER,		.scheme = 1				},
	{ "",		"",		0.0,	EndRow												},

	{ "shift",	"shift",2.25,	Mod,		Shift,			.scheme = 1				},
	{ "z",		"Z",	1.0,	Code,		KEY_Z									},
	{ "x",		"X",	1.0,	Code,		KEY_X									},
	{ "c",		"C",	1.0,	Code,		KEY_C									},
	{ "v",		"V",	1.0,	Code,		KEY_V									},
	{ "b",		"B",	1.0,	Code,		KEY_B									},
	{ "n",		"N",	1.0,	Code,		KEY_N									},
	{ "m",		"M",	1.0,	Code,		KEY_M									},
	{ ",",		"<",	1.0,	Code,		KEY_COMMA								},
	{ ".",		">",	1.0,	Code,		KEY_DOT									},
	{ "/",		"?",	1.0,	Code,		KEY_SLASH								},
	{ "",		"",		0.25,	Pad													},
	{ "shift",	"shift",1.0,	Code,		KEY_UP,			.scheme = 1				},
	{ "⇧",		"⇫",	1.0,	Mod,		Shift,			.scheme = 1				},
	{ "",		"",		0.0,	EndRow												},

	{ "esc",	"esc",	1.0,	Code,		KEY_ESC,		.scheme = 1				},
	{ "⌨͕",		"⌨͔",	1.0,	NextLayer,	.scheme = 1								},
	{ "alt",	"alt",	1.0,	Mod,		Alt,			.scheme = 1				},
	{ "mod",	"mod",	1.0,	Mod,		Super,			.scheme = 1				},
	{ "",		"tab",	7.5,	Code,		KEY_SPACE								},
	{ "←",		"←",	1.0,	Code,		KEY_LEFT,		.scheme = 1				},
	{ "↓",		"↓",	1.0,	Code,		KEY_DOWN,		.scheme = 1				},
	{ "→",		"→",	1.0,	Code,		KEY_RIGHT,		.scheme = 1				},

	/* end of layout */
	{ "",		"",		0.0,	Last												},
};

static struct key keys_compact[] = { // 14.5 keys wide per row
	{ "tab",	"tab",	1.5,	Code,		KEY_TAB,		.scheme = 1				},
	{ "q",		"Q",	1.0,	Code,		KEY_Q									},
	{ "w",		"W",	1.0,	Code,		KEY_W									},
	{ "e",		"E",	1.0,	Code,		KEY_E									},
	{ "r",		"R",	1.0,	Code,		KEY_R									},
	{ "t",		"T",	1.0,	Code,		KEY_T									},
	{ "y",		"Y",	1.0,	Code,		KEY_Y									},
	{ "u",		"U",	1.0,	Code,		KEY_U									},
	{ "i",		"I",	1.0,	Code,		KEY_I									},
	{ "o",		"O",	1.0,	Code,		KEY_O									},
	{ "p",		"P",	1.0,	Code,		KEY_P									},
	{ "[",		"{",	1.0,	Code,		KEY_LEFTBRACE							},
	{ "]",		"}",	1.0,	Code,		KEY_RIGHTBRACE							},
	{ "\\",		"|",	1.0,	Code,		KEY_BACKSLASH							},
	{ "",		"",		0.0,	EndRow												},

	{ "ctrl",	"ctrl",	1.75,	Mod,		Ctrl,			.scheme = 1				},
	{ "a",		"A",	1.0,	Code,		KEY_A									},
	{ "s",		"S",	1.0,	Code,		KEY_S									},
	{ "d",		"D",	1.0,	Code,		KEY_D									},
	{ "f",		"F",	1.0,	Code,		KEY_F									},
	{ "g",		"G",	1.0,	Code,		KEY_G									},
	{ "h",		"H",	1.0,	Code,		KEY_H									},
	{ "j",		"J",	1.0,	Code,		KEY_J									},
	{ "k",		"K",	1.0,	Code,		KEY_K									},
	{ "l",		"L",	1.0,	Code,		KEY_L									},
	{ ";",		":",	1.0,	Code,		KEY_SEMICOLON							},
	{ "'",		"\"",	1.0,	Code,		KEY_APOSTROPHE							},
	{ "enter",	"enter",1.75,	Code,		KEY_ENTER,		.scheme = 1				},
	{ "",		"",		0.0,	EndRow												},

	{ "shift",	"shift",2.25,	Mod,		Shift,			.scheme = 1				},
	{ "z",		"Z",	1.0,	Code,		KEY_Z									},
	{ "x",		"X",	1.0,	Code,		KEY_X									},
	{ "c",		"C",	1.0,	Code,		KEY_C									},
	{ "v",		"V",	1.0,	Code,		KEY_V									},
	{ "b",		"B",	1.0,	Code,		KEY_B									},
	{ "n",		"N",	1.0,	Code,		KEY_N									},
	{ "m",		"M",	1.0,	Code,		KEY_M									},
	{ ",",		"<",	1.0,	Code,		KEY_COMMA								},
	{ ".",		">",	1.0,	Code,		KEY_DOT									},
	{ "/",		"?",	1.0,	Code,		KEY_SLASH								},
	{ "",		"",		0.25,	Pad													},
	{ "↑",		"↑",	1.0,	Code,		KEY_UP,			.scheme = 1				},
	{ "⌫",		"⌫",	1.0,	Code,		KEY_BACKSPACE,	.scheme = 1				},
	{ "",		"",		0.0,	EndRow												},

	{ "esc",	"esc",	1.0,	Code,		KEY_ESC,		.scheme = 1				},
	{ "⌨͕",		"⌨͔",	1.0,	NextLayer,	.scheme = 1								},
	{ "alt",	"alt",	1.0,	Mod,		Alt,			.scheme = 1				},
	{ "mod",	"mod",	1.0,	Mod,		Super,			.scheme = 1				},
	{ "",		"tab",	7.5,	Code,		KEY_SPACE								},
	{ "←",		"←",	1.0,	Code,		KEY_LEFT,		.scheme = 1				},
	{ "↓",		"↓",	1.0,	Code,		KEY_DOWN,		.scheme = 1				},
	{ "→",		"→",	1.0,	Code,		KEY_RIGHT,		.scheme = 1				},

	/* end of layout */
	{ "",		"",		0.0,	Last												},
};

static struct key keys_index[] = {
	{ "Compact","Compact",	1.0,	Layout,	0,	&layouts[Compact],	.scheme = 1		},
	{ "Full",	"Full",		1.0,	Layout,	0,	&layouts[Full],		.scheme = 1		},
	{ "",		"",			0.0,	Last											},
};


