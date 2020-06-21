@echo off

set root-dir=%~pd0
set project-dir=%root-dir%
set cmake-output-dir=%root-dir%build/

cmake -S %project-dir% -B %cmake-output-dir%
cmake --build %cmake-output-dir% --config Debug

set visual-studio-dir=C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/
set visual-studio-test-tool-dir=%visual-studio-dir%Common7/IDE/Extensions/TestPlatform/

"%visual-studio-test-tool-dir%vstest.console.exe" %cmake-output-dir%Debug/ntrvlmp.dll
