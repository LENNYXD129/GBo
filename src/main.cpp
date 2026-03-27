#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        
        
        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
           
            if (auto geodeBtn = bottomMenu->getChildByID("geode.loader/geode-button")) {
                geodeBtn->setVisible(false);
                geodeBtn->removeFromParent(); 
            }
        }

        
        this->scheduleOnce(schedule_selector(MyMenuLayer::eliminarBoton), 0.1f);

        return true;
    }

    void eliminarBoton(float dt) {
        
        auto btn = this->getChildByID("geode.loader/geode-button");
        auto bMenu = this->getChildByID("bottom-menu");
        
        if (btn) btn->setVisible(false);
        
        if (bMenu) {
            if (auto btnInMenu = bMenu->getChildByID("geode.loader/geode-button")) {
                btnInMenu->setVisible(false);
                btnInMenu->setScale(0);
            }
        }
    }
};