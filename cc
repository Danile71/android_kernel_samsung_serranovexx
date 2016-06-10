#!/bin/bash
export ARCH=arm
export CROSS_COMPILE="/home/danil_e71/android-toolchain-eabi-4.9/bin/arm-eabi-"

#mkdir out

make -C $(pwd) O=out msm8916_sec_defconfig VARIANT_DEFCONFIG=msm8916_sec_serranovelte_eur_defconfig SELINUX_DEFCONFIG=selinux_defconfig
make -C $(pwd) O=out




