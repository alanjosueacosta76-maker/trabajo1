@echo off
REM ==========================================
REM Ejecuta el DEMO del Proyecto Final
REM Árbol General + Trie + Consola (C# .NET)
REM ==========================================

REM Ir a la carpeta del proyecto (donde está el .csproj)
cd /d "%~dp0"

echo ================================
echo Iniciando DEMO del proyecto...
echo ================================
echo.

dotnet run

if %errorlevel% neq 0 (
    echo.
    echo ❌ Error al ejecutar el demo.
    pause
    exit /b %errorlevel%
)

echo.
echo ✅ Demo finalizado correctamente.
pause
