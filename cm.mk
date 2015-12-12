$(call inherit-product, device/samsung/jfltegsm/full_jfltegsm.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit some common JDC stuff.
$(call inherit-product, vendor/jdc/config/common.mk)

#CM (V4A) Audio Mod		
CM_AUDIO_MOD := viper

PRODUCT_NAME := cm_jfltegsm
