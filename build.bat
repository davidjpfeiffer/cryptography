@echo off
echo Building Ciphers
set originalpath=%~dp0
set buildspath=%~dp0builds\
set encryptionpath=%~dp0encryption\
set decryptionpath=%~dp0decryption\

if exist %buildspath%\* (
  rmdir %buildspath% /s /q
)

mkdir %buildspath%
cd %buildspath%

for %%f in (%encryptionpath%*.cpp) do (
  g++ -o encrypt-%%~nf -std=c++11 %%f
)

for %%f in (%decryptionpath%*.cpp) do (
  g++ -o decrypt-%%~nf -std=c++11 %%f
)

echo|set /p="thisisatestmessage" > message.txt

cd %originalpath%