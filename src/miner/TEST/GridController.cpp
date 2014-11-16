
/* ---------------------------------------------------------------------------
** GridController.h
** 
** Implements the grid in the game
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "GridController.h"
#include "GridModel.h"
#include "GridView.h"
#include "TileSprite.h"
#include "GemSprite.h"

#include <core/error_check.h>
#include <core/Event.h>
#include <core/GameConfig.h>

namespace miner
{
    
    GridController::GridController( GridModel* model, GridView* view )
    : m_gridModel( model ), m_gridView( view )
    {
        m_gridModel->onTileCreated.Connect( this, &GridController::tileCreated );
        m_gridModel->onGemCreated.Connect( this, &GridController::gemCreated );
        m_gridModel->onBorderCreated.Connect( this, &GridController::borderCreated );
    }


    GridController::~GridController()
    {
        m_gridModel->onTileCreated.Disconnect( this, &GridController::tileCreated );
        m_gridModel->onGemCreated.Disconnect( this, &GridController::gemCreated );
        m_gridModel->onBorderCreated.Disconnect( this, &GridController::borderCreated );
    }


    void GridController::processInput(InputEvent& e)
    {
        if( ! e.getConsumed() && e.getEvent().type == SDL_MOUSEBUTTONUP )
        {
            // Get Mouse coordinates as tile
            int x, y;
            SDL_GetMouseState( &x, &y );
            e.setConsumed(true);

            const Point& layer_transform = gDisplayConfig::instance().getLayer( K_GAMELAYER_TILE );
            const unsigned int ratio = gDisplayConfig::instance().getPixelPerUnit();
            m_gridModel->fireOnTile((y - layer_transform.y) / ratio, (x - layer_transform.x) / ratio );
        }
    }


    void GridController::tileCreated( const Entity* e )
    {
        DEBUG_ASSERT( e != NULL )
        m_gridView->addDecoration( new TileSprite( e ) );
    }

    void GridController::gemCreated( const Entity* e )
    {
        DEBUG_ASSERT( e != NULL )
        m_gridView->addDecoration( new GemSprite( e ) );
    }

    void GridController::borderCreated( unsigned int x, unsigned int y )
    {
        m_gridView->addDecoration( new Sprite( "border", x*gDisplayConfig::instance().getPixelPerUnit(), y*gDisplayConfig::instance().getPixelPerUnit(), K_GAMELAYER_GRID_BORDER ) );
    }



} // end namespace miner