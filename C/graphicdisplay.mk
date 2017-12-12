##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=graphicdisplay
ConfigurationName      :=Debug
WorkspacePath          :=C:/mop/c/Moplaborationer
ProjectPath            :=C:/mop/c/Moplaborationer/DIPs-Witch/C
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sparven
Date                   :=12/12/2017
CodeLitePath           :=C:/cseapp/CodeLite
LinkerName             :=$(CodeLiteDir)/tools/gcc-arm/bin/arm-none-eabi-g++.exe
SharedObjectLinkerName :=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi-g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).elf
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="graphicdisplay.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=
LinkOptions            :=  -T$(ProjectPath)/md407-ram.x -L$(ARM_V6LIB) -L$(ARM_GCC_V6LIB) -nostartfiles
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)gcc $(LibrarySwitch)c_nano 
ArLibs                 :=  "gcc" "c_nano" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := $(CodeLiteDir)/tools/gcc-arm/bin/arm-none-eabi-ar.exe rcu
CXX      := $(CodeLiteDir)/tools/gcc-arm/bin/arm-none-eabi-g++.exe
CC       := $(CodeLiteDir)/tools/gcc-arm/bin/arm-none-eabi-gcc.exe
CXXFLAGS :=  -g -O0 -W $(Preprocessors)
CFLAGS   :=  -Wa,-adhln=test.s -g -O0 -w -mthumb -march=armv6-m  -mfloat-abi=soft -std=c99 -mthumb -march=armv6-m $(Preprocessors)
ASFLAGS  := 
AS       := $(CodeLiteDir)/tools/gcc-arm/bin/arm-none-eabi-as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\cseapp\CodeLite
ARM_V6LIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v6-m
ARM_GCC_V6LIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/6.3.1/thumb/v6-m
ARM_M4FPLIB:=$(CodeLiteDir)/tools/gcc-arm/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard
ARM_GCC_M4FPLIB:=$(CodeLiteDir)/tools/gcc-arm/lib/gcc/arm-none-eabi/6.3.1/thumb/v7e-m
Objects0=$(IntermediateDirectory)/startup.c$(ObjectSuffix) $(IntermediateDirectory)/gameobject.c$(ObjectSuffix) $(IntermediateDirectory)/fire.c$(ObjectSuffix) $(IntermediateDirectory)/player.c$(ObjectSuffix) $(IntermediateDirectory)/graphics.c$(ObjectSuffix) $(IntermediateDirectory)/image.c$(ObjectSuffix) $(IntermediateDirectory)/sprite.c$(ObjectSuffix) $(IntermediateDirectory)/gpio.c$(ObjectSuffix) $(IntermediateDirectory)/ascii_display.c$(ObjectSuffix) $(IntermediateDirectory)/slow_text.c$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	arm-none-eabi-objcopy -S -O srec  ./Debug/graphicdisplay.elf ./Debug/graphicdisplay.s19
	arm-none-eabi-objdump -D -S ./Debug/graphicdisplay.elf > ./Debug/graphicdisplay.dass
	@echo Done

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/startup.c$(ObjectSuffix): startup.c $(IntermediateDirectory)/startup.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/startup.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/startup.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/startup.c$(DependSuffix): startup.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/startup.c$(ObjectSuffix) -MF$(IntermediateDirectory)/startup.c$(DependSuffix) -MM startup.c

$(IntermediateDirectory)/startup.c$(PreprocessSuffix): startup.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/startup.c$(PreprocessSuffix) startup.c

$(IntermediateDirectory)/gameobject.c$(ObjectSuffix): gameobject.c $(IntermediateDirectory)/gameobject.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/gameobject.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gameobject.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gameobject.c$(DependSuffix): gameobject.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gameobject.c$(ObjectSuffix) -MF$(IntermediateDirectory)/gameobject.c$(DependSuffix) -MM gameobject.c

$(IntermediateDirectory)/gameobject.c$(PreprocessSuffix): gameobject.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gameobject.c$(PreprocessSuffix) gameobject.c

$(IntermediateDirectory)/fire.c$(ObjectSuffix): fire.c $(IntermediateDirectory)/fire.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/fire.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fire.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fire.c$(DependSuffix): fire.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fire.c$(ObjectSuffix) -MF$(IntermediateDirectory)/fire.c$(DependSuffix) -MM fire.c

$(IntermediateDirectory)/fire.c$(PreprocessSuffix): fire.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fire.c$(PreprocessSuffix) fire.c

$(IntermediateDirectory)/player.c$(ObjectSuffix): player.c $(IntermediateDirectory)/player.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/player.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/player.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/player.c$(DependSuffix): player.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/player.c$(ObjectSuffix) -MF$(IntermediateDirectory)/player.c$(DependSuffix) -MM player.c

$(IntermediateDirectory)/player.c$(PreprocessSuffix): player.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/player.c$(PreprocessSuffix) player.c

$(IntermediateDirectory)/graphics.c$(ObjectSuffix): graphics.c $(IntermediateDirectory)/graphics.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/graphics.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/graphics.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/graphics.c$(DependSuffix): graphics.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/graphics.c$(ObjectSuffix) -MF$(IntermediateDirectory)/graphics.c$(DependSuffix) -MM graphics.c

$(IntermediateDirectory)/graphics.c$(PreprocessSuffix): graphics.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/graphics.c$(PreprocessSuffix) graphics.c

$(IntermediateDirectory)/image.c$(ObjectSuffix): image.c $(IntermediateDirectory)/image.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/image.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/image.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/image.c$(DependSuffix): image.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/image.c$(ObjectSuffix) -MF$(IntermediateDirectory)/image.c$(DependSuffix) -MM image.c

$(IntermediateDirectory)/image.c$(PreprocessSuffix): image.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/image.c$(PreprocessSuffix) image.c

$(IntermediateDirectory)/sprite.c$(ObjectSuffix): sprite.c $(IntermediateDirectory)/sprite.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/sprite.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sprite.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sprite.c$(DependSuffix): sprite.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sprite.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sprite.c$(DependSuffix) -MM sprite.c

$(IntermediateDirectory)/sprite.c$(PreprocessSuffix): sprite.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sprite.c$(PreprocessSuffix) sprite.c

$(IntermediateDirectory)/gpio.c$(ObjectSuffix): gpio.c $(IntermediateDirectory)/gpio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/gpio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gpio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gpio.c$(DependSuffix): gpio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gpio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/gpio.c$(DependSuffix) -MM gpio.c

$(IntermediateDirectory)/gpio.c$(PreprocessSuffix): gpio.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gpio.c$(PreprocessSuffix) gpio.c

$(IntermediateDirectory)/ascii_display.c$(ObjectSuffix): ascii_display.c $(IntermediateDirectory)/ascii_display.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/ascii_display.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ascii_display.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ascii_display.c$(DependSuffix): ascii_display.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ascii_display.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ascii_display.c$(DependSuffix) -MM ascii_display.c

$(IntermediateDirectory)/ascii_display.c$(PreprocessSuffix): ascii_display.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ascii_display.c$(PreprocessSuffix) ascii_display.c

$(IntermediateDirectory)/slow_text.c$(ObjectSuffix): slow_text.c $(IntermediateDirectory)/slow_text.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/slow_text.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/slow_text.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/slow_text.c$(DependSuffix): slow_text.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/slow_text.c$(ObjectSuffix) -MF$(IntermediateDirectory)/slow_text.c$(DependSuffix) -MM slow_text.c

$(IntermediateDirectory)/slow_text.c$(PreprocessSuffix): slow_text.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/slow_text.c$(PreprocessSuffix) slow_text.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


