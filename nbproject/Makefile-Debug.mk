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
CND_CONF=Debug
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
	${OBJECTDIR}/src/TitleScene.o \
	${OBJECTDIR}/src/Window.o \
	${OBJECTDIR}/src/ZShape.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/mainTestShapes.o \
	${OBJECTDIR}/src/tinyxml2.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11 -g -Wall
CXXFLAGS=-std=c++11 -g -Wall

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lboost_system -lboost_filesystem

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tetris ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Command.o: nbproject/Makefile-${CND_CONF}.mk src/Command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Command.o src/Command.cpp

${OBJECTDIR}/src/EmptySquare.o: nbproject/Makefile-${CND_CONF}.mk src/EmptySquare.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/EmptySquare.o src/EmptySquare.cpp

${OBJECTDIR}/src/EventManager.o: nbproject/Makefile-${CND_CONF}.mk src/EventManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/EventManager.o src/EventManager.cpp

${OBJECTDIR}/src/Fall.o: nbproject/Makefile-${CND_CONF}.mk src/Fall.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Fall.o src/Fall.cpp

${OBJECTDIR}/src/FallEvent.o: nbproject/Makefile-${CND_CONF}.mk src/FallEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FallEvent.o src/FallEvent.cpp

${OBJECTDIR}/src/FallToGround.o: nbproject/Makefile-${CND_CONF}.mk src/FallToGround.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/FallToGround.o src/FallToGround.cpp

${OBJECTDIR}/src/Game.o: nbproject/Makefile-${CND_CONF}.mk src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Game.o src/Game.cpp

${OBJECTDIR}/src/IShape.o: nbproject/Makefile-${CND_CONF}.mk src/IShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/IShape.o src/IShape.cpp

${OBJECTDIR}/src/ImagesManager.o: nbproject/Makefile-${CND_CONF}.mk src/ImagesManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ImagesManager.o src/ImagesManager.cpp

${OBJECTDIR}/src/JShape.o: nbproject/Makefile-${CND_CONF}.mk src/JShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/JShape.o src/JShape.cpp

${OBJECTDIR}/src/LShape.o: nbproject/Makefile-${CND_CONF}.mk src/LShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LShape.o src/LShape.cpp

${OBJECTDIR}/src/LeftRight.o: nbproject/Makefile-${CND_CONF}.mk src/LeftRight.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LeftRight.o src/LeftRight.cpp

${OBJECTDIR}/src/OShape.o: nbproject/Makefile-${CND_CONF}.mk src/OShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/OShape.o src/OShape.cpp

${OBJECTDIR}/src/Painter.o: nbproject/Makefile-${CND_CONF}.mk src/Painter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Painter.o src/Painter.cpp

${OBJECTDIR}/src/RemoveCompletedLines.o: nbproject/Makefile-${CND_CONF}.mk src/RemoveCompletedLines.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/RemoveCompletedLines.o src/RemoveCompletedLines.cpp

${OBJECTDIR}/src/Rotate.o: nbproject/Makefile-${CND_CONF}.mk src/Rotate.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Rotate.o src/Rotate.cpp

${OBJECTDIR}/src/SShape.o: nbproject/Makefile-${CND_CONF}.mk src/SShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SShape.o src/SShape.cpp

${OBJECTDIR}/src/Score.o: nbproject/Makefile-${CND_CONF}.mk src/Score.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Score.o src/Score.cpp

${OBJECTDIR}/src/Shape.o: nbproject/Makefile-${CND_CONF}.mk src/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Shape.o src/Shape.cpp

${OBJECTDIR}/src/Square.o: nbproject/Makefile-${CND_CONF}.mk src/Square.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Square.o src/Square.cpp

${OBJECTDIR}/src/TShape.o: nbproject/Makefile-${CND_CONF}.mk src/TShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TShape.o src/TShape.cpp

${OBJECTDIR}/src/TableBoard.o: nbproject/Makefile-${CND_CONF}.mk src/TableBoard.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TableBoard.o src/TableBoard.cpp

${OBJECTDIR}/src/Timer.o: nbproject/Makefile-${CND_CONF}.mk src/Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Timer.o src/Timer.cpp

${OBJECTDIR}/src/TitleScene.o: nbproject/Makefile-${CND_CONF}.mk src/TitleScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TitleScene.o src/TitleScene.cpp

${OBJECTDIR}/src/Window.o: nbproject/Makefile-${CND_CONF}.mk src/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Window.o src/Window.cpp

${OBJECTDIR}/src/ZShape.o: nbproject/Makefile-${CND_CONF}.mk src/ZShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ZShape.o src/ZShape.cpp

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/mainTestShapes.o: nbproject/Makefile-${CND_CONF}.mk src/mainTestShapes.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mainTestShapes.o src/mainTestShapes.cpp

${OBJECTDIR}/src/tinyxml2.o: nbproject/Makefile-${CND_CONF}.mk src/tinyxml2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tinyxml2.o src/tinyxml2.cpp

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
