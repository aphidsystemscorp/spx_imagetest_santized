########################################################################### ###
#@File          nullws_drm.mk
#@Title         Specify NullWS components
#@Copyright     Copyright (c) Imagination Technologies Ltd. All Rights Reserved
#               Copyright (c) 2016 Renesas Electronics Corporation
#@Description   For NullWS driver builds, pull in NullWS related components.
#@License       Strictly Confidential.
### ###########################################################################

LWS_COMPONENTS += lws 
COMPONENTS += dlc_server dlc_client null_ws_drm

ifeq ($(PVR_REMOTE),1)
 COMPONENTS += null_remote null_none
endif

ifneq ($(GBM_BACKEND),)
 COMPONENTS += gbm
endif
