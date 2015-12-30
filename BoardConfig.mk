# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

LOCAL_PATH := device/samsung/jfltegsm

# inherit from common jf
include device/samsung/jf-common/BoardConfigCommon.mk

# Assert
TARGET_OTA_ASSERT_DEVICE := jflteatt,jfltecan,jfltetmo,jfltexx,jfltezm,jgedlte,jflte,i9505,GT-I9505,i9505g,GT-I9505G,GT-I9507,GT-I9508

# Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := $(LOCAL_PATH)/releasetools

# Vendor Init
TARGET_UNIFIED_DEVICE := true
TARGET_INIT_VENDOR_LIB := libinit_jfltegsm
TARGET_LIBINIT_DEFINES_FILE := $(LOCAL_PATH)/init/init_jfltegsm.cpp
