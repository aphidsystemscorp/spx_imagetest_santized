/*************************************************************************/ /*!
@Title          Hardware definition file rgx_bvnc_table_km.h
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/

/******************************************************************************
 *                 Auto generated file by rgxbvnc_tablegen.py                 *
 *                  This file should not be edited manually                   *
 *****************************************************************************/

#ifndef RGX_BVNC_TABLE_KM_H
#define RGX_BVNC_TABLE_KM_H

#include "img_types.h"
#include "img_defs.h"
#include "rgxdefs_km.h"
#include "rgx_bvnc_defs_km.h"

#ifndef RGXBVNC_C
#error "This file should only be included from rgxbvnc.c"
#endif

#if defined(RGX_BVNC_TABLE_UM_H)
#error "This file should not be included in conjunction with rgx_bvnc_table_um.h"
#endif


/******************************************************************************
 * Arrays for each feature with values used
 * for handling the corresponding values
 *****************************************************************************/

static const IMG_UINT16 aui16_RGX_FEATURE_CDM_CONTROL_STREAM_FORMAT_values[RGX_FEATURE_CDM_CONTROL_STREAM_FORMAT_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_CONTEXT_SWITCH_3D_LEVEL_values[RGX_FEATURE_CONTEXT_SWITCH_3D_LEVEL_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 3, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_ECC_RAMS_values[RGX_FEATURE_ECC_RAMS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 0, 1, };

static const IMG_UINT16 aui16_RGX_FEATURE_FBCDC_values[RGX_FEATURE_FBCDC_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_FBCDC_ALGORITHM_values[RGX_FEATURE_FBCDC_ALGORITHM_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_FBCDC_ARCHITECTURE_values[RGX_FEATURE_FBCDC_ARCHITECTURE_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 6, };

static const IMG_UINT16 aui16_RGX_FEATURE_FBC_MAX_DEFAULT_DESCRIPTORS_values[RGX_FEATURE_FBC_MAX_DEFAULT_DESCRIPTORS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 512, 2048, };

static const IMG_UINT16 aui16_RGX_FEATURE_FBC_MAX_LARGE_DESCRIPTORS_values[RGX_FEATURE_FBC_MAX_LARGE_DESCRIPTORS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 0, 32, };

static const IMG_UINT16 aui16_RGX_FEATURE_HOST_SECURITY_VERSION_values[RGX_FEATURE_HOST_SECURITY_VERSION_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, };

static const IMG_UINT16 aui16_RGX_FEATURE_LAYOUT_MARS_values[RGX_FEATURE_LAYOUT_MARS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 0, };

static const IMG_UINT16 aui16_RGX_FEATURE_MAX_TPU_PER_SPU_values[RGX_FEATURE_MAX_TPU_PER_SPU_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_META_values[RGX_FEATURE_META_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, MTP219, };

static const IMG_UINT16 aui16_RGX_FEATURE_META_COREMEM_BANKS_values[RGX_FEATURE_META_COREMEM_BANKS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 8, };

static const IMG_UINT16 aui16_RGX_FEATURE_META_COREMEM_SIZE_values[RGX_FEATURE_META_COREMEM_SIZE_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 96, };

static const IMG_UINT16 aui16_RGX_FEATURE_META_DMA_CHANNEL_COUNT_values[RGX_FEATURE_META_DMA_CHANNEL_COUNT_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 2, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_MMU_VERSION_values[RGX_FEATURE_MMU_VERSION_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 3, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_NUM_CLUSTERS_values[RGX_FEATURE_NUM_CLUSTERS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_NUM_ISP_IPP_PIPES_values[RGX_FEATURE_NUM_ISP_IPP_PIPES_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 4, 8, 16, };

static const IMG_UINT16 aui16_RGX_FEATURE_NUM_ISP_PER_SPU_values[RGX_FEATURE_NUM_ISP_PER_SPU_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_NUM_MEMBUS_values[RGX_FEATURE_NUM_MEMBUS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_NUM_OSIDS_values[RGX_FEATURE_NUM_OSIDS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 8, };

static const IMG_UINT16 aui16_RGX_FEATURE_NUM_SPU_values[RGX_FEATURE_NUM_SPU_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_PBE_PER_SPU_values[RGX_FEATURE_PBE_PER_SPU_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_PHYS_BUS_WIDTH_values[RGX_FEATURE_PHYS_BUS_WIDTH_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 40, };

static const IMG_UINT16 aui16_RGX_FEATURE_POWER_ISLAND_VERSION_values[RGX_FEATURE_POWER_ISLAND_VERSION_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_RAY_TRACING_ARCH_values[RGX_FEATURE_RAY_TRACING_ARCH_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 0, };

static const IMG_UINT16 aui16_RGX_FEATURE_RENDER_TARGET_XY_MAX_values[RGX_FEATURE_RENDER_TARGET_XY_MAX_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 16384, 32768, };

static const IMG_UINT16 aui16_RGX_FEATURE_SCALABLE_TE_ARCH_values[RGX_FEATURE_SCALABLE_TE_ARCH_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_SCALABLE_VCE_values[RGX_FEATURE_SCALABLE_VCE_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, };

static const IMG_UINT16 aui16_RGX_FEATURE_SLC_BANKS_values[RGX_FEATURE_SLC_BANKS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1, 2, 4, };

static const IMG_UINT16 aui16_RGX_FEATURE_SLC_CACHE_LINE_SIZE_BITS_values[RGX_FEATURE_SLC_CACHE_LINE_SIZE_BITS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 1024, };

static const IMG_UINT16 aui16_RGX_FEATURE_SLC_SIZE_IN_KILOBYTES_values[RGX_FEATURE_SLC_SIZE_IN_KILOBYTES_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 128, 256, 512, 2048, };

static const IMG_UINT16 aui16_RGX_FEATURE_TILE_SIZE_X_values[RGX_FEATURE_TILE_SIZE_X_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 32, };

static const IMG_UINT16 aui16_RGX_FEATURE_TILE_SIZE_Y_values[RGX_FEATURE_TILE_SIZE_Y_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 32, };

static const IMG_UINT16 aui16_RGX_FEATURE_VIRTUAL_ADDRESS_SPACE_BITS_values[RGX_FEATURE_VIRTUAL_ADDRESS_SPACE_BITS_MAX_VALUE_IDX] = {(IMG_UINT16)RGX_FEATURE_VALUE_DISABLED, 40, };


/******************************************************************************
 * Table contains pointers to each feature value array for features that have
 * values.
 * Indexed using enum RGX_FEATURE_WITH_VALUE_INDEX from rgx_bvnc_defs_km.h
 *****************************************************************************/

static const IMG_UINT16 * const gaFeaturesValues[RGX_FEATURE_WITH_VALUES_MAX_IDX] = {
	aui16_RGX_FEATURE_CDM_CONTROL_STREAM_FORMAT_values,
	aui16_RGX_FEATURE_CONTEXT_SWITCH_3D_LEVEL_values,
	aui16_RGX_FEATURE_ECC_RAMS_values,
	aui16_RGX_FEATURE_FBCDC_values,
	aui16_RGX_FEATURE_FBCDC_ALGORITHM_values,
	aui16_RGX_FEATURE_FBCDC_ARCHITECTURE_values,
	aui16_RGX_FEATURE_FBC_MAX_DEFAULT_DESCRIPTORS_values,
	aui16_RGX_FEATURE_FBC_MAX_LARGE_DESCRIPTORS_values,
	aui16_RGX_FEATURE_HOST_SECURITY_VERSION_values,
	aui16_RGX_FEATURE_LAYOUT_MARS_values,
	aui16_RGX_FEATURE_MAX_TPU_PER_SPU_values,
	aui16_RGX_FEATURE_META_values,
	aui16_RGX_FEATURE_META_COREMEM_BANKS_values,
	aui16_RGX_FEATURE_META_COREMEM_SIZE_values,
	aui16_RGX_FEATURE_META_DMA_CHANNEL_COUNT_values,
	aui16_RGX_FEATURE_MMU_VERSION_values,
	aui16_RGX_FEATURE_NUM_CLUSTERS_values,
	aui16_RGX_FEATURE_NUM_ISP_IPP_PIPES_values,
	aui16_RGX_FEATURE_NUM_ISP_PER_SPU_values,
	aui16_RGX_FEATURE_NUM_MEMBUS_values,
	aui16_RGX_FEATURE_NUM_OSIDS_values,
	aui16_RGX_FEATURE_NUM_SPU_values,
	aui16_RGX_FEATURE_PBE_PER_SPU_values,
	aui16_RGX_FEATURE_PHYS_BUS_WIDTH_values,
	aui16_RGX_FEATURE_POWER_ISLAND_VERSION_values,
	aui16_RGX_FEATURE_RAY_TRACING_ARCH_values,
	aui16_RGX_FEATURE_RENDER_TARGET_XY_MAX_values,
	aui16_RGX_FEATURE_SCALABLE_TE_ARCH_values,
	aui16_RGX_FEATURE_SCALABLE_VCE_values,
	aui16_RGX_FEATURE_SLC_BANKS_values,
	aui16_RGX_FEATURE_SLC_CACHE_LINE_SIZE_BITS_values,
	aui16_RGX_FEATURE_SLC_SIZE_IN_KILOBYTES_values,
	aui16_RGX_FEATURE_TILE_SIZE_X_values,
	aui16_RGX_FEATURE_TILE_SIZE_Y_values,
	aui16_RGX_FEATURE_VIRTUAL_ADDRESS_SPACE_BITS_values,
};


/******************************************************************************
 * Array containing the lengths of the arrays containing the values.
 * Used for indexing the aui16_<FEATURE>_values defined upwards
 *****************************************************************************/


static const IMG_UINT16 gaFeaturesValuesMaxIndexes[] = {
	RGX_FEATURE_CDM_CONTROL_STREAM_FORMAT_MAX_VALUE_IDX,
	RGX_FEATURE_CONTEXT_SWITCH_3D_LEVEL_MAX_VALUE_IDX,
	RGX_FEATURE_ECC_RAMS_MAX_VALUE_IDX,
	RGX_FEATURE_FBCDC_MAX_VALUE_IDX,
	RGX_FEATURE_FBCDC_ALGORITHM_MAX_VALUE_IDX,
	RGX_FEATURE_FBCDC_ARCHITECTURE_MAX_VALUE_IDX,
	RGX_FEATURE_FBC_MAX_DEFAULT_DESCRIPTORS_MAX_VALUE_IDX,
	RGX_FEATURE_FBC_MAX_LARGE_DESCRIPTORS_MAX_VALUE_IDX,
	RGX_FEATURE_HOST_SECURITY_VERSION_MAX_VALUE_IDX,
	RGX_FEATURE_LAYOUT_MARS_MAX_VALUE_IDX,
	RGX_FEATURE_MAX_TPU_PER_SPU_MAX_VALUE_IDX,
	RGX_FEATURE_META_MAX_VALUE_IDX,
	RGX_FEATURE_META_COREMEM_BANKS_MAX_VALUE_IDX,
	RGX_FEATURE_META_COREMEM_SIZE_MAX_VALUE_IDX,
	RGX_FEATURE_META_DMA_CHANNEL_COUNT_MAX_VALUE_IDX,
	RGX_FEATURE_MMU_VERSION_MAX_VALUE_IDX,
	RGX_FEATURE_NUM_CLUSTERS_MAX_VALUE_IDX,
	RGX_FEATURE_NUM_ISP_IPP_PIPES_MAX_VALUE_IDX,
	RGX_FEATURE_NUM_ISP_PER_SPU_MAX_VALUE_IDX,
	RGX_FEATURE_NUM_MEMBUS_MAX_VALUE_IDX,
	RGX_FEATURE_NUM_OSIDS_MAX_VALUE_IDX,
	RGX_FEATURE_NUM_SPU_MAX_VALUE_IDX,
	RGX_FEATURE_PBE_PER_SPU_MAX_VALUE_IDX,
	RGX_FEATURE_PHYS_BUS_WIDTH_MAX_VALUE_IDX,
	RGX_FEATURE_POWER_ISLAND_VERSION_MAX_VALUE_IDX,
	RGX_FEATURE_RAY_TRACING_ARCH_MAX_VALUE_IDX,
	RGX_FEATURE_RENDER_TARGET_XY_MAX_MAX_VALUE_IDX,
	RGX_FEATURE_SCALABLE_TE_ARCH_MAX_VALUE_IDX,
	RGX_FEATURE_SCALABLE_VCE_MAX_VALUE_IDX,
	RGX_FEATURE_SLC_BANKS_MAX_VALUE_IDX,
	RGX_FEATURE_SLC_CACHE_LINE_SIZE_BITS_MAX_VALUE_IDX,
	RGX_FEATURE_SLC_SIZE_IN_KILOBYTES_MAX_VALUE_IDX,
	RGX_FEATURE_TILE_SIZE_X_MAX_VALUE_IDX,
	RGX_FEATURE_TILE_SIZE_Y_MAX_VALUE_IDX,
	RGX_FEATURE_VIRTUAL_ADDRESS_SPACE_BITS_MAX_VALUE_IDX,
};


/******************************************************************************
 * Bit-positions for features with values
 *****************************************************************************/

static const IMG_UINT16 aui16FeaturesWithValuesBitPositions[] = {
	(0U), /* RGX_FEATURE_CDM_CONTROL_STREAM_FORMAT_POS */
	(2U), /* RGX_FEATURE_CONTEXT_SWITCH_3D_LEVEL_POS */
	(4U), /* RGX_FEATURE_ECC_RAMS_POS */
	(6U), /* RGX_FEATURE_FBCDC_POS */
	(8U), /* RGX_FEATURE_FBCDC_ALGORITHM_POS */
	(10U), /* RGX_FEATURE_FBCDC_ARCHITECTURE_POS */
	(12U), /* RGX_FEATURE_FBC_MAX_DEFAULT_DESCRIPTORS_POS */
	(14U), /* RGX_FEATURE_FBC_MAX_LARGE_DESCRIPTORS_POS */
	(16U), /* RGX_FEATURE_HOST_SECURITY_VERSION_POS */
	(18U), /* RGX_FEATURE_LAYOUT_MARS_POS */
	(20U), /* RGX_FEATURE_MAX_TPU_PER_SPU_POS */
	(22U), /* RGX_FEATURE_META_POS */
	(24U), /* RGX_FEATURE_META_COREMEM_BANKS_POS */
	(26U), /* RGX_FEATURE_META_COREMEM_SIZE_POS */
	(28U), /* RGX_FEATURE_META_DMA_CHANNEL_COUNT_POS */
	(30U), /* RGX_FEATURE_MMU_VERSION_POS */
	(32U), /* RGX_FEATURE_NUM_CLUSTERS_POS */
	(35U), /* RGX_FEATURE_NUM_ISP_IPP_PIPES_POS */
	(38U), /* RGX_FEATURE_NUM_ISP_PER_SPU_POS */
	(40U), /* RGX_FEATURE_NUM_MEMBUS_POS */
	(42U), /* RGX_FEATURE_NUM_OSIDS_POS */
	(44U), /* RGX_FEATURE_NUM_SPU_POS */
	(46U), /* RGX_FEATURE_PBE_PER_SPU_POS */
	(48U), /* RGX_FEATURE_PHYS_BUS_WIDTH_POS */
	(50U), /* RGX_FEATURE_POWER_ISLAND_VERSION_POS */
	(52U), /* RGX_FEATURE_RAY_TRACING_ARCH_POS */
	(54U), /* RGX_FEATURE_RENDER_TARGET_XY_MAX_POS */
	(56U), /* RGX_FEATURE_SCALABLE_TE_ARCH_POS */
	(58U), /* RGX_FEATURE_SCALABLE_VCE_POS */
	(60U), /* RGX_FEATURE_SLC_BANKS_POS */
	(64U), /* RGX_FEATURE_SLC_CACHE_LINE_SIZE_BITS_POS */
	(66U), /* RGX_FEATURE_SLC_SIZE_IN_KILOBYTES_POS */
	(69U), /* RGX_FEATURE_TILE_SIZE_X_POS */
	(71U), /* RGX_FEATURE_TILE_SIZE_Y_POS */
	(73U), /* RGX_FEATURE_VIRTUAL_ADDRESS_SPACE_BITS_POS */
};


/******************************************************************************
 * Bit-masks for features with values
 *****************************************************************************/

static const IMG_UINT64 aui64FeaturesWithValuesBitMasks[] = {
	(IMG_UINT64_C(0x0000000000000003)), /* RGX_FEATURE_CDM_CONTROL_STREAM_FORMAT_BIT_MASK */
	(IMG_UINT64_C(0x000000000000000C)), /* RGX_FEATURE_CONTEXT_SWITCH_3D_LEVEL_BIT_MASK */
	(IMG_UINT64_C(0x0000000000000030)), /* RGX_FEATURE_ECC_RAMS_BIT_MASK */
	(IMG_UINT64_C(0x00000000000000C0)), /* RGX_FEATURE_FBCDC_BIT_MASK */
	(IMG_UINT64_C(0x0000000000000300)), /* RGX_FEATURE_FBCDC_ALGORITHM_BIT_MASK */
	(IMG_UINT64_C(0x0000000000000C00)), /* RGX_FEATURE_FBCDC_ARCHITECTURE_BIT_MASK */
	(IMG_UINT64_C(0x0000000000003000)), /* RGX_FEATURE_FBC_MAX_DEFAULT_DESCRIPTORS_BIT_MASK */
	(IMG_UINT64_C(0x000000000000C000)), /* RGX_FEATURE_FBC_MAX_LARGE_DESCRIPTORS_BIT_MASK */
	(IMG_UINT64_C(0x0000000000030000)), /* RGX_FEATURE_HOST_SECURITY_VERSION_BIT_MASK */
	(IMG_UINT64_C(0x00000000000C0000)), /* RGX_FEATURE_LAYOUT_MARS_BIT_MASK */
	(IMG_UINT64_C(0x0000000000300000)), /* RGX_FEATURE_MAX_TPU_PER_SPU_BIT_MASK */
	(IMG_UINT64_C(0x0000000000C00000)), /* RGX_FEATURE_META_BIT_MASK */
	(IMG_UINT64_C(0x0000000003000000)), /* RGX_FEATURE_META_COREMEM_BANKS_BIT_MASK */
	(IMG_UINT64_C(0x000000000C000000)), /* RGX_FEATURE_META_COREMEM_SIZE_BIT_MASK */
	(IMG_UINT64_C(0x0000000030000000)), /* RGX_FEATURE_META_DMA_CHANNEL_COUNT_BIT_MASK */
	(IMG_UINT64_C(0x00000000C0000000)), /* RGX_FEATURE_MMU_VERSION_BIT_MASK */
	(IMG_UINT64_C(0x0000000700000000)), /* RGX_FEATURE_NUM_CLUSTERS_BIT_MASK */
	(IMG_UINT64_C(0x0000003800000000)), /* RGX_FEATURE_NUM_ISP_IPP_PIPES_BIT_MASK */
	(IMG_UINT64_C(0x000000C000000000)), /* RGX_FEATURE_NUM_ISP_PER_SPU_BIT_MASK */
	(IMG_UINT64_C(0x0000030000000000)), /* RGX_FEATURE_NUM_MEMBUS_BIT_MASK */
	(IMG_UINT64_C(0x00000C0000000000)), /* RGX_FEATURE_NUM_OSIDS_BIT_MASK */
	(IMG_UINT64_C(0x0000300000000000)), /* RGX_FEATURE_NUM_SPU_BIT_MASK */
	(IMG_UINT64_C(0x0000C00000000000)), /* RGX_FEATURE_PBE_PER_SPU_BIT_MASK */
	(IMG_UINT64_C(0x0003000000000000)), /* RGX_FEATURE_PHYS_BUS_WIDTH_BIT_MASK */
	(IMG_UINT64_C(0x000C000000000000)), /* RGX_FEATURE_POWER_ISLAND_VERSION_BIT_MASK */
	(IMG_UINT64_C(0x0030000000000000)), /* RGX_FEATURE_RAY_TRACING_ARCH_BIT_MASK */
	(IMG_UINT64_C(0x00C0000000000000)), /* RGX_FEATURE_RENDER_TARGET_XY_MAX_BIT_MASK */
	(IMG_UINT64_C(0x0300000000000000)), /* RGX_FEATURE_SCALABLE_TE_ARCH_BIT_MASK */
	(IMG_UINT64_C(0x0C00000000000000)), /* RGX_FEATURE_SCALABLE_VCE_BIT_MASK */
	(IMG_UINT64_C(0x7000000000000000)), /* RGX_FEATURE_SLC_BANKS_BIT_MASK */
	(IMG_UINT64_C(0x0000000000000003)), /* RGX_FEATURE_SLC_CACHE_LINE_SIZE_BITS_BIT_MASK */
	(IMG_UINT64_C(0x000000000000001C)), /* RGX_FEATURE_SLC_SIZE_IN_KILOBYTES_BIT_MASK */
	(IMG_UINT64_C(0x0000000000000060)), /* RGX_FEATURE_TILE_SIZE_X_BIT_MASK */
	(IMG_UINT64_C(0x0000000000000180)), /* RGX_FEATURE_TILE_SIZE_Y_BIT_MASK */
	(IMG_UINT64_C(0x0000000000000600)), /* RGX_FEATURE_VIRTUAL_ADDRESS_SPACE_BITS_BIT_MASK */
};


/******************************************************************************
 * Table mapping bitmasks for features and features with values
 *****************************************************************************/


static const IMG_UINT64 gaFeatures[][4]=
{
	{ IMG_UINT64_C(0x001b000000fe0002), IMG_UINT64_C(0x0276bcf0f6b177ca), IMG_UINT64_C(0x1555958a65555555), IMG_UINT64_C(0x00000000000002a5) },	/* 27.0.254.2 */
	{ IMG_UINT64_C(0x001e000001980065), IMG_UINT64_C(0x027efef0ffb3ffcb), IMG_UINT64_C(0x15555549a5555559), IMG_UINT64_C(0x00000000000002a5) },	/* 30.0.408.101 */
	{ IMG_UINT64_C(0x001e000003300014), IMG_UINT64_C(0x027efef0ffb3ffcb), IMG_UINT64_C(0x25555592a5655559), IMG_UINT64_C(0x00000000000002a9) },	/* 30.0.816.20 */
	{ IMG_UINT64_C(0x001e000006600001), IMG_UINT64_C(0x027efef0ffb3ffcb), IMG_UINT64_C(0x3a55669ba5655559), IMG_UINT64_C(0x00000000000002ad) },	/* 30.0.1632.1 */
	{ IMG_UINT64_C(0x0023000001980017), IMG_UINT64_C(0x027efef0ffbbffcf), IMG_UINT64_C(0x15995549a555a559), IMG_UINT64_C(0x00000000000002a5) },	/* 35.0.408.23 */
	{ IMG_UINT64_C(0x0023000001980021), IMG_UINT64_C(0x03fffef4ffbbffcf), IMG_UINT64_C(0x159955499515a569), IMG_UINT64_C(0x00000000000002a5) },	/* 35.0.408.33 */
	{ IMG_UINT64_C(0x0023000001980022), IMG_UINT64_C(0x03fffef4ffbbffcf), IMG_UINT64_C(0x159955499515a569), IMG_UINT64_C(0x00000000000002a5) },	/* 35.0.408.34 */
	{ IMG_UINT64_C(0x0023000001980065), IMG_UINT64_C(0x027efef0ffb3ffcb), IMG_UINT64_C(0x15555549a5555559), IMG_UINT64_C(0x00000000000002a5) },	/* 35.0.408.101 */
	{ IMG_UINT64_C(0x0023000006600015), IMG_UINT64_C(0x027efef0ffbbffcf), IMG_UINT64_C(0x3a99669ba565a559), IMG_UINT64_C(0x00000000000002ad) },	/* 35.0.1632.21 */
	{ IMG_UINT64_C(0x0023000006600017), IMG_UINT64_C(0x027efef0ffbbffcf), IMG_UINT64_C(0x3a99669ba565a559), IMG_UINT64_C(0x00000000000002ad) },	/* 35.0.1632.23 */
	{ IMG_UINT64_C(0x0023000006600022), IMG_UINT64_C(0x03fffef4ffbbffcf), IMG_UINT64_C(0x3a99669b9525a569), IMG_UINT64_C(0x00000000000002b1) },	/* 35.0.1632.34 */
};

/******************************************************************************
 * Table mapping bitmasks for ERNs/BRNs
 *****************************************************************************/


static const IMG_UINT64 gaErnsBrns[][2]=
{
	{ IMG_UINT64_C(0x001b000500fe0002), IMG_UINT64_C(0x0000000000000011) },	/* 27.5.254.2 */
	{ IMG_UINT64_C(0x001b000700fe0002), IMG_UINT64_C(0x0000000000000001) },	/* 27.7.254.2 */
	{ IMG_UINT64_C(0x001b000800fe0002), IMG_UINT64_C(0x0000000000000001) },	/* 27.8.254.2 */
	{ IMG_UINT64_C(0x001e000301980065), IMG_UINT64_C(0x0000000000000025) },	/* 30.3.408.101 */
	{ IMG_UINT64_C(0x001e000303300014), IMG_UINT64_C(0x0000000000000025) },	/* 30.3.816.20 */
	{ IMG_UINT64_C(0x001e000506600001), IMG_UINT64_C(0x0000000000000025) },	/* 30.5.1632.1 */
	{ IMG_UINT64_C(0x0023000201980021), IMG_UINT64_C(0x0000000000000025) },	/* 35.2.408.33 */
	{ IMG_UINT64_C(0x0023000201980022), IMG_UINT64_C(0x0000000000000025) },	/* 35.2.408.34 */
	{ IMG_UINT64_C(0x0023000206600015), IMG_UINT64_C(0x000000000000002d) },	/* 35.2.1632.21 */
	{ IMG_UINT64_C(0x0023000206600017), IMG_UINT64_C(0x000000000000002d) },	/* 35.2.1632.23 */
	{ IMG_UINT64_C(0x0023000206600022), IMG_UINT64_C(0x0000000000000025) },	/* 35.2.1632.34 */
	{ IMG_UINT64_C(0x0023000301980065), IMG_UINT64_C(0x0000000000000025) },	/* 35.3.408.101 */
	{ IMG_UINT64_C(0x0023000306600017), IMG_UINT64_C(0x0000000000000025) },	/* 35.3.1632.23 */
	{ IMG_UINT64_C(0x0023000406600017), IMG_UINT64_C(0x0000000000000025) },	/* 35.4.1632.23 */
	{ IMG_UINT64_C(0x0023000501980017), IMG_UINT64_C(0x0000000000000025) },	/* 35.5.408.23 */
};

#if defined(DEBUG)

#define	FEATURE_NO_VALUES_NAMES_MAX_IDX	(58)

static const IMG_CHAR * const gaszFeaturesNoValuesNames[FEATURE_NO_VALUES_NAMES_MAX_IDX] =
{
	"ALBIORIX_TOP_INFRASTRUCTURE",
	"AXI_ACE",
	"BARREX_TOP_INFRASTRUCTURE",
	"BINDLESS_IMAGE_AND_TEXTURE_STATE",
	"CATURIX_TOP_INFRASTRUCTURE",
	"CATURIX_XTP_TOP_INFRASTRUCTURE",
	"CLUSTER_GROUPING",
	"COMPUTE",
	"COMPUTE_MORTON_CAPABLE",
	"COMPUTE_OVERLAP",
	"COMPUTE_OVERLAP_WITH_BARRIERS",
	"COMPUTE_SLC_MMU_AUTO_CACHE_OPS",
	"COREID_PER_OS",
	"DUST_POWER_ISLAND_S7",
	"FASTRENDER_DM",
	"FRAG_SLC_MMU_AUTO_CACHE_OPS",
	"GEOMETRY_BIF_ARBITER",
	"GEOM_SLC_MMU_AUTO_CACHE_OPS",
	"GPU_CPU_COHERENCY",
	"GPU_MULTICORE_SUPPORT",
	"GPU_VIRTUALISATION",
	"GS_RTA_SUPPORT",
	"HYPERVISOR_MMU",
	"META_DMA",
	"META_REGISTER_UNPACKED_ACCESSES",
	"PBE_CHECKSUM_2D",
	"PBVNC_COREID_REG",
	"PDS_INSTRUCTION_CACHE_AUTO_INVALIDATE",
	"PDS_TEMPSIZE8",
	"PERFBUS",
	"PERF_COUNTER_BATCH",
	"PM_BYTE_ALIGNED_BASE_ADDRESSES",
	"PM_MMUSTACK",
	"PM_MMU_VFP",
	"RISCV_FW_PROCESSOR",
	"RT_RAC_PER_SPU",
	"S7_CACHE_HIERARCHY",
	"S7_TOP_INFRASTRUCTURE",
	"SCALABLE_VDM_GPP",
	"SIGNAL_SNOOPING",
	"SLC_FAULT_ACCESS_ADDR_PHYS",
	"SLC_SIZE_ADJUSTMENT",
	"SLC_VIVT",
	"SOC_TIMER",
	"SYS_BUS_SECURE_RESET",
	"TDM_PDS_CHECKSUM",
	"TDM_SLC_MMU_AUTO_CACHE_OPS",
	"TESSELLATION",
	"TILE_REGION_PROTECTION",
	"TPU_CEM_DATAMASTER_GLOBAL_REGISTERS",
	"TPU_DM_GLOBAL_REGISTERS",
	"USC_INSTRUCTION_CACHE_AUTO_INVALIDATE",
	"USC_TIMER",
	"VDM_DRAWINDIRECT",
	"VDM_OBJECT_LEVEL_LLS",
	"WATCHDOG_TIMER",
	"WORKGROUP_PROTECTION",
	"ZLS_CHECKSUM",
};

#define	ERNSBRNS_IDS_MAX_IDX	(7)

static const IMG_UINT32 gaui64ErnsBrnsIDs[ERNSBRNS_IDS_MAX_IDX] =
{
	65104,
	66927,
	69700,
	71157,
	71422,
	71960,
	72143,
};

#endif /* defined(DEBUG) */
#endif /* RGX_BVNC_TABLE_KM_H */
