#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Ejecutamos la limpieza un momento después para que Geode termine de cargar
        this->scheduleOnce(schedule_selector(MyMenuLayer::limpiarYCentrar), 0.1f);

        return true;
    }

    void limpiarYCentrar(float dt) {
        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            // 1. Buscamos y borramos el botón de Geode
            if (auto geodeBtn = bottomMenu->getChildByID("geode.loader/geode-button")) {
                geodeBtn->removeFromParent(); // Lo borramos físicamente
            }

            // 2. FORZAMOS EL RE-CENTRADO
            // Esto le dice al menú: "Acomoda lo que quedó como si el botón nunca hubiera existido"
            bottomMenu->updateLayout();
        }
    }
};