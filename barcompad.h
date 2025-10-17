#ifndef BARCOMPAD_H
#define BARCOMPAD_H

/* ------------------------------------------------------------------
 * BarComPad (padding properties, tag gap and global struct object).
 *
 * All stuff here is a lil' complex to explain using C code comments.
 * Consider reading the official path repository at:
 *     https://github.com/nasccped/dwm-barcompad
 *
 * It contains usage tips! :^D
 * --------------------------------------------------------------- */

/* padding for rectangle sides */
struct BCPSideValues {
	unsigned int
		top,
		left,
		right,
		bottom;
};

/* main struct */
struct BarComPad {
	struct BCPPaddingProperties
		outer_tag_padding,
		inner_tag_padding,
		title_padding,
		root_padding;
	unsigned int
		tag_gap;
};

static const struct BarComPad BARCOMPAD = {
	.outer_tag_padding = {6, 6, 6, 6},
	.inner_tag_padding = {4, 4, 4, 4},
	.title_padding     = {6, 6, 6, 6},
	.root_padding      = {6, 6, 6, 6},
	.tag_gap           = 6
};

/* gets the max height of status bar + avoid if-else hell within dwm.c
 * file */
unsigned int barcompad_get_max_height(const struct BarComPad *bcp, int fontsize) {
	if (!bcp) return 0;
	int
		tags = bcp->outer_tag_padding->top
			+ bcp->outer_tag_padding->bottom
			+ bcp->inner_tag_padding->top
			+ bcp->inner_tag_padding->bottom,
		title = bcp->title_padding->top
			+ bcp->title_padding->bottom,
		root = bcp->root_padding->top
			+ bcp->root_padding->bottom;
	int max = tags;
	max = max < title ? title : max;
	max = max < root ? root : max;
	return fontsize + max;
}

#endif // !BARCOMPAD_H
