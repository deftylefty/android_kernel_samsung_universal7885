/*
 *  dma.h --
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 *  ALSA PCM interface for the Samsung SoC
 */

#ifndef _S3C_AUDIO_H
#define _S3C_AUDIO_H

#include <sound/dmaengine_pcm.h>

struct s3c_dma_params {
	struct s3c2410_dma_client *client;	/* stream identifier */
	int channel;				/* Channel ID */
	dma_addr_t dma_addr;
	int dma_size;			/* Size of the DMA transfer */
#ifdef CONFIG_ARM64
	unsigned long ch;
#else
	unsigned ch;
#endif
	struct samsung_dma_ops *ops;
	struct device *sec_dma_dev; /* stream identifier */
	char *ch_name;
	bool esa_dma;
	bool compr_dma;

};

void samsung_asoc_init_dma_data(struct snd_soc_dai *dai,
				struct s3c_dma_params *playback,
				struct s3c_dma_params *capture);
int samsung_asoc_dma_platform_register(struct device *dev);
int asoc_dma_platform_register(struct device *dev);
void asoc_dma_platform_unregister(struct device *dev);

#endif
