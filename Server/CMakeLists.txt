# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project (Server)

#----------宏定义----------#
#根据是平台区分链接什么库
MACRO(LINK_LIB_PLATFORM WIN_LIB_NAME LINUX_LIB_NAME)
	IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
		string(CONCAT NEW_NAME ${LINUX_LIB_NAME} "")	
	ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
		IF(CMAKE_BUILD_TYPE MATCHES "Debug")
			string(CONCAT NEW_NAME ${WIN_LIB_NAME} "d")
		ELSE()
			string(CONCAT NEW_NAME ${WIN_LIB_NAME} "")
		ENDIF()
	ENDIF ()
	target_link_libraries( ${PROJECT_NAME} ${NEW_NAME})
ENDMACRO()

#根据平台不同,并且区分debug release的库
MACRO(LINK_LIB_PLATFORM_DR LIB_DIR WIN_LIB_NAME LINUX_LIB_NAME DEBUGSUFFIX EXSUFFIX)
	IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
		#linux下就不用d后缀的debug库了
		set(DEBUG_LIB ${LIB_DIR}/${LINUX_LIB_NAME}${EXSUFFIX}.a)
		set(RELEASE_LIB ${LIB_DIR}/${LINUX_LIB_NAME}${EXSUFFIX}.a)
	ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
		set(DEBUG_LIB ${LIB_DIR}/${WIN_LIB_NAME}${DEBUGSUFFIX}.lib)
		set(RELEASE_LIB ${LIB_DIR}/${WIN_LIB_NAME}${EXSUFFIX}.lib)
	ENDIF ()
	MESSAGE(STATUS "<-------------------------------------->")
	MESSAGE(STATUS ${DEBUG_LIB})
	MESSAGE(STATUS ${RELEASE_LIB})
	IF(CMAKE_BUILD_TYPE MATCHES "Debug")
		IF(EXISTS ${DEBUG_LIB})
			target_link_libraries(${PROJECT_NAME} ${DEBUG_LIB})
		ELSE()
			target_link_libraries(${PROJECT_NAME} ${RELEASE_LIB})
		ENDIF()
	ELSEIF(CMAKE_BUILD_TYPE MATCHES "Release")
		target_link_libraries(${PROJECT_NAME} ${RELEASE_LIB})		
	ENDIF()
ENDMACRO()

MACRO(LINK_LIB_PLATFORM_DIR WIN_DIR LINUX_DIR)
	IF(CMAKE_SYSTEM_NAME MATCHES "Linux")
		include_directories(${LINUX_DIR})
	ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
		include_directories(${WIN_DIR})
	ENDIF ()
ENDMACRO()

#这个就是定义各个版本对应的后缀，例如d，debug版本后缀，当然你想定义为其他，	#自己修改这块就可以了。
SET(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually Debug")
SET(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually Release")
SET(CMAKE_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "add a postfix, usually RelWithDebInfo")
SET(CMAKE_MINSIZEREL_POSTFIX "s" CACHE STRING "add a postfix, usually MinSizeRel")

#判断自己的编译状态
IF(CMAKE_BUILD_TYPE MATCHES "Debug")
	MESSAGE(STATUS "current compilation type: Debug ")
	set(BIN_PATH ${PROJECT_SOURCE_DIR}/build/bin)
	set(LIB_PATH ${PROJECT_SOURCE_DIR}/build/lib)
ELSEIF(CMAKE_BUILD_TYPE MATCHES "Release")
	MESSAGE(STATUS "current compilation type: Release ")
	set(BIN_PATH ${PROJECT_SOURCE_DIR}/build/bin)
	set(LIB_PATH ${PROJECT_SOURCE_DIR}/build/lib)
ELSEIF(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
	MESSAGE(STATUS "current compilation type: RelWithDebInfo")
	set(BIN_PATH ${PROJECT_SOURCE_DIR}/build/bin)
	set(LIB_PATH ${PROJECT_SOURCE_DIR}/build/lib)
ELSEIF(CMAKE_BUILD_TYPE MATCHES "MinSizeRel")
	MESSAGE(STATUS "current compilation type: MinSizeRel")
	set(BIN_PATH ${PROJECT_SOURCE_DIR}/build/bin)
	set(LIB_PATH ${PROJECT_SOURCE_DIR}/build/lib)
ENDIF()


#----------编译选项设置----------#
IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	#设置运行库编译选项
	SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
	#禁用特定警告
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996 /wd4800")
ENDIF()
#添加c++11编译条件
add_definitions(-std=c++11)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

#开启编译输出
SET( CMAKE_VERBOSE_MAKEFILE on )

#设置库文件存放路径
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
#设置执行文件存放路径
set(EXECUTABLE_OUTPUT_PATH ${BIN_PATH})

#设置include目录
set(ServerEngineInc ${PROJECT_SOURCE_DIR}/ServerEngine)
set(LuaInc ${PROJECT_SOURCE_DIR}/third_party/Lua)
set(MysqlInc ${PROJECT_SOURCE_DIR}/third_party/Mysql)
set(ProtobufInc ${PROJECT_SOURCE_DIR}/third_party/protobuf/src)
set(SqliteInc ${PROJECT_SOURCE_DIR}/third_party/Sqlite)
set(MessageSrc ${PROJECT_SOURCE_DIR}/Message)
set(ServerData ${PROJECT_SOURCE_DIR}/ServerData)
Set(GameEntitySrc ${PROJECT_SOURCE_DIR}/GameEntity)
Set(DetourInc ${PROJECT_SOURCE_DIR}/third_party/recastnavigation/Detour/Include)
set(RedisInc ${PROJECT_SOURCE_DIR}/third_party/hiredis)
#设置lib目录
set(OpenLibs  ${PROJECT_SOURCE_DIR}/third_party/Lib)

# 包含子项目。
add_subdirectory ("ServerEngine")
add_subdirectory("Message")
add_subdirectory("UnitTest")
add_subdirectory ("AccountServer")
add_subdirectory ("LoginServer")
#add_subdirectory("DBServer")
add_subdirectory("ProxyServer")


