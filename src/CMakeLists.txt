file(GLOB_RECURSE SOURCES "*.c" "*.cpp")

idf_component_register(SRCS "${SOURCES}"
                    INCLUDE_DIRS "../include"
                    PRIV_REQUIRES esp_adc
                    REQUIRES driver freertos)