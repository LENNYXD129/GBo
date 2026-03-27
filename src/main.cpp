#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Activamos una actualización constante (cada frame)
        this->scheduleUpdate();

        return true;
    }

    void update(float dt) {
        // Ejecutamos la lógica original del juego
        MenuLayer::update(dt);

        // Buscamos el botón por ID y por nombre de clase por si acaso
        if (auto geodeButton = this->getChildByID("geode.loader/geode-button")) {
            geodeButton->setVisible(false);
            geodeButton->setScale(0); // Lo hacemos invisible y minúsculo
        }
    }
};