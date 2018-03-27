# macro
COMP = cl
LINK = link
OPTIONS = /EHsc /I.
EXE = shell.exe

# suffix rule
.cpp.obj:
	$(COMP) /Fe$@ /c $< $(OPTIONS)

$(EXE): CommandLine.obj CommandProcess.obj commands.obj main.obj script.obj
	$(LINK) /out:$@ $** /LIBPATH:.\boost

CommandLine.obj: CommandLine.cpp function.h exception.h
CommandProcess.obj: CommandProcess.cpp function.h wtokenizer.h exception.h
commands.obj: commands.cpp function.h exception.h constant.h
main.obj: main.cpp function.h exception.h
script.obj: script.cpp function.h exception.h
