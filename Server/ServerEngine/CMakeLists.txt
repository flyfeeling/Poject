# CMakeList.txt: ServerEngine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
project (ServerEngine)

#添加include目录
include_directories(${LuaInc})
include_directories(${ProtobufInc})
include_directories(${SqliteInc})
LINK_LIB_PLATFORM_DIR(${MysqlInc}/windows ${MysqlInc}/linux)
#添加库目录 = -L
#link_directories(${OpenLibs})
# 将源代码添加到此项目的可执行文件。
file(GLOB_RECURSE DIR_SRCS ./*.cpp ./*.cc ./*.c ./*.h ./*.hpp)
message(STATUS ${DIR_SRCS})
# 将源代码添加到此项目的生成库文件
add_library(${PROJECT_NAME} ${DIR_SRCS})
# TODO: 如有需要，请添加测试并安装目标。

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
  list(APPEND engine_defines 
		_CONSOLE 
		SERVER_ENGINE 
		_CRT_SECURE_NO_WARNINGS
		_WINSOCK_DEPRECATED_NO_WARNINGS)
	target_compile_definitions(${PROJECT_NAME} PRIVATE ${engine_defines})
else(CMAKE_SYSTEM_NAME MATCHES "Linux")
	list(APPEND engine_libs
		pthread
		dl
	)
	target_link_libraries(${PROJECT_NAME} ${engine_libs})
endif()

#LINK_LIB_PLATFORM_DR(${OpenLibs} libprotobuf libprotobuf "d" "")
#LINK_LIB_PLATFORM_DR(${OpenLibs} libmysql libmysqlclient "" "")
#LINK_LIB_PLATFORM_DR(${OpenLibs} sqlite3 libsqlite3 "" "")
#LINK_LIB_PLATFORM_DR(${OpenLibs} lua liblua "" "")


