CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(OPTICAL_TEXT_RECOGNITION)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED YES)


cmake_policy(SET CMP0167 NEW)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
endif()

###################################################DIZINLERI AYARLAMA
SET(DIZIN_SRC ${CMAKE_SOURCE_DIR}/src)
SET(DIZIN_INCLUDE ${CMAKE_SOURCE_DIR}/include)

SET(
    PROGRAM_SRC 
    ${DIZIN_SRC}/main.cpp

    ${DIZIN_SRC}/gui/window.cpp
    ${DIZIN_SRC}/gui/mainWindow.cpp
    
    ${DIZIN_SRC}/file_read/manuelFileOperation.cpp
    ${DIZIN_SRC}/file_read/imageReader.cpp

    ${DIZIN_SRC}/point_operation/brightnessOperation.cpp
    ${DIZIN_SRC}/point_operation/thresholdOperation.cpp
    ${DIZIN_SRC}/point_operation/grayscaleOperation.cpp

    ${DIZIN_SRC}/filter_operation/medianFilter.cpp

)

SET(
    PROGRAM_INCLUDE
    ${DIZIN_INCLUDE}/image_manuel_header/manuelFileOperation.hpp
    ${DIZIN_INCLUDE}/image_manuel_header/bmpHeader.hpp
    
    ${DIZIN_INCLUDE}/window.hpp
    ${DIZIN_INCLUDE}/mainWindow.hpp

    ${DIZIN_INCLUDE}/imageReader.hpp

    #nokta operasyonlari goruntu uzerinde
    ${DIZIN_INCLUDE}/point_operation/pointOperation.hpp 
    ${DIZIN_INCLUDE}/point_operation/brightnessOperation.hpp
    ${DIZIN_INCLUDE}/point_operation/thresholdOperation.hpp
    ${DIZIN_INCLUDE}/point_operation/grayscaleOperation.hpp
    
    #filtre operasyonlari
    ${DIZIN_INCLUDE}/filter_operation/medianFilter.hpp


    ${DIZIN_INCLUDE}/crossPlatform.hpp
    ${DIZIN_INCLUDE}/debug.hpp
    ${DIZIN_INCLUDE}/enums.hpp

    
    
    
    )
###################################################DIZINLERI AYARLAMA




if(WIN32)
    #wxWidgets
    set(wxWidgets_ROOT_DIR "./utils-WIN32/wxWidgetsWIN32")
    set(wxWidgets_INCLUDE_DIRS 
        "${wxWidgets_ROOT_DIR}/include/wx-3.3/" 
        "${wxWidgets_ROOT_DIR}/lib/wx/include/x86_64-w64-mingw32-msw-unicode-3.3"
    )
    
    set(wxWidgets_LIBRARY_DIRS "${wxWidgets_ROOT_DIR}/lib")
	set(wxWidgets_LIBRARIES
		wx_baseu-3.3-x86_64-w64-mingw32
		wx_mswu_propgrid-3.3-x86_64-w64-mingw32
		wx_baseu_net-3.3-x86_64-w64-mingw32
		wx_mswu_qa-3.3-x86_64-w64-mingw32
		wx_baseu_xml-3.3-x86_64-w64-mingw32
		wx_mswu_ribbon-3.3-x86_64-w64-mingw32
		wx_mswu_adv-3.3-x86_64-w64-mingw32
		wx_mswu_richtext-3.3-x86_64-w64-mingw32
		wx_mswu_aui-3.3-x86_64-w64-mingw32
		wx_mswu_stc-3.3-x86_64-w64-mingw32
		wx_mswu_core-3.3-x86_64-w64-mingw32
		wx_mswu_webview-3.3-x86_64-w64-mingw32
		wx_mswu_gl-3.3-x86_64-w64-mingw32
		wx_mswu_xrc-3.3-x86_64-w64-mingw32
		wx_mswu_html-3.3-x86_64-w64-mingw32
		wx_mswu_media-3.3-x86_64-w64-mingw32
	)

    include_directories(${wxWidgets_INCLUDE_DIRS})
    link_directories(${wxWidgets_LIBRARY_DIRS})
    
elseif(UNIX)
    find_package(wxWidgets REQUIRED COMPONENTS core base)
    include(${wxWidgets_USE_FILE})
endif()




if(WIN32)
    INCLUDE_DIRECTORIES(
        ${wxWidgets_INCLUDE_DIRS}
        )
    
    add_executable(
        ${PROJECT_NAME} WIN32
        ${PROGRAM_SRC}
        )
    
    target_link_libraries(
        ${PROJECT_NAME}
        ${wxWidgets_LIBRARIES}
        )



elseif(UNIX)
    INCLUDE_DIRECTORIES(
        ${PROGRAM_INCLUDE} 
        ${wxWidgets_INCLUDE_DIRS} 
        )
    
    add_executable(
        ${PROJECT_NAME} 
        ${PROGRAM_SRC}
        )

    target_link_libraries(
        ${PROJECT_NAME}
        ${wxWidgets_LIBRARIES}
          )
endif()