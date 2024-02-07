#ifndef config_def_h_INCLUDED
#define config_def_h_INCLUDED

#define DEFAULT_FONT "Sans 14"
static const int transparency = 255;

struct clr_scheme schemes[] = {{
	/* colors */
	.bg		= { .bgra = { 0, 0, 0, 0 }},
	.fg		= { .bgra = { 0, 0, 0, 0 }},
	.high	= { .bgra = { 100, 100, 100, transparency }},
	.swipe	= { .bgra = { 100, 255, 100, 64 }},

	.text	= { .color = UINT32_MAX},
	.font	= DEFAULT_FONT,
}, {
	/* colors */
	.bg		= { .bgra = { 0, 0, 0, 0 }},
	.fg		= { .bgra = { 255, 255, 255, 25 }},
	.high	= { .bgra = { 100, 100, 100, transparency }},
	.swipe	= { .bgra = { 100, 255, 100, 64 }},

	.text	= { .color = UINT32_MAX},
	.font	= DEFAULT_FONT,
}};

/* layers is an ordered list of layouts, used to cycle through */
static enum layout_id layers[] = {
	Compact,
	Full,
	NumLayouts
};

/* layers is an ordered list of layouts, used to cycle through */
static enum layout_id landscape_layers[] = {
	Compact,
	Full,
	NumLayouts
};

#endif // config_def_h_INCLUDED
