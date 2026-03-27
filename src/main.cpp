#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Buscamos en todos los hijos del menú
        auto children = this->getChildren();
        for (int i = 0; i < children->count(); ++i) {
            auto child = static_cast<CCNode*>(children->objectAtIndex(i));
            
            // Verificamos si el ID contiene la palabra "geode"
            // Esto atrapa al botón sin importar el nombre exacto del ID
            std::string id = child->getID();
            if (id.find("geode") != std::string::npos) {
                child->setVisible(false);
                child->setScale(0);
                child->setPosition({-1000, -1000}); // Lo mandamos fuera de la pantalla
            }
        }

        return true;
    }
};