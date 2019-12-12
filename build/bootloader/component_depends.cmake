# Component requirements generated by expand_requirements.cmake

set(BUILD_COMPONENTS soc;esp32;log;bootloader;spi_flash;micro-ecc;efuse;bootloader_support;main;esptool_py;partition_table)
set(BUILD_COMPONENT_PATHS C:/Users/Sagarr/Desktop/esp-idf/components/soc;C:/Users/Sagarr/Desktop/esp-idf/components/esp32;C:/Users/Sagarr/Desktop/esp-idf/components/log;C:/Users/Sagarr/Desktop/esp-idf/components/bootloader;C:/Users/Sagarr/Desktop/esp-idf/components/spi_flash;C:/Users/Sagarr/Desktop/esp-idf/components/micro-ecc;C:/Users/Sagarr/Desktop/esp-idf/components/efuse;C:/Users/Sagarr/Desktop/esp-idf/components/bootloader_support;C:/Users/Sagarr/Desktop/esp-idf/components/bootloader/subproject/main;C:/Users/Sagarr/Desktop/esp-idf/components/esptool_py;C:/Users/Sagarr/Desktop/esp-idf/components/partition_table)
set(BUILD_TEST_COMPONENTS )
set(BUILD_TEST_COMPONENT_PATHS )

# get_component_requirements: Generated function to read the dependencies of a given component.
#
# Parameters:
# - component: Name of component
# - var_requires: output variable name. Set to recursively expanded COMPONENT_REQUIRES 
#   for this component.
# - var_private_requires: output variable name. Set to recursively expanded COMPONENT_PRIV_REQUIRES 
#   for this component.
#
# Throws a fatal error if 'componeont' is not found (indicates a build system problem).
#
function(get_component_requirements component var_requires var_private_requires)
  if("${component}" STREQUAL "soc")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esp32")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "log")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "bootloader")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "spi_flash")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "bootloader_support" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "micro-ecc")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "efuse")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "bootloader_support" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "bootloader_support")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "spi_flash;micro-ecc;efuse" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "main")
    set(${var_requires} "bootloader;bootloader_support" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "esptool_py")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  if("${component}" STREQUAL "partition_table")
    set(${var_requires} "" PARENT_SCOPE)
    set(${var_private_requires} "" PARENT_SCOPE)
    return()
  endif()
  message(FATAL_ERROR "Component not found: ${component}")
endfunction()