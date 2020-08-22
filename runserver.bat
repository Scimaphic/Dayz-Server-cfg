@echo off
:start
::Server name
set serverName=Maxwell DayZ server
::Server files location
set serverLocation="C:\SteamLibrary\steamapps\common\DayZServer"
::Server Port
set serverPort=5150
::Server config
set serverConfig=serverDZ.cfg
::Logical CPU cores to use (Equal or less than available)
set serverCPU=2
::Sets title for terminal (DONT edit)
title %serverName% batch

::DayZServer location (DONT edit)
cd "%serverLocation%"
echo (%time%) %serverName% started.
::Launch parameters (edit end: -config=|-port=|-profiles=|-doLogs|-adminLog|-netLog|-freezeCheck|-filePatching|-BEpath=|-cpuCount=)
:watchdog
echo (%time%) %wat% started.
start "DayZ Server" /wait /affinity FF /high "DayZServer_x64.exe" -mod=@CF;@VPPAdminTools;@VanillaPlusPlusMap;@Stamina -profiles=DZMod -config=%serverConfig% -port=%serverPort% -cpuCount=%serverCPU% -freezecheck
echo (%time%) %wat% closed or crashed, restarting.
goto watchdog

::Time in seconds before kill server process (14400 = 4 hours)
::timeout 14390
::taskkill /im DayZServer_x64.exe /F
::Time in seconds to wait before..
::timeout 10
::Go back to the top and repeat the whole cycle again
::goto start