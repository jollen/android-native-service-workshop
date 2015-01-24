LOCAL_PATH:= $(call my-dir)

#### build libledservice.so
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	LedService.cpp

LOCAL_MODULE := libledservice

LOCAL_SHARED_LIBRARIES += \
	libutils \
	libcutils \
	libhardware \
        liblog \
        libbinder \
        libui \
        libgui

LOCAL_C_INCLUDES += \
	frameworks/base/include \
	device/mokoid/hardware/modules/include

LOCAL_MODULE_TAGS := eng

LOCAL_PRELINK_MODULE := false

include $(BUILD_SHARED_LIBRARY)

