@echo off
REM ============================================
REM Proyecto Final - Consola de Archivos
REM Lenguaje: C# (.NET)
REM ============================================

echo Iniciando consola del sistema de archivos...
echo.

REM Ir al directorio donde esta el .bat
cd /d "%~dp0"

REM Ejecutar directamente la consola
dotnet run

echo.
echo Consola finalizada.
pause
