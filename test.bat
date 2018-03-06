@echo off
SETLOCAL enabledelayedexpansion

call build.bat

set originalpath=%~dp0
set buildspath=%~dp0builds\

cd %buildspath%

set /A count=0
set e[0]=1
set d[0]=1

for %%f in (encrypt*cipher.exe) do (
  set e[!count!]=%%f
  set /A count+=1
)

set /A count=0

for %%f in (decrypt*cipher.exe) do (
  set d[!count!]=%%f
  set /A count+=1
)

for /f "tokens=*" %%a in ('type "message.txt"') do set plaintext=%%a

set /A countminusone=!count!-1

for /l %%i in (0, 1, !countminusone!) do (
  for /f "tokens=*" %%a in ('type "message.txt" ^| "!e[%%i]!"') do set encrypted=%%a
  for /f "tokens=*" %%a in ('type "message.txt" ^| "!e[%%i]!" ^| "!d[%%i]!"') do set decrypted=%%a

  if [!encrypted!] == [] ( goto Failed )
  if [!decrypted!] == [] ( goto Failed )
  if !plaintext!==!encrypted! ( goto Failed )
  if not !plaintext!==!decrypted! ( goto Failed )
)

goto Passed

:Failed
echo Tests Failed
goto End

:Passed
echo Tests Passed
goto End

:End

cd %originalpath%
ENDLOCAL