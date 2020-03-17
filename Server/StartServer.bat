:start
@echo off
color 0A
set DebugDir=%cd%\build\bin\
start %DebugDir%AIServer.exe
start %DebugDir%GameServer.exe