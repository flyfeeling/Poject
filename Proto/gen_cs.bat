
@echo off
set proto_dir=./proto_raw
set excute_dir=.\proto_tool\protogen.exe
set output_dir=./protoc-gen-cs
set copy_dir=..\Server\Message\
for /f "delims=\" %%i in ('dir /b  /a-d /o-d "%proto_dir%\*.proto"') do (
	%excute_dir% -i:%proto_dir%/%%~ni.proto -o:%output_dir%/%%~ni.cs -ns:Proto -p:detectMissing
)
rem xcopy  "%output_dir%\*.*" %copy_dir% /S /C /Y
pause