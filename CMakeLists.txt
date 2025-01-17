cmake_minimum_required(VERSION 3.20)

project(test CXX)

# デフォルトのビルドタイプを指定
if(NOT CMAKE_BUILD_TYPE)        
    set(CMAKE_BUILD_TYPE Debug)
endif()
message(STATUS "CMAKE_BUILD_TYPE" = ${CMAKE_BUILD_TYPE})

set(SOURCE_FILES
    src/test.cpp
)

# 実行ファイルの作成
add_executable(test ${SOURCE_FILES})


# ---------------------------------------
# Set ConvexHull DLL
# ---------------------------------------

# DLLファイルのヘッダーファイルとインポートライブラリのパスを設定
set(CONVEXHULL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/ConvexHull/include)

# Debug/ReleaseでQHULL_LIB_DIRを切り替える。
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in Debug mode")
    set(CONVEXHULL_LIB_DIR ${PROJECT_SOURCE_DIR}/ConvexHull/lib)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Building in Release mode")
    set(CONVEXHULL_LIB_DIR ${PROJECT_SOURCE_DIR}/ConvexHull/lib)
endif()

# ヘッダーファイルのディレクトリをインクルードパスに追加
target_include_directories(test PUBLIC ${CONVEXHULL_INCLUDE_DIR})

target_link_libraries(test ${CONVEXHULL_LIB_DIR}/testlib$<$<CONFIG:Debug>:_d>.lib)

# IDE でヘッダーファイルを表示させる
target_sources(test PRIVATE ${HEADER_FILES})


# # ---------------------------------------
# # Define install
# # ---------------------------------------
