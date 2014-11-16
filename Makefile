

ifeq ($(BUILD),debug)
	BUILD_SUFFIX = -d
	BUILD_FLAGS = -g -Wall -Wno-unused -Wno-unused-variable -D_DEBUG
else
	BUILD_SUFFIX = 
	BUILD_FLAGS = -O2 -Wall -Wno-unused -Wno-unused-variable
endif

#OBJS specifies which files to compile as part of the project
OBJS = \
	src/main.cpp							\

OBJS_CORE = \
	src/core/core.cpp						\
	src/core/Game.cpp						\
	src/core/GameConfig.cpp					\
	src/core/SceneManager.cpp				\
	src/core/Texture.cpp					\
	src/core/TextureSystem.cpp				\
	src/core/Sprite.cpp						\
	src/core/GridTraverser.cpp				\
	src/core/AnimatedSprite.cpp				\

OBJ_MINER = \
	src/miner/miner.cpp						\
	src/miner/MinerGame.cpp					\
	src/miner/scenes/GridScene.cpp			\
	src/miner/TEST/GridModel.cpp			\
	src/miner/TEST/GridController.cpp		\
	src/miner/TEST/GridView.cpp				\
	src/miner/TEST/TileSprite.cpp			\
	src/miner/TEST/gemSprite.cpp			\
	src/miner/TEST/Logic.cpp				\
	src/miner/TEST/Gem.cpp					\


	

#EXECUTABLE_NAME specifies the name of our exectuable
EXECUTABLE_NAME += bin/game$(BUILD_SUFFIX).exe

INCLUDE_FOLDER 	= D:\WORKSPACE\include
LIB_FOLDER 		= D:\WORKSPACE\lib
MINGW_FOLDER 	= C:\MinGW\lib

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = \
	-I src									\
	-I $(INCLUDE_FOLDER)\SDL2\2.0.3 		\
	-I $(INCLUDE_FOLDER)\SDL2_image\2.0.0 	\
	-I $(INCLUDE_FOLDER)\SDL2_ttf\2.0.12 	\
	-I $(INCLUDE_FOLDER)\SDL2_mixer\2.0.0	\


	

#LIBRARY_PATHS specifies the additional library paths we'll need
LIB_PATHS = \
	-L $(MINGW_FOLDER)\lib 					\
	-L $(LIB_FOLDER)\SDL2\2.0.3 			\
	-L $(LIB_FOLDER)\SDL2_image\2.0.0 		\
	-L $(LIB_FOLDER)\SDL2_ttf\2.0.12 		\
	-L $(LIB_FOLDER)\SDL2_mixer\2.0.0 		\

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wl,-subsystem,console $(BUILD_FLAGS)


#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) $(OBJS_CORE) $(OBJ_MINER) $(INCLUDE_PATHS) $(LIB_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXECUTABLE_NAME)