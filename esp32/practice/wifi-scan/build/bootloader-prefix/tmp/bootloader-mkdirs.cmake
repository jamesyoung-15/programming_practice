# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/opt/esp-idf/components/bootloader/subproject"
  "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader"
  "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader-prefix"
  "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader-prefix/tmp"
  "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader-prefix/src/bootloader-stamp"
  "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader-prefix/src"
  "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/jamesyoung/Documents/Personal_Projects/programming/programming_practice/esp32/practice/wifi-scan/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
