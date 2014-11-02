/* ---------------------------------------------------------------------------
** main.cpp
** 
** Entry point for the game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include <miner/miner.h>
#include <miner/MinerGame.h>

using namespace miner;

int main( int argc, char* args[] )
{
	MinerGamePtr game( MinerGame::create() );
	game->run();

	return 0;
}