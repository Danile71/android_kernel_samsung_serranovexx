#!/bin/bash
export ARCH=arm
export CROSS_COMPILE="/home/danil_e71/android-toolchain-eabi-4.9/bin/arm-eabi-"

git rev-parse --abbrev-ref HEAD > $(pwd)/.tmpfile

file=$(pwd)/.tmpfile
while read line;do
  out="out-$line";
done < $file




mkdir $(pwd)/$out
mkdir $(pwd)/$out/boot/
mkdir $(pwd)/$out/boot/modules/


make -C $(pwd) O=$out msm8916_sec_defconfig VARIANT_DEFCONFIG=msm8916_sec_serranovelte_eur_defconfig SELINUX_DEFCONFIG=selinux_defconfig
make -j4 -C $(pwd) O=$out



cp $(pwd)/$out/arch/arm/boot/zImage $(pwd)/$out/boot/boot.img-kernel

$(pwd)/dtbTool -2 -o ./$out/boot/boot.img-dt -s 2048 -p ./$out/scripts/dtc/ ./$out/arch/arm/boot/dts/ -v

find $(pwd)/$out/drivers/   -name "*.ko" -exec cp {} $(pwd)/$out/boot/modules/  \;

cp $(pwd)/$out/boot/boot.img-kernel /home/danil_e71/Документы/android/repack/CarlivImageKitchen/boot/
cp $(pwd)/$out/boot/boot.img-dt /home/danil_e71/Документы/android/repack/CarlivImageKitchen/boot/
echo "Finish"


