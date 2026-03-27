#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Buscamos el botón de Geode por su ID estándar
        if (auto geodeButton = this->getChildByID("geode.loader/geode-button")) {
            geodeButton->setVisible(false); // Simplemente lo ocultamos
            // geodeButton->removeFromParent(); // O lo eliminamos por completo
        }

        return true;
    }
};