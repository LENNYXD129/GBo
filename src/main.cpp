#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Programamos una tarea que se repite un par de veces al inicio
        // para asegurar que pescamos el botón en cuanto Geode lo cree
        this->schedule(schedule_selector(MyMenuLayer::cazarBotonGeode), 0.05f);

        return true;
    }

    void cazarBotonGeode(float dt) {
        // Buscamos el botón por su ID conocido
        if (auto geodeButton = this->getChildByID("geode.loader/geode-button")) {
            geodeButton->setVisible(false);
            geodeButton->setScale(0);
            geodeButton->setPosition({-9999, -9999});
            
            // Una vez que lo encontramos y ocultamos, dejamos de buscar
            this->unschedule(schedule_selector(MyMenuLayer::cazarBotonGeode));
        }
    }
};