cmake_minimum_required(VERSION 3.20)

project(test CXX)

set(SOURCE_FILES
    src/test.cpp
)

# 実行ファイルの作成
add_executable(test ${SOURCE_FILES})


# ---------------------------------------
# Set Qhull
# ---------------------------------------

# DLLファイルのヘッダーファイルとインポートライブラリのパスを設定
# 下記のように、自動で必要なパッケージを探す方法もあるが、見つけてくれなかった。（Find<PackageName>.cmakeが存在しない？）
# find_package(Qhull REQUIRED)
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
# include_directoriesはターゲットの指定ができないため非推奨。
# include_directories(${QHULL_INCLUDE_DIR})
target_include_directories(test PUBLIC ${CONVEXHULL_INCLUDE_DIR})

# target_link_libraries(test ${CONVEXHULL_LIB_DIR}/testdll.lib )
target_link_libraries(test ${PROJECT_SOURCE_DIR}/ConvexHull/lib/testdll.lib )

# # Qhull ライブラリをリンク
# # ${QHULL_LIB_DIR}/qhullstatic_r.libではなく、{QHULL_LIB_DIR}/qhullstatic.libを利用するとnon-reentrantエラーが発生する。
# # Debug/ReleaseでQHULL_LIB_DIRを切り替える。
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     target_link_libraries(convex ${QHULL_LIB_DIR}/qhull_rd.lib ${QHULL_LIB_DIR}/qhullstatic_rd.lib  ${QHULL_LIB_DIR}/qhullcpp_d.lib)
# elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
#     target_link_libraries(convex ${QHULL_LIB_DIR}/qhull_r.lib ${QHULL_LIB_DIR}/qhullstatic_r.lib  ${QHULL_LIB_DIR}/qhullcpp.lib)
# endif()

# # IDE でヘッダーファイルを表示させる
# target_sources(MakeDll PRIVATE ${HEADER_FILES})


# # ---------------------------------------
# # Define install
# # ---------------------------------------
