@echo off

call build.bat

set originalpath=%~dp0
set buildspath=%~dp0builds\

cd %buildspath%

for /f "tokens=*" %%a in ('type "message.txt"') do set plaintext=%%a

for /f "tokens=*" %%a in ('type "message.txt" ^| "encrypt-shift-cipher.exe"') do set encrypted=%%a
for /f "tokens=*" %%a in ('type "message.txt" ^| "encrypt-shift-cipher.exe" ^| "decrypt-shift-cipher.exe"') do set decrypted=%%a

if %plaintext%==%encrypted% ( goto Failed )
if not %plaintext%==%decrypted% ( goto Failed )

for /f "tokens=*" %%a in ('type "message.txt" ^| "encrypt-hill-cipher.exe"') do set encrypted=%%a
for /f "tokens=*" %%a in ('type "message.txt" ^| "encrypt-hill-cipher.exe" ^| "decrypt-hill-cipher.exe"') do set decrypted=%%a

if %plaintext%==%encrypted% ( echo 1 )
if not %plaintext%==%decrypted% ( echo %decrypted% )

goto Passed

:Failed
echo Tests Failed
goto End

:Passed
echo Tests Passed
goto End

:End

cd %originalpath%