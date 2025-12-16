@echo off
REM ==========================================
REM Ejecuta PRUEBAS del Proyecto Final
REM Árbol General + Trie + Consola (C# .NET)
REM Días 10–11: Integración y rendimiento
REM ==========================================

REM Ir a la carpeta del proyecto
cd /d "%~dp0"

echo ================================
echo Ejecutando PRUEBAS del proyecto
echo ================================
echo.

REM Ejecuta el proyecto (Program.cs debe llamar a PruebasIntegracion)
dotnet run

if %errorlevel% neq 0 (
    echo.
    echo ❌ Error al ejecutar las pruebas.
    pause
    exit /b %errorlevel%
)

echo.
echo ✅ Pruebas finalizadas correctamente.
pause
