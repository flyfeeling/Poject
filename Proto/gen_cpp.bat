@echo off
set proto_dir=./proto_raw
set excute_dir=.\proto_tool\protoc.exe
set output_dir=./protoc-gen-cpp
set copy_dir=..\Server\Message\
for /f "delims=\" %%i in ('dir /b  /a-d /o-d "%proto_dir%\*.proto"') do (
	rem .\proto_tool\protoc.exe -I=./proto_raw --cpp_out=./protoc-gen-cpp ./proto_raw/%%~ni.proto
	%excute_dir% -I=%proto_dir% --cpp_out=%output_dir% %proto_dir%/%%~ni.proto
)
xcopy  "%output_dir%\*.*" %copy_dir% /S /C /Y
pause