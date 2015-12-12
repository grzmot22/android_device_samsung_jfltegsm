#!/bin/sh

set -e

export DEVICE=jfltegsm
export VENDOR=samsung
./../jf-common/extract-files.sh $@
