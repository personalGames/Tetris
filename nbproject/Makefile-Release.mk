#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Command.o \
	${OBJECTDIR}/src/EmptySquare.o \
	${OBJECTDIR}/src/EventManager.o \
	${OBJECTDIR}/src/Fall.o \
	${OBJECTDIR}/src/FallEvent.o \
	${OBJECTDIR}/src/FallToGround.o \
	${OBJECTDIR}/src/Game.o \
	${OBJECTDIR}/src/IShape.o \
	${OBJECTDIR}/src/ImagesManager.o \
	${OBJECTDIR}/src/JShape.o \
	${OBJECTDIR}/src/LShape.o \
	${OBJECTDIR}/src/LeftRight.o \
	${OBJECTDIR}/src/OShape.o \
	${OBJECTDIR}/src/Painter.o \
	${OBJECTDIR}/src/RemoveCompletedLines.o \
	${OBJECTDIR}/src/Rotate.o \
	${OBJECTDIR}/src/SShape.o \
	${OBJECTDIR}/src/Score.o \
	${OBJECTDIR}/src/Shape.o \
	${OBJECTDIR}/src/Square.o \
	${OBJECTDIR}/src/TShape.o \
	${OBJECTDIR}/src/TableBoard.o \
	${OBJECTDIR}/src/Timer.o \
	${OBJECTDIR}/src/Window.o \
	${OBJECTDIR}/src/ZShape.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/mainTestShapes.o \
	${OBJECTDIR}/src/tinyxml2.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Command.o: src/Command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Command.o src/Command.cpp

${OBJECTDIR}/src/EmptySquare.o: src/EmptySquare.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/EmptySquare.o src/EmptySquare.cpp

${OBJECTDIR}/src/EventManager.o: src/EventManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/EventManager.o src/EventManager.cpp

${OBJECTDIR}/src/Fall.o: src/Fall.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Fall.o src/Fall.cpp

${OBJECTDIR}/src/FallEvent.o: src/FallEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FallEvent.o src/FallEvent.cpp

${OBJECTDIR}/src/FallToGround.o: src/FallToGround.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FallToGround.o src/FallToGround.cpp

${OBJECTDIR}/src/Game.o: src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Game.o src/Game.cpp

${OBJECTDIR}/src/IShape.o: src/IShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IShape.o src/IShape.cpp

${OBJECTDIR}/src/ImagesManager.o: src/ImagesManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ImagesManager.o src/ImagesManager.cpp

${OBJECTDIR}/src/JShape.o: src/JShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/JShape.o src/JShape.cpp

${OBJECTDIR}/src/LShape.o: src/LShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LShape.o src/LShape.cpp

${OBJECTDIR}/src/LeftRight.o: src/LeftRight.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LeftRight.o src/LeftRight.cpp

${OBJECTDIR}/src/OShape.o: src/OShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/OShape.o src/OShape.cpp

${OBJECTDIR}/src/Painter.o: src/Painter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Painter.o src/Painter.cpp

${OBJECTDIR}/src/RemoveCompletedLines.o: src/RemoveCompletedLines.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/RemoveCompletedLines.o src/RemoveCompletedLines.cpp

${OBJECTDIR}/src/Rotate.o: src/Rotate.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Rotate.o src/Rotate.cpp

${OBJECTDIR}/src/SShape.o: src/SShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SShape.o src/SShape.cpp

${OBJECTDIR}/src/Score.o: src/Score.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Score.o src/Score.cpp

${OBJECTDIR}/src/Shape.o: src/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Shape.o src/Shape.cpp

${OBJECTDIR}/src/Square.o: src/Square.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Square.o src/Square.cpp

${OBJECTDIR}/src/TShape.o: src/TShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TShape.o src/TShape.cpp

${OBJECTDIR}/src/TableBoard.o: src/TableBoard.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TableBoard.o src/TableBoard.cpp

${OBJECTDIR}/src/Timer.o: src/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Timer.o src/Timer.cpp

${OBJECTDIR}/src/Window.o: src/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Window.o src/Window.cpp

${OBJECTDIR}/src/ZShape.o: src/ZShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ZShape.o src/ZShape.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/mainTestShapes.o: src/mainTestShapes.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mainTestShapes.o src/mainTestShapes.cpp

${OBJECTDIR}/src/tinyxml2.o: src/tinyxml2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyxml2.o src/tinyxml2.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
