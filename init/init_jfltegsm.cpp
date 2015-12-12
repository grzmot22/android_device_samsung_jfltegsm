/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties();

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "I337M")) {
        /* jfltecan */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltevl/jfltecan:4.2.2/JDQ39/I337MVLUAMDJ:user/release-keys");
        property_set("ro.build.description", "jfltevl-user 4.2.2 JDQ39 I337MVLUAMDJ release-keys");
        property_set("ro.product.model", "SGH-I337M");
        property_set("ro.product.device", "jfltecan");
    } else if (strstr(bootloader, "I337")) {
        /* jflteatt */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jflteuc/jflteatt:5.0.1/LRX22C/I337UCUGOC3:user/release-keys");
        property_set("ro.build.description", "jflteuc-user 5.0.1 LRX22C I337UCUGOC3 release-keys");
	property_set("ro.product.model", "SGH-I337");
	property_set("ro.product.device", "jflteatt");
    } else if (strstr(bootloader, "M919")) {
        /* jfltetmo */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltetmo/jfltetmo:4.4.4/KTU84P/M919UVUFNK2:user/release-keys");
        property_set("ro.build.description", "jfltetmo-user 4.4.4 KTU84P M919UVUFNK2 release-keys");
        property_set("ro.product.model", "SGH-M919");
        property_set("ro.product.device", "jfltetmo");
    } else if (strstr(bootloader, "I9505G")) {
        /* jgedlte */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jgedlteue/jgedlte:5.1/LMY47O.S008/150802:user/release-keys");
        property_set("ro.build.description", "jgedlteue-user 5.1 LMY47O.S008 150802 release-keys");
        property_set("ro.product.model", "GT-I9505G");
        property_set("ro.product.device", "jgedlte");
        property_set("ril.subscription.types", "NV,RUIM");
        property_set("DEVICE_PROVISIONED", "1");
    } else if (strstr(bootloader, "I9505")) {
        /* jfltexx */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltexx/jflte:5.0.1/LRX22C/I9505XXUHOB7:user/release-keys");
        property_set("ro.build.description", "jfltexx-user 5.0.1 LRX22C I9505XXUHOB7 release-keys");
        property_set("ro.product.model", "GT-I9505");
        property_set("ro.product.device", "jfltexx");
    } else if (strstr(bootloader, "I9507")) {
        /* jftddxx */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jftddxx/jftdd:4.3/JSS15J/I9507XXUENB5:user/release-keys");
        property_set("ro.build.description", "jftddxx-user 4.3 JSS15J I9507XXUENB5 release-keys");
        property_set("ro.product.model", "GT-I9507");
        property_set("ro.product.device", "jftddxx");
    } else if (strstr(bootloader, "I9508")) {
        /* jfltezm */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jfltezm/jflte:4.2.2/JDQ39/I9508ZMUAMG1:user/release-keys");
        property_set("ro.build.description", "jfltezm-user 4.2.2 JDQ39 I9508ZMUAMG1 release-keys");
        property_set("ro.product.model", "GT-I9508");
        property_set("ro.product.device", "jfltezm");
    } else if (strstr(bootloader, "I9295")) {
        /* jactivelte */
        gsm_properties();
        property_set("ro.build.fingerprint", "samsung/jactivelte/jactivelte:4.4.2/KTU84Q/I9295XXUCNE5:user/release-keys");
        property_set("ro.build.description", "jactivelte-user 4.4.4 KTU84Q I9295XXUCNE5 release-keys");
        property_set("ro.product.model", "GT-I9295");
        property_set("ro.product.device", "jactivelte");
    }

    property_get("ro.product.device", device);
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, device);

}

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}
