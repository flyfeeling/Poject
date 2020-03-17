# CMakeList.txt: AIServer 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project (AIServer)
#添加include目录
include_directories(${ServerEngineInc})
include_directories(${LuaInc})
include_directories(${ProtobufInc})
include_directories(${SqliteInc})
include_directories(${MessageSrc})
LINK_LIB_PLATFORM_DIR(${MysqlInc}/windows ${MysqlInc}/linux)
#添加库目录 = -L
link_directories(${OpenLibs})
# 并将名称保存到 DIR_SRCS 变量
file(GLOB_RECURSE DIR_SRCS ./*.cpp ./*.cc ./*.c ./*.h ./*.hpp)
message(STATUS ${DIR_SRCS})
# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} ${DIR_SRCS})
LINK_LIB_PLATFORM_DR(${OpenLibs} libprotobuf libprotobuf "d" "")
LINK_LIB_PLATFORM_DR(${OpenLibs} libmysql libmysqlclient "" "")
LINK_LIB_PLATFORM_DR(${OpenLibs} sqlite3 libsqlite3 "" "")
LINK_LIB_PLATFORM_DR(${OpenLibs} lua liblua "" "")

target_link_libraries(${PROJECT_NAME} ServerEngine)
target_link_libraries(${PROJECT_NAME} Message)

# TODO: 如有需要，请添加测试并安装目标。
