@echo off
REM
REM $Id: msvcvars.bat 492980 2016-02-23 16:24:57Z gouriano $
REM

@if not "%VSINSTALLDIR%"=="" goto devenv
@call "%VS140COMNTOOLS%vsvars32.bat"

:devenv

if exist "%VS140COMNTOOLS%..\IDE\VCExpress.*" set DEVENV="%VS140COMNTOOLS%..\IDE\VCExpress"
if exist "%VS140COMNTOOLS%..\IDE\devenv.*" set DEVENV="%VS140COMNTOOLS%..\IDE\devenv"

:end
