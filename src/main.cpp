#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/NodeIDs.hpp> // Importante para manejar IDs

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Creamos un "escuchador" de nodos. 
        // En cuanto aparezca algo con el ID del botón, ejecutamos la función.
        this->template addEventListener<NodeIDsEvent>(
            [this](NodeIDsEvent* event) {
                if (auto geodeButton = this->getChildByID("geode.loader/geode-button")) {
                    geodeButton->setVisible(false);
                    geodeButton->setScale(0);
                    geodeButton->setPosition({-9999, -9999});
                }
                return ListenerResult::Propagate;
            },
            "geode.loader/geode-button" 
        );

        // Por si acaso ya existía antes del evento, lo intentamos una vez más aquí
        if (auto geodeButton = this->getChildByID("geode.loader/geode-button")) {
            geodeButton->setVisible(false);
        }

        return true;
    }
};