/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */
#ifndef __NVGPU_IOCTL_CHANNEL_H__
#define __NVGPU_IOCTL_CHANNEL_H__

#include <linux/fs.h>

struct inode;
struct file;
struct gk20a;
struct nvgpu_channel_open_args;

int gk20a_channel_open(struct inode *inode, struct file *filp);
int gk20a_channel_release(struct inode *inode, struct file *filp);
long gk20a_channel_ioctl(struct file *filp,
	unsigned int cmd, unsigned long arg);
int gk20a_channel_open_ioctl(struct gk20a *g,
		struct nvgpu_channel_open_args *args);

extern const struct file_operations gk20a_event_id_ops;
extern const struct file_operations gk20a_channel_ops;

u32 nvgpu_event_id_to_ioctl_channel_event_id(u32 event_id);
u32 nvgpu_get_common_runlist_level(u32 level);

u32 nvgpu_get_ioctl_graphics_preempt_mode_flags(u32 graphics_preempt_mode_flags);
u32 nvgpu_get_ioctl_compute_preempt_mode_flags(u32 compute_preempt_mode_flags);
u32 nvgpu_get_ioctl_graphics_preempt_mode(u32 graphics_preempt_mode);
u32 nvgpu_get_ioctl_compute_preempt_mode(u32 compute_preempt_mode);
#endif
