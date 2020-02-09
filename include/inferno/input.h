/*
 *	inferno/input.h
 *
 *	Copyright (c) 2020 Ariston Lorenzo
 *	All rights reserved.
 */

#ifndef _INPUT_H
#define _INPUT_H

/* Implementation details, userspace should not care about these */
#define ABS_MT_FIRST		ABS_MT_TOUCH_MAJOR
#define ABS_MT_LAST		ABS_MT_TOOL_Y

/*
 * In-kernel definitions.
 */

struct input_dev_poller;

/**
struct
