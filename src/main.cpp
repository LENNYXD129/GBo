#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Usamos un "Schedule" para ejecutar el código un frame después
        // Esto asegura que Geode ya haya creado su botón
        this->scheduleOnce(schedule_selector(MyMenuLayer::hideGeodeButton), 0.0f);

        return true;
    }

    void hideGeodeButton(float dt) {
        // Buscamos el botón por su ID oficial de la versión actual
        if (auto geodeButton = this->getChildByID("geode.loader/geode-button")) {
            geodeButton->setVisible(false);
        }
    }
};