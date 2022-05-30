cmake_minimum_required(VERSION 3.16)

project(TamKL VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED LinguistTools)

qt_add_executable(appTamKL
    base/I18n.h
    base/I18n.cpp
    main.cpp
)

qt_add_qml_module(appTamKL
    URI TamKL
    VERSION 1.0
    QML_FILES main.qml 
)

qt_add_lupdate ( appTamKL
TS_FILES TamKL_en.ts TamKL_zh_CN.ts )
qt_add_lrelease ( appTamKL
    TS_FILES TamKL_en.ts TamKL_zh_CN.ts
    QM_FILES_OUTPUT_VARIABLE qm_files )
qt_add_resources ( appTamKL "translations"
    PREFIX "/i18n"
    BASE "${CMAKE_CURRENT_BINARY_DIR}"
    FILES "${qm_files}" )


set_target_properties(appTamKL PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER www.tamkl.cn
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appTamKL
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appTamKL
    PRIVATE Qt6::Quick)
