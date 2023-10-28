add_library(Dynamic_Type STATIC dynamic_type.cpp
                                ${PROJECT_SOURCE_DIR}/include/dynamic_type.hpp)
target_include_directories(Dynamic_Type PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_compile_definitions(Dynamic_Type PUBLIC dataBase__type_entry_PUBLIC)
target_compile_definitions(Dynamic_Type PRIVATE dataBase__type_entry_PRIVATE)

target_compile_features(Dynamic_Type PRIVATE cxx_std_20)
target_compile_features(Dynamic_Type PUBLIC cxx_std_17)
target_compile_options(Dynamic_Type PRIVATE)
