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
Date                   :=14/12/2017
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
Objects0=$(IntermediateDirectory)/startup.c$(ObjectSuffix) $(IntermediateDirectory)/gameobject.c$(ObjectSuffix) $(IntermediateDirectory)/fire.c$(ObjectSuffix) $(IntermediateDirectory)/player.c$(ObjectSuffix) $(IntermediateDirectory)/bird.c$(ObjectSuffix) $(IntermediateDirectory)/witch.c$(ObjectSuffix) $(IntermediateDirectory)/DIP.c$(ObjectSuffix) $(IntermediateDirectory)/flame.c$(ObjectSuffix) $(IntermediateDirectory)/boom.c$(ObjectSuffix) $(IntermediateDirectory)/graphics.c$(ObjectSuffix) \
	$(IntermediateDirectory)/image.c$(ObjectSuffix) $(IntermediateDirectory)/sprite.c$(ObjectSuffix) $(IntermediateDirectory)/gpio.c$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/ascii_display.c$(ObjectSuffix) $(IntermediateDirectory)/slow_text.c$(ObjectSuffix) $(IntermediateDirectory)/indoors.c$(ObjectSuffix) $(IntermediateDirectory)/indoors2.c$(ObjectSuffix) $(IntermediateDirectory)/trophy.c$(ObjectSuffix) 



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
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

$(IntermediateDirectory)/bird.c$(ObjectSuffix): bird.c $(IntermediateDirectory)/bird.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/bird.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bird.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bird.c$(DependSuffix): bird.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bird.c$(ObjectSuffix) -MF$(IntermediateDirectory)/bird.c$(DependSuffix) -MM bird.c

$(IntermediateDirectory)/bird.c$(PreprocessSuffix): bird.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bird.c$(PreprocessSuffix) bird.c

$(IntermediateDirectory)/witch.c$(ObjectSuffix): witch.c $(IntermediateDirectory)/witch.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/witch.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/witch.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/witch.c$(DependSuffix): witch.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/witch.c$(ObjectSuffix) -MF$(IntermediateDirectory)/witch.c$(DependSuffix) -MM witch.c

$(IntermediateDirectory)/witch.c$(PreprocessSuffix): witch.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/witch.c$(PreprocessSuffix) witch.c

$(IntermediateDirectory)/DIP.c$(ObjectSuffix): DIP.c $(IntermediateDirectory)/DIP.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/DIP.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DIP.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DIP.c$(DependSuffix): DIP.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DIP.c$(ObjectSuffix) -MF$(IntermediateDirectory)/DIP.c$(DependSuffix) -MM DIP.c

$(IntermediateDirectory)/DIP.c$(PreprocessSuffix): DIP.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DIP.c$(PreprocessSuffix) DIP.c

$(IntermediateDirectory)/flame.c$(ObjectSuffix): flame.c $(IntermediateDirectory)/flame.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/flame.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/flame.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/flame.c$(DependSuffix): flame.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/flame.c$(ObjectSuffix) -MF$(IntermediateDirectory)/flame.c$(DependSuffix) -MM flame.c

$(IntermediateDirectory)/flame.c$(PreprocessSuffix): flame.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/flame.c$(PreprocessSuffix) flame.c

$(IntermediateDirectory)/boom.c$(ObjectSuffix): boom.c $(IntermediateDirectory)/boom.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/boom.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/boom.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/boom.c$(DependSuffix): boom.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/boom.c$(ObjectSuffix) -MF$(IntermediateDirectory)/boom.c$(DependSuffix) -MM boom.c

$(IntermediateDirectory)/boom.c$(PreprocessSuffix): boom.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/boom.c$(PreprocessSuffix) boom.c

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

$(IntermediateDirectory)/indoors.c$(ObjectSuffix): indoors.c $(IntermediateDirectory)/indoors.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/indoors.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/indoors.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/indoors.c$(DependSuffix): indoors.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/indoors.c$(ObjectSuffix) -MF$(IntermediateDirectory)/indoors.c$(DependSuffix) -MM indoors.c

$(IntermediateDirectory)/indoors.c$(PreprocessSuffix): indoors.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/indoors.c$(PreprocessSuffix) indoors.c

$(IntermediateDirectory)/indoors2.c$(ObjectSuffix): indoors2.c $(IntermediateDirectory)/indoors2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/indoors2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/indoors2.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/indoors2.c$(DependSuffix): indoors2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/indoors2.c$(ObjectSuffix) -MF$(IntermediateDirectory)/indoors2.c$(DependSuffix) -MM indoors2.c

$(IntermediateDirectory)/indoors2.c$(PreprocessSuffix): indoors2.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/indoors2.c$(PreprocessSuffix) indoors2.c

$(IntermediateDirectory)/trophy.c$(ObjectSuffix): trophy.c $(IntermediateDirectory)/trophy.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/mop/c/Moplaborationer/DIPs-Witch/C/trophy.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/trophy.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/trophy.c$(DependSuffix): trophy.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/trophy.c$(ObjectSuffix) -MF$(IntermediateDirectory)/trophy.c$(DependSuffix) -MM trophy.c

$(IntermediateDirectory)/trophy.c$(PreprocessSuffix): trophy.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/trophy.c$(PreprocessSuffix) trophy.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


