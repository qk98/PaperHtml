cmake_minimum_required(VERSION 3.12)
project(PaperHtmlFormat)

set(CMAKE_CXX_STANDARD 14)

include(/home/vradmin/workspace/VR_Project/InnoRealTools/cmake/innoreal_qt.cmake)

add_executable(generate_html GenerateHtml.cpp)

target_link_libraries(generate_html
    GL
    Qt5::Widgets
    Qt5::Core
    )

add_executable(convert_to_html ConvertPdfToHtml.cpp)

target_link_libraries(convert_to_html
    GL
    Qt5::Widgets
    Qt5::Core
    )