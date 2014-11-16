/* ---------------------------------------------------------------------------
** GridScene.h
** 
** Implements grid scene
**
** Author: Gianluca
** -------------------------------------------------------------------------*/

#include "GridScene.h"
#include "../TEST/GridModel.h"
#include "../TEST/GridView.h"
#include "../TEST/GridController.h"

#include <core/error_check.h>
#include <core/TextureSystem.h>
#include <core/Singleton.h>
#include <core/GameConfig.h>

namespace miner
{

    GridScene::GridScene(const std::string& name)
    : Scene(name)
    {

    }


    void GridScene::init()
    {
        gTextureSystem::instance().registerTexture( "../assets/background.png", "background", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/tile_default.png", "tile_default", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/gem-crystal.png", "gem-crystal", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/gem-diamond.png", "gem-diamond", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/gem-rubin.png", "gem-rubin", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/gem-topaz.png", "gem-topaz", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/stone.png", "border", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/explotion.png", "explotion", sWhiteColor );
        gTextureSystem::instance().registerTexture( "../assets/smoke.png", "smoke", sWhiteColor );

    }
    

    void GridScene::load()
    {
        const unsigned int numRow = 14;
        const unsigned int numCol = 12;
        
        m_gridModel         = GridModelPtr( new GridModel( numRow, numCol, 15 ) );
        m_gridView          = GridViewPtr( new GridView() );
        m_gridController    = GridControllerPtr( new GridController( m_gridModel.get(), m_gridView.get() ) );

        Point layer_grid;
        layer_grid.x = ( gDisplayConfig::instance().getWindowWidth() / 2.0f) - ( numCol * gDisplayConfig::instance().getPixelPerUnit()/2.0f);
        layer_grid.y = ( gDisplayConfig::instance().getWindowHeight() / 2.0f) - ( numRow * gDisplayConfig::instance().getPixelPerUnit()/2.0f);
        Point layer_border = { layer_grid.x - gDisplayConfig::instance().getPixelPerUnit() , layer_grid.y - gDisplayConfig::instance().getPixelPerUnit() };
        
        gDisplayConfig::instance().registerLayer( K_GAMELAYER_GRID_BORDER, layer_border );
        gDisplayConfig::instance().registerLayer( K_GAMELAYER_TILE, layer_grid );
        gDisplayConfig::instance().registerLayer( K_GAMELAYER_GEM, layer_grid );

        // load from a file or load random
        m_gridModel->initializeGridRandom();


    }


    void GridScene::processInput(InputEvent& e)
    {
        DEBUG_ASSERT( m_gridController.get() != NULL )
        m_gridController->processInput( e );
    }


    void GridScene::update()
    {
        DEBUG_ASSERT( m_gridModel.get() != NULL )
        m_gridModel->update();

    }
    

    void GridScene::draw()
    {
        DEBUG_ASSERT( m_gridView.get() != NULL )
        m_gridView->draw();
    }


    GridScene::~GridScene()
    {

    }

} // end namespace miner